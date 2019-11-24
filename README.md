# Merkel-Binary-Tree-DS-Project
Implementing File encryption using Merkel Tree concepts..
Project Topic :Construction of GGM tree(Binary Merkel tree).
Description:Merkle Trees are a fundamental component of blockchains that underpin their functionality they work on the concepts of Pseudo Random functions of GGM,They allow for efficient and secure verification of large data structures, and in the case of  blockchains, potentially boundless data sets.
Basic Structure: A tree data structure where each non-leaf node is a hash of it’s child nodes.All the leaf nodes contain the crytographic hashes of the data set.
Merkel Root:The Root of this tree holds a unique cryptographic hash as the fingerprint for the entire data in a binary Merkel tree
 SOURCE:https://en.wikipedia.org/wiki/Merkle_tree

Implementation of the Binary Merkel Tree in your project:

A system to check the Integrity of the files in a folder inorder to avoid tampering of the data in any instance.If there is a file transfer from source to destination then the user
receiving this file can easily check for any modification in the source file thus guaranteeing safe transactions.


Inputs and Features:
User has to input the set of files he wants to secure.The data in each individual files are passed to a cryptographic hash function and unique hashcodes are generated thus
a merkel root is generated after hashing these files at each levels from leaf nodes to the root thus generating a single unique hash code for the set of files.

Any Tamper in the data of any individual file in this set leads to the mismatch of the merkel root hashcode thus indicating that someone has modified the file



Data structure used:

1.Binary tree as GGM tree
2.Stack to Hold hashes of child nodes to concatenate these in the parent node.
3.File reading techniques in C
4.Cryptography Hashing function:To generate Hash codes of a fixed length for any arbitrary length and to avoid any hashing collisions(using concepts of SHA-256 Algorithm).


Outputs:
Check for the given set of files whether it is tampered or not,if it's tampered output the particular file which got tampered.
Output the unique hash code for the particular set of files.


How to Run these files

Open Command prompt after downloading these files 
----> a.exe (Executable is already provided no need of compiling it again)
----> type cd "file_path" move to the current directory of the project
-----> then type a


