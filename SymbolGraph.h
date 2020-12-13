#pragma once
#include <string>
#include"Digraph.h"
#include <unordered_map>
#include <fstream>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;
class SymbolGraph
{
public:
	/**
	* given a filename, open that file, and use whitespace as delimeter.
	* every line of that file responds to an edge in digraph
	*/
	SymbolGraph(string filename);
	~SymbolGraph();
	/**
	* Does this symbol graph have this key as a node?
	*/
	bool contains(string key);
	/**
	* given a string version vertex, return the integer index(integer version vertex) of the digraph
	*/
	int index(string key);
	/**
	* given a integer index(integer version vertex), return the string version vertex
	*/
	std::string name(int v);
	Digraph * G();
private:
	/**
 	* returns the digraph.
 	*/ 
	Digraph * digraph;
	unordered_map<string, int> umap;// mapping between vertex name and
	//integer index
	string * keys;// mapping between vertex name and
	//integer index
	/**
 	* implement a split method just like split() in Java.
 	*/ 
	static string * split(string line);
};


