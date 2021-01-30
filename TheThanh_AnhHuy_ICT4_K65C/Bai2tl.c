#include <stdio.h>
#include <stdlib.h>

void swap(float *a, float *b);
int partition(float arr[], float arc[], int low, int high);
void qsrt(float arr[], float arc[], int low, int high);

int main(){

  int w, n;
  FILE *inp, *out;

  inp = fopen("BAG.INP", "r");
  if (inp == NULL){
    printf("Error! opening file\n");
    exit(1);
  }

  fscanf(inp, "%d", &n);           //Bat day lay du lieu tu input
  fscanf(inp, "%d", &w);

  int g[n], v[n], i = 0;
  char ni[n];
  float den[n], cou[n];            //den la chuoi gia tri trung binh cua tung mon do, cou danh dau vi tri ban dau cua tung den

  for (i = 0; i < n; i++){
    fscanf(inp, "%d %d %c", &g[i], &v[i], &ni[i]);

    cou[i] = i;
    den[i] = (float)v[i] / g[i];
  }

  qsrt(den, cou, 0, n-1);         //sap xep den theo thu tu giam dan

  int amount[n], weigh = 0, value = 0, counter;

  for (i = 0; i < n; i++){                                //bat dau lay do vat
    amount[(int)cou[i]] = (w - weigh) / g[(int)cou[i]];
    weigh = weigh + g[(int)cou[i]] * amount[(int)cou[i]];
    value = value + v[(int)cou[i]] * amount[(int)cou[i]];
  }

  printf("%d\n", value);
  for (i = 0; i < n; i++)
    if (amount[i] > 0)
      printf("%c %d\n", ni[i], amount[i]);

  fclose(inp);
  return 0;
  }

void swap(float *a, float *b){
  float c;
  c = *a;
  *a = *b;
  *b = c;
}

int partition(float arr[], float arc[], int low, int high){

  float pivot;
  int i, j;

  pivot = arr[low];
  i = low;

  for (j = low + 1; j <= high; j++){
    if (arr[j] > pivot){
      i++;
      swap(&arr[i], &arr[j]);
      swap(&arc[i], &arc[j]);
    }
  }

  swap(&arr[i], &arr[low]);
  swap(&arc[i], &arc[low]);

  return (i);
}

void qsrt(float arr[], float arc[], int low, int high){

  if (low < high){
    int i = partition(arr, arc, low, high);

    qsrt(arr, arc, low, i - 1);
    qsrt(arr, arc, i + 1, high);
  }
}
