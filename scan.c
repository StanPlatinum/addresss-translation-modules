#include "v2p.h"
  
#include <sys/mman.h>

#define ALLOC_FLAG (MAP_PRIVATE | MAP_ANONYMOUS)

int main()
{
	int n = 1;
	int end = 256;
	size_t buf_size = ALLOC_SIZE * n + 1;

	int i;
	for (i=1;i<=end; i++) {
		//Alloc memory by "malloc"
		//char *v = (char*)malloc(buf_size);
		
		//Alloc memory by "stack point"
        	//char p[100000]; char v=p;
		
		//Alloc memory by "mmap"
		//char *v = (char *)mmap(NULL, ALLOC_SIZE * n, PROT_READ | PROT_WRITE, ALLOC_FLAG, -1, 0);
		
		if(v == NULL)
        	{
                	printf("Failed to allocate memory for buffer\n");
                	exit(1);
        	}
		
		int j;
		for(j=1;j<=1000000;j++){
			printf("%x",v[j]);
		}
		
		//printf("v addr: %p\n", v);
		//uint64_t p = v2p(v);
        	//printf("p addr: %p\n", p);
		//printf("%p\n", p);
	}
}
