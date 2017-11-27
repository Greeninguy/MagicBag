#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "stdafx.h" 

using namespace std;
/*
Class MagicBag is a data storage for holding different data types.  A bag of any particular type can be made, and the items of
the bags can be drawn opon randomly.  Contents of the bag can be checked for.
*/
template <class T> class MagicBag
{
public:
	/*
	MagicBag item contents are stored into a linked list of nodes.
	*/
	class Node {
	public:
		T item;
		Node *next;

		Node() {
			next = nullptr;
		}
	};

	/*
	Default constructor for MagicBag initiates a bag of type T with no items inside.
	*/
	MagicBag() {
		number = 0;
		head = nullptr;
	}

	/*
	MagicBag copy constructor creates a duplicate bag with the same data type and the same contents
	Input Paramaters: MagicBag& -  Reference to the MagicBag to be copied
	*/
	MagicBag(const MagicBag& copied) {
		Node *current;

		if (other.head) {
			current = copied.head;
		}
		else {
			while (current) {
				insert(current->item);
				current = current->next;
			}
		}
	}

	/*
	Override operator for the '=' which functions as another way to copy a MagicBag
	Input Parameters: MagicBag& -  Reference to MagicBag to be copied.
	Output: MagicBag& -  A reference to the new duplicate MagicBag
	*/
	MagicBag& operator=(const MagicBag& other) {
		Node *current;

		if (other.head) {
			current = other.head;
			while (current) {
				insert(current->item);
				current = current->next;
			}
		}
		number = other.number;
		return *this;
	}

	/*
	Deconstructor for the MagicBag class
	*/
	~MagicBag() {
		Node *current;
		Node *after;

		if (head) {
			current = head;
			after = head->next;
			delete current;

			while (after) {
				current = after;
				after = after->next;
				delete current;
			}
		}
	}

	/*
	Insert member function which puts an item into the bag.  Item is placed at the end of the linked list.
	Input Parameter: T item - An item of type T is placed into the bag
	*/
	void insert(T item) {
		number++;
		Node *newNode;
		Node *current;
		newNode = new Node;
		newNode->item = item;

		if (!head) {
			head = newNode;
		}
		else {
			current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = newNode;
		}
	}

	/*
	Draw function returns an item from the bag.  A random item is selected and removed from the MagicBag.
	Output: T - An item of whichever data type was chosen for the particular bag which is being drawed from.
	*/
	T draw() {
		if (number < 1) {
			cout << "There are not any items in the bag" << endl;
			throw;
		}
		T drawed;
		Node *current = head;
		Node *previous = head;
		srand((unsigned int)time(NULL));
		int ranNumber = rand() % number + 1;

		if (ranNumber == 1) {  //condition for if the item picked is the the first item in the list.  Head must be reassigned
			drawed = current->item;
			if (current->next) {
				head = current->next;
			}
			else {
				head = nullptr;
			}
			delete current;
			number--;
			return drawed;
		}

		int x = 1;
		while (x < ranNumber) { //while loop works up the list towards the randomly selected item
			current = current->next;
			if (x < ranNumber - 1) {
				previous = previous->next;
			}
			x++;
		}
		drawed = current->item;
		if (current->next) {  //makes sure that the node previous to the deleted node points to the next item's node
			previous->next = current->next;
		}
		else {                  //if selected item was the last item of the list, only need to have the previous node point to null
			previous->next = nullptr;
		}
		delete current;
		number--;
		return drawed;
	}

	/*
	Peek member function allows to check if an item is in a bag.
	Input Parameter: T item - Any occurences of this item will be checked for in the linked list.
	Output: int - An integer value is outputed to represent how many occurences of the requested item is in the MagicBag.
	*/
	int peek(T item) {
		int count = 0;
		Node *current = head;
		int x = 0;
		while (x < number) {
			if (current->item == item) {
				count++;
			}
			current = current->next;
			x++;
		}
		return count;
	}

	/*
	Print member function outputs the bag contents as well as the number of items in the bag in an output stream
	Input Parameter: ostream& - A reference to any output stream can be inputed to retrieve bag contents
	*/
	void print(ostream& cout) const {
		Node *current = head;
		cout << "Number of items: " << number << endl;
		if (number > 0) {
			cout << "Items: [" << current->item;
			current = current->next;
			while (current) {
				cout << ", " << current->item;
				current = current->next;
			}
			cout << "]" << endl;
		}
		else {
			cout << "Items: None" << endl;
		}
	}

private:
	int number;
	Node *head;
	//friend ostream& operator<<(ostream& os, const MagicBag& mb) {
	//}
};
