/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#ifndef _VKA_ARCH_OBJECT_H__
#define _VKA_ARCH_OBJECT_H__

#include <vka/vka.h>
#include <vka/kobject_t.h>
#include <utils/util.h>
#include <vka/sel4_arch/object.h>

static inline int vka_alloc_io_page_table(vka_t *vka, vka_object_t *result)
{
    return 0; /* Not supported */ 
}

LEAKY(io_page_table)

static inline unsigned long
vka_arch_get_object_size(seL4_Word objectType)
{
    switch (objectType) {
    case seL4_RISCV_4K_Page:
        return seL4_PageBits;
    case seL4_RISCV_2M_Page:
        return seL4_LargePageBits;
    case seL4_RISCV_1G_Page:
        return seL4_HugePageBits;
    case seL4_RISCV_PageTableObject:
    case seL4_RISCV_LVL2PageTableObject:
        return seL4_PageTableBits;
    case seL4_RISCV_PageDirectoryObject:
        return seL4_PageDirBits;

    default:
        return vka_riscv_mode_get_object_size(objectType);
    }
}

#endif /* _VKA_ARCH_OBJECT_H__ */
