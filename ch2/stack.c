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

node *new_nonhouse(node *left, node *right){
  node *n = malloc(sizeof(node));
  if (n == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }

  n->left = left;
  n->right = right;
  return n;
}

int main_0 (void) {
  node *n, *n1, *n2, *tmp;

  n = new_house(10);
  n1 = new_house(20);
  n2 = new_house(30);

  stack *s = new_stack();
  push(s, n); 
  push(s, n1); push(s, n2); 

  while (!is_empty(s)){
    tmp = pop(s); 
    printf("Not empty, pop %d\n", tmp->candy);
  }  

  return  0;
}

node *make_tree(void){
  node *n72 = new_house(72);
  node *n3 = new_house(3);
  node *A = new_nonhouse(n72, n3);
  node *n4 = new_house(4);
  node *n9 = new_house(9);
  node *B = new_nonhouse(n4, n9);
  node *n15 = new_house(15);
  node *C = new_nonhouse(B, n15); 
  node *n8 = new_house(8);
  node *D = new_nonhouse(C, n8);
  node *n6 = new_house(6);
  node *E = new_nonhouse(n6, D);
  node *F = new_nonhouse(A, E);
  node *n7 = new_house(7);
  node *n41 = new_house(41);
  node *G = new_nonhouse(n7, n41);
  node *H = new_nonhouse(F, G);
  return H;
}

int tree_candy (node *tree){
  int total = 0;
  stack *s = new_stack();
  while (tree != NULL){

    if (tree->left && tree->right){
      push(s, tree->left);
      tree = tree->right;
    }

    else {
     total = total + tree->candy; 

     if (!is_empty(s)){
       tree = pop(s);
     }
     else {
       tree = NULL;
     }
    } 
  }
  return total;
}

int main (void){
  node *root = make_tree(); 
  int total_candy;
  total_candy = tree_candy(root);
  printf("total candy: %d\n", total_candy);
  return 0;
}
