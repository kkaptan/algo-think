#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 10

typedef struct node {
  char *name;
  struct node **children;
  int num_children;
} node;


node *find_node (node *n[], int num_nodes, char *name){
  int i;
  for ( i = 0; i < num_nodes; i++){

    if (strcmp(n[i]->name, name) == 0){
      //printf("%s %s\n", n[i]->name, name);
      return n[i];
    }
  } return NULL;
}

void *malloc_safe (int size){
  char *ptr = malloc(size);
  if (ptr == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }
  return ptr;
}

node *new_node(char *name){
  node *n = malloc_safe(sizeof(node));
  n->name = name;
  n->num_children = 0;
  return n;
}

int read_tree(node *nodes[], int num_lines){
  node *parent_node, *child_node;
  int k, i, j, num_children;
  int num_nodes = 0;
  char *parent_name, *child_name;

  for (i = 0; i < num_lines; i++){
    parent_name = malloc_safe(MAX_LINE + 1);
    scanf("%s", parent_name);
    scanf("%d", &num_children);

    parent_node = find_node(nodes, num_nodes, parent_name);
    if (parent_node == NULL){
      parent_node = new_node(parent_name);
      nodes[num_nodes] = parent_node;
      num_nodes++;
    }
    else
      free(parent_name);

    parent_node->children = malloc_safe(num_children * sizeof(node)); 
    parent_node->num_children = num_children; 

    for (j = 0; j < num_children; j++){
      child_name = malloc_safe(MAX_LINE + 1);
      scanf("%s", child_name);
      child_node = find_node(nodes, num_nodes, child_name);
      if (child_node == NULL){
        child_node = new_node(child_name);
        nodes[num_nodes] = child_node;
        num_nodes++;
      }
      else
        free (child_name);

      parent_node->children[j] = child_node;
    }


  }

  return num_nodes;
}


int main (void) {
  int n, d, num_nodes;
  int i, k;
  node *nodes[255];
  scanf("%d %d", &n, &d);
  num_nodes = read_tree(nodes, n);

  for (k=0; k < num_nodes; k++){
      printf("%d %s\n", k,  nodes[k]->name);
  }

  printf("%d\n", num_nodes);
  return 0;
}
