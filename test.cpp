#include "iostream"

#include "v2p.h"

using namespace std;

#define ALLOC_SIZE 4096
#define ALLOC_FLAG (MAP_PRIVATE | MAP_ANONYMOUS)

int main()
{
	int n = 1;
	char *v;
	//char *v = "test";
	cout << "test begins" << endl;
        ASSERT((v = (char *)mmap(0, ALLOC_SIZE * n, PROT_READ | PROT_WRITE, ALLOC_FLAG, -1, 0)) != MAP_FAILED);
	//memset(v, 0, ALLOC_SIZE * n);
	cout << "v addr: " << &v << endl;

	uint64_t p = v2p(v);
	cout << "p addr: " << &p << endl;
}
