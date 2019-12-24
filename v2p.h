#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"

//---------------------------------
// page select
#define PAGE_SIZE 0x1000
#define PAGE_MASK 0xfff
#define PAGE_SHIFT 12
#define PAGE_FLAG 0
#define HUGE_SIZE 0x200000ull
#define HUGE_MASK 0x1fffffull
#define HUGE_SHIFT 21
#define HUGE_FLAG 0x40000
#define PFN_MASK ((1ull << 55) - 1)
#define ALLOC_SIZE PAGE_SIZE

//---------------------------------
// v2p with pagemap
#ifndef ASSERT
    #define ASSERT(line) if (!(line)) { fprintf(stderr, "ASSERT error: " #line "\n%s\n", strerror(errno)); exit(-1); }
#endif

extern int fd_pagemap;

uint64_t v2p(void *v);

//---------------------------------
