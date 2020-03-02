/*
 * Dictionary implementation of the Linked List ADT.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include"Dictionary.h"

// Private Types and Functions ---------------------------------

// NodeObj type
typedef struct NodeObj{
   //int item;
   char* key;
   char* value;
   struct NodeObj* next;
} NodeObj;

// Node type
typedef NodeObj* Node;

// newNode()
// constructor for the Node type
Node newNode(char* k, char* v) {
   Node N = malloc(sizeof(NodeObj));
   //assert(N!=NULL);
   N->key = k;
   N->value = v;
   N->next = NULL;
   return N;
}

// DictionaryObj type
typedef struct DictionaryObj{
   Node head;		// pointer to the first Node in list
   int numPairs;	// number of pairs in this Dictionary
} DictionaryObj;

// freeNode()
// destructor for the Node type
void freeNode(Node* pN){
   if(pN != NULL && *pN != NULL){
      free(*pN);
      *pN = NULL;
   }
}

// findKey()
// returns a Node reference pointing to the Node object containing its argument k as key, or returns NULL if no such Node exists
Node findKey(Dictionary D, char* k){
   Node T;
   if (D == NULL) {
      fprintf(stderr, 
         "Dictionary Error: findKey() called on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   T = D->head;
   for(int i = 0; i < D->numPairs; i++) {
      if ((T->key) == k) {
         T = T->next;
      }
   }
   return T;
}      

// freeAllNodes()
// uses recursion to free all the Nodes in list headed by H
void freeAllNodes(Node H){
   if(H != NULL){
      freeAllNodes(H->next);
      freeNode(&H);
   }
}

// Constructors-Destructors ------------------------------------

// newDictionary()
// Constructor for the LinkedList ADT
Dictionary newDictionary(){
   Dictionary D = malloc(sizeof(DictionaryObj));
   D->head = NULL;
   D->numPairs = 0;

   return D;
}

// freeLinkedList()
// Destructor for the List ADT
void freeDictionary(Dictionary *pD){
   if(pD != NULL && *pD != NULL){
      makeEmpty(*pD);
      free(*pD);
      *pD = NULL;
   }
}

// ADT operations ---------------------------------------------------

// size()
// Return the number of (key, value) pairs in Dictionary D.
int size(Dictionary D){
   if(D == NULL){
      fprintf(stderr,
         "Dictionary Error: calling size() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
      return D->numPairs;
}

// lookup()
// If D contains a pair whose key matches argument k, then return the corresponding value, otherwise return NULL
char* lookup(Dictionary D, char* k) {
   if(D == NULL){
      fprintf(stderr,
         "Dictionary Error: calling lookup() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   char* test;
   Node T;
   T = D->head;
     
      if(T->key == k) {
         return T->value;
      }

      while ((T->key != k) && (T->next != NULL)) {
         T = T->next;
         test = T->key;
         int check = strcmp(test, k);
         //T = T->next;
         if (check == 0) { 
         //if (T->key == k) {
             //T = T->next;
            //T = T->key;
            return T->value;
         }
      }
}

// insert()
// Insert the pair (k, v) into D.
// Pre: lookup(D, k) == NULL. (D does not contain a pair whose first member is k.)
void insert(Dictionary D, char* k, char* v){
   if(D == NULL){
      fprintf(stderr, 
         "Dictionary Error: calling insert() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }

   Node T;
      if(size(D) == 0) {
         T = D->head;
         T = newNode(k, v);
         D->head = T;
         //D->head = newNode(k, v);
         D->numPairs++;
      }
      else if (size(D) > 0){
        T->next = newNode(k,v);
        T = T->next;
        D->numPairs++;
      }
}

// delete()
// Remove pair whose first member is the argument k from D
// Pre: lookup(D,k) ≠ NULL. (D contains a pair whose first member is k.)
void delete(Dictionary D, char* k) {
   if(D == NULL){
      fprintf(stderr,
         "Dictionary Error: calling delete() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   
   Node N;
   Node P;
   Node O;
   int count = 0;
   P = D->head;
   O = D->head;
   Node J;
   J = D->head;
   if (J->key == k) {
      D->head = J->next;
      D->numPairs--;
      freeNode(&J);
   }
   else {  
      while ((P->key !=k) && P->next != NULL) {
         P = P->next;
         count++;
      }

      for(int i = 0; i < count-1; i++) {
         O = O->next;
      }
      N = O->next;
      O->next = N->next;
      N->next = NULL;
      freeNode(&N);
      D->numPairs--;
  }
}

// makeEmpty()
// Reset D to the empty state, the empty set of pairs
void makeEmpty(Dictionary D) {
   if(D == NULL){
      fprintf(stderr, 
         "Dictionary Error: calling makeEmpty() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }
   
   freeAllNodes(D->head);
   D->head = NULL;
   D->numPairs = 0;
}

// Other Operations ----------------------------------------------------------------------------------------

// DictionaryToString()
char* DictionaryToString(Dictionary D){
   char* str;
   int n;
   if( D==NULL ){
      fprintf(stderr, 
         "Dictionary Error: calling DictionaryToString() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }

    if(D->head == NULL) {
       n = 1;
       str = malloc(n+1 * sizeof(char));
       strcat(str, "\n");
    }

    if(D->head != NULL) {
      n = countChars(D);
      str = malloc(1000 * sizeof(char*));
      Node T;
      T = D->head;

      while(T->next != NULL) {
         char* keyC = T->key;
         char* valueC = T->value;
         strcat(str, keyC);
         strcat(str, " ");
         strcat(str, valueC);
         strcat(str, "\n");
         T = T->next;
     } 
     char* keyC2 = T->key;
     char* valueC2 = T->value;
     strcat(str, keyC2);
     strcat(str, " ");
     strcat(str, valueC2);
     strcat(str, "\0");
     strcat(str, "\n");
   } 
  return str;
}


// countChars()
// counts the number of characters in the text representation of D
int countChars(Dictionary D) {
   int count = 0;
   Node T;
   T = D->head;

   if (D != NULL) {
      while(T->next != NULL) {
         count += strlen(T->key) + strlen(T->value) + 1;
         T = T->next;
      }
      count += strlen(T->key) + strlen(T->value) + 1;
      return count;
   }
   else if (D == NULL) {
       count = 0;
       return count;
   }
}

