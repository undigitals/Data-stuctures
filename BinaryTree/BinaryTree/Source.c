#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BinaryTree.h"

int compare(void* argu1, void* argu2) {
	int a, b;
	a = *(int*)argu1;
	b = *(int*)argu2;
	if (a < b)
		return (-1);
	else if (a > b)
		return 1;
	else return 0;
}
void print(void* data) {
	int n;
	n = *(int*)data;
	printf(" %d\n", n);
}
int main()
{
	BST_TREE* tree;
	int* data, n;
	tree = BST_create(compare);
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		
		n = rand() % 200 + 1;
		data = (int*)malloc(sizeof(int));
		*data = n;
		BST_Insert(tree, data);
	}
	BST_Traverse(tree, print);

	return 0;
}