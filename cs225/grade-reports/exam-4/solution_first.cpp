#include "common.h"
#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

Node<int>* findLCA(Node<int> *&root, int val1, int val2)
{
	// YOUR CODE HERE!
	if(root == NULL){
		return NULL;
	}
	if(root->left == NULL && root->right == NULL){
		if(root->data == val1 || root->data == val2)	return root;
		return NULL;
	}
	//cmp
	if(root->data == val1 || root->data == val2){
		return root;
	}
	Node<int> * left, *right;
	left = findLCA(root->left, val1, val2);
	right = findLCA(root->right, val1, val2);
	if((left != NULL && right != NULL)){
		if((left->data = val1 && right->data == val2) || (left->data = val2 && right->data == val1)){
			return root;
		}
	}
	if(left == NULL)	return right;
	if(right == NULL)	return left;
	return NULL;
}
