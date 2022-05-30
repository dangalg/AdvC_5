#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>
#include <stdlib.h>

void insert(TreeNode* root, int value);
void inorder(TreeNode* root);
int reversedinorder(TreeNode* root, int n, int* x);
void freeTree(TreeNode* root);
TreeNode* createNode();

void initBST(BST* bst)
{
	bst->root = NULL;
}

void insertBST(BST* bst, int value)
{
	if (bst->root == NULL)
	{
		bst->root = createNode();
		bst->root->element = value;
	}
	else
	{
		insert(bst->root, value);
	}
}

void insert(TreeNode* root, int value)
{
	if (value <= root->element)
	{
		//left subtree (<=)
		if (root->left == NULL) {
			root->left = createNode();
			root->left->element = value;
		}
		else
		{
			insert(root->left, value);
		}
	}
			
	if (value > root->element) 
	{
		//right subtree (>)
		if (root->right == NULL) 
		{
			root->right = createNode();
			root->right->element = value;
		}
		else
		{
			insert(root->right, value);
		}
	}
			
}

void printTreeInorder(BST* bst)
{
	if (bst->root != NULL)
	{
		inorder(bst->root);
	}
	else
	{
		printf("The tree is empty");
	}
}

void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d", root->element);
		inorder(root->right);
	}
}

void destroyBST(BST* bst)
{
	if (bst->root == NULL)
	{
		return;
	}

	freeTree(bst->root);
}

int findIndexNFromLast(BST* bst, int N) 
{
	int x;
	reversedinorder(bst->root, N-1, &x);
	return x;
}

int reversedinorder(TreeNode* root, int n, int* x)
{
	if (root != NULL)
	{
		n = reversedinorder(root->right, n, x);
		// first time null after largest number
		if (n == 0)
		{
			*x = root->element;
		}
		n = reversedinorder(root->left, n-1, x);
		if (n == 0)
		{
			*x = root->element;
		}
	}

	return n;
}

void freeTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	freeTree(root->left);

	if (root->left == NULL && root->right == NULL)
	{
		free(root);
		root = NULL;
		return;
	}

	freeTree(root->right);

	if (root->left == NULL && root->right == NULL)
	{
		free(root);
		root = NULL;
		return;
	}

}

TreeNode* createNode() {
	TreeNode* temp;
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	CHECKNULL(&temp);
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
