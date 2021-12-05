#include <stdio.h>
#include <stdlib.h>

#define SIZE 255

typedef struct node {
  int candy;
  struct node *left, *right;
} node;


typedef struct stack {
  node *values[SIZE];
  int head;
} stack;


node *push(stack *s, node *n){
  s->head += 1;
  s->values[s->top] = n;
  return s->values[s->top];
}


stack *new_stack(void){
  stack *s = malloc(sizeof(stack));
  if (s == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }

  s->head = -1;
  return s;
}

int main (void){
  node *n = malloc(sizeof(node));
  node *last = malloc(sizeof(node));
  n->candy = 10;
  n->left  = NULL;
  n->right = NULL;
  stack *s = malloc(sizeof(stack));
  s->top = -1;
  
  last = push(s, n); 
  printf("%d\n", last->candy); 
  return  0;
}
