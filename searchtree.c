#include <stdio.h>
#include <stdlib.h>


/*
Defines the functions for 


*/


// defines the the structure to create the node and refers to it as NODE
typedef struct node_struct {
  int value;
  struct node_struct *left, *right;
} NODE;


// allocates memory and corresponding fields for the NODE structure
NODE* new_node(int value) {
  NODE* n = (NODE*) malloc(sizeof(NODE));
  n->value = value;
  n->left = n->right = 0;
  return n;
}



void insert1(NODE* p,int value) {
  if (value < p->value) {
    if (p->left == 0)
      p->left = new_node(value);
    else
      insert1(p->left,value);
  }else if (value > p->value) {
    if (p->right == 0) 
      p->right = new_node(value);
    else
      insert1(p->right,value);
  }
}
  
 
NODE* insert(NODE* root,int value) {
  if (root  == 0) {
    root = new_node(value);
    return root;
  }
  insert1(root,value);
  return root;
}


void PreOrder1(NODE* p) {
  printf("%d ",p->value);
  if (p->left) PreOrder1(p->left);
  if (p->right) PreOrder1(p->right);
}

void PreOrder(NODE* root) {
  if (root == 0) {
    printf("empty tree\n");
    return;
  }
  PreOrder1(root);
  printf("\n");
}

void InOrder1(NODE* p) {
  if (p->left) InOrder1(p->left);
  printf("%d ",p->value);
  if (p->right) InOrder1(p->right);
}

void InOrder(NODE* root) {
  if (root == 0) {
    printf("empty tree\n");
    return;
  }
  InOrder1(root);
  printf("\n");
}

void PostOrder1(NODE* p) {
  if (p->left) PostOrder1(p->left);
  if (p->right) PostOrder1(p->right);
  printf("%d ",p->value);
}

void PostOrder(NODE* root) {
  if (root == 0) {
    printf("empty tree\n");
    return;
  }
  PostOrder1(root);
  printf("\n");
}

int main() {
  int n;
  char buf[500];
  NODE* root = 0;

  while(1) {
    printf("enter positive integer or 'quit': ");
    scanf("%s",buf);
    if (strcmp(buf,"quit") == 0) break;
    sscanf(buf,"%d",&n);
    root = insert(root,n);
  }

  printf("in-order traversal:\n");
  InOrder(root);  
  printf("pre-order traversal:\n");
  PreOrder(root);  
  printf("post-order traversal:\n");
  PostOrder(root);  
  return 0;
}