#include "SymbolGraph.h"


#pragma warning(disable : 4996)


SymbolGraph::~SymbolGraph(){
	delete[] keys;
	delete digraph;
}
/**
* given a filename, open that file, and use whitespace as delimeter.
* every line of that file responds to an edge in digraph
*/
SymbolGraph::SymbolGraph(string filename){
	/*
	* for the reason that there is no explicit number of
	* edges and vertices, we need to compute the number of
	* vertices.(numbers of edges are automatically increased when calling addEgde())
	*/

	/*
	* So, how can we convert file of several lines to a digraph?
	* Solution :
	* We need 2 steps generally.
	* From the constructor, we know that both digraph and "keys" array need
	* to know the size to initialize themselves.
	* So we cannot initialize them without knowing the size.
	* So everytime we read in a line, the only thing we can do is add to the map.
	* only after we finish adding can we initialize both variables.
	*/


	/*
	Pass 1: add all tokens into the map, get number of Vertices
	*/
	umap = unordered_map<string, int>();
	string line;

	ifstream infile(filename, ios::in);
	if (!infile.is_open()){
		cout << "failed to open " << filename << ", program exited" << endl;
		exit(1);
	}
	
	
	while (getline(infile, line))
	{
		if (line == "")
			continue;
		string * tokens = split(line);
		if (umap.find(tokens[0]) == umap.end()) umap[tokens[0]] = umap.size();
		if (umap.find(tokens[1]) == umap.end()) umap[tokens[1]] = umap.size();
		delete [] tokens;
	}

	infile.close();

	keys = new string[umap.size()];
	for (auto it = umap.begin(); it != umap.end(); ++it){
		keys[it->second] = it->first;
	}

	digraph = new Digraph(umap.size());

	
	/*
	Pass 2: add all edges into the digraph, and at the same time
	add all tokens into the "keys" array
	*/
	ifstream ifile(filename, ios::in);
	if (!ifile.is_open()){
		cout << "failed to open " << filename << ", program exited" << endl;
		exit(1);
	}
	while (getline(ifile, line))
	{
		if (line == "")
			continue;
		string * tokens = split(line);
		digraph->addEdge(umap[tokens[0]], umap[tokens[1]]);
		delete [] tokens;
	}
}
/**
* Does this symbol graph have this key as a node?
*/
bool SymbolGraph::contains(string key){
	return umap.find(key) != umap.end();// token  exists in the map
}
/**
* given a string version vertex, return the integer index(integer version vertex) of the digraph
*/
int SymbolGraph::index(string key){
	return umap[key];
}
/**
* given a integer index(integer version vertex), return the string version vertex
*/
string SymbolGraph::name(int v){
	return keys[v];
}
/**
 * returns the digraph.
 */ 
Digraph * SymbolGraph::G(){
	return digraph;
}
/**
 * implement a split method just like split() in Java.
 */ 
string * SymbolGraph::split(string line){
	string * result = new string[2];
	char * space = (char *)strchr(line.c_str(), ' ');
	int index = space - line.c_str();
	result[0] = line.substr(0, index);
	result[1] = line.substr(index + 1, line.size());
	return result;
}