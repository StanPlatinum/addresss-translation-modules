#include "v2p.h"

#include <sys/mman.h>

#define ALLOC_FLAG (MAP_PRIVATE | MAP_ANONYMOUS)

int main()
{
	int n = 1;
	char *v;
	printf("test begins\n");
        ASSERT((v = (char *)mmap(0, ALLOC_SIZE * n, PROT_READ | PROT_WRITE, ALLOC_FLAG, -1, 0)) != MAP_FAILED);
	//Weijie: must add the following line
	memset(v, 0, ALLOC_SIZE * n);
	printf("v addr: %p\n", v);

	uint64_t p = v2p(v);
	printf("p addr: %p\n", p);
}
