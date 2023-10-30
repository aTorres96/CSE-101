#include "billheader.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Default constructor for LinkedList
LinkedList :: LinkedList()
{
    head = NULL;
}
/*Check if word is already present, if so increment
its frequency. If not insert it into the list.*/
void LinkedList :: insert(string word)
{
		Node *curr = head;
    while(curr != NULL){
			if (curr->data == word){
				curr->freq++;
				return;
			}
			curr = curr->next;
		}
		Node *new_word = new Node;
    new_word->data = word;
		new_word->freq = 1;
    new_word->next = head;
    head = new_word;
}
//return length of linked list
int LinkedList :: length()
{
	int length = 0;
	Node *curr = head;

	while(curr != NULL){
		length++;
		curr = curr->next;
	}
	return length;
}

string LinkedList :: print()
{
	string list_str = print(head);
	if (list_str.length() > 0)
		list_str.pop_back();
	return list_str;
}

string LinkedList :: print(Node* curr)
{
	if(curr == NULL)
		return "";
	return curr->data + " " + print(curr->next);
}

void LinkedList :: deleteList()
{
	deleteList(head);
}

void LinkedList :: deleteList(Node *curr)
{
	if (curr == NULL)
			return;
	Node *nextNode = curr->next;
	delete(curr);
	deleteList(nextNode);
}
/*Get the node in the list  of rank k*/
string LinkedList :: getk(int k)
{
	Node *curr = head;
	int c = 0;
	while(curr != NULL)
	{
		if (c >= k) // Break if the node is found
			break;
		c++;							
		curr = curr->next; // Continue to the next node
	}
	if (curr == NULL){ // if no node is found return "-"
		return "-";
	}
	return curr->data;
}
/*Sort the list by increasing frequency and decreasing lexographic order.*/
void LinkedList :: bubsort() 
{														
	Node* curr = NULL; 
	int listLength = length(); //Length of list
	int swapped;

	for(int i = 0; i <= listLength; i++){
		curr = head; //set the current node position to the head of the list
		swapped = 0; //set swapped to 0

		for(int j = 0; j < listLength - i - 1; j++){
			Node* left = curr; 
			Node* right = curr->next; 
			int leftFreq = left->freq;
			int rightFreq = right->freq;

			if(leftFreq > rightFreq){ // compare frequencies of left and right nodes
					swap(left, right); // swap to arrange order
					swapped = 1;
			}
			else if (leftFreq == rightFreq){ // order the nodes lexographically if 
				if (left->data < right->data){ // the frequencies of the nodes are equal
					swap(left, right); // swap to arrange order
					swapped = 1;
				}
			}
			curr = curr->next;
		}
		if (swapped == 0) 
			break;
	}
}
/*Swaps the words and frequencies of the nodes*/
void LinkedList :: swap(Node*& left, Node*& right){
	string temps = right->data;
	right->data = left->data;
	left->data = temps;
	int tempf = right->freq;
	right->freq = left->freq;
	left->freq = tempf;
}

/* Reverses the LinkedList. */
void LinkedList :: reverseList()
{
	Node* curr = head;
	Node* prev = NULL;
	Node* temp = NULL;
	while(curr != NULL){
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
}