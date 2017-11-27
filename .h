#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "stdafx.h" 

using namespace std;

template <class T> class MagicBag
{
public:

	class Node {
	public:
		T item;
		Node *next;

		Node() {
			next = nullptr;
		}
	};



	MagicBag() {
		number = 0;
		head = nullptr;
	}

	MagicBag(const MagicBag& copied) {
		number = copied.number;
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
	// I THINK THIS MAY WORK!?
	MagicBag% operator=(const MagicBag& other) {
		number = other.number;
		Node *current;

		if (other.head) {
			current = copied.head;
			while (current) {
				insert(current->item);
				current = current->next;
			}
		}
		return *this;
	}

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
			current = newNode;
		}
	}

	T draw() {
		if (number < 1) {
			cout << "There are not any items in the bag" << endl;
			throw;
		}

		Node *current = head;
		Node *previous = head;
		srand((unsigned int)time(NULL));
		int ranNumber = rand() % number + 1;

		if (ranNumber == 1) {
			T = current->item;
			delete current;
			head = nullptr;
			return T;
		}

		int x = 1;
		while (x < ranNumber) {
			current = current->next;
			if (x < ranNumber - 1) {
				previous = previous->next;
			}
			x++;
		}
		T = current->item;
		if (current->next) {
			previous->next = current->next;
		}
		else {
			previous->next = nullptr;
		}
		delete current;
		return T;



		/**
		if (ranNumber == 1) {
		T = current->item;
		head = current->next;
		delete current;
		return T;
		}
		else if (ranNumber == 2) {
		current = current->next;
		T = current->item;
		delete current;
		head->next = nullptr;
		return T;
		}
		else if (ranNumber = number) {
		previous = current;
		for (int i = 0; i < ranNumber - 1; i++) {
		current = current->next;
		if (i < ranNumber - 2) {
		previous = previous->next;
		}
		}
		T = current->item;
		delete current;
		previous->next = nullptr;
		return T;
		}
		else {
		previous = current;
		for (int i = 0; i < ranNumber - 1; i++) {
		current = current->next;
		if (i < ranNumber - 2) {
		previous = previous->next;
		}
		}
		T = current->item;
		previous->next = current->next;
		delete current;
		return T;
		}
		*/

	}

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

	void print(cout) const {
		Node *current = head;
		cout << "Number of items: " << number << endl;
		if (number > 0) {
			cout << "Items: [" << current->item << ;
			current = current->next;
			while (current) {
				cout << ", " << current->item << ;
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
	friend ostream& operator<<(ostream& os, const MagicBag& mb) {
	}
};
