#include "v2p.h"
  
#include <sys/mman.h>

#define ALLOC_FLAG (MAP_PRIVATE | MAP_ANONYMOUS)

int main()
{
        int n = 1;
        printf("filling begins\n");

        //char *v;
	//ASSERT((v = (char *)mmap(0, ALLOC_SIZE * n, PROT_READ | PROT_WRITE, ALLOC_FLAG, -1, 0)) != MAP_FAILED);
        //memset(v1, '9', ALLOC_SIZE * n);

        // Allocate some memory to manipulate
	int i;
	int end = 352 * 256;
	for (i=1;i<=end;i++){
        	size_t buf_size = ALLOC_SIZE * n + 1;
        	void *v = malloc(buf_size);
        	if(v == NULL)
        	{
                	printf("Failed to allocate memory for buffer\n");
                	exit(1);
        	}

        	/* Lock the page in memory
        	if(mlock(v, buf_size) == -1)
        	{
                	printf("Failed to lock page in memory");
                	exit(1);
        	}*/

        	// Add some data to the memory
        	memset(v, '9', buf_size);
		printf("%d\n",i);

		//printf("v addr: %p\n", v);
		//uint64_t p = v2p(v);
        	//printf("p addr: %p\n", p);
	}

}
