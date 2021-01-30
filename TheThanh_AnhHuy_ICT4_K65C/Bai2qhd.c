#include <stdio.h>
#include <stdlib.h>
int maximum(int a, int b);

int main(){

  int w, n, N, W, k;
  FILE *inp, *out;

  inp = fopen("BAG.INP", "r");
  if (inp == NULL){
    printf("Error! opening file\n");
    exit(1);
  }

  fscanf(inp, "%d", &N);
  fscanf(inp, "%d", &W);

  int g[N+1], v[N+1];
  char ni[N+1];

  for (n = 1; n <= N; n++){
    fscanf(inp, "%d %d %c", &g[n], &v[n], &ni[n]);
  }

  int s[N+1][W+1], x[N+1][W+1];

  for(n = 1; n <= N; n++){
    s[n][0] = 0;
    x[n][0] = 0;
  }

  for(w = 1; w <= W; w++){
    x[1][w] = w / g[1];
    s[1][w] = x[1][w] * v[1];
  }

  for(n = 2; n <= N; n++){
    for(w = 1; w <= W;w++){
      k = w / g[n];
      int max = 0;
      for (int i = 0; i <= k; i++){
        s[n][w] = s[n-1][w - i*g[n]] + i*v[n];
        if(maximum(max, s[n][w]) == 0){
          max = s[n][w];
          x[n][w] = i;
        }
      }
      s[n][w] = max;
    }
  }

  int counter[N + 1];
  n = N;
  w = W;

  printf("%d\n", s[n][w]);

  while(n > 0){
    counter[n] = x[n][w];
    w = w - counter[n] * g[n];
    n--;
  }

  for(n = 1; n <= N; n++){
    if(counter[n] != 0){
      printf("%d", counter[n]);
      printf(" %c\n", ni[n]);
    }
  }

  return 0;
}

int maximum(int a, int b){
  if (a > b)
    return 1;
    else
      return 0;
  }
