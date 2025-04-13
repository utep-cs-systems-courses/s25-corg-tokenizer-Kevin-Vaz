#include <stdio.h>

#include <stdlib.h>

#include <string.h>



typedef struct s_Item {

  int id;

  char *str;

  struct s_Item *next;

} Item;



typedef struct s_List {

  struct s_Item *root;

} List;



/* Initialize the linked list to keep the history. */

List* init_history(){

  List *list = (List *)malloc(sizeof(List));

  if (!list) {

    perror("Memory allocation failed");

    exit(1);
  }

  list->root = NULL;

  return list;

}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str) {

  if (!list || !str) return;



  Item *temp = (Item *)malloc(sizeof(Item));

  if (!temp) return;



  temp->str = strdup(str);

  if (!temp->str) {

    free(temp);

    return;

  }
  temp->next = NULL;

  temp->id = 1;



  if (list->root == NULL) {

    list->root = temp;

  } else {

    Item *copy_list = list->root;

    while (copy_list->next != NULL) {

      copy_list = copy_list->next;

    }

    temp->id = copy_list->id + 1;

    copy_list->next = temp;

  }

}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){

  Item *current = list->root;

  while (current != NULL) {
    if (current->id == id) {

      return current->str;

    }

    current = current->next;

  }

  return NULL;

}



/*Print the entire contents of the list. */

void print_history(List *list){

  Item *current = list->root;

  while (current != NULL) {

    printf("%d: %s\n", current->id, current->str);

    current = current->next;

  }

}



/*Free the history list and the strings it references. */

void free_history(List *list){

  Item *current = list->root;

  while (current != NULL) {

    Item *temp = current;

    current = current->next;

    free(temp->str);

    free(temp);

  }

  free(list);

}
