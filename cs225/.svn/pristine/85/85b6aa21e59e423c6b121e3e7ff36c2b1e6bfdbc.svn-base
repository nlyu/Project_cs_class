#include <iostream>
#include <vector>
using namespace std;

int depthUpTree(vector<int> uptree, int index)
{
  // Your code here!
  if(index > uptree.size()-1)	return 0;
  if(uptree[index] < 0) 
  {
  	return 0;
  }
  int a = uptree[index];
  return 1 + depthUpTree(uptree, a);
}

