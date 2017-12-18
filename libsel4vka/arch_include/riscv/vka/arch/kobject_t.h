/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef _ARCH_KOBJECT_T_H_
#define _ARCH_KOBJECT_T_H_

#include <sel4/types.h>
#include <assert.h>
#include <autoconf.h>
#include <utils/util.h>
#include <vka/sel4_arch/kobject_t.h>

enum _riscv_kobject_type {
    KOBJECT_IO_PAGETABLE = KOBJECT_MODE_NUM_TYPES,
    KOBJECT_PAGE_DIRECTORY,
    KOBJECT_PAGE_TABLE,
    KOBJECT_LVL2_PAGE_TABLE,
    KOBJECT_ARCH_NUM_TYPES,
};

/*
 * Get the size (in bits) of the untyped memory required to
 * create an object of the given size.
 */
static inline seL4_Word
arch_kobject_get_size(kobject_t type, seL4_Word objectSize)
{
    switch (type) {
    case KOBJECT_FRAME:
        switch (objectSize) {
        case seL4_PageBits:
        case seL4_LargePageBits:
            return objectSize;
        }
        /* If frame size was unknown fall through to default case as it
         * might be a mode specific frame size */
    default:
        return riscv_mode_kobject_get_size(type, objectSize);
    }
}


static inline seL4_Word
arch_kobject_get_type(int type, seL4_Word objectSize)
{
    switch (type) {
    case KOBJECT_PAGE_DIRECTORY:
        return seL4_RISCV_PageDirectoryObject;
    case KOBJECT_PAGE_TABLE:
        return seL4_RISCV_PageTableObject;
    case KOBJECT_LVL2_PAGE_TABLE:
        return seL4_RISCV_LVL2PageTableObject;
    case KOBJECT_FRAME:
        switch (objectSize) {
        case seL4_PageBits:
            return seL4_RISCV_4K_Page;
        case seL4_LargePageBits:
            return seL4_RISCV_2M_Page;
        default:
            return riscv_mode_kobject_get_type(type, objectSize);
        }
    default:
        return riscv_mode_kobject_get_type(type, objectSize);
    }
}


#endif /* _ARCH_KOBJECT_T_H_ */
