/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */
#include "quadtree.h"

 using namespace std;

Quadtree::Quadtree()
{
	root = NULL;
	pic_size = 0;;	
}

Quadtree::Quadtree(const PNG & source, int resolution)
{
	pic_size = resolution;
	buildTree(source, pic_size);
}

Quadtree::Quadtree(Quadtree const & other){
	int depth = 0;
	root = helper_copy(other.root, depth);
	pic_size = sqrt(depth);
}

Quadtree::~Quadtree()
{
	helper_delete(root);
	root = NULL;
}

Quadtree const & Quadtree::operator=(Quadtree const & other){
	int depth = 0;
	helper_delete(root);
	root = helper_copy(other.root, depth);
	pic_size = sqrt(depth);
	return (*this);
}

void Quadtree::buildTree(PNG const & source, int resolution)
{
	cout<<"resolution"<<resolution<<endl;
	root = helper_build(source, 0, 0, resolution);
}

RGBAPixel Quadtree::getPixel(int x, int y) const{
	if(x >= pic_size || y >= pic_size || x < 0 || y < 0 || pic_size == 0){
		return RGBAPixel();
	}
	else{
		return helper_getPixel(root, x, y, pic_size/2, pic_size/2, pic_size);
	}
}

PNG Quadtree::decompress() const{
    cout<<"The size of pic is "<<pic_size<<endl; 
    if (pic_size == 0 || root == NULL)   return PNG();
    PNG result = PNG(pic_size, pic_size);
    for(int i = 0; i < pic_size; i++){
    	for(int j = 0; j < pic_size; j++){
    		*(result(i, j)) = getPixel(i, j);	
    	}
    }
    //helper_decompress(result, root, 0, 0, pic_size);
    return result;
}


Quadtree::QuadtreeNode * Quadtree::helper_build(PNG const & source, int x, int y, int pic_size_p){
	//base case
	if(pic_size_p <= 0) 	return NULL;
	if(pic_size_p == 1){
		QuadtreeNode * cur = new QuadtreeNode();
		cur->nwChild = NULL;
		cur->neChild = NULL;
		cur->swChild = NULL;
		cur->seChild = NULL;
		cur->element = *source(x,y);
		return cur;
	}
	int newsize = pic_size_p/2;

        QuadtreeNode * cur = new QuadtreeNode();
	cur->nwChild = helper_build(source, x, y, newsize);
	cur->neChild = helper_build(source, x + newsize, y, newsize);
	cur->swChild = helper_build(source, x, y + newsize, newsize);
	cur->seChild = helper_build(source, x + newsize, y + newsize, newsize);
	//assign color
	uint8_t sum_r, sum_g, sum_b, sum_a;
	sum_r = cur->nwChild->element.red + cur->neChild->element.red + cur->swChild->element.red + cur->seChild->element.red;
	sum_g = cur->nwChild->element.green + cur->neChild->element.green + cur->swChild->element.green + cur->seChild->element.green;
	sum_b = cur->nwChild->element.blue + cur->neChild->element.blue + cur->swChild->element.blue + cur->seChild->element.blue;
	sum_a = cur->nwChild->element.alpha + cur->neChild->element.alpha + cur->swChild->element.alpha + cur->seChild->element.alpha;
	cur->element.red = sum_r/4;
	cur->element.green = sum_r/4;
	cur->element.blue = sum_g/4;
	cur->element.alpha = sum_a/4;
	return cur;
}

Quadtree::QuadtreeNode * Quadtree::helper_copy(QuadtreeNode const * ancestor, int & depth){
	if(ancestor == NULL){
		return NULL;
	}
	if(ancestor->nwChild == NULL && ancestor->neChild == NULL && ancestor->swChild == NULL && ancestor->seChild == NULL){
		depth++;
	}
    QuadtreeNode * cur = new QuadtreeNode();
    cur->nwChild = helper_copy(ancestor->nwChild, depth);
    cur->neChild = helper_copy(ancestor->neChild, depth);
	cur->swChild = helper_copy(ancestor->swChild, depth);
	cur->seChild = helper_copy(ancestor->seChild, depth);
	cur->element = ancestor->element;
	return cur;
}

void Quadtree::helper_delete(Quadtree::QuadtreeNode *ancestor){
	if(ancestor == NULL){
		return;
	}
	if(ancestor->nwChild == NULL && ancestor->seChild == NULL && ancestor->swChild == NULL && ancestor->neChild == NULL){
		delete ancestor;
		ancestor = NULL;
		return;
		}
	helper_delete(ancestor->nwChild);
        helper_delete(ancestor->neChild);
	helper_delete(ancestor->swChild);
	helper_delete(ancestor->seChild);
	delete ancestor;
	ancestor = NULL;
	return;
}

RGBAPixel Quadtree::helper_getPixel(QuadtreeNode * ancestor, int x, int y, int x_mid, int y_mid, int pic_size_p) const{
	if(ancestor == NULL){
		return RGBAPixel();
		}
	QuadtreeNode * NW = ancestor->nwChild;
	QuadtreeNode * NE = ancestor->neChild;
	QuadtreeNode * SW = ancestor->swChild;
	QuadtreeNode * SE = ancestor->seChild;
	if(NW == NULL || NE == NULL || SW == NULL || SE == NULL){
		return ancestor->element;
	}
	//find pixel
	int newsize = pic_size_p/2;
	if(x < x_mid){
		if(y < y_mid){
			return helper_getPixel(NW, x, y, x_mid-newsize/2, y_mid-newsize/2, newsize);
		}
		else{
			return helper_getPixel(SW, x, y, x_mid-newsize/2, y_mid+newsize/2, newsize);
		}
	}
	else{
		if(y < y_mid){
			return helper_getPixel(NE, x, y, x_mid+newsize/2, y_mid-newsize/2, newsize);
		}
		else{
			return helper_getPixel(SE, x, y, x_mid+newsize/2, y_mid+newsize/2, newsize);
		}
	}
	return RGBAPixel();
}

void Quadtree::helper_decompress(PNG & img, QuadtreeNode * ancestor, int x, int y, int pic_size_p) const{
	if(ancestor == NULL){
		return;
	}
	QuadtreeNode * NW = ancestor->nwChild;
	QuadtreeNode * NE = ancestor->neChild;
	QuadtreeNode * SW = ancestor->swChild;
	QuadtreeNode * SE = ancestor->seChild;
	if(pic_size_p == 1){
        	*(img(x, y)) = ancestor->element;	
        	return;	
	}
	int newsize = pic_size_p/2;
	if(NW == NULL || NE == NULL || SW == NULL || SE == NULL){
		for(int i = 0; i < x + pic_size_p; i++){
			for(int j = 0; j < y + pic_size_p; j++){
	       			*(img(i, j)) = ancestor->element;	
			}
		}
		return;
	}
	helper_decompress(img, NW, x, y, newsize);
	helper_decompress(img, NE, x + newsize, y, newsize);
	helper_decompress(img, SW, x, y + newsize, newsize);
	helper_decompress(img, SE, x + newsize, y + newsize, newsize);
	return;
}

void Quadtree::clockwiseRotate(){
	if(root == NULL || pic_size == 1){
		return;
	}
	helper_rotate(root);
}

void Quadtree::helper_rotate(QuadtreeNode * & root){
	if(root == NULL){
		return;	
	}
	helper_rotate(root->nwChild);
	helper_rotate(root->swChild);
	helper_rotate(root->seChild);
	helper_rotate(root->neChild);
	
	QuadtreeNode *temp = root->nwChild;
	root->nwChild = root->swChild;
	root->swChild = root->seChild;
	root->seChild = root->neChild;
	root->neChild = temp;
	return;
}


void Quadtree::prune(int tolerance){
	helper_prune(root, tolerance);
	return;
	}

void Quadtree::helper_prune(QuadtreeNode * & ancestor, int tolerance){
	if(ancestor == NULL) 	return;
	
	QuadtreeNode * NW = ancestor->nwChild;
	QuadtreeNode * NE = ancestor->neChild;
	QuadtreeNode * SW = ancestor->swChild;
	QuadtreeNode * SE = ancestor->seChild;
	if(NW && NE && SW && SE)	return;
	//TODO
	if(helper_isprune(NW, ancestor, tolerance) && helper_isprune(NE, ancestor, tolerance) && helper_isprune(SW, ancestor, tolerance) && helper_isprune(SE, ancestor, tolerance)){
		helper_delete(NW);
		helper_delete(NE);
		helper_delete(SW);
		helper_delete(SE);
		
		NW = NE = SW = SE = NULL;
		return;
	}
	helper_prune(NW, tolerance);
	helper_prune(NE, tolerance);
	helper_prune(SW, tolerance);
	helper_prune(SE, tolerance);
	return;
}

bool Quadtree::helper_isprune(QuadtreeNode * & child, QuadtreeNode * & ancestor, int tolerance){
	if(child || ancestor)	return false;
	if(child->nwChild == NULL){
		return	helper_difference(child->element, ancestor->element) <= tolerance;
	}
	
	return helper_isprune(child->nwChild, ancestor, tolerance)&&helper_isprune(child->neChild, ancestor, tolerance)&&helper_isprune(child->swChild, ancestor, tolerance)&&helper_isprune(child->seChild, ancestor, tolerance);
}
	
int Quadtree::helper_difference(RGBAPixel first, RGBAPixel second){
	return 0 + pow(first.red - second.red, 2) + pow(first.green - second.green, 2) + pow(first.blue - second.blue, 2);
}

int Quadtree::pruneSize(int tolerance) const{
	return 0;
	}

 int Quadtree::idealPrune( int numLeaves) const
{
	int upper_bound, lower_limit, trial, tolerance;
	tolerance = lower_limit = 0;
	upper_bound = pow(128, 2) * 3;
	trial = 0.5*(upper_bound+lower_limit);

	while (trial > lower_limit && trial < upper_bound)
	{
		if  (pruneSize(trial) > numLeaves )		// guess is too big 
		{	
			lower_limit = trial;
			trial = upper_bound * 0.5 + lower_limit * 0.5;
		}
		tolerance = upper_bound = trial;
		trial = (upper_bound + lower_limit)/2;
	}
	return tolerance;
}



