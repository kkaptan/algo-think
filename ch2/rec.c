#include <stdio.h>
#include <stdlib.h>

#define SIZE 255
#define TEST_CASES 5


typedef struct node {
  int candy;
  struct node *left, *right;
} node;


node *new_house(int candy){
  node *n = malloc(sizeof(node));

  if (n == NULL){
    fprintf(stderr,"malloc error.");
    exit(1);
  }

  n->left = NULL;
  n->right = NULL;
  n->candy = candy;

  return n;
}

node *new_nonhouse (node *left, node *right){
  node *n = malloc(sizeof(node));
  if (n == NULL){
    fprintf(stderr, "malloc error.");
  }
  n->left = left;
  n->right = right;

  return n;
}

int tree_candy (node *tree){
  if (!tree->left && !tree->right){
    return tree->candy;
  }
  return tree_candy(tree->left) + tree_candy(tree->right);
}

int tree_leaves (node *tree){
  if (!tree->left && !tree->right){
    return 1;
  }
  return tree_leaves(tree->left) + tree_leaves(tree->right);
}

int tree_nodes (node *tree){
  if (!tree->left && !tree->right){
    return 1;
  }
  return 1 + tree_nodes(tree->left) + tree_nodes(tree->right);
}

int tree_streets (node *tree){
  if (!tree->left && !tree->right){
    return 0;
  }
  return tree_streets(tree->left) + tree_streets(tree->right) + 4;
}

int tree_height(node *tree){
  if (!tree->right && !tree->left){
    return 0;
  }
  return 1 + (tree_height(tree->right) > tree_height(tree->left) ?
    tree_height(tree->right) : tree_height(tree->left));
}

node *read_tree_helper (char *line, int *pos){
  node *tree;
  tree = malloc(sizeof(node));
  if (tree == NULL){
    fprintf(stderr, "malloc error.");
    exit(1);
  }
  if (line[*pos] == '('){
    (*pos)++;
    tree->left = read_tree_helper(line, pos); 
    (*pos)++;
    tree->right = read_tree_helper(line, pos);
    (*pos)++;
    return tree;
  }
  else {
    tree->left = NULL;
    tree->right = NULL;
    tree->candy = line[*pos] - '0';
    (*pos)++;
    if (line[*pos] != ')' && line[*pos] != ' ' && line[*pos] != '\0'){
      tree->candy = tree->candy * 10 + line[*pos] - '0';
      (*pos)++;
    }
    return tree;
  }
}

void tree_solve (node *tree){
  int total_candy;
  int num_streets;
  total_candy = tree_candy(tree);
  num_streets = tree_streets(tree) - tree_height(tree);
  printf("%d %d\n", total_candy, num_streets);
}

node *read_tree(char *line){
  int pos = 0;
  return read_tree_helper(line, &pos);
}

int main () {
  node *n;
  int i;
  char line[SIZE + 1];

  for (i = 0; i < TEST_CASES; i++){
    gets(line);
    n = read_tree(line);
    tree_solve(n);
  }

}
