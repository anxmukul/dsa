#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
node *insert(node *r, int v)
{
	if (r == NULL)
	{
		node *cur = new node();
		cur->data = v;
		cur->left = NULL;
		cur->right = NULL;
	}
	else if (r->data < v)
	{
		r->right = insert(r->right, v);
		return r;
	}
	else if (r->data > v)
	{
		r->left = insert(r->left, v);
		return r;
	}
}
void display_preorder(node *r)
{
	if (r != NULL)
	{
		printf("%d ", r->data);
		display_preorder(r->left);
		display_preorder(r->right);
	}
}
node * maxValue(node *root)
{
	node *current = root;
	while (current->right != NULL)
		current = current->right;

	return (current);
}
node *deleteNode(node *root, int key)
{
	if (root == NULL)
	{
		return root;
	}

	if (root->data > key)
		root->left = deleteNode(root->left, key);
	else if (root->data < key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			node *temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			node *leftSubTreeMax = maxValue(root->left);
			root->data = leftSubTreeMax->data;
			root->left = deleteNode(root->left, leftSubTreeMax->data);
		}
		return root;
	}
	return root;
}

int main()
{
	node *root = NULL;
	int r, k;
	cout << "Inter root node\n";
	cin >> r;
	root = insert(root, r);
	int n;
	cout << "Enter Number of element in binary_search_tree\n";
	cin >> n;
	cout << "Enter elements one by one\n";
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		root = insert(root, temp);
	}
	cout << "Ente key value\n";
	cin >> k;
	display_preorder(deleteNode(root, k));
	cout << endl;
	return 0;
}