#include "v2p.h"

int fd_pagemap = -1;

// note: before calling v2p, v should be in memory
uint64_t v2p(void *v) {
    if (getuid() != 0) return -1; // returns when not root

    if (fd_pagemap < 0) ASSERT((fd_pagemap = open("/proc/self/pagemap", O_RDONLY)) > 0);
    uint64_t vir_page_idx = (uint64_t)v / PAGE_SIZE;      // 虚拟页号
    uint64_t page_offset = (uint64_t)v % PAGE_SIZE;       // 页内偏移
    uint64_t pfn_item_offset = vir_page_idx*sizeof(uint64_t);   // pagemap文件中对应虚拟页号的偏移

    // 读取pfn
    uint64_t pfn_item, pfn;
    ASSERT( lseek(fd_pagemap, pfn_item_offset, SEEK_SET) != -1 );
    ASSERT( read(fd_pagemap, &pfn_item, sizeof(uint64_t)) == sizeof(uint64_t) );
    pfn = pfn_item & PFN_MASK;              // 取低55位为物理页号

    return pfn * PAGE_SIZE + page_offset;
}
