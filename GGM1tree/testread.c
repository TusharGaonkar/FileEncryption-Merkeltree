#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "hasher.h"

int n,i,count;
#define MAX 100


struct file{
     char file_name[20];
     char *file_data;


};
struct hash_codes{

char *hashes;

};//structure to hold hash of the files

struct file files[30];
int main()
{
   char ch, file_name[20];
   FILE *fp;
   printf("\nEnter number of files you want to hash:");
   scanf("%d",&n);
  

 
   
   for(i=0;i<n;i++){

   printf("\nEnter name of a file you wish to see:");
    fflush(stdin);
    fgets(files[i].file_name, 100, stdin);
    
    strtok(files[i].file_name,"\n");
    printf("\nSuccessfully stored the hashed file name....\n");
    

     fp= fopen(files[i].file_name, "r"); // read mode

   if (fp == NULL)
   {
      printf("\nError while opening the file.\n");
      return -1;
     
   }
   else{

   printf("\nThe contents of %s file are:\n",files[i].file_name );
   files[i].file_data=malloc(2000);
   int j=0;



   while((ch = fgetc(fp)) != EOF){
      if(ch=='\n'||ch==' ')
      continue;
      
      files[i].file_data[j]=ch;
      count++;

        j++;
   }
        
   
      
      printf("%s", files[i].file_data);
      printf("\nSuccessfully hashed the file contents.....\n");}
    int size_filename = sizeof(files[i].file_name)/sizeof(files[i].file_name[0]);
    int size_filedata=count;
    //printf("%d",size_filedata);
     unsigned int hash_filename=smh(files[i].file_name,size_filename);
     unsigned int hash_filedata=smh(files[i].file_data,size_filedata);
     char s[300], g[300];
     decToHexa(hash_filename, s);
     decToHexa(hash_filedata, g);
     
     strcat(g,s);
     printf("Files Unique Hash code is :%s",g);
     count=0;
     
    
     


  }
  fclose(fp);
  if(n%2!=0){
     n=n+1;
   strcpy(files[n-1].file_data,files[n-2].file_data);
   
  }
  for(i=0;i<n;i++){

     createnode(files[i].file_data);

  }
  
   
    struct Merkel_node **leafnodes = malloc(n * sizeof(struct Merkel_node *));
         for (int i = 0; i < n; i++)
     {
         char hash[600];
         concatHash(files[i].file_data, strlen(files[i].file_data), hash);
        leafnodes[i] = createnode(hash);
        printf("\nThe leaves are:");
         inorder(leafnodes[i]);
     }
    
    struct Merkel_node *root = generateTree(leafnodes, n);
     printf("\nInorder traversal of the GGM tree is\n");
     inorder(root);
     printf("\nThe New Merkel unique Root Hash for the set of your files at this instance  is :%s",root->hashconcat);

    



   return 0;}


