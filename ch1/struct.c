#include <stdio.h>

#define N 100

typedef struct word_node {
  char c;
  int i;
} word_node;


void fill_arr(char arr[], int n){
  int i, code;
  for ( i = 0; i < n; i++){
    code = (i  % 58) + 65;
    arr[i] = code;
  }
}


int main (void){

  word_node w = {'1',10};

  char *ptr;
  char cs[N];
  int i;

  fill_arr(cs, N);

  //p->i = 100;
  printf("%lu\n", sizeof(w));
  printf("%d\n", w.i);
  printf("%c\n", w.c);

  return 0;
}
