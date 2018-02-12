/* Your code here! */
#include "maze.h"
#define L 0
#define B 1
#define R 2
#define U 3


SquareMaze::SquareMaze(){
	mywidth = 0;
	myheight = 0;
}

void SquareMaze::makeMaze(int width, int height)
{	
	//check
	if(width < 0 || height < 0)	return;
	//initialization
	int i = 0, flag = 1;
	int size = width*height;
	mywidth = width;
	myheight = height;
	//make maze
	while(i < size){
		maze.push_back(cell());
		i++;
	}
	//make disjoint structure
	DisjointSets maze_d;
	maze_d.addelements(size);
	//set random
	srand(time(NULL));
	i = 0;
	int target;
	int counter = 0;
	while(counter < size-1){
		//pickup one cell
		target = rand() % size;
		if(flag == 1){
			//set right
			if((target + 1) % width != 0){
				if(maze_d.find(target) != maze_d.find(target + 1)){
					maze_d.setunion(target, target+1);
					maze[target].r = false; 		
					counter++;
				}	
			}
			flag = 0;
		}
		else{
			//set bot
			if(target < size - width){
				if(maze_d.find(target) != maze_d.find(target + mywidth)){
					maze_d.setunion(target, target + mywidth);
					maze[target].b = false; 		
					counter++;
				}
			}
			flag = 1;
		}
	}
	return;
}

bool SquareMaze::canTravel(int x, int y, int dir)const
{
	//left
	switch(dir){
		case 0:
			if(x == mywidth -1)	return false;
			return	!(maze[y*mywidth + x].r);
		case 1:
			if(y == myheight -1)	return false;
			return  !(maze[y*mywidth + x].b);
		case 2:
			if(x == 0)	return false;
			return  !(maze[y*mywidth + x - 1].r);
		case 3:
			if(y == 0)	return false;
			return  !(maze[(y-1)*mywidth + x].b);
		default:
			return false;
	}
}



void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
	if(dir == 1)	maze[y*mywidth + x].b = exists;
	else		maze[y*mywidth + x].r = exists;
	return;
}


vector<int> SquareMaze::solveMaze()
{
	vector<int> result;
	helper_solveMaze(0, 0, 0, result);
	return bestpath;
}


void SquareMaze::helper_solveMaze(int x, int y, int dir, vector<int>& direct){\
	//check boundary
	if(x < 0 || y < 0 || y >= myheight || x >= mywidth)	return;
	//check final
	if(y == myheight -1){
		//find the answer
		if(bestpath.size() == 0 || direct.size() > bestpath.size()){
			bestpath = direct;
			lastx = x;
		}
		//if the length is the same, get the one whose x is smaller
		if(direct.size() == bestpath.size()){
			if(x < lastx){
				bestpath = direct;
				lastx = x;
			}
		}
	}
	//check left
	if(canTravel(x, y, L)){
		if((dir+2)%4 != L){
			direct.push_back(L);
			helper_solveMaze(x+1, y, L, direct);
			direct.pop_back();
		}
	}
	if(canTravel(x, y, B)){
		if((dir+2)%4 != B){
			direct.push_back(B);
			helper_solveMaze(x, y+1, B, direct);
			direct.pop_back();
		}
	}
	if(canTravel(x, y, R)){
		if((dir+2)%4 != R){
			direct.push_back(R);
			helper_solveMaze(x-1, y, R, direct);
			direct.pop_back();
		}
	}
	if(canTravel(x, y, U)){
		if((dir+2)%4 != U){
			direct.push_back(U);
			helper_solveMaze(x, y-1, U, direct);
			direct.pop_back();
		}
	}	
	return;
}


PNG * SquareMaze::drawMaze()const
{
	PNG * result = new PNG(mywidth*10 +1, myheight*10+1);
	//draw boundry
	int size = mywidth*myheight;
	for(int i = 0; i < size; i++){
		if(maze[i].b){
			helper_drawbot(result, i);
		}
		if(maze[i].r){
			helper_drawright(result, i);
		}
	}
	for(int i=0; i < (int)(result->height()); i++){
		(*result)(0,i)->red = (*result)(0,i)->green = (*result)(0,i)->blue = 0;
	}
	for(int i = 10; i < (int)(result->width()); i++){
		(*result)(i,0)->red = (*result)(i,0)->green = (*result)(i,0)->blue = 0;
	}	
	return result;
}

PNG * SquareMaze::drawMazeWithSolution()
{
	  //initia point
	  int x = 5; 
	  int y = 5;
	  int cellx = 0 ;
	  int celly = 0;
	  PNG * result = drawMaze();
  	  vector<int> sol_path = solveMaze();
	  for(int i = 0; i < (int)sol_path.size(); i++){
	    	if(sol_path[i] == 2){//left
	  		cellx--;
			for(int k=0; k<10; k++, x--){
				(*result)(x,y)->red = 255;
				(*result)(x,y)->green = (*result)(x,y)->blue = 0;
			}
		}else if(sol_path[i] == 1){//down
	 	      celly++;
		      for(int k=0; k<10; k++, y++){
				(*result)(x,y)->red = 255;
				(*result)(x,y)->green = (*result)(x,y)->blue = 0;
		      }
	  	}else if(sol_path[i] == 0){//right
	    	      cellx++;
		      for(int k=0; k<10; k++, x++){
				(*result)(x,y)->red = 255;
				(*result)(x,y)->green = (*result)(x,y)->blue = 0;
		      }
	 	}else{//up
	 		celly--;
		      	for(int k=0; k<10; k++, y--){
				(*result)(x,y)->red = 255;
				(*result)(x,y)->green = (*result)(x,y)->blue = 0;
			}
	        }
	  }
	  //draw the last pixel
	  (*result)(x,y)->red = 255;
	  (*result)(x,y)->green = (*result)(x,y)->blue = 0;
	  //make the exit
	  for(int k = 1; k<10; k++){
		(*result)(cellx*10+k,(celly+1)*10)->red =  (*result)(cellx*10+k,(celly+1)*10)->green = (*result)(cellx*10+k,(celly+1)*10)->blue = 255;
	  }
	  return result;
}

void SquareMaze::helper_drawright(PNG * result, int index) const{
	int k = 0;
	while(k <= 10){
		(*result)((index%mywidth+1)*10, (index/mywidth)*10+k)->red =   (*result)((index%mywidth+1)*10, (index/mywidth)*10+k)->green =  (*result)((index%mywidth+1)*10, (index/mywidth)*10+k)->blue = 0;
		k++;
	}
}

void SquareMaze::helper_drawbot(PNG * result, int index) const{
	int k = 0;
	while(k <= 10){
		(*result)((index%mywidth)*10+k, (index/mywidth+1)*10)->red =  (*result)((index%mywidth)*10+k, (index/mywidth+1)*10)->green =  (*result)((index%mywidth)*10+k, (index/mywidth+1)*10)->blue = 0;
		k++;
	}
}
