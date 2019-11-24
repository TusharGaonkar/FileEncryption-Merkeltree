#include<stdio.h>
#include <stdlib.h>
#include<string.h>

struct Merkel_node 
{

    char *hashconcat;
    struct Merkel_node *left;
    struct Merkel_node *right;
};//  it contains the hashcode as the data part and the left and right are the pointers

struct Merkel_node *createnode(char hashes[]);


struct Merkel_node *generateTree(struct Merkel_node **leafnodes, int n);
void inorder(struct Merkel_node *root);



void decToHexa(unsigned int n, char *hexaDeciNum);

unsigned int smh(char input[],int size);
//This is the simple hashing function based on Knuth Multiplicative hashing algorithm it generates 8Charcters length fixed hash code which is 
 //unique for each file

void concatHash(char input[], int size, char *c);