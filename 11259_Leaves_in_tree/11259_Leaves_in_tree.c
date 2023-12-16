#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define KEYS 10

struct treenode{
  int data;
  struct treenode *left;
  struct treenode *right;
};

typedef struct treenode TreeNode;
TreeNode *genTreeNode(int data, TreeNode *left, TreeNode *right);
TreeNode *insertBsTree(TreeNode *root, int data);
void freeTree(TreeNode *root);

int countLeaf(TreeNode *root){
  if(root->left == NULL && root->right == NULL){
    return 1;
  }
  int left_leaf = 0, right_leaf = 0;
  if (root->left != NULL) left_leaf = countLeaf(root->left);
  if (root->right != NULL) right_leaf = countLeaf(root->right);
  return left_leaf + right_leaf;
}

int main(){
  TreeNode *root = NULL;
  int data;
  for (int i = 0; i < KEYS; i++){
    scanf("%d", &data);
    root = insertBsTree(root, data);
  }
  printf("%d\n", countLeaf(root));
  freeTree(root);
  return 0;
}

TreeNode *genTreeNode(int data, TreeNode *left, TreeNode *right){
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  assert(node != NULL);
  node->data = data;
  node->left = left;
  node->right = right;
  return node;
}

TreeNode *insertBsTree(TreeNode *root, int data){
  struct treenode *current;
  if (root == NULL)
    return genTreeNode(data, NULL, NULL);
  if (data < root->data)
    root->left = insertBsTree(root->left, data);
  else
    root->right = insertBsTree(root->right, data);
  return root;
}

void freeTree(TreeNode *root){
  if (root == NULL)
    return;
  else{
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}