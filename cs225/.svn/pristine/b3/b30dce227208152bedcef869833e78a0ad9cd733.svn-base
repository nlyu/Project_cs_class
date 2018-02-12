/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    //validity
    if(theTiles.size() == 0)	return NULL;
    RGBAPixel cur_pixel;
    Point<3> cur_point;
    vector<Point<3>> cur_tile;
    map<Point<3>, TileImage> transfer;
    //perpare for the vector and map
    for(auto i: theTiles){
    	cur_pixel = i.getAverageColor();
    	cur_point = Point<3>(cur_pixel.red, cur_pixel.green, cur_pixel.blue);
    	cur_tile.push_back(cur_point);
    	transfer[cur_point] = i;
    }
    //build KDTree
    KDTree<3> tree(cur_tile);
    MosaicCanvas * result = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    //make picture
    for(int i = 0; i < theSource.getRows(); i++){
    	for(int j = 0; j < theSource.getColumns(); j++){
    		cur_pixel = theSource.getRegionColor(i, j);
    		cur_point = Point<3>(cur_pixel.red, cur_pixel.green, cur_pixel.blue);
    		cur_point = tree.findNearestNeighbor(cur_point);
    		result->setTile(i, j, transfer[cur_point]);
    	}
    }
    return result;
}

