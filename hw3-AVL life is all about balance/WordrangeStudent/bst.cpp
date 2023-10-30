#include "bst.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

BST :: BST()
{
  root = NULL;
}

void BST :: insert(string val)
{
  Node *to_insert = new Node(val);
  if (root == NULL)
    root = to_insert;
	else
		insert(root, to_insert);
}

void BST :: insert(Node* start, Node* to_insert)
{
	if (start == NULL)
		return;
	if (to_insert->key <= start->key)
	{
		if(start->left == NULL)
		{
			start->left = to_insert;
			to_insert->parent = start;
			return;
		}
		else
		{
			insert(start->left, to_insert);
			return;
		}
	}
	else
	{
		if(start->right == NULL)
		{
			start->right = to_insert;
			to_insert->parent = start;
			return;
		}
		else
		{
			insert(start->right, to_insert);
			return;
		}
	}
}

Node* BST :: find(string val)
{
	return find(root, val);
}

Node* BST :: find(Node* start, string val)
{
	if (start == NULL || start->key == val)
		return start;
	if(val < start->key)
		return find(start->left, val);
	else
		return find(start->right, val);
}

Node* BST :: maxNode(Node* start)
{
	if(start == NULL)
		return NULL;
	if(start->right == NULL)
		return start;
	else
		return maxNode(start->right);
}

Node* BST :: minNode(Node* start)
{
	if(start == NULL)
		return NULL;
	if(start->left == NULL)
		return start;
	else
		return minNode(start->left);
}

Node* BST :: deleteNode(Node* to_delete)
{
	if(to_delete == NULL)
		return NULL;
	bool isRoot = (to_delete == root) ? true : false;
	bool isLeftChild = false;
	if(!isRoot)
		isLeftChild = (to_delete->parent->left == to_delete) ? true : false;

	bool isDeleted = false;

	if(to_delete->left == NULL)
	{
		if(isRoot)
		{
			root = to_delete->right;
			if(root != NULL)
				root->parent = NULL;
		}
		else
		{
			if(isLeftChild)
				to_delete->parent->left = to_delete->left;
			else
				to_delete->parent->right = to_delete->left;
			if(to_delete->left != NULL)
				to_delete->left->parent = to_delete->parent;
		}
		isDeleted = true;
	}

	if(!isDeleted && to_delete->right == NULL)
	{
		if(isRoot)
		{
			root = to_delete->left;
			if(root != NULL)
				root->parent = NULL;
		}
		else
		{
			if(isLeftChild)
				to_delete->parent->left = to_delete->left;
			else
				to_delete->parent->right = to_delete->left;
			if(to_delete->left != NULL)
				to_delete->left->parent = to_delete->parent;
		}
		isDeleted = true;
	}
	if(isDeleted)
	{
		to_delete->left = to_delete->right = NULL;
		return to_delete;
	}
	Node* succ = minNode(to_delete->right);
	to_delete->key = succ->key;
	return deleteNode(succ);
}

void BST :: deleteBST()
{
	deleteBST(root);
}

void BST :: deleteBST(Node* start)
{
	if(start == NULL)
		return;
	deleteBST(start->left);
	deleteBST(start->right);
	delete(start);
}

string BST :: printInOrder()
{
	return printInOrder(root);
}

string BST :: printPreOrder()
{
	return printPreOrder(root);
}

string BST :: printPostOrder()
{
	return printPostOrder(root);
}

string BST :: printInOrder(Node* start)
{
	if(start == NULL)
		return "";
	string leftpart = printInOrder(start->left);
	string rightpart = printInOrder(start->right);
	string output = start->key;
	if(leftpart.length() != 0)
		output = leftpart + " " + output;
	if(rightpart.length() != 0)
		output = output + " " + rightpart;
	return output;
}

string BST :: printPreOrder(Node* start)
{
	if(start == NULL)
		return "";
	string leftpart = printPreOrder(start->left);
	string rightpart = printPreOrder(start->right);
	string output = start->key;
	if(leftpart.length() != 0)
		output = output + " " + leftpart;
	if(rightpart.length() != 0)
		output = output + " " + rightpart;
	return output;
}

string BST :: printPostOrder(Node* start)
{
	if(start == NULL)
		return "";
	string leftpart = printPostOrder(start->left);
	string rightpart = printPostOrder(start->right);
	string output = start->key;
	if(rightpart.length() != 0)
		output = rightpart + " " + output;
	if(leftpart.length() != 0)
		output = leftpart + " " + output;
	return output;
}

int BST :: range(string word1, string word2)
{
	int c = 0; //The count for the number of words between
						//word1 and word2.
	if(root != NULL)// if the tree is not empty call the recursive 
	{								//function to search the tree and count the words
		range(root, word1, word2, c);// in the range.
	}
	return c; //return the count
}

void BST :: range(Node* start, string word1, string word2, int& c)
{
	if (start == NULL)
		return;
	range(start->left, word1, word2, c); //Recurse through the left child
	range(start->right, word1, word2, c); //Recurse through the right child
	string output = start->key;// check if the word in the current node is between
	if(output >= word1 && output <= word2) // word1 and word2, and increase the count
		c++;																// if it is.
}
