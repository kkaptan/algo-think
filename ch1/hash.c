#include <stdio.h>
#include <stdlib.h>

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

unsigned long oaat (char *key, unsigned long len, unsigned long bits){
  unsigned long hash, i;
  printf("len - %lu\n", len);
  for (hash = 0, i = 0; i < len; i++){
    hash += key[i];
    hash = hash + (hash << 10);
    hash = hash ^ (hash >> 6);
  }
  hash = hash + (hash << 3);
  hash = hash ^ (hash >> 11);
  hash = hash + (hash << 15);
  return hash & hashmask(bits);
}

int main (void){
  unsigned long hashcode;
  char w[] = "abcde";
  printf("[%p] -> %c\n", w, *w);
  hashcode = oaat(w, sizeof(w), 17);
  printf("%lu", hashcode);
  return 0;
}
