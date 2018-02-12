#include "linkedlist.h"
#include <iostream>
using namespace std;

bool addAt(LinkedList &mylist, int pos, int newdata)
{
	//check
	if(pos < 0){
		return 0;
	}
	
	int length = 0;
	Node *curr = mylist.head;
	Node *prev = mylist.head;
	Node *my = new Node(newdata);

	if(pos == 0){
		mylist.head = my;
		my->next = curr;
		return 1;
	}
	
	while(curr != NULL){
		if(curr->next == NULL){
			prev = curr;
		}
		length++;
		curr = curr->next;
	}

	if(pos == length){
		prev->next = my;
		my->next = NULL;
		return 1;
	}

	curr = mylist.head;
	prev = mylist.head;
	while(curr != NULL){
		if(pos == 0){
			prev->next = my;
			my->next = curr;
			return 1;
		}
		pos--;
		prev = curr;
		curr = curr->next;		
	}
	return 0;
	return 0;
}
