#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "strtab.h"

const char *dataTypeStr[3] = {"int", "char", "void"};
const char *symbolTypeStr[3] = {"", "[]", "()"};

table_node* current_scope = NULL;
param *working_list_head = NULL;
param *working_list_end = NULL;

/* The symbolTable, which will be implemented as a hash table
  */
struct strEntry strTable[MAXIDS];

/* Provided is a hash function that you may call to get an integer back. */
int hash(unsigned char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++)) {
    hash += (hash << 5) + c;
  }
  return hash % MAXIDS; // MAXIDS defined in strtab.h
}

int ST_insert(char *id, char *scope, int data_type, int symbol_type){
  // TODO: Concatenate the scope and id and use that to create the hash key

  /* TODO: Use ST_lookup to check if the id is already in the symbol table.
    If yes, ST_lookup will return an index that is not -1.
    if index != -1, that means the variable is already in the hashtable.
    Hence, no need to insert that variable again.
    However, if index == -1,
      then use linear probing to find an empty spot and insert there.
    Then return that index.
    */
    //stores key and formats it as scope:id
    char key[256];
    snprintf(key, sizeof(key), "%s:%s", scope, id);
    //checks if symbol already exists in the table
    int existingIdx = ST_lookup(id, scope);
    if (existingIdx != -1) {
        printf("error: multiply declared identifier %s\n", id);
        return existingIdx;
    }
    //computes hash key
    int idx = hash((unsigned char*)key);

    while (current_scope->strTable[idx] != NULL) {
       idx = (idx + 1) % MAXIDS;
    }

    //assign values
    symEntry* entry = malloc(sizeof(symEntry));
    entry->id = strdup(id);
    entry->scope = strdup(scope);
    entry->data_type = data_type;
    entry->symbol_type = symobl_type;
    entry->size = 0;
    entry->params = NULL;

    current_scope->strTable[idx] = entry;
    
    /*
    while (strTable[idx].id != NULL) {
        idx = (idx + 1) % MAXIDS;
    }
    //copy data and return index of the table
    
    strTable[idx].id = strdup(id);
    strTable[idx].scope = strdup(scope);
    strTable[idx].data_type = data_type;
    strTable[idx].symbol_type = symbol_type;
    */
   
    return idx;
}

symEntry* ST_lookup(char *id, char *scope) {
  // TODO: Concatenate the scope and id and use that to create the hash key

  /* TODO: Use the hash value to check if the index position has the "id".
    If not, keep looking for id until you find an empty spot.
    If you find "id", return that index.
    If you arrive at an empty spot, that means "id" is not there.
    Then return -1.
    */
   /*
   char key[256];
   snprintf(key, sizeof(key), "%s:%s", scope, id);
   int h = hash((unsigned char*)key);

   int start = h;

  //need to search table until finding the symbol or finding an empty space
   while (strTable[h].id != NULL) {
      char currentKey[256];
         snprintf(currentKey, sizeof(currentKey), "%s:%s",
                 strTable[h].scope, strTable[h].id);

        if (strcmp(currentKey, key) == 0) {
           return h;
        }

      //prevents going out of bounds
      h++;
      if (h == MAXIDS) {
         h = 0;
      }
      //helps prevent infinite loops
      if (h == start) {
         break;
      }
    }
    return -1;
    */
   //OLD CODE ABOVE THIS

   table_node* scope = current_scope;

   while (scope != NULL) {
      for (int i = 0; i < MAXIDS; i++) {
         if (scope->strTable[i] != NULL && strcmp(scope->strTable[i]->id, id) == 0) {
            return scope->strTable[i];
         }
      }
      scope = scope->parent;
   }

   return NULL;
}

void output_entry(int i){
  printf("%d: %s ", i, dataTypeStr[strTable[i].data_type]);
  printf("%s:%s%s\n",
    strTable[i].scope, strTable[i].id, symbolTypeStr[strTable[i].symbol_type]);
}

void new_scope() {
   table_node* node = malloc(sizeof(table_node));
   for (int i = 0; i < MAXIDS; i++) {
      node->strTable[i] = NULL;
   }
   node->parent = current_scope;
   current_scope = node;
}

void up_scope() {
   if (current_scope != NULL) {
      current_scope = current_scope->parent
   }
}

void add_param(int data_type, int symbol_type) {
   param* parameter = malloc(sizeof(param));
   parameter->data_type = data_type;
   paramter->symbol_type = symbol_type;
   parameter->next = NULL;

   if (working_list_head == NULL) {
      working_list_head = parameter;
      working_list_end = parameter;
   }
   else {
      working_list_end->next = parameter;
      working_list_end = parameter;
   }
}
