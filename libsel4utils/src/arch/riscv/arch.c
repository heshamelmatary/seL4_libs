/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */
#include <autoconf.h>
#include <sel4/types.h>
#include <sel4utils/thread.h>
#include <stdbool.h>

int
sel4utils_arch_init_context(void *entry_point, void *stack_top, seL4_UserContext *context)
{
    //context->ra = (seL4_Word) entry_point;
    context->sepc = (seL4_Word) entry_point;
    context->sp = (seL4_Word) stack_top;
    if ((uintptr_t) stack_top % (sizeof(seL4_Word) * 2) != 0) {
        ZF_LOGE("Stack %p not aligned on double word boundary", stack_top);
        return -1;
    }
    return 0;
}

int
sel4utils_arch_init_context_with_args(void *entry_point, void *arg0, void *arg1, void *arg2,
                            bool local_stack, void *stack_top, seL4_UserContext *context,
                            vka_t *vka, vspace_t *local_vspace, vspace_t *remote_vspace)
{
    extern char _gp[];

    context->a0 = (seL4_Word) arg0;
    context->a1 = (seL4_Word) arg1;
    context->a2 = (seL4_Word) arg2;
    context->x3 = (seL4_Word) _gp;

    return sel4utils_arch_init_context(entry_point, stack_top, context);
}
