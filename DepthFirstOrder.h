/**
* depth first search order(post order)
*/

#pragma once
#include <stack>
#include "SymbolGraph.h"
using namespace std;

class DepthFirstOrder
{
public:
	/**
	 * takes the symbol graph and does all the work including dfs 
	 * and putting vertices on to the stack to get ready for returning
	 * the stack.
	 */ 
	DepthFirstOrder(SymbolGraph* SG);
	~DepthFirstOrder();
	/**
	 * return the stack storing reverse post order of vertices.
	 */ 
	stack<string> * reversePost();
private:
	stack<string> reversePostStack;
	bool * marked;
	/**
	 * method that does dfs
	 */
	void dfs(SymbolGraph * SG, int v);
};

