/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    /* Your code goes here! */

    vector<StringTriple> output;

ifstream wordsFile(word_list_fname);
vector<string> out;
string word;
if (wordsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */
    while (getline(wordsFile, word)) {
        out.push_back(word);
    }
}

    for(auto & wordit : out)
    {
	string tempstr=wordit;
        tempstr.erase(tempstr.begin());       
        string rfirst=tempstr;
	tempstr=wordit;
	tempstr.erase(tempstr.begin()+1);
        string rsecond=tempstr;       
        if(d.homophones(wordit, rfirst)&&d.homophones(wordit, rsecond))
        {
            output.push_back({wordit, rfirst, rsecond});

        }
    }

    return output;
}
