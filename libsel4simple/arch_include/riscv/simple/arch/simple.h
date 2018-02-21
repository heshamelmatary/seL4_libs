/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef _INTERFACE_ARCH_SIMPLE_H_
#define _INTERFACE_ARCH_SIMPLE_H_

#include <autoconf.h>

#include <assert.h>
#include <sel4/sel4.h>
#include <stdlib.h>
#include <utils/util.h>
#include <vka/cspacepath_t.h>

/**
 * Request a cap to a specific IRQ number on the system
 *
 * @param irq the irq number to get the cap for
 * @param data cookie for the underlying implementation
 * @param the CNode in which to put this cap
 * @param the index within the CNode to put cap
 * @param Depth of index
 */
typedef seL4_Error (*arch_simple_get_IRQ_control_fn)(void *data, int irq, seL4_CNode cnode, seL4_Word index, uint8_t depth); 

typedef struct arch_simple {
    void *data;
    arch_simple_get_IRQ_control_fn irq;
} arch_simple_t;

static inline seL4_CPtr 
arch_simple_get_IOPort_cap(arch_simple_t *arch_simple, uint16_t start_port, uint16_t end_port)
{
    ZF_LOGE("%s not implemented", __FUNCTION__);
    return seL4_CapNull;
}
#endif /* _INTERFACE_ARCH_SIMPLE_H_ */
