#ifndef _GUARD_BINARY_TREE_H
#define _GUARD_BINARY_TREE_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
	void* dataPtr;
	struct node* left;
	struct node* right;
} NODE;

typedef struct {
	int count;
	int (*compare)(void* argu1, void *argu2);
	NODE* root;
} BST_TREE;

BST_TREE* BST_create(int(*compare)(void* argu1, void* argu2));
BST_TREE* BST_destroy(BST_TREE* tree);

bool BST_Insert(BST_TREE* tree, void* dataPtr);
bool BST_Delete(BST_TREE* tree, void* dltKey);
void* BST_Retrieve(BST_TREE* tree, void* keyPtr);
void BST_Traverse(BST_TREE* tree, void(*process)(void* dataPtr));

bool BST_Empty(BST_TREE* tree);
bool BST_full(BST_TREE* tree);
int BST_count(BST_TREE* tree);

static NODE* _insert(BST_TREE* tree, NODE* root, NODE* newPtr);
static NODE* _delete(BST_TREE* tree, NODE* root, void* dataPtr, bool* success);
static void* _retrieve(BST_TREE* tree, void* dataPtr, NODE* root);
static void _traverse(NODE* root, void(*process)(void* dataPtr));
static void _destroy(NODE* root);

#endif