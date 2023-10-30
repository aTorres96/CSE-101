// Filename: billheader.h
#ifndef BILL_H
#define BILL_H

#include <string>

using namespace std;

struct Node // node struct to hold data
{
  int freq = 1;
  string data;
  Node *next;
};

class LinkedList
{
  private:
    Node *head;
  public:
    LinkedList();
    void insert(string); //insert word into linked list if new, or increment existing
    void deleteList(Node*);
    void deleteList();
    void bubsort(); 
    void swap(Node*&, Node*&);
		void reverseList();
    string getk(int);
		int length();
		string print();
		string print (Node*);
};

#endif