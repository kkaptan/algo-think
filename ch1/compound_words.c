#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LENGTH 16
#define NUM_BITS 18

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)


unsigned long oaat (char *key, unsigned long len, unsigned long bits){
  unsigned long hash, i;
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

char *read_line(size){
  int len;
  char ch;
  char *str;

  str = malloc(size);
  len = 0;
  if (str == NULL){
    fprintf(stderr, "malloc error.\n");
  }
  while ((ch = getchar()) != EOF && ch != '\n'){
    str[len++] = ch;
    if (len == size){
      size = size * 2;
      str = realloc(str, size);
      if (str == NULL){
        fprintf(stderr, "realloc error.\n");
      }
    }
  }
  str[len] = '\0';
  return str;
}

void print_word (char *w){
  /*
   *print_word = prints a string
   */
  while (*w != '\0') {
    //printf("[%p] -> '%c' //size('%c') = %lu\n",w,*w,*w, sizeof(*w));
    printf("%c",*w);
    w += sizeof(*w);
  }
  printf("\n");
}

int m_strlen(const char *w){
  /*
   *My strlen fun, returns number of chars in string
   */
  unsigned i = 0;
  while (*w != '\0'){
    i++;
    w = w + sizeof(*w);
  }
  return i;
}

typedef struct word_node {
  char **word;
  struct word_node *next;
} word_node;

int in_hash_table(word_node *hash_table[], char *find, unsigned find_len){
  unsigned word_code;
  word_node *wordptr;

  word_code = oaat(find, find_len, NUM_BITS);
  wordptr = hash_table[word_code];

  while (wordptr){
    if ((m_strlen(*(wordptr->word)) == find_len) && 
       (strncmp(*(wordptr->word), find, find_len)==0)) {
      return 1;
    }
    wordptr = wordptr->next;
  }
  //printf("[%u] = %p", word_code, wordptr);
  return 0;
} 

void print_array(char *words[], unsigned tot){
  int i;
  for (i = 0; i < tot; i++){
    printf("[%p]->",words[i]);
    print_word(words[i]);
  }
  printf("%d", tot);
}

void print_split(char *word, int j){
  int i = 0;
  while (word[i] != '\0'){
    printf("%c", word[i]);
    if (i==j) {
      printf("|");
    }
    i++;
  }
  printf("\n");
}

int identify_compound_words(char *words[], word_node *hash_table[], int total_words){
  int i, j, word_length;
  char *word;
  for (i = 0; i < total_words; i++){
    word = words[i];
    word_length = m_strlen(word);
    for (j = 1; j < word_length; j++){
      if ((in_hash_table(hash_table, words[i], j)) && 
          (in_hash_table(hash_table, &words[i][j], word_length - j))){
        //printf("[%d] %s\n", j, words[i]);
        print_split(words[i], j);
        break;
      }
    }
  }
  return 0;
}

int main (void) {
  static char *words[1 << NUM_BITS] = {NULL};
  static word_node *hash_table[1 << NUM_BITS] = {NULL};
  int total = 0;

  unsigned long length, hashcode;
  char *word;
  word_node *wordptr;

  word = read_line(WORD_LENGTH);
  while (*word){
    words[total] = word;
    wordptr = malloc(sizeof(word_node));
    if (wordptr == NULL){
      fprintf(stderr, "malloc error.\n");
      exit(1);
    }
    length = m_strlen(word);
    hashcode = oaat(word, length, NUM_BITS);
    wordptr->word = &words[total];
    wordptr->next = hash_table[hashcode];
    hash_table[hashcode] = wordptr;
    word = read_line(WORD_LENGTH);
    total++;
  }

  //print_array(words, total);
  identify_compound_words(words, hash_table, total);
  //print_word(w);
  //hashcode = oaat(w, sizeof(w), 17);
  //printf("%lu", hashcode);
  return 0;
}
