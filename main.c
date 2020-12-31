#include <stdio.h>
#include <stdlib.h>

typedef struct Data{ // Creating a student struct
    char name[50];
    float grade1;
    float grade2;
    float average;
}Data;

// prototypesfunction prototypes
void InsertData(Data p[], int *iteratorPtr);
void ReadData(Data *ptr, Data p[],int *iteratorPtr);
void ShowData(Data *ptr, Data p[],int *iteratorPtr);

int main(void) { // Main function
 Data *ptr, p[1];
 ptr = &p[0];
 int i=0, iterator=0, *iteratorPtr, op=0;
 iteratorPtr = &iterator;
 while(1){
   printf("[ 1 ] - Enter New Student data\n");
   printf("[ 2 ] - Show entered student data\n");
   printf("[ 3 ] - Search for student in the list\n");
   printf("[ 0 ] - Exit\n");
   printf("Choose an option\n");
   scanf("%d",&op);
   switch(op){
     case 1:{
            ReadData(ptr,p,iteratorPtr);
            break;
          }
     case 2:{
            ShowData(ptr, p, iteratorPtr);
            break;
          }
     case 3:{
            break;
          }
     case 0:{
            exit(0);
         }
     default:{
            printf("Invalid Option\n");
            break;
     }
   }
 }

printf("%d\n",*iteratorPtr);
 for(i=0; i < *iteratorPtr; i++){
   printf("%s\t\t\t\t\t\t\t%.2f  %.2f\t\tAVERAGE: %.2f\n",p[i].name,p[i].grade1,p[i].grade2,p[i].average);
 }
 
  return 0;
}


void ReadData(Data *ptr, Data p[],int *iteratorPtr){ // Function to input data
    int i=0;
    char re='y'; // variable to store the user's response

system("clear");
 ptr = (Data *)calloc(4,sizeof(Data));// Allocating memory with calloc function

 while(re=='y'){ // While the answer is yes

  // Reading the data
   printf("NAME:\n");
  scanf("%s", p[i].name);
   printf("GRADE 1: \n");
   scanf("%f",&p[i].grade1);
   printf("GRADE 2: \n");
   scanf("%f",&p[i].grade2);
   p[i].average = (p[i].grade1 + p[i].grade2)/2;
   printf("More records? y/n\n");
   scanf(" %c",&re);

   i++;

   (*iteratorPtr)++; // iterator counts the size of the struct

   if(re=='y'){ // if the answer is yes then reallocates memory

      if((ptr = (Data *)realloc(ptr, 4*sizeof(Data)))==NULL){ // checks if the relocation was successful
            printf("Memory allocation error\n"); // if not, show error message and end the program
            exit(1);
      }
   }
   getchar();

 }
 InsertData(p,iteratorPtr);// function to insert date into file
 free(ptr); // releasing memory allocated to the pointer
 iteratorPtr=NULL;
 return;
}

void InsertData(Data p[], int *iteratorPtr){
 
    FILE *file;
    int i=0;
    if((file = fopen("StudentData.txt","a")) == NULL){
      printf("Error opening file");
      exit(1);
    }
    else{
        for(i=0; i < (*iteratorPtr); i++){
            fprintf(file,"NAME\t\t%s\nGRADE 1:\t\t%.2f\nGRADE 2:\t\t%.2f\nAVERAGE:\t\t%.2f\n\n",p[i].name,p[i].grade1,p[i].grade2,p[i].average);
        }
        fclose(file);
    }
     
}

void ShowData(Data *ptr, Data p[],int *iteratorPtr){
    FILE *file;
    char character =' ';
    system("clear");
    if((file = fopen("StudentData.txt", "r"))==NULL){
      printf("Unable to Open the File\n");
      exit(1);
    }
    else{
        while((character = getc(file))!=EOF){
          printf("%c", character);
        }
        fclose(file);
    }
    
    free(ptr);
}