# pragma once
# include <iostream>
# include <string>
# include "config.h"
# include "CvtExp.h"
# include "SymbolGraph.h"
# include "DepthFirstOrder.h"
using namespace std;

int main(){
	/**
	*  first step: convert expressions to edges that implys precedence constraints and put edges into another file.
	*/
	CvtExp converter(expFile,edgeFile);// parameters are configured in config.h
	converter.cstctEdgeFile();
	/**
	* second step: use edges to create a digraph that uses string as the vertex name(symbol digraph).
	*/
	SymbolGraph SG(edgeFile);
	DepthFirstOrder dfo(&SG);

	stack<string>* reversePost = dfo.reversePost();
	cout << "The topological sort order is:" << endl;
	while (!reversePost->empty())
	{
		cout << reversePost->top() << " ";
		reversePost->pop();
	}
	cout << endl;
	//system("pause");
	return 0;
}