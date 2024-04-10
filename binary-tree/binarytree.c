#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node *node =(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

void postorder(struct node *node)
{
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	printf(" | %d | ", node->data);
}

void inorder(struct node *node)
{
	if (node == NULL)
		return;
	inorder(node->left);
	printf(" | %d | ", node->data);
	inorder(node->right);
}


void preorder(struct node *node)
{
	if (node == NULL)
		return;
	printf(" | %d | ", node->data);
	preorder(node->left);
	preorder(node->right);
}

void main()
{
	struct node *root = newnode(3);
	root->left = newnode(2);
	root->right = newnode(4);
	root->left->left = newnode(1);
	root->right->right = newnode(5);
	printf("Preorder traversal is :\n");
	preorder(root);
	printf("\nInorder traversal is :\n");
	inorder(root);
	printf("\nPostorder traversal is :\n");
	postorder(root);
	printf("\n");
}

