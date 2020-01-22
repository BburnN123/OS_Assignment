/*----------------------------------------------------------------------------------------------
Project: CSC1007 - Operating Systems Assignment
Program name: OS File System
Authors: Xie Yuan Shan, Kwang Qi Rong, Hui Jie, Sharon, June, Hui Ting
Group: ???
Date Created: 16 January 2020
Description: 
-----------------------------------------------------------------------------------------------*/

#include "main.h"
#include "readCSV.c"

int main(void){
    register int i=0;
    register int j=0;
    unsigned char input[20];
    unsigned int choice = 0;
    unsigned int format = 0;

    do{
        printf("Type Y to format File System or N to exit\n");
        scanf("%s", &input);
        if(strlen(input) == 1){
            if(input[0] == 89 || input[0] == 121) //If user key in Y(89) / y(121)
            { 
                //space for format
                format = 1;
            }  
            else if(input[0] == 78 || input[0] == 110) ////If user key in N(78) / n(110)
            {
                exit(0);
            }
            else
            {
                printf("Invalid input, please enter between Y or N\n");   
            }                      
        }else
        {
            printf("Invalid input, please enter between Y or N\n");   
        }
            
    }while(format != 1);

    //Block size
    do{
        printf("\nEnter required block size: ");
        scanf("%s", &input);
        blockSize = atoi(input);
        if(blockSize < 0 || 130%blockSize != 0) //Ensure that the block can be divisible
            printf("Invalid entry, please enter between 1 - 10");      
    }while(blockSize < 0 || 130%blockSize != 0);
    noOfBlocks = MAX_BLOCK/blockSize; // If is 5 , 26 block is created

    struct block *blocks; //Create one block
    blocks = calloc(noOfBlocks, sizeof(char) * MAX_STRING_SIZE); //Create an array to store the block inside

    for(i = 0; i < noOfBlocks; i++){
        blocks[i].entryNode = malloc(sizeof(struct node *) * blockSize);
    }
    blocks[1].entryNode[3].index = 1;
    
    blocks[1].entryNode[3].data[0] = '1';
    blocks[1].entryNode[3].data[1] = '0';
    blocks[1].entryNode[3].data[2] = '1';

    for(int j = 0; j < noOfBlocks; j++)
    {
        printf("Block %d\n", j);
        printf("Index\n");
        for(int n = 0; n < blockSize; n++)
        {
            printf("%d\t%s\n", n, blocks[j].entryNode[n].data);
        }
        printf("---------------\n");
    }



    //File system choice
    do{
        printf("Enter choice for file system: \n1: Contiguous Allocation\n2: Linked Allocation\n3: Indexed Allocation\n4: Custom Allocation\n");
        scanf("%s", &input);
        choice = atoi(input);
        if(choice == 1){
            //Space for Contiguous
        }else if(choice == 2){
            //Space for Linked
        }else if(choice == 3){
            //  indexed();
        }else if(choice == 4){
            //Space for custom
        }else
            printf("Invalid choice, please enter between 1 - 4");      
    }while(choice <= 0 || choice > 4);
    
    //Read CSV File
    printf("Enter name of .csv file to read from\n");
    scanf("%s", &input);
    readCSV(input);

    free(blocks);
} 