#ifndef SCENE_H
#define SCENE_H
 
#include "image.h"
#include "png.h"
#include <vector>

using namespace std;

class Scene{
public:
	Scene(int max);
	
	~Scene();
	
	Scene(const Scene &source);
	
	const Scene& operator=(const Scene &source);
	
	void changemaxlayers(int newmax);

	void addpicture(const char *FileName, int index, int x_p, int y_p);
 
	void changelayer(int index, int newindex);
 
	void translate(int index, int xcoord, int ycoord);
 
	void deletepicture(int index);
 
	Image * getpicture(int index)const;
 
	Image drawscene() const;
	
private:
	int size;
	vector<int> x;
	vector<int> y;
	vector<Image*> layer;
	
};
#endif
