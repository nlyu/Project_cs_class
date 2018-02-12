/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if(curDim < 0)	return false;
     if(first[curDim] < second[curDim])		return true;
     if(first[curDim] == second[curDim])	return first < second;
    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    int distance_cur, distance_pot, i;
    distance_cur = distance_pot = i = 0;
    for(; i < Dim; i++){
    	distance_cur += pow(target[i] - currentBest[i], 2);
    	distance_pot += pow(target[i] - potential[i], 2);
    }

    if(distance_pot == distance_cur)	return potential < currentBest;    
    return distance_pot < distance_cur;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
	points = newPoints;
	buildtree(points,0,points.size()-1,0);

}
template <int Dim>
void KDTree<Dim>::buildtree(vector<Point<Dim>>& newPoints,int left,int right,int dim)
{
	if(left>=right) return;
	newPoints[(left+right)/2]=select(newPoints,left,right,(left+right)/2, dim);
	buildtree(newPoints, (left+right)/2 +1, right, (dim+1) % Dim);
	buildtree(newPoints, left, (left+right)/2 -1, (dim+1) % Dim);
}

template <int Dim>
int  KDTree<Dim>::partition(vector<Point<Dim>>&Points , int left, int right, int pivotIndex, int dim)
{
    Point<Dim> pivotValue = Points[pivotIndex];
    swap(Points,pivotIndex,right); 
    int j = left;
    for (int i = left; i < right; i++)
    {
      	if (smallerDimVal(Points[i],pivotValue, dim))
	{
		swap (Points,j,i);
         	j++;
	}
    }
     swap (Points, right, j); 
     return j;
}


template <int Dim>
void KDTree<Dim>::swap(vector<Point<Dim>>&Points,int a,int b)
{
	Point<Dim> c = Points[a];
	Points[a] = Points[b];
	Points[b] = c;
}


template <int Dim>
Point<Dim> KDTree<Dim>::select(vector<Point<Dim>>& list, int left,int right,int n,int curdim)
{
     if (left == right)       return list[left]; 
     int mid  = (left+right)/2;    
     int  pivotIndex  = partition(list, left, right, mid, curdim);
     if (n == pivotIndex) return list[n];
     return ( n < pivotIndex) ?  select(list, left, pivotIndex - 1, n, curdim) : select(list, pivotIndex + 1, right, n, curdim);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    int size = points.size() == 0 ? 1 : points.size();
    return helper_find(0, size -1, 0, query);
}


template <int Dim>
Point<Dim> KDTree<Dim>::helper_find(int left, int right, int dim, const Point<Dim>& q) const
{
	int mid = (left + right)/2;//get mid point
	Point<Dim> left_best_point, right_best_point;
	if(left >= right)	return points[left];	
	//recursion into the deepest leaf
	left_best_point = (smallerDimVal(q, points[mid], dim)) ? helper_find(left, mid-1, (dim + 1) % Dim, q) : helper_find(mid + 1, right, (dim + 1) % Dim, q);
	//do the recur comparsion
	if(shouldReplace(q, left_best_point, points[mid]))	left_best_point = points[mid];
	//check up and low
	int radius = 0;
	for (int x = 0; x < Dim; x++)
    	{
        	radius += pow(q[x] - left_best_point[x], 2);
    	}	
    	int distance = (-points[mid][dim]+q[dim])*(q[dim] - points[mid][dim]);
    	if(distance > radius){	return left_best_point;}   	
	//go to the other root
	right_best_point = (!smallerDimVal(q, points[mid], dim)) ? helper_find(left, mid-1, (dim + 1) % Dim, q) : helper_find(mid + 1, right, (dim + 1) % Dim, q);	
	return shouldReplace(q, left_best_point, right_best_point) ? right_best_point : left_best_point;
}




