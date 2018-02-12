/* Your code here! */
#include <vector>
#include "png.h"
#include "dsets.h"
#include "rgbapixel.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;

class SquareMaze{
public:
	SquareMaze();
	void makeMaze(int width, int height);
	bool canTravel(int x, int y, int dir)const;
	void setWall(int x, int y, int dir, bool exists);
	vector<int> solveMaze();
	PNG * drawMaze()const;
	PNG * drawMazeWithSolution();

private:
	class cell{
	public:
		cell(){
			r = b = true;
		}
		bool r;
		bool b;
	};
	class position{
	public:
		position(){
			x = y = 0;
		}
		position(int a, int b){
			x = a;
			y = b;
		}
		int x;
		int y;
	};
	int lastx;
	vector<cell> maze;
	vector<int> bestpath;
	int mywidth;
	int myheight;
	void helper_drawright(PNG * result, int index) const;
	void helper_drawbot(PNG * result, int index) const;
	void helper_solveMaze(int x, int y, int dir, vector<int>& direct);
};

