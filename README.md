# Merkel Binary Tree - A project on (Cryptography and Hashing)



## About

*Implementing File encryption using* **Merkel Tree Algorithm**

>  A system to check the Integrity of the files in a folder in order to
> avoid tampering of the data in any instance. If there is a file transfer from source to destination then the user receiving this file can easily check for any modification in the source file thus guaranteeing safe transactions.


## Description
Merkle Trees are a fundamental component of blockchains that underpin their functionality they work on the concepts of **Pseudo Random functions** .They allow for efficient and secure verification of large data structures, and in the case of blockchains, potentially boundless data sets. 

 [Source](https://en.wikipedia.org/wiki/Merkle_tree)

![enter image description here](https://upload.wikimedia.org/wikipedia/commons/thumb/9/95/Hash_Tree.svg/1920px-Hash_Tree.svg.png)

## Structure of a Merkel Tree

A **Tree** data structure where each ***non-leaf node is a hash of it’s child node*** and
all the ***leaf nodes contain*** the **cryptographic** hashes of the data set.

**Merkel Root**: The Root of this tree holds a unique cryptographic hash as the fingerprint for the entire data in a binary Merkel tree

## Data Structures Used

 1. Binary tree as GGM tree with a structure 
    ```c
    struct Merkel_node{ 
    char *hashconcat; 
    struct Merkel_node *left;
    struct Merkel_node *right
    };
    ```

 2. Stack to Hold hashes of child nodes to concatenate these in the
    parent node.
 3. File reading techniques in C
 4. Cryptography Hashing function to generate Hash codes of a fixed
    length for any arbitrary length and to avoid any hashing collisions(using concepts of SHA-256 Algorithm).

## Inputs & Features

 - User has to input the set of files he wants to secure.
 - The data in each individual files are passed to a cryptographic hash
   function and unique hash codes are generated
 - Thus a Merkel root is generated at the end after hashing these files at each
   levels from leaf nodes to the root thus generating a single unique
   hash code for the set of files.

![enter image description here](https://pbs.twimg.com/media/CqHRpKjUkAA0o-w.jpg)


***Any Tamper in the data of any individual file in this set leads to the mismatch of the Merkel root hash code thus indicating that someone has modified the file***




# How to Run these files !

    sudo git clone https://github.com/TusharGaonkar/MerkelTree-File_encryption.git

 

 - `cd .\MerkelTree-File_encryption\GGM1tree\` 
 -  `gcc merkel.c customhasher.c testread.c -o fileencryption`
 - `.\fileencryption.exe` (Windows)  `.\fileencryption` (Linux)


