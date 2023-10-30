#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

class Node
{
  public:
    string key;
    Node *left, *right, *parent;

	Node()
    {
      left = right = parent = NULL;
    }

    Node(string val)
    {
      key = val;
      left = right = parent = NULL;
    } 
};

class BST {
	private:
		Node *root;
	public:
		BST();
		void insert(string);
		void insert(Node*, Node*);
		Node* find(string);
		Node* find(Node*, string);
		Node* minNode(Node*);
		Node* maxNode(Node*);
		Node* deleteKey(string);
		Node* deleteNode(Node*);
		void deleteBST();
		void deleteBST(Node* start);
		string printInOrder();
		string printInOrder(Node* start);
		string printPreOrder();
		string printPreOrder(Node* start);
		string printPostOrder();
		string printPostOrder(Node* start);
		int range(string, string);
		void range(Node* start, string, string, int&);
};

#endif