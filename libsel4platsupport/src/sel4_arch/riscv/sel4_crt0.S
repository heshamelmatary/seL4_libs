/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */
/*
 * A default seL4 crt0 for arm. It does the bare minimum required to emulate
 * a typical startup environment and jump to the regular _start symbol
 */

#include <autoconf.h>

#ifdef CONFIG_LIB_SEL4_PLAT_SUPPORT_SEL4_START

    .global _sel4_start
    .extern sel4_vsyscall
    .extern __dso_handle 
.text

_sel4_start:

    /* Dirty hack to load gp and avoid load/store exceptions, this should be
     * defined by the linker */
    //li gp, 0x800
    //la s0, __dso_handle
    //add gp, gp, s0
    la gp, __global_pointer$

    /* Setup a stack for ourselves. */
    la     sp, _stack_top

    /* Setup bootinfo. The pointer to the bootinfo struct starts in 'a0'. */
    //jal      seL4_InitBootInfo
    /* Construct bootinfo environment variable */   
    mv     a2, a0                                  
    la     a0, bootinfo_storage                   
    la     a1, bootinfo_format                    
    jal    sprintf                                 


    /* Setup stack frame ready for jumping to _start */
    addi sp, sp, -80
    
    /* argc */
    li   a1, 1
    sd   a1, 0(sp)
    
    /* prog name */
    la   a1, prog_name
    sd   a1, 8(sp)
    
    /* Null-terminate arg vector */
    sd   x0, 16(sp)
    
    /* Give an environment string */
    la   a1, environment_string
    sd   a1, 24(sp)

    /* Give bootinfo location */
    la   a1, bootinfo_storage
    sd   a1, 32(sp)

    /* Null terminate envp */
    sd   x0, 40(sp)

    /* give vsyscall location */
    li   a1, 32
    sd   a1, 48(sp)
    la   a1, sel4_vsyscall
    sd   a1, 56(sp)
    
    /* null terminate auxv */
    sd   x0, 64(sp)
    sd   x0, 72(sp)
    sd   x0, 80(sp)

    /* Now go to actual _start */
    j       _start

/* .text Literal Pool */
    .data
    .align  8
bootinfo_format:         
    .asciz "bootinfo=%p" 
    .align  8
bootinfo_storage:        
    .space 29            

environment_string:
    .asciz "seL4=1"
prog_name:
    .asciz "rootserver"

    .bss
    .align  8

_stack_bottom:
    .space  16384
_stack_top:

#endif /* CONFIG_LIB_SEL4_PLAT_SUPPORT_SEL4_START */
