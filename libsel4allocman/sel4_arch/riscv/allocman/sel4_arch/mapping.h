/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef __ALLOCMAN_SEL4_ARCH_MAPPING__
#define __ALLOCMAN_SEL4_ARCH_MAPPING__

#include <allocman/allocman.h>

static inline seL4_Error allocman_sel4_arch_create_object_at_level(allocman_t *alloc, seL4_Word bits, cspacepath_t *path, void *vaddr, seL4_CPtr vspace_root) {
    /* RISCV has no paging objects beyond the common page table
     * so this function should never get called */
    ZF_LOGF("Invalid lookup level");
    return seL4_InvalidArgument;
}

#endif
