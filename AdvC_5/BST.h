#ifndef _BST_ADT_H
#define _BST_ADT_H

#define CHECKNULL(param) if (*(param) == NULL){ printf("memory allocation failed!"); exit(1);}

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;

#endif // !_BST_ADT_H

void initBST(BST* bst);
void insertBST(BST* bst, int value);
void printTreeInorder(BST* bst);
void destroyBST(BST* bst);
