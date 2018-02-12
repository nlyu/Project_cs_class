/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num)
{
	if(num < 0)	return; //check validity
	for(int i = 0; i < num; i++)	data.push_back(-1);
}

int DisjointSets::find(int elem)
{
	//return size
	if(data[elem] < 0)	return elem;
	data[elem] = find(data[elem]);
	return data[elem];
}

void DisjointSets::setunion(int a, int b)
{
	int set_a = find(a);
	int set_b = find(b);
	int newsize = data[set_a] + data[set_b];
	if(data[set_a] == data[set_b] || data[set_a] > data[set_b]){
		data[set_b] = set_a;
		data[set_a] = newsize;
	}
	else{
		data[set_a] = set_b;
		data[set_b] = newsize;
	}
}
