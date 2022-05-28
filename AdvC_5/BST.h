#ifndef _BST_ADT_H
#define _BST_ADT_H

#define CHECKNULL(param) ((*param == NULL) ? 1 : 0)

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