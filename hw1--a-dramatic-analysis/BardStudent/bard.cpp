//Filename: billmain.cpp

#include <iostream>
#include "billheader.h"
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;
/*Function to get the longest word in the file*/
int longestWord(string shakespeare)
{
	ifstream file;
	file.open(shakespeare);
	string line;
	int longest = 0;
	while(getline(file, line))
	{
		int len = line.length();
		if (len > longest)
		 longest = len;
	}
	file.close();
	return longest;
}

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		throw std::invalid_argument("Usage: ./hello <INPUT FILE> <OUTPUTFILE>");
	}
    string line = "";
		ifstream myfile ("shakespeare-cleaned5.txt"); //stream Shakespear file
		ifstream input; // stream for input file
		ofstream output; // stream for output file

		input.open(argv[1]); //open input file
		output.open(argv[2]); // open output file
		
		int maxL = longestWord("shakespeare-cleaned5.txt");// store the longest word in the file

		LinkedList myList[maxL + 1]; //initialize LinkedList array with size of the longest word + 1

		if (myfile.is_open())					// check if file is open
			while(getline(myfile, line)){ //get next line of input
					if (line.length() == 0)	// if line is empty continue
						continue;
					myList[line.length()].insert(line);// insert word into linked list of apprpriate size
			}
		
		int listLength = sizeof(myList)/sizeof(myList[0]); //save length of myList
		int c = 0; // counter for while loop
		/*Sort each linked list and reverse each list
		so that it is in decreasing in frequency
		and increasing lexographically*/
		while(c < listLength){
			myList[c].bubsort();
			myList[c].reverseList();
			c++;
		}

		int l = 0; // input word length
		int k = 0; // input rank

		while(input >> l >> k) // read from input file
		{
				string out = "";
				/*If the length input is greater than the longest word,
				or less than zero, or the rank input is less than zero
				output "-" */
				if(l > maxL || l < 0 || k < 0)
					out = "-";
				else
					out = myList[l].getk(k); //output the word with the input length
				output << out << endl;		 //and rank.
		}
		myfile.close(); //close shakespeare
		input.close(); //close input file
		output.close(); //close output file
}