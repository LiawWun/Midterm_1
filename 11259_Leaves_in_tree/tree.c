#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define KEYS 8

struct treenode{
  int data;
  struct treenode *left;
  struct treenode *right;
};

typedef struct treenode TreeNode;

TreeNode *genTreeNode(int data, TreeNode *left, TreeNode *right);
TreeNode *insertBsTree(TreeNode *root, int data);
void freeTree(TreeNode *root);
void preorderBsTree(TreeNode *root);

int countLeaf(TreeNode *root){
  if(root->left == NULL && root->right == NULL){
    return 1;
  }
  int left_leaf = 0, right_leaf = 0;
  if (root->left != NULL) left_leaf = countLeaf(root->left);
  if (root->right != NULL) right_leaf = countLeaf(root->right);
  return left_leaf + right_leaf;
}

int height(TreeNode *root){
  if(root == NULL){
    return 0;
  }
  else{
    int left_height = height(root->left);
    int right_height = height(root->right);
    return left_height > right_height ? left_height + 1 : right_height + 1;
  }
}

void printlevel(TreeNode *root, int level){
  if (root == NULL){
    return;
  }
  else if (level == 1){
    printf("%d ", root->data);
  }
  else{
    printlevel(root->left, level - 1);
    printlevel(root->right, level - 1);
  }
}

void Print(TreeNode *root){
  if (root == NULL){
    printf("\n");
    return;
  }
  int level = height(root);
  for (int i = 1; i <= level; i ++){
    printlevel(root, i);
  }
  printf("\n");
}

int main(){
  TreeNode *root = NULL;
  int data;
  for (int i = 0; i < KEYS; i++){
    scanf("%d", &data);
    root = insertBsTree(root, data);
  }
  printf("Preorder\n");
  preorderBsTree(root);
  printf("Leaves number: %d\n", countLeaf(root));
  printf("Height : %d\n", height(root));
  Print(root);
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

void preorderBsTree(TreeNode *root){
  if (root == NULL) return;
  printf("data = %d\n", root->data);
  preorderBsTree(root->left);
  preorderBsTree(root->right);
  return;
}