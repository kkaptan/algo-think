#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int candy;
  struct node *left, *right;
} node;

typedef struct stack {
  node *values[SIZE];
  int head;
} stack;


node* new_house(int candy){
  node *house = malloc(sizeof(node));
  if (house == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }
  
  house->candy = candy;
  house->left = NULL;
  house->right = NULL;

  return house;
}


node *new_nonhouse(node *left, node *right){
  node *nonhouse = malloc(sizeof(node));
  if (nonhouse == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }

  nonhouse->left = left;
  nonhouse->right = right;

  return nonhouse;
}


stack *new_stack(void){
  stack *s = malloc(sizeof(stack));
  if (s == NULL){
    fprintf(stderr, "malloc error.");
  }

  s->head = -1;
  return s;
}


node *push(stack *s, node *n){
  s->head += 1;
  s->values[s->top] = n;
  return s->values[s->top];
}


node *pop(stack *s){
  node *ret = s->values[s->head];
  s->head--;
  return ret;
}

int main_0 (void){
  /*
   * node *four = malloc(sizeof(node));
   * four->candy = 4;
   * four->right = NULL;
   * four->left = NULL;
   *
   *  node *nine = malloc(sizeof(node));
   *  nine->candy = 9;
   *  nine->left = NULL;
   *  nine->right = NULL;
   *  node *four = new_house(4);
   * */

  node *four = new_house(4);
  node *nine = new_house(9);
  node *B = new_nonhouse(four, nine);
  node *fifteen = new_house(15);
  node *C = new_nonhouse(B, fifteen);

  return 0;
}


int main (void){
  return 0;
}


