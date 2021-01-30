#include<stdio.h>

int main(){
  FILE *inp, *out;
  inp = fopen("TOHOP.INP","r");
  if (inp == NULL)
    printf("Error");
  out = fopen("TOHOP.OUT","w");
  int n, k;
  double com;
  while (feof(inp) == 0){
    fscanf(inp, "%d", &n);
    fscanf(inp, "%d", &k);
    printf("%d %d\n", n, k);
    com = 1;
    for (int i = 1; i <= k; i++)
      com = com * (n-i+1) /i;
    fprintf(out, "%.0lf\n", com);
  }
  fclose(inp);
  fclose(out);
  return 0;
  }
