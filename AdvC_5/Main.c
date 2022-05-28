#define _CRT_SECURE_NO_WARNINGS
#include "BST.h"
#include "TreePrintLibrary.h"
#include <stdio.h>

void main()
{
	char arr[2] = { 'a','b'};
	if (CHECKNULL(arr))
	{
		printf("item is null");
	}
	else
	{
		printf("item is not null");
	}
}