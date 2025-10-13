#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
  char *input;

  struct node *next;
};
typedef struct node node_t;

struct linked_list {

  int cap;
  int size;
  node_t *head;
};
typedef struct linked_list list_t;

node_t *construct(char *str) {
  node_t *node = malloc(sizeof(node_t));
  node->input = strdup(str);
  node->next = NULL;
  return node;
}

list_t *create_list() {
  list_t *list = malloc(sizeof(list_t));
  list->cap = 5;
  list->head = NULL;
  list->size = 0;
  return list;
}
void move_head(list_t *list) {

  if (list->size < 5) {
    return;
  }

  node_t *tmp = list->head;
  list->head = list->head->next;
  free(tmp->input);
  free(tmp);
  list->size--;
}

// change it to add at tail not front
void add_node(list_t *list, char *str) {
  // consider the cap later remove tail when 5
  //
  //

  node_t *new = construct(str);
  if (list->head == NULL) {
    list->head = new;
    new->next = NULL;
  } else {

    node_t *curr = list->head;
    node_t *tmp;
    while (curr != NULL) {
      tmp = curr;
      curr = curr->next;
    }
    tmp->next = new;
    list->size++;

    if (list->size >= list->cap) {
      move_head(list);
    }
  }
}
// not needed
void delete_tail(list_t *list) {
  node_t *curr = list->head;
  node_t *prev;

  while (curr != NULL) {
    prev = curr;
    curr = curr->next;
  }
  prev->input = NULL;
  free(prev->next);
  prev->next = NULL;
}
void print_list(list_t *list) {

  if (list->head == NULL) {
    printf("empty list\n");
  }
  node_t *curr = list->head;
  while (curr != NULL) {
    printf("%s \n", curr->input);
    curr = curr->next;
  }
}

void clear(list_t *list) {

  // clear the LL on command
  //
  node_t *curr = list->head;
  node_t *next;

  while (curr != NULL) {
    next = curr->next;
    free(curr->input);
    free(curr);
    curr = next;
    list->size--;
  }
  list->head = NULL;
}

int main() {

  list_t *list = create_list();

  char *buff = NULL;
  size_t size = 0;

  while (1) {
    printf("Enter something: ");
    if (getline(&buff, &size, stdin) != -1L) {
      buff[strcspn(buff, "\n")] = '\0';
      if (strcmp(buff, "print") == 0) {
        add_node(list, buff);
        print_list(list);
      } else if (strcmp(buff, "exit") == 0) {
        clear(list);
      } else {
        add_node(list, buff);
      }
    }
  }
}
