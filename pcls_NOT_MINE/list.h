#ifndef list_akjerb
#define list_akjerb
#include <stdlib.h>

typedef struct node{
  struct node* n;
  void* d;
}node;

node* Add(node* root, void* value);//Adds value to front
node* FreeNodes(node* root);//Frees the nodes
node* FreeData(node* root);//Frees data and nodes

node* Add(node* root, void* value){
  node* r = malloc(sizeof(node));
  r->d = value;
  r->n = root;
  return r;
}

node* FreeNodes(node* root){
  node* next;
  while(root){
    next = root->n;
    free(root);
    root = next;
  }
  return 0;
}

node* FreeData(node* root){
  node* next;
  while(root){
    next = root->n;
    free(root->d);
    free(root);
    root = next;
  }
  return 0;
}

#endif