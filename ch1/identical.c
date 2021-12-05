#include <stdio.h>

#define MAXSIZE 

void identical_0(int x[], int n){
    int i,j;
    for ( i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (x[i] == x[j]){
                printf("Found %d.\n", x[i]);
                return;
            }
        }
    }
    printf("Matching pair not found.\n");
}

int identical_right (int s1[], int s2[], int k){
    int i, o;
    for ( i = 0; i < 6; i++){
        o = (i + k) % 6;
        if (s1[i] != s2[o]){
            return 0;
        }
    }
    return 1;
}

int identical_left (int s1[], int s2[], int k) {
    int i, o;
    for (i = 0; i < 6; i ++){
        o = (k - i) < 0 ? (k - i) + 6 : (k - i);
        if (s1[i] != s2[o]){
            return 0;
        }
    }
    return -1;

}


int are_identical (int x1[], int x2[]) {
    int k;
    for (k = 0; k < 6; k++){
        if (identical_right(x1,x2,k)) {
            return 1;
        }
        if (identical_left(x1,x2,k)) {
            return 1;
        }
    }
    return 0;
}

void identical(int x[][6], int n){
    int i, j;
    for ( i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (are_identical(x[i], x[j])){
                printf("Found.\n");
                return;
            }
        }
    }
    printf("Matching pair not found.\n");
}

int code (int s[], int SIZE) {
    int i, code_sum;
    code_sum = 0;
    for (i = 0; i < 6; i++){
        code_sum += s[i];
    }
    return code_sum % SIZE;
}



int main(){
    int x1[6] = {1,2,3,4,5,6};
    int x2[6] = {4,5,6,1,2,3};
    int xs[5][6] = {
        {1,2,3,4,5,6},
        {4,5,6,1,2,31},
        {1,2,3,14,5,6},
        {4,5,6,12,2,31},
        {3,4,5,6,1,2}
    };

    int i;
    for (i = 0; i < 6; i++){
        printf("%d\n", code(xs[i], MAXSIZE));
    }
    identical(xs, 5);
    return 0;
}