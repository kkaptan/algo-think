#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM(a) (sizeof(a) / sizeof(a[0]))


int shortest_line_idx(int x[], int n) {
    int i;
    int j = 0;
    for (i = 1; i < n; i++) {
        if (x[i] < x[j]){
            j = i;
        }
    }
    return j;
}

void solve(int x[], int n, int m){
    int j;
    for (int i = 0; i < m; i++){
        j = shortest_line_idx(x, n);
        printf("x[%d] -> %d\n",j, x[j]);
        x[j]++;
    }
}

int main (void) {
    int lines[10] = {8,10,3,4,2,4,1,4,1,4};
    solve(lines, 10, 15);
    return 0;
}


