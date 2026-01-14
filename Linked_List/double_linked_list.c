#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
  int num;
  struct list* prev;
  struct list* next;
} list;

list* init_node(int data){
  list* new_node = malloc(sizeof(list));
  if (new_node == NULL){
    fprintf(stderr, "Mem alloc failed!\n");
    exit(1);
  }
  new_node->num = data;
  new_node->prev = NULL;
  new_node->next = NULL;

  return new_node;
}

list* add_front(int data, list* head){
  list* new_node = init_node(data);
  if (head!=NULL){
    new_node->next = head;
    head->prev = new_node;
  }
  
  return new_node;
}

list* create_list(int size){
  list* head = init_node(rand() % 50);
  for (int i = 1; i < size; i++){
    head = add_front((rand() % 50), head);
  }

  return head;
}

void print_list(list* head){
  list* node = head;
  int count = 0;
  while (node!=NULL){
    printf("%d: ", node->num);
    node = node->next;
    count ++;
    if (count % 20 == 0)
      printf("\n");
  }
}

void remove_node(list* node, list* prev, list* next){
  prev->next = next;
  if (next != NULL)
    next->prev = prev;

  node->next = NULL;
  node->prev = NULL;
  free(node);
}


void remove_duplicates(list* head){
  list* node = head;
  while (node!=NULL){
    list* dup_finder = node->next;
    while (dup_finder!=NULL){
      if (node->num == dup_finder->num){
        list* temp = dup_finder->next; 
        remove_node(dup_finder, dup_finder->prev, dup_finder->next);
        dup_finder = temp; 
      }
      else{
        dup_finder = dup_finder->next;
      }
    }
    node = node->next;
  }
}

int main(void){
  srand(time(NULL));
  list* head = create_list(200);

  printf("\nOriginal List: \n");
  print_list(head);

  
  remove_duplicates(head);

  printf("\nAfter removing duplicates: \n");
  print_list(head);

  return 0;
}
