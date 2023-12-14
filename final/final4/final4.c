#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct tree
{
	char name[10];
	int pair;
	struct tree* left;
	struct tree* right;

};
struct tree* find(struct tree* root, const char name[]) {
	if (root) {
		if (strcmp(root->name, name) == 0)
			return root;
		else {
			struct tree* foundLeft = find(root->left, name);
			if (foundLeft)
				return foundLeft;

			return find(root->right, name);
		}
	}
	return NULL;
}

struct tree* create(struct tree* Tree,char child[],int pair)
{
	Tree = malloc(sizeof(struct tree));
	strcpy(Tree->name, child);
	Tree->pair = pair + 1;
	Tree->left = NULL;
	Tree->right = NULL;
	return Tree;
}

struct tree* findsame(struct tree *root, struct tree* N1,struct tree* N2)
{
	if (root == NULL || root == N1 || root == N2)
	{
		return root;
	}
	struct tree* L = findsame(root->left, N1, N2);
	struct tree* R = findsame(root->right, N1, N2);

	if (L && R)
	{
		return root;
	}

	return L != NULL? L:R;

}

int main()
{
	int n = 0;
	scanf("%d", &n);
	struct tree *Tree = NULL;
	struct tree* root=NULL;
	char parent[10], child[10];

	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", parent,child);
		if (Tree==NULL)
		{
			Tree = malloc(sizeof(struct tree));
			Tree->left = NULL;
			Tree->right = NULL;
			Tree->pair = 1;
			strcpy(Tree->name, parent);
			root = Tree;
			Tree->left=create(Tree->left, child, Tree->pair);
		}
		else
		{
			Tree = find(root, parent);
			if (Tree->left)
			{
				Tree->right = create(Tree->right, child, Tree->pair);
			}
			else
			{
				Tree->left = create(Tree->left, child, Tree->pair);
			}
		}
	}
	
	while(1)
	{
		scanf("%s %s", parent,child);
		struct tree* L = find(root, parent);
		struct tree* R = find(root, child);

		struct tree* findroot = findsame(root, L, R);

		printf("%d\n", (  L->pair-findroot->pair) + ( R->pair-findroot->pair ));
	}

}
