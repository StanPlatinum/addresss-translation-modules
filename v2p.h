#ifndef _V2P_H_
#define _V2P_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define GET_BIT(X,Y) (X & (1ul<<Y)) >> Y
#define PFN_MASK ((1ul << 55) - 1)
#define PFN_PRESENT_FLAG (1ul << 63)

#define page_map_file  "/proc/self/pagemap"
#define page_flag_file "/proc/kpageflags"
#define mem_file "/dev/md_device"
#define PAGE_SIZE 0x1000ul      

#define ASSERT(line) if (!(line)) { fprintf(stderr, "ASSERT error at line %d: " #line, __LINE__); perror(" "); return -1; }

static int npages = 0;

static int fd=-1, flag_fd=-1, mem_fd=-1; 


uint64_t v2p(void *v) {
    uint64_t vir_page_idx = (uint64_t)v / PAGE_SIZE;      // 虚拟页号
    uint64_t page_offset = (uint64_t)v % PAGE_SIZE;       // 页内偏移
    uint64_t pfn_item_offset = vir_page_idx*sizeof(uint64_t);   // pagemap文件中对应虚拟页号的偏移
    
    int dummy = *(int *)v;  // visit the addr, keep it in memory
    // 读取pfn
    uint64_t pfn_item, pfn;
    ASSERT( lseek(fd, pfn_item_offset, SEEK_SET) != -1 );
    ASSERT( read(fd, &pfn_item, sizeof(uint64_t)) == sizeof(uint64_t) );
   // ASSERT( pfn_item & PFN_PRESENT_FLAG );  // 确保页面存在
    pfn = pfn_item & PFN_MASK;              // 取低55位为物理页号
    
    uint64_t page_flags;
    ASSERT( lseek(flag_fd, pfn*sizeof(uint64_t), SEEK_SET) != -1);
    ASSERT( read(flag_fd, &page_flags, sizeof(uint64_t)) == sizeof(uint64_t) );

   // printf("here vir=0x%lx, item=0x%lx, pfn=0x%lx, offset=%ld, flag=0x%lx\n", v, pfn_item, pfn, page_offset, page_flags);

    return pfn * PAGE_SIZE + page_offset;
}

#endif
