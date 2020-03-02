//-----------------------------------------------------------------------------
// DictionaryTest.c
// Test client for the Dictionary ADT
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include"Dictionary.h" 

int main(){

   char* strng;
   Dictionary A = newDictionary();
   insert(A, "1", "a");
   insert(A, "2", "b");
   printf("count: %d\n", countChars(A));

   insert(A, "3", "c");
   insert(A, "4", "d");
   insert(A, "5", "e");
   printf("count: %d\n", countChars(A));

   insert(A, "6", "f");
   printf("count: %d\n", countChars(A));

   insert(A, "7", "g");
   printf("count: %d\n", countChars(A));

   insert(A, "8", "h");
   insert(A, "9", "i");


   printf(DictionaryToString(A));
   printf("count: %d\n", countChars(A));


   //printf("count: %d\n", countChars(A));
   //makeEmpty(A);

   //strng = DictionaryToString(A);
   //printf("%s\n", strng);
   //free(strng);

   //printf("where it segfaults: %d\n", size(A));
   

   //printf(DictionaryToString(A));
   //printf("count: %d\n", countChars(A));

   /*printf("\ntesting delete:\n");

   delete(A, "1");
   delete(A, "5");
   delete(A, "3");
   delete(A, "9");
   //delete(A, "4");
   //delete(A, "1");
   //printf(DictionaryToString(A));

   //printf("size: %d\n", size(A));
   printf("countChars(): %d\n", countChars(A));


   printf("lookup 1: %s\n", lookup(A, "1"));
   printf("lookup 2: %s\n", lookup(A, "2"));
   printf("lookup 3: %s\n", lookup(A, "3"));
   //printf("lookup 5: %s\n", lookup(A, "5"));
   printf("lookup 7: %s\n", lookup(A, "7"));
   //printf("lookup 5: %s\n", lookup(A, "5"));
   printf("lookup 4: %s\n", lookup(A, "4"));

   printf(DictionaryToString(A));


   makeEmpty(A);

   printf(DictionaryToString(A));
   printf("size after makeEmpty(): %d\n", size(A));

   insert(A, "a", "blah");
   insert(A, "b", "hello");
   insert(A, "c", "testing");
   insert(A, "d", "hello");
   insert(A, "e", "hi");
   insert(A, "f", "word");


   DictionaryToString(A);   
   printf("size after insert(): %d\n", size(A));

   printf("lookup 3: %s\n", lookup(A, "a"));
   printf("lookup 4: %s\n", lookup(A, "b"));
   printf("lookup 100: %s\n", lookup(A, "g"));

   printf("\ntesting delete\n");
   //delete(A, "d");
   delete(A, "f");
   //delete(A, "7");
   DictionaryToString(A);

   printf("countChars(): %d\n", countChars(A)); */
   freeDictionary(&A);
   return(EXIT_SUCCESS);

}

