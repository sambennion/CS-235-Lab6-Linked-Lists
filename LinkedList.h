
#pragma once
#include <string>
#include <sstream>
#include "LinkedListInterface.h"
using namespace std;

template<class T>
class LinkedList: public LinkedListInterface<T>
{
private:
	struct Node {
		T data;
		Node* next;
		Node(const T& the_data, Node* next_val = NULL):
		data(the_data){next = next_val;
		}
	};
	Node *myList;
	int num_items = 0;
	bool isInList(T value){
			for(Node *ptr = myList; 	ptr != NULL; ptr = ptr->next){
				if(value == ptr->data){
					return true;
				}
			}
			return false;
		};
public:

	LinkedList(void) {
		//cout << "In constructor" << endl;
		myList = NULL;
		num_items = 0;
	};
	virtual ~LinkedList(void) {
		//cout << "In destructor" << endl;
		//while(myList != NULL){
			//Node *current = myList;
	//		myList = myList->next;
		//	delete current;
			clear();
		//}
		//myList = NULL;
		delete myList;
	};
	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString(){
		//cout << "In toString" << endl;
		stringstream ss;
		for(Node *ptr = myList; ptr != NULL; ptr = ptr->next){
			ss << ptr->data << " ";
		}
		cout << ss.str();
		return ss.str().substr(0, ss.str().length()-1);
		}

	
	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value){
		if(isInList(value)){
			return;
		}
		//cout << "In insertHead" << endl;
		Node *ptr = myList;
		myList = new Node(value);
		myList->next = ptr;
		num_items++;
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value){
		if(isInList(value)){
			return;
		}
		cout << "In insertTail" << endl;
		Node *ptr = myList;
		if(myList == NULL){
			 myList = new Node(value, NULL);
		} else{
			while(ptr != NULL){
				cout << ptr << " data " << ptr->data << " next " << ptr->next << endl;
				if(ptr->next == NULL){
					ptr->next = new Node(value, NULL);
					break;
				} else{
					ptr = ptr->next;
				}
			}
		}
		num_items++;
		toString();
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode){
		if(isInList(value)){
			return;
		}
		Node *newNode = new Node(value, NULL);
		for(Node *ptr = myList; ptr != NULL; ptr = ptr->next){
			if(ptr->data == insertionNode){
				newNode->next = ptr->next;
				ptr->next = newNode;
				num_items++;
				return;
			}
		}
		//int index =
		/*
		cout << "In insertAfter" << endl;
		if(index >= num_items) {
			throw std::out_of_range("insertAt Error");
		}
		Node *newnode = new Node(value,NULL);
		if(index == 0) {
			newnode->next = myList;
			myList = newnode;
		} else {
			Node *ptr = myList;
			for(int i = 0; i <= index; i++) {
		  		if(i == (index-1)) { // Insert after this
		  			newnode->next = ptr->next;
		  			ptr->next = newnode;
		  			num_items++;
		  		} else {
		  			ptr = ptr->next;
		  		}
			}
		}
		*/
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value){

		//cout << "In remove" << endl;
		if(!isInList(value)){
			//throw std::out_of_range("At Error");
			return;
		}
		if(myList->data == value){
			Node *ptr = myList;
			myList = myList->next;
			delete ptr;
			num_items--;
		}
		else{
			for(Node *ptr = myList; ptr != NULL; ptr = ptr->next){
			if(ptr->next->data == value){
					Node* tempPtr = ptr->next;
					ptr->next = ptr->next->next;

					delete tempPtr;
					num_items--;
					break;
				} /*else if(ptr->data == value){ //in case it's the first element of the list

					myList = myList->next;
					delete ptr;
					num_items--;
				}*/
			}
		}
		toString();
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear(){
		cout << "In clear" << endl;
		for(Node *ptr = myList; ptr != NULL; ptr = myList){
				myList = myList->next;
				delete ptr;
				num_items--;
			}
			delete myList;
		}
	

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index){
		cout << "In at" << endl;
		toString();
		if(index >= num_items || index < 0) {
			throw std::out_of_range("At Error");
		} else {
			Node *ptr = myList;
			for(int i = 0; i <= index; i++) {
				cout << "["<<i<<"]="<<ptr->data<<endl;
		  		if(i == (index)) { 
		  			return(ptr->data);
		  		}else {
		  			ptr = ptr->next;
		  		}
			}
		}
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size(){
		cout << "In size" << endl;
		return num_items;
	}

	
	
};