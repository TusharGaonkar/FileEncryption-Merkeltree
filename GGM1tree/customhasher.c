#include<stdio.h>
#include<string.h>
#include "hasher.h"

void decToHexa(unsigned int n, char *hexaDeciNum) 
{    
   
    int i = 0; 
    while(n!=0) 
    {    
        // temporary variable to store remainder 
        int temp  = 0; 
          
        // storing remainder in temp variable. 
        temp = n % 16; 
          
         
        if(temp < 10) 
        { 
            hexaDeciNum[i] = (char) (temp + 48); 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = (char) (temp + 55);
            i++; 
        } 
          
        n = n/16; 
    } //function to convert decimal to hexadcimal so to make hashed value alphanumeric
    char hexfile[8];
    hexaDeciNum[i] = '\0';
    
} 
  


unsigned int smh(char input[],int size){
    
    unsigned int init=1737199;
    unsigned int magic=7139379;
    unsigned int hash=0;
    for(int i=0;i<size;i++)
    {
        
        hash=hash^(input[i]);
        hash=hash*magic;
        
        
    }
    
    return hash;

  
}//This is the simple hashing function based on Knuth Multiplicative hashing algorithm it generates 8Charcters length fixed hash code which is 
 //unique for each file

void concatHash(char input[], int size, char *c)
{
    decToHexa(smh(input, size), c);
}