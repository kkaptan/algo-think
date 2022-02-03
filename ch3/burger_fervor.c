#include <stdio.h>
#include <stdlib.h>


int max (int v1, int v2){
  if (v1 > v2)
    return v1;
  else
    return v2;
}

int solve_t(int m, int n, int t){
  int first;
  int second;

  if (t == 0)
    return 0;

  if (t >= m)
    first = solve_t(m, n, t-m);
  else
    first = -1;
  
  if (t >= n)
    second = solve_t(m, n, t-n);
  else
    second = -1;

  if (first == -1 && second == -1)
    return -1;
  else
    return max(first, second) + 1;

}


void solve (int m, int n, int t){
  int result;
  int i;

  result = solve_t(m, n, t);

  if (result >= 0)
    printf("%d\n", result);

  else{
    i = t - 1;
    result = solve_t(m, n, i);
    while (result < 0){
      i--;
      result = solve_t(m, n, i);
    }
    printf("%d %d\n", result, t - i);
  }
}


int main (void){

  int m, n, t;
  scanf("%d %d %d", &m, &n, &t);
  solve(m, n, t);

  return EXIT_SUCCESS;
}
