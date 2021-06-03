#include <stdio.h>
#include <stdlib.h>
#define MAX_NODE_NUM 10000

typedef int element;
typedef struct tree {
	element key;
	struct tree *left, *right;
}tree;

tree *new_node(int item) {
	tree *temp = (tree *)malloc(sizeof(tree));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

tree *insert_node(tree *node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

tree *order(tree *node, int key[], int count) {
	node = insert_node(node, key[0]);

	for (int i = 1; i < count; i++)
	{
		if (node->key > key[i])
			node->left = insert_node(node->left, key[i]);
		else if (node->key < key[i])
			node->right = insert_node(node->right, key[i]);
	}

	return node;
}

void preorder(tree *node) {
	if (node != NULL) {
		preorder(node->left);
		preorder(node->right);
		printf("%d\n", node->key);
	}
}

int main() {
	int key_num[MAX_NODE_NUM];
	int count = 0;
	int node_num = 0;
	tree *node = NULL;

	scanf_s("%d", &count);

	for (int m = 0; m < count; m++)
	{
		scanf_s(" %d", &key_num[m]);
	}

	node = order(node, key_num,count );

	preorder(node);

	return 0;
}