#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#define NO_OF_STRING 50
#define MAX_STRING_SIZE 100
#define MAX_BLOCK 130

struct node{
    int index;
    //int blockNo;
    char data[MAX_STRING_SIZE];
    //struct block blockData;
};

struct block{
    int blockNo;
    struct node *entryNode;
};

int blockSize;
int noOfBlocks;
char CSV_Data[NO_OF_STRING][MAX_STRING_SIZE];
#endif