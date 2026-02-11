#include <stdio.h>
#include <stddef.h>

#define HEAP_SIZE (1024 * 1024 * 10)

static unsigned char heap[HEAP_SIZE];
static unsigned char *heap_ptr = heap;

int main(){
	printf("allocator starting...\n");
	printf("Heap starts at: %p\n",heap);
	printf("Heap ends at:   %p\n",heap + HEAP_SIZE);
	return 0;
}
