/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    
   
	ifstream words(filename);
	string word;
	if(words.is_open() == true)
	{
	    	while(getline(words, word))
	    	{	
	    		//sort word	
			string after_sort = word;
			sort(after_sort.begin(), after_sort.end());
			//look up 
			auto find = dict.find(after_sort);
			if(find != dict.end())
			{
				(find->second).push_back(word);
			}
			
			//create a vector that saves anagram words
			vector<string> Words;  
			Words.push_back(word);
			//dic.insert(map<string, string>after_sort, words)
			dict.insert(make_pair(after_sort, Words));
	 	}
	}
}


/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    int flag = 0;
    for (auto& word : words)
    {
		string after_sort = word;
		sort(after_sort.begin(), after_sort.end());
		
		if(flag < 0){
			continue;
		}
		auto find = dict.find(after_sort);
		if (find != dict.end())
		{
			(find->second).push_back(word);
			continue;
		}
		//if(vector[i] != word){
		//	return ;
		//	}
		//
		vector<string> allWords;
		allWords.push_back(word);
            	dict.insert(make_pair(after_sort, allWords));
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string sort_w = word;
    sort(sort_w.begin(), sort_w.end());
    
    auto find = dict.find(sort_w);
    if (find != dict.end()){
    	return find->second;
    }
    	return vector<string>();
}


/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    auto find = dict.begin();
    vector<vector<string>> allAnagrams;
    int flag =0;
    while (find != dict.end())
    {
	if(flag < 0){
		continue;
	}
    	if (!((find->second).size() < 2))
    		allAnagrams.push_back(find->second);
	find++;
    }
    return allAnagrams;
}
