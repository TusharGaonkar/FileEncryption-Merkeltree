#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "hasher.h"
//#include "file.h"
// int i;

struct Merkel_node *createnode(char hashes[])
{
    struct Merkel_node *node = (struct Merkel_node *)malloc(sizeof(struct Merkel_node));
    node->hashconcat = (char *)malloc(1000* sizeof(char));
    strcpy(node->hashconcat, hashes);
    node->left = NULL;
    node->right = NULL;
    return node;
    free(node);
}  //A structure to create leaf node we are moving from the leaf to  the root

struct Merkel_node *generateTree(struct Merkel_node **leafnodes, int n)
{
    if (n == 1)
        return leafnodes[0];

    int y = n / 2, isOdd = 0;
    if (y % 2 != 0 && y != 1)
    {
        y++;
        isOdd = 1;
    }  //A function to create the non-leaf nodes if the number of nodes are odd then create a new node to make it even then replicate the data of the previous node

    struct Merkel_node **temp = malloc(y * sizeof(struct Merkel_node *));
    // if (isOdd) 
    // { 
        int e = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 != 0)
            {
                char temphash[400], hash[400];
                strcpy(temphash, leafnodes[i - 1]->hashconcat);
                strcat(temphash, leafnodes[i]->hashconcat);
                concatHash(temphash, 256, hash);
                temp[e] = createnode(hash);
                temp[e]->left = leafnodes[i - 1];
                temp[e]->right = leafnodes[i];
                e++;
            }//A structure holding structure of merkel leaf nodes to track the nodes
        }
        if (isOdd)
        {
            temp[e] = temp[e - 1];
            temp[e]->left = NULL;
            temp[e]->right = NULL;
        }
    
    generateTree(temp, y);
}

void inorder(struct Merkel_node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("\n%s\n", root->hashconcat);
   
    inorder(root->right);
}

