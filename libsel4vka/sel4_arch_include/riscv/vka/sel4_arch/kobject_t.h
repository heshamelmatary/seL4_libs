/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef _SEL4_ARCH_KOBJECT_T_H_
#define _SEL4_ARCH_KOBJECT_T_H_

#include <sel4/types.h>
#include <assert.h>
#include <autoconf.h>
#include <utils/util.h>

enum _riscv_mode_kobject_type {
    KOBJECT_FRAME,
    KOBJECT_MODE_NUM_TYPES,
};

typedef int kobject_t;

/*
 * Get the size (in bits) of the untyped memory required to
 * create an object of the given size.
 */
static inline seL4_Word
riscv_mode_kobject_get_size(kobject_t type, seL4_Word objectSize)
{
    switch (type) {
    default:
        ZF_LOGE("Uknown object type");
        return 0;
    }
}


static inline seL4_Word
riscv_mode_kobject_get_type(kobject_t type, seL4_Word objectSize)
{
    switch (type) {
    case KOBJECT_FRAME:
        switch (objectSize) {
        case seL4_HugePageBits:
            return seL4_RISCV_1G_Page;
        default:
            return -1;
        }
    default:
        /* Unknown object type. */
        ZF_LOGE("Unknown object type %d", type);
        return -1;
    }
}


#endif /* _SEL4_ARCH_KOBJECT_T_H_ */
