#include <stdio.h>

/*
 *Bitwise
 *(un)signed char, short, int, long, 
 * */

int main (void){

  int a = 4; //100
  int b = 6; //110
  int n = a & b; //100
  int m = a | b;
  int o = a ^ b;
  int p = a << 2; //00100 << 2 -> 10000 (a*4)
  printf("Bitwise & - used as a mask\n100\n110\n---\n100 (%d)\n", n); 
  printf("Bitwise | - used to turn on bits\n100\n110\n---\n110 (%d)\n", m);
  printf("Bitwise ^ - XOR, switches ON the differing bits\n100\n110\n---\n010 (%d)\n", o);
  printf("Bitwise << OP - shifts int by OP bits to the left = a * (OP*2)\n00100\n---\n10000 (%d)\n", p);
  return 0;
}
