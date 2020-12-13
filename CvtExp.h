#pragma once
#include<fstream>
#include <cctype>
#include "config.h" // contains file name
/**
* Utility class that construct file of edges from given expression file.
*/
class CvtExp
{
public:
	/**
 	* Construct an object using two files:
 	* 1. The file to read expressions from.
 	* 2. The file to write lines of edges to.
 	*/ 
	CvtExp(string expFile, string edgeFile);
	~CvtExp();
	/**
	*	construct file of edges from the input expression file.
	*/
	static void cstctEdgeFile();
	/**
	* parse a single line from the original file of expressions
	*/
	static void parseSglLine(string line);
	/**
	* get first index of +,-,*,/
	*/
	static size_t getFirstDelim(string s);
	/**
	* test whether a token is a number
	*/
	static bool isNumber(const string & s);

private:
	 ofstream static outFile;// output stream shared by all methods
	 ifstream static inFile;// input stream shared by all methods
};


