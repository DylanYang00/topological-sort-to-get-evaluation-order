#include "Digraph.h"


Digraph::~Digraph(){
	for (int i = 0; i < V; i++){
		delete adj[i];
	}
	delete[] adj;
}
/**
 * This method is actually useless. It is just
 * for successful compiling.
 */ 
Digraph::Digraph(){

}
/**
 * create digraph of V vertices but no edges. 
 */
Digraph::Digraph(int V){
	this->V = V;
	this->E = 0;
	adj = new list<int> *[V];
	for (int i = 0; i < V; i++){
		adj[i] = new list<int>();
	}
}
/**
* add an edge v->w into this digraph
*/
void Digraph::addEdge(int v, int w){
	adj[v]->push_back(w);
	E++;
}
/**
 * return the number of vertices.
 */ 
int Digraph::getV(){
	return this->V;
}
/**
 * return the number of edges.
 */ 
int Digraph::getE(){
	return this->E;
}
/**
 * return all vertices adjacent to a given vertex.
 */ 
list<int>* Digraph::getAdj(int v){
	return adj[v];
}