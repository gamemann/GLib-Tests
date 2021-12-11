#pragma once

#include <linux/types.h>

#define MAX_ENTRIES_DEFAULT 5

struct key
{
    __u32 field32_1;
    __u16 field16_1;
    __u32 field32_2;
    __u16 field16_2;
};

struct val
{
    __u32 field32_1;
    __u32 field32_2;
    __u32 field32_3;
    __u32 field32_4;
    __u64 field64_1;
    __u64 field64_2;
};