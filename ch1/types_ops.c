#include <stdio.h>


int mystrlen(char s[]){
  int i;
  i =0;
  while (s[i] != '\0'){
    i++;
  }
  return i;
}

int main (void){
  char c;
  int i;
  long l;
  float f;
  double d;
  long double ld;

  long sizec = sizeof(c);
  long s = sizeof(i);
  long sizel = sizeof(l);
  long sizef = sizeof(f);
  long sized = sizeof(d);
  long sizeld = sizeof(ld);

  printf("char - No. bytes: %lu, No. bits: %lu\n", sizec, sizec * 8);
  printf("int - No. bytes: %lu, No. bits: %lu\n", s, s * 8);
  printf("long - No. bytes: %lu, No. bits: %lu\n", sizel, sizel * 8);
  printf("float - No. bytes: %lu No. bits: %lu\n", sizef, sizef * 8);
  printf("double - No. bytes: %lu No. bits: %lu\n", sized, sized * 8);
  printf("long double - No. bytes: %lu, No. bits: %lu\n", sizeld, sizeld * 8);
  
  char str[] = "matthew";
  printf("%d\n", mystrlen(str));
  printf("%d, %d", 'a','A');
  return 0;
}
