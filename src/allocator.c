#include <stdio.h>
#include <stddef.h>

#define HEAP_SIZE (1024 * 1024 * 10)

static unsigned char heap[HEAP_SIZE];
static unsigned char *heap_ptr = heap;

void* vyom_malloc(size_t size) {

    // align to 8 bytes
    size = (size + 7) & ~7;

    // check capacity
    if (heap_ptr + size > heap + HEAP_SIZE) {
        return NULL;
    }

    void* ptr = heap_ptr;  // save current position
    heap_ptr += size;      // move forward

    return ptr;
}

int main(){

    printf("allocator starting...\n");

    int *a = vyom_malloc(sizeof(int));
    double *b = vyom_malloc(sizeof(double));
    char *c = vyom_malloc(1);

    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("c: %p\n", c);

    return 0;
}
