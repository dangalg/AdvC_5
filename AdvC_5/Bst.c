#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>
#include <stdlib.h>

void initBST(BST* bst)
{
	bst->root = NULL;
}

void insertBST(BST* bst, int value)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	CHECKNULL(&newNode);
	newNode->element = value;
	insert(bst->root, newNode);
}

void insert(TreeNode* root, TreeNode* newNode)
{
	if (newNode->element <= root->element) //left subtree (<=)
		if (root->left == NULL)
			root->left = newNode;
		else
			insert(root->left, newNode);
	if (newNode->element > root->element) //right subtree (>)
		if (root->right == NULL)
			root->right = newNode;
		else
			insert(root->right, newNode);
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
		printf("", root->element);
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

void freeTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	if (root->left == NULL && root->right == NULL)
	{
		free(root);
		return;
	}

	freeTree(root->left);
	freeTree(root->right);
}



TreeNode* createNode() {
	TreeNode* temp;
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->left = NULL; /// could use calloc instead
	temp->right = NULL; /// could use calloc instead
	return temp;
}