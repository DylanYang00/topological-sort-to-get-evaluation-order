#include "CvtExp.h"

/**
* solution for linking problem of visual studio: just define whatever symbol is not found wherever it is needed.
*/
ofstream CvtExp::outFile; 
ifstream CvtExp::inFile;
/**
 * Construct an object using two files:
 * 1. The file to read expressions from.
 * 2. The file to write lines of edges to.
 */ 
CvtExp::CvtExp(string expFile, string edgeFile){
	inFile.open(expFile);
	outFile.open(edgeFile, ios::trunc);
}
CvtExp::~CvtExp(){
	inFile.close();
	outFile.close();
}

/**
*	construct file of edges from the input expression file.
*/
void CvtExp::cstctEdgeFile(){

	string line;
	while (getline(inFile, line))
	{
		parseSglLine(line);
	}

}

/**
* parse a single line from the original file of expressions
*/
void CvtExp::parseSglLine(string line){
	string left = line.substr(0, 2);
	line.erase(0, 5);
	size_t pos = std::string::npos;
	string token;
	while ((pos = getFirstDelim(line)) != std::string::npos){
		token = line.substr(0, pos);
		if (!isNumber(token)) outFile << token << " " << left << endl;
		line.erase(0, pos + 1);// erase token and operator(+,-,*,/);
	}
	if (!isNumber(line)) outFile << line << " " << left << endl;
}
/**
* get first index of +,-,*,/
*/
size_t CvtExp::getFirstDelim(string s){
	size_t pos = std::string::npos;// position of the first delimeter
	size_t tmp = 0;
	if ((tmp = s.find("+")) != std::string::npos) {
		if (pos == std::string::npos)
			pos = tmp;
		else if (tmp < pos)
			pos = tmp;
	}
	if ((tmp = s.find("-")) != std::string::npos) {
		if (pos == std::string::npos)
			pos = tmp;
		else if (tmp < pos)
			pos = tmp;
	}
	if ((tmp = s.find("*")) != std::string::npos) {
		if (pos == std::string::npos)
			pos = tmp;
		else if (tmp < pos)
			pos = tmp;
	}
	if ((tmp = s.find("/")) != std::string::npos) {
		if (pos == std::string::npos)
			pos = tmp;
		else if (tmp < pos)
			pos = tmp;
	}
	return pos;
}
/**
* test whether a token is a number
*/
bool CvtExp::isNumber(const string & s){
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}