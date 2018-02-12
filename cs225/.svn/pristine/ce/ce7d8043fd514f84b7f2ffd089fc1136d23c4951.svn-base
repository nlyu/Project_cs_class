#include "common.h"
#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

void updateMax(Node<int> *&root)
{
	// YOUR CODE HERE!
	int left_v, right_v;
	if(root == NULL){
		return;
		}
	updateMax(root->left);
	updateMax(root->right);
	if(root->left == NULL && root->right == NULL){
		return;
	}
	if(root->left == NULL && root->right != NULL){
		left_v = 0;
		right_v = root->right->data;
	}
	if(root->left != NULL && root->right == NULL){
		left_v = root->left->data;
		right_v = 0;
	}
	if(root->left != NULL && root->right != NULL){
		left_v = root->left->data;
		right_v = root->right->data;
	}
	
	if(left_v > right_v){
		root->data += left_v;
	}
	else{
		root->data += right_v;
	}
	
	return;
}
