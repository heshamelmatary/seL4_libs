/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2018 Hesham Almatary <Hesham.Almatary@cl.cam.ac.uk>
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory (Department of Computer Science and
 * Technology) under DARPA contract HR0011-18-C-0016 ("ECATS"), as part of th
 * DARPA SSITH research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include "events.h"
#include <sel4bench/types.h>

#define PMU_WRITE(reg, v)                      \
    do {                                       \
    }while(0)

#define PMUCYCLE   "cycle"
#define PMU_READ(reg, v) asm volatile("csrr %0, " reg :  "=r"(v))

#define CCNT_FORMAT "%"PRIu64
typedef uint64_t ccnt_t;

#define SEL4BENCH_READ_CCNT(var) do { \
 asm volatile("csrr %0, cycle":  "=r"(var)); \
 } while(0)

void seL4_DebugRun(void (* userfn) (void *), void* userarg);

static void sel4bench_init()
{
}

static ccnt_t sel4bench_get_cycle_count()
{
    uint64_t time;
    asm volatile("csrr %0, cycle" :  "=r"(time));
    return time;
}

static void sel4bench_start_counters(counter_bitfield_t mask)
{
}

static void sel4bench_stop_counters(counter_bitfield_t mask)
{
}

static void sel4bench_destroy()
{
    //stop all performance counters
    sel4bench_stop_counters(-1);
}

static void sel4bench_reset_counters(void)
{
}
