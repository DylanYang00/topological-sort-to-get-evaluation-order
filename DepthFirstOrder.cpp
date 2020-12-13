#include "DepthFirstOrder.h"

DepthFirstOrder::~DepthFirstOrder(){
	delete[] marked;
}
/**
 * takes the symbol graph and does all the work including dfs 
 * and putting vertices on to the stack to get ready for returning
 * the stack.
 */ 
DepthFirstOrder::DepthFirstOrder(SymbolGraph * SG){
	/* initialization */
	int V = SG->G()->getV();
	marked = new bool[V];
	for (int v = 0; v < V; v++)
		marked[v] = false;
	reversePostStack = stack<string>();
	/* call dfs */
	for (int v = 0; v < V; v++){
		if (!marked[v]) dfs(SG, v);
	}
}
/**
 * method that does dfs
 */
void DepthFirstOrder::dfs(SymbolGraph * SG, int v){
	marked[v] = true;

	Digraph * G = SG->G();

	list<int> * adj = G->getAdj(v);
	for (list<int>::iterator it = adj->begin(); it != adj->end(); ++it){
		if (!marked[*it]) dfs(SG, *it);
	}

	reversePostStack.push(SG->name(v));

}
/**
 * return the stack storing reverse post order of vertices.
 */ 
stack<string>* DepthFirstOrder::reversePost(){
	return &reversePostStack;
}
