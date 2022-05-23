#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int select = 1;
int option;
int memoryArray[10] = {0,0,0,0,0,0,0,0,0,0};
int count = 1;
int generateRandomNumbers() {
    srand(time(NULL));
    int num = rand()%((4+1)-1) + 1;
    return num;
}

void printArray(){
    printf("DISPLAYING PROCESS ALLOCATION\n");
     for (int i = 0; i < 10; i++){
      printf("%d, ", memoryArray[i]);
    }
}

void create(){
    if(count<10){
        printf("CREATION\n");
        int randomNumber = generateRandomNumbers();
        for(int i=0;i<10;i++){
            if(memoryArray[i]==0){
            memoryArray[i] = randomNumber;
            break; 
            }
        }
        printArray();
        count = count++;
    }
    else{
        printf("memory full\n");
    }
}

void delete(){
    int processToDelete;
    printf("DELETION\nEnter Process to Delete\n");
    scanf("%d", &processToDelete);
    memoryArray[processToDelete-1]==0;
    printArray();
}

void exitProgram(){
    printf("EXIT\n");
    select= 0;
}

int main(){
    while(select == 1){
        printf("SELECT OPTION\n  [CREATE : 1] [DELETE : 2] [EXIT : 0]\n");  
        scanf("%d", &option);
        switch (option){
            case 1: create();
                break;
            case 2: delete();
                break;
            case 0: exitProgram();
                break;
        }
    }
}

