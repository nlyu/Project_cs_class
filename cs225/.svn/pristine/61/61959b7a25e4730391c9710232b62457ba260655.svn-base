/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s)
{
    // Your code here
    if(s.empty())
    return T(); // stub return value (0 for primitive types). Change this!
    	T top = s.top();
    	s.pop();
    	T mysum = top + sum(s);
    	s.push(top); 
	return mysum;
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble(queue<T>& q)
{
	int size = 1, cur = 1;
	stack<T> temp;
	queue<T> q2;
	
	//use for test 
	T data;
	while(!q.empty() && cur < (int)(q.size())){
		data = q.size();
		if(size == cur && size % 2 == 1){
			while(cur != 0){
				q2.push(q.front());
				data = q.front();
				q.pop();
				cur--;
			}
			size++;
			cur = 1;
			continue;
		}
		if(size == cur && size % 2 != 1){
			while(cur != 0){
				temp.push(q.front());
				
				data = temp.top();
				q.pop();
				cur--;
				}
			cur = size;
			while(cur != 0){
				q2.push(temp.top());
				temp.pop();
				cur--;
				}
			size++;
			cur = 1;
			while(!temp.empty()){
				temp.pop();
			}
			continue;
		}
		cur++;
	}
	
	if(!q.empty()){
		if(size % 2 == 1){
			while(!q.empty()){
				q2.push(q.front());
				q.pop();
			}
		}
		else{
			while(!q.empty()){
				temp.push(q.front());
				q.pop();
				}
			while(!temp.empty()){
				q2.push(temp.top());
				temp.pop();
				}
		}
	}
	while(!q2.empty()){
		q.push(q2.front());
		q2.pop();
	}
	//free q2, temp
	while(!q2.empty()){
		q2.pop();
		}
	while(!temp.empty()){
		temp.pop();
		}
	return;
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{
	if(s.empty())
		return true;
		
    	bool retval = true; // optional
	T temp1; // rename me
    	T temp2; // rename :) 


	temp1 = s.top();
	s.pop();
	
	retval= verifySame(s,q);
	
	temp2 = q.front();
	q.pop();
	
	
	s.push(temp1);
	q.push(temp2);
    return retval = retval && (temp1 == temp2);;

}

}
