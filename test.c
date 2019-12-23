#include "iostream"

#include "v2p.h"

int main()
{
	char *v;
        ASSERT((v = (char *)mmap(0, ALLOC_SIZE * n, PROT_READ | PROT_WRITE, ALLOC_FLAG, -1, 0)) != MAP_FAILED);
	cout << “v: ” << v << endl;
	uint64_t p = v2p(v);
	cout << “p: ” << p << endl;
}
