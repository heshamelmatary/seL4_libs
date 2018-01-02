/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */
#ifndef _SEL4UTILS_ARCH_UTIL_H
#define _SEL4UTILS_ARCH_UTIL_H

#include <stdint.h>
#include <sel4/sel4.h>
#include <sel4/arch/pfIPC.h>
#include <sel4/arch/exIPC.h>
#include <sel4utils/sel4_arch/util.h>

static inline int
sel4utils_is_read_fault(void)
{
    seL4_Word fsr = seL4_GetMR(seL4_VMFault_FSR);
    return (fsr == 1 || fsr == 2 || fsr == 5);
}

#endif /* _SEL4UTILS_ARCH_UTIL_H */
