#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
  int num;
  struct list *next;
} list;

void randomize_array(int arr[], int size){
  for (int i = 0; i < size; i++){
    arr[i] = rand() % 500 + 1;
  }
}

list* init_node(int d){
  list *new_node = malloc(sizeof(list));
  new_node->num = d;
  new_node->next = NULL;
  return new_node;
}

list* add_front(int d, list* head){
  list* node = init_node(d);
  node->next = head;

  return node;
}

list* convert_array (int arr[], int size){
  list* head = init_node(0);
  list* node = init_node(arr[0]);
  for (int i = 1; i < size; i++){
    node = add_front(arr[i], node);
  }
  head->next = node;

  return head;
}

void swap (list* p1, list* p2, list* prev){
  list* temp = p2->next;
  p2->next = p1;
  p1->next = temp;
  prev->next = p2;
}

void sort_linked_list(list* head, int size){
  for (int i = 0; i <= size; i++){
  list* prev = head;
  list* p1 = head->next;
    while (p1 != NULL && p1->next != NULL){
      list* p2 = p1->next;
      if (p1->num > p2->num){
        swap(p1, p2, prev);
        p1 = p2->next;
      }
      else {
        p1 = p1->next;
      }
      prev = prev->next;
    }
  } 
}

void print_list(list* head){
  int count = 0;
  list* node = head->next;
  while (node!=NULL){
    printf("%d ", node->num);
    count++;
    if (count % 20 == 0)
      printf("\n");
    node = node->next;
  }
}

int main(void){
  int random_arr[100];
  srand(time(NULL));

  randomize_array(random_arr, 100);
  
  list* head = convert_array(random_arr, 100);
  
  sort_linked_list(head, 100);

  print_list(head);

  return 0;
}
