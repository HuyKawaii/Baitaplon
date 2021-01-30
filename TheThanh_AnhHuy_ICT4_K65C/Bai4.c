#include <stdio.h>
#include <stdlib.h>

void deal(int card[13][4]);
void show(int row, int col);
void showquad(int card[13][4]);

int main(){
  int card[13][4];
  int row, col;

  deal(card);
  printf("\n");

  showquad(card);

  return 0;
}

void deal(int card[13][4]){
  int i, j, row, col, player;

  for (i = 0; i < 13; i++)
    for (j = 0; j < 4; j++)
      card[i][j] = 0;
  for (player = 1; player <= 4; player ++){
    printf("Player%d: ", player);
    for (i = 0; i < 13; i++){
      j = rand() % 52;
      row = j/4;
      col = j%4;
      while (card[row][col] != 0){
        if (col < 3)
          col++;
          else if(row < 12){
            col = 0;
            row++;
          }
          else{
            col = 0;
            row = 0;
          }
      }
      card[row][col] = player;
      show(row, col);
    }
  printf("\n");
  }
}

void show(int row, int col){
  if (row == 0){
    printf("A");
  }
    else if (row == 10){
      printf("J");
    }
      else if (row == 11){
        printf("Q");
      }
        else if (row == 12){
          printf("K");
        }
          else{
            printf("%d", row+1);
          }
  if (col == 0){
    printf("H  ");
  }
    else if (col == 1){
      printf("D  ");
    }
      else if (col == 2){
        printf("S  ");
      }
        else{
          printf("C  ");
        }
  }

  void showquad(int card[13][4]){
    for (int row = 0; row < 13; row++){
      if ((card[row][0] == card[row][1])&& (card[row][1] == card[row][2]) && (card[row][2] == card[row][3])){
      printf("Player %d has quads ", card[row][0]);
      if (row == 0){
      printf("A");
      }
      else if (row == 10){
        ("J");
      }
        else if (row == 11){
          printf("Q");
        }
          else if (row == 12){
            printf("K");
          }
            else{
              printf("%d", row+1);
            }
      printf("\n");
      }
    }
  }
