#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(){
    FILE *f, *o;
    student std;
    int n;
    char name[20];

    if ((f = fopen("SV2021.dat","ab+")) == NULL){
        printf("Error opening file");
        exit(1);
    }

    o = fopen("output.txt", "w");
    fclose(o);

    printf("Students management program\n");
    printf("Press:\n");
    printf("1   to view full list\n");
    printf("2   to import record\n");
    printf("3   to find record by name\n");
    printf("4   to exit program\n\n\n");

    printf("Enter a number from 1 to 4: ");
    scanf("%d", &n);

    while(n != 4){
      if(n == 1){

        fseek(f,0,SEEK_SET);
        while(fread(&std,sizeof(student),1,f) != NULL)
          printf("Name: %20s  GPA: %f\n", std.name, std.gpa);
      }

      if(n == 2){

        getchar();
        printf("Name: ");
        gets(name);
        fseek(f,0,SEEK_SET);
        while(fread(&std,sizeof(student),1,f) != NULL){
          if (strcmp(name, std.name) == 0){
            printf("Record already existed\n");
            break;
          }
        }

        if (feof(f)){
          printf("GPA: ");
          scanf("%f", &std.gpa);

          fwrite(&std,sizeof(student),1,f);
          printf("Record added sucessfully\n");
        }
      }

      if (n == 3){

        if ((o = fopen("output.txt","a")) == NULL){
          printf("Error opening file\n");
          continue;
        }

        printf("Enter name: ");
        getchar();
        gets(name);

        fseek(f,0,SEEK_SET);
        while(fread(&std,sizeof(student),1,f) != NULL){
          if (strcmp(name, std.name) == 0){
            printf("Name: %20s  GPA: %f\n", std.name, std.gpa);
            fprintf(o,"%20s  %f\n", std.name, std.gpa);
            break;
          }
        }

        if (feof(f) != 0)
          printf("No record found");

        fclose(o);
      }

      if((n != 1) && (n != 2) && (n != 3)){
        printf("Irrelevant syntax");
      }

      printf("\n\n\nEnter a number from 1 to 4: ");
      scanf("%d", &n);
    }

    if (n == '4')
      return 0;

}
