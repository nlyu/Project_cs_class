#include <iostream>
#include <set>
#include <string>
#include <map>
#include <queue>

/* STL Sets have several methods you may (or may not) need:
 *
 * begin() -- return iterator from beginning
 * count(x) -- return number of instances of x in the set (will be 0 or 1)
 * insert(x) -- insert an element x into the set
 * erase(x) -- remove an element x from the set
 * empty() -- test if the set is empty
 * size() -- return number of elements in set
 */

using namespace std;

set<string> findNeighbors(string curr,  set<string>& wordList)
{
    set<string> neighbors;
    int N = curr.size();
    for(int i = 0; i < N; i++)
    {
        for(char c = 'a'; c <= 'z'; c++)
        {
            if(c == curr[i])
                continue;
            string oneChange = curr.substr(0,i) + (c) + curr.substr(i+1);
            if(wordList.count(oneChange))
            {
                neighbors.insert(oneChange);
                wordList.erase(oneChange);
            }
        }
    }
    return neighbors;
}

int sequenceLength(string beginWord, string endWord, set<string>& wordList) {

    // YOUR CODE HERE!
    	int size;
    	if(beginWord == endWord)	return 1;
	map<string, string> path;
	map<string, bool>   dis;
	queue<string> bfs;
	//first
	bfs.push(beginWord);
	dis[beginWord] = true;
	while(!bfs.empty()){
		string curr = bfs.front();
		bfs.pop();
		set<string> around = findNeighbors(curr, wordList);
		for(auto i = around.begin(); i != around.end(); i++){
			if(dis[*i] == false){
				path[*i] = curr;
				dis[*i] = true;
				bfs.push(*i);
			}
		}
	}
	string next = endWord;
	for(size = 1; beginWord != next; size++){
		next = path[next];
		if(size >= 999999)	return 1;
	}
	cout<<size<<endl;
    return size;
}
