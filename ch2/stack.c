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
  s->values[s->head] = n;
  return s->values[s->head];
}


node *pop (stack *s){
  node *n = malloc(sizeof(node));
  if (n == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }
  n = s->values[s->head];
  printf(">%d ", s->head);
  s->head--;
  return n;
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


int is_empty(stack *s){
  if (s->head == -1) {
    return 1;
  }
  return 0;
}


node *new_house(int candy){
  node *n = malloc(sizeof(node));
  if (n == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }
  n->candy = candy;
  n->left = NULL;
  n->right = NULL;

  return n;
}

int main (void){
  node *n, *n1, *n2, *tmp;

  n = new_house(10);
  n1 = new_house(20);
  n2 = new_house(30);

  stack *s = new_stack();
  push(s, n); 
  push(s, n1); 
  push(s, n2); 

  while (!is_empty(s)){
    tmp = pop(s); 
    printf("Not empty, pop %d\n", tmp->candy);
  }  

  return  0;
}
