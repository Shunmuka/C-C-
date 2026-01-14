#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
  int data;
  struct treeNode *left;
  struct treeNode *right;
} treeNode;

void file_to_array(FILE *fptr, int arr[], int size){
  for(int i = 0; i < size; i++){
    fscanf(fptr, "%d", &arr[i]);
  }
}

treeNode* init_node(int d, treeNode *p1, treeNode *p2){
  treeNode *node = malloc(sizeof(treeNode));
  node->data = d;
  node->left = p1;
  node->right = p2;

  return node;
}

treeNode* create_tree(int arr[], int i, int size){
  if (i >= size){
    return NULL;
  }
  else {
    return init_node(arr[i], create_tree(arr, i * 2 + 1, size), create_tree(arr, i * 2 + 2, size));
  }
}

void inorder(treeNode *root){
  if (root == NULL){
    return;
  }
  else{
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main(int argc, char *argv[]){
  FILE *ifp;
  ifp = fopen(argv[1], "r");
  int size; 
  fscanf(ifp, "%d", &size);
  int bin_values[size];

  file_to_array(ifp, bin_values, size);


  treeNode *r_ptr = create_tree(bin_values, 0, size);

  inorder(r_ptr);

  return 0;


}
