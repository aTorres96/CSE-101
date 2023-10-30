#include <iostream>
#include "bst.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector> 
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		throw std::invalid_argument("Usage: ./wordrange <INPUT FILE> <OUTPUT FILE>");
	}

	ifstream input;
	ofstream output;

	input.open(argv[1]);
	output.open(argv[2]);

	string command = "";
	char *com, *valstr, *op;
	string word1;
	string word2;


	BST myBST;

	while(getline(input, command))
	{
		if (command.length() == 0)
			continue;
		com = strdup(command.c_str());
		op = strtok(com, " \t");

		valstr = strtok(NULL, " \t");
		if(valstr != NULL)
			word1 = valstr;

		valstr = strtok(NULL, " \t"); //token for the second value when looking for the range
		if(valstr != NULL)
			word2 = valstr;
		
		if(strcmp(op, "i") == 0)
		{
			if (myBST.find(word1) == NULL)
			myBST.insert(word1);

		}

		if(strcmp(op, "r") == 0){
			int wordrange = myBST.range(word1, word2); // read and search through the tree and 
			//find the number of words that are between word1 and word2.
			output << wordrange << endl; //output the number of words between word1 and word2
		}
	}
	myBST.deleteBST();
	input.close();
	output.close();
}