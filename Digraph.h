#pragma once
# include <list>
# include <fstream>
using namespace std;
class Digraph
{
public:
	/**
	 * This method is actually useless. It is just
	 * for successful compiling.
	 */ 
	Digraph();
	/**
	 * create digraph of V vertices but no edges. 
	 */
	Digraph(int V);
	~Digraph();
	/**
	 * return the number of vertices.
	 */ 
	int getV();
	/**
	 * return the number of edges.
	 */ 
	int getE();
	/**
	* add an edge v->w into this digraph
	*/
	void addEdge(int v, int w);
	/**
	 * return all vertices adjacent to a given vertex.
	 */ 
	list<int>* getAdj(int v);
private:
	int V; // number of vertices
	int E; // number of edges
	list<int>  ** adj ;// adjacency list.
};

