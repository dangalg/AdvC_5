#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>
#include <stdlib.h>

void insert(TreeNode* root, int value);
void inOrder(TreeNode* root);
int reversedInOrder(TreeNode* root, int n, int* x);
void freeTree(TreeNode* root);
TreeNode* createNode();
int checkleafHeight(TreeNode* root, int n, int* x);

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
		inOrder(bst->root);
	}
	else
	{
		printf("The tree is empty");
	}
}

void inOrder(TreeNode* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("%d", root->element);
		inOrder(root->right);
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
	reversedInOrder(bst->root, N-1, &x);
	return x;
}

int sameHeightLeaves(BST* bst)
{
	int x = -1;
	int n = 0;
	checkleafHeight(bst->root, n, &x);
	return x;
}

int checkleafHeight(TreeNode* root, int n, int* x)
{
	if (root != NULL)
	{
		// found leaf, set x to leaf height
		if (root->left == NULL && root->right == NULL)
		{

			return n;
		}
		n = checkleafHeight(root->left, n + 1, x);
		n = checkleafHeight(root->right, n + 1, x);
	}
}

int reversedInOrder(TreeNode* root, int n, int* x)
{
	if (root != NULL)
	{
		n = reversedInOrder(root->right, n, x);
		// first time null after largest number
		if (n == 0)
		{
			*x = root->element;
		}
		n = reversedInOrder(root->left, n-1, x);
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

	if (root->left == NULL && root->right == NULL)
	{
		free(root);
		root = NULL;
		return;
	}

	freeTree(root->left);
	if (root->left != NULL)
	{
		root->left = NULL;
	}
	freeTree(root->right);
	if (root->right != NULL)
	{
		root->right = NULL;
	}

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
