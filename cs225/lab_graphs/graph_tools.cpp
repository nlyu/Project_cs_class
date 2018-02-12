/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"
#include <map>
using namespace std;
/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    Edge smallest;//store the smallest edge
    smallest.weight = 99*99*99*99;//set distance as infinite
    vector<Edge> alledge = graph.getEdges();//vector that saves all the edges
    for(int i = 0; i < (int)alledge.size(); i++){
    	if(alledge[i].weight < smallest.weight)		smallest = alledge[i];
    }
    graph.setEdgeLabel(smallest.source, smallest.dest, "MIN");//label edge as min
    return smallest.weight;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
	int size;//local var
    Vertex now, after; //the starting city and ending city
    map <Vertex, Vertex> path; //store the result path after bfs
    vector <Vertex> around; //the adjacent city around a given city
    queue <Vertex> bfs; //queue for bfs algorithm
    if(graph.getEdges().size() == 0)	return 0;//check
    //initialization
    graph.setVertexLabel(start, "VISITED");
    bfs.push(start);
    //do bfs
    while(!bfs.empty())
    {
    	//get the first one in the queue
    	now = bfs.front();
    	//get neighbor cities
    	around = graph.getAdjacent(now);
    	size = around.size();
    	//cout<<"size is"<<size<<endl;
    	bfs.pop();//remove the current city
    	for(int i = 0; i < size; i++){
    		after = around[i];//the target city
    		if(graph.getVertexLabel(after) != "VISITED")
    		{//if this city is unvisited
    			//cout<<"hey2"<<endl;
    			graph.setEdgeLabel(now, after, "DISCOVERY");
    			graph.setVertexLabel(after, "VISITED");
    			path[after] = now;//build path 
    			bfs.push(after);
    			//cout<<"hey3"<<endl;
    			continue;
    		}
    		if(graph.getEdgeLabel(now, after).compare("") == 0)
    		{//if the city has been visited before
    			//cout<<"hey"<<endl;
    			graph.setEdgeLabel(now, after, "CROSS");
    		}
    	}
    }
    //get the distance
    for(size = 0; start != end; size++)
    {
    	graph.setEdgeLabel(end, path[end], "MINPATH");//draw
    	end = path[end];//trance the path from the end city
    }
    return size;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
	/* Your code here! */
    vector<Edge> all_e = graph.getEdges();
    vector<Vertex> all_v = graph.getVertices();
    //push vertex into disjointset
    DisjointSets vertexunion;
    vertexunion.addelements(all_v.size());
    //sort edges
    sort(all_e.begin(), all_e.end());
    //make mini span tree
    for(int i=0; i< (int)all_e.size(); i++){
        if(vertexunion.find(all_e[i].source) != vertexunion.find(all_e[i].dest)){
        	graph.setEdgeLabel(all_e[i].source,all_e[i].dest,"MST");
            vertexunion.setunion(all_e[i].source, all_e[i].dest);
        }
    }
}

