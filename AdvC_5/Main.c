#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> //uncomment this block to check for heap memory allocation leaks.

void main()
{
	BST bst;
	initBST(&bst);
	insertBST(&bst, 5);
	insertBST(&bst, 2);
	insertBST(&bst, 4);
	insertBST(&bst, 1);
	insertBST(&bst, 8);
	insertBST(&bst, 9);
	insertBST(&bst, 10);
	insertBST(&bst, 11);

	print_ascii_tree(bst.root);

	printf("\n\n");
	printTreeInorder(&bst);
	printf("\n");
	printf("\n%d\n",findIndexNFromLast(&bst, 3));

	printf("\n");
	int res = sameHeightLeaves(&bst);
	if (res)
	{
		printf("The leaves are the same height");
	}
	else
	{
		printf("The leaves are not the same height");
	}
	printf("\n");

	destroyBST(&bst);

	_CrtDumpMemoryLeaks(); //uncomment this block to check for heap memory allocation leaks.
}