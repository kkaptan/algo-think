#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000
#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

typedef struct snowflake_node {
  int snowflake[6];
  struct snowflake_node *next; 
} snowflake_node;


int identical_right (int s1[], int s2[], int k){
  int i, j;
  for ( i = 0; i < 6; i++) {
    j = (i + k) % 6;
    if (s1[i] != s2[j]) {
      return 0;
    }
  }
  return 1;
}

int identical_left(int s1[], int s2[], int k){
  int i, j;
  for ( i = 0; i < 6; i++) {
    j = (k - i) < 0 ? (k - i) + 6: ( k - i);
    if (s1[i] != s2[j]) {
      return 0;
    }
  }
  return 1;
}

int are_identical(int s1[], int s2[]){
  int k;
  for ( k = 0; k < 6; k++) {
    if (identical_right(s1, s2,k)){
      return 1;
    }
    if (identical_left(s1, s2, k)){
      return 1;
    }
  }
  return 0;
}

void identify_identical(snowflake_node *snowflakes[]){
  int i;
  snowflake_node *s1, *s2;

  for (i = 0; i < MAXSIZE; i++){
    //printf("%p\n", snowflakes[i]);
    s1 = snowflakes[i];
    while (s1 != NULL){
      s2 = s1->next;
      while (s2 != NULL){
        if (are_identical(s1->snowflake, s2->snowflake)){
          printf("Two identical snowflakes found!\n");
          return;
        }
        s2 = s2->next;
      }
      s1 = s1->next;
    }
  }
  printf("No identical snowflakes found!\n");
}

int code (int s[], int SIZE) {
    int i, code_sum;
    code_sum = 0;
    for (i = 0; i < 6; i++){
        code_sum += s[i];
    }
    return code_sum % SIZE;
}


int main_0 (void) {
  static snowflake_node *snowflakes[MAXSIZE] = {NULL};
  snowflake_node *si;
  int n, i, j, scode;
  scanf("%d", &n);
  for (i = 0; i < n; i++){
    si = malloc(sizeof(snowflake_node));
    if (si == NULL) {
      fprintf(stderr, "malloc error\n");
    }
    for (j = 0; j < 6; j++){
      scanf("%d", &si->snowflake[j]);
    }
    scode = code(si->snowflake, MAXSIZE); 
    si->next = snowflakes[scode];
    snowflakes[scode] = si;
    printf( "[%p] -> (%d, [%p])\n", si, scode, si->next);
    //printf("%p", snowflakes[scode]);
  }
  identify_identical(snowflakes);
  return 0;
}

unsigned long oaat (char *key, unsigned long len, unsigned long bits){

}


int main (void) {
  long snowflake[] = {1,2,3,4,5,6};
}
