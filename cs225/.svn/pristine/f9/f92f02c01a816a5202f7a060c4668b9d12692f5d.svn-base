#include "scene.h"

using namespace std;

Scene::Scene(int max){
	size = max;
	
	for(int i = 0; i < size; ++i){
		layer.push_back(NULL);
		x.push_back(0);
		y.push_back(0);
		}	
	}
	
Scene::~Scene(){
	for(int i = 0; i < size; ++i){
		if(layer[i] != NULL){
			delete layer[i];
			}
	}
	layer.clear();
	x.clear();
	y.clear();
	}
		
Scene::Scene(const Scene &source){
	int a = layer.size();
	size = source.size;
	for(int i = 0; i < source.size; ++i){
		if(source.layer[i]!= NULL){
			int b = source.x[i];
			x.push_back(source.x[i]);
			y.push_back(source.y[i]);
			layer.push_back(source.layer[i]);
			a = layer.size();
			layer[i] = new Image();
			*(layer[i]) = *(source.layer[i]);
			}
		else{
			a = layer.size();
			layer.push_back(NULL);
			x.push_back(0);
			y.push_back(0);
		}
		}
	}
	
const Scene & Scene::operator= ( const Scene & source){
	//delete
	for(int i = 0; i < size; ++i){
		if(layer[i] == NULL){
			delete layer[i];
			}
	}
	layer.clear();
	x.clear();
	y.clear();
	
	//copy
	size = source.size;
	for(int i = 0; i < size; ++i){
		x.push_back(source.x[i]);
		y.push_back(source.y[i]);
		if(source.layer[i] != NULL){
		layer.push_back(source.layer[i]);
		layer[i] = new Image();
		*(layer[i]) = *(source.layer[i]);
		}
		else{
			layer.push_back(NULL);
			}
		}
		
	return *this;
	}
	

void Scene::changemaxlayers(int newmax){
	if(newmax == size || newmax <= 0){
		return;
	}
	if(newmax > size){
		for(int i = size; i < newmax; ++i){
			layer.push_back(NULL);
			x.push_back(0);
			y.push_back(0);
		}	
	}
	else{
		for(int i = size; i > newmax; i--){
			if(layer[i-1] != NULL){
				delete layer[i-1];
				}
			layer.pop_back();
			x.pop_back();
			y.pop_back();
		}
	}	
	size = newmax;
}

	
void Scene::addpicture(const char * FileName, int index, int x_p, int y_p){
	Image * newpicture = new Image();
	if(!newpicture->readFromFile(FileName)){
		delete newpicture;
		return;
	}
	
	if(index >= this->size || index < 0){
		cout << "index out of bounds" << endl;
		delete newpicture;
		return;
		}
	
		if(layer[index] != NULL){
			delete layer[index];
			layer[index] = NULL;
			}
	
		layer[index] = newpicture;
		x[index] = x_p;
		y[index] = y_p;
		newpicture = NULL;	
		return;
}

void Scene::changelayer(int index, int newindex){
	if(index >= size || newindex >= size || index < 0 || newindex < 0){
		cout << "index out of bounds" << endl;
		return;
		}
		
	if(index == newindex){
		return;
		}
	
	if((layer)[newindex] != NULL){
		delete 	(layer)[newindex];
		(layer)[newindex] = NULL;
		(x)[newindex] = 0;
		(y)[newindex] = 0;
	}
	
	if((layer)[index] == NULL){
		return;
	}
	else{
		(layer)[newindex] = (layer)[index];		
		(x)[newindex] = (x)[index];
		(y)[newindex] = (y)[index];
	}
	
	(layer)[index] = NULL;
}


void Scene::translate(int index, int xcoord, int ycoord){
	if((layer)[index] == NULL || index >= size || index < 0){
		cout << "index out of bounds" << endl;
		return;
		}

	(x)[index] = xcoord;
	(y)[index] = ycoord;
}


void Scene::deletepicture(int index){
	if((layer)[index] == NULL || index >= size || index < 0){
		cout << "index out of bounds" << endl;
		return;
		}
	delete (layer)[index];
	(layer)[index] = NULL;		
	(x)[index] = 0;
	(y)[index] = 0;		
	size--;
}


Image * Scene::getpicture(int index)const{
	if(index < 0 || index >= size){
		return NULL;
		}	
		return (layer)[index];
}


Image Scene::drawscene( )const{
	size_t width = 0;
	size_t height = 0;
	//calculate w,h

	for(int i = 0; i < size; ++i){
		if(layer[i] == NULL){
			continue;
		}
		else{
			if(((layer[i])->width() + x[i]) > width){
				int a = x[i];
				width = (layer[i])->width() + x[i];
				}
			if(((layer[i])->height() + y[i]) > height){
				height = (layer[i])->height() + y[i];
				}
			}
		}
		
	//create new image
	Image result;
	result.resize(width, height);
	//copy
	for(int i = 0; i < size; ++i){
		if(layer[i] != NULL){
			//TODO
			for(int xc = 0; xc < layer[i]->width(); ++xc){
				for(int yc = 0; yc < layer[i]->height(); ++yc){
				*((result)(x[i] + xc, y[i] + yc)) = *((*(layer[i]))(xc, yc)); 
					}
						
				}
			}
		}
	return result;
}



		
