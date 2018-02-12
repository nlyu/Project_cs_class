#include "common.h"
#include "quadtree.h"

#include <iostream>
#include <algorithm>

/*
	The algorithm library is included if needed, for the function:
	max: returns the largest of the values passed as arguments.
*/

using namespace std;

int Quadtree::tallyDeviants(RGBAPixel const & target, 
    QuadtreeNode const * curNode, int tolerance) const {
    //YOUR CODE HERE
	if(curNode == NULL)	return 0;
	if(curNode->neChild == NULL){
		//calculate
		int dis = maxDev(target, curNode);
		if(dis > tolerance)	return 1;
		return 0;
	}
    return tallyDeviants(target, curNode->nwChild, tolerance) + tallyDeviants(target, curNode->neChild, tolerance) + tallyDeviants(target, curNode->swChild, tolerance) + tallyDeviants(target, curNode->seChild, tolerance);
}

void Quadtree::prunish(int tolerance, double percent) {
    //YOUR CODE HERE
	if(tolerance < 0 || percent < 0)	return;
	prunish(root, tolerance, resolution, percent);
} 

void Quadtree::prunish(QuadtreeNode * curNode, int tolerance, int res, double percent) {
    //YOUR CODE HERE
	if(curNode == NULL)	return;
	int prun = tallyDeviants(curNode->element, curNode, tolerance);
	double ratio = ((double)res*res - (double)prun)/(double)(res*res);
	cout<<res*res<<" prun: "<<prun<<" percent: "<<percent<<" ratio: "<<ratio<<endl;
	//double ratio = (res*res - prun)/(res*res);
	if(ratio >= percent){
		cout<<ratio<<endl;
		clear(curNode->neChild);
		clear(curNode->nwChild);
		clear(curNode->seChild);
		clear(curNode->swChild);
		curNode->neChild = NULL;
		curNode->nwChild = NULL;
		curNode->seChild = NULL;
		curNode->swChild = NULL;	
	}
	prunish(curNode->neChild, tolerance, res/2, percent);
	prunish(curNode->nwChild, tolerance, res/2, percent);
	prunish(curNode->seChild, tolerance, res/2, percent);
	prunish(curNode->swChild, tolerance, res/2, percent);
	return;
}
