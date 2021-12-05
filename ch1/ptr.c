#include <stdio.h>

int main (void) {
    int a;
    int *p;
    //*ptr stores a pointer to an address
    a = 10;
    p = &a;
    printf("[%p] %d\n", &a, a);
    printf("\n");
    printf("[%p] %p\n", &p, p);
    *p += 10;
    printf("%d\n",a);
    return 0;
}