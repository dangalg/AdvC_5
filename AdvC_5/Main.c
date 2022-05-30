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

	//print_ascii_tree(&bst);
	//printTreeInorder(&bst);
	printf("\n%d\n",findIndexNFromLast(&bst, 3));

	destroyBST(&bst);

	_CrtDumpMemoryLeaks(); //uncomment this block to check for heap memory allocation leaks.
}