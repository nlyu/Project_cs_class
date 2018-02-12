#include "linkedlist.h"

void intersection(LinkedList* lst1,
           LinkedList* lst2,
           LinkedList &intersect)
{
	LinkedList* lst2,
           LinkedList &intersect){
	Node *c1 = lst1->head;
	Node *c2 = lst2->head;
	Node *c3 = intersect.head;
	if(c1 == NULL || c2 == NULL){
		return;
	}

	while(c1 != NULL && c2 != NULL){
		if(c1->data == c2->data){
			Node *temp = new Node(c1->data);
			c3 = temp;
			c3 = c3->next;
			c1 = c1->next;
			c2 = c2->next;
		}
		if(c1->data > c2->data){
			c2 = c2->next;
		}
		if(c1->data < c2->data){
			c1 = c1->next;
		}		
	}

	return;
}
