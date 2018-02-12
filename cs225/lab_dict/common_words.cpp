/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string result;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(result), std::ptr_fun<int, int>(&std::ispunct));
    return result;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());
    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        vector<string> words = file_to_vector(filenames[i]);
        for(size_t j = 0; j < words.size(); j++){
    	     file_word_maps[i][words[j]]++;
        }
    }
}

void CommonWords::init_common()
{   
      for(auto & file : file_word_maps){
              for(auto & word : file){
      			common[word.first]++;
              }
      }
}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    bool flag;
    vector<string> result;
    for(auto & word : common){
             flag = true;
             
             //for(int i; i < map<int, char> i++){
             //end
       for(auto & file : file_word_maps){
		if((file.find(word.first))->second < n){
			flag = false;
 	        }
       }
       //if(flag != true)
       if(flag == true){
        	result.push_back(word.first);
       }
     } 
    //return vector()
    return result;
}

/*
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> result;
    if (words.is_open()){
        std::istream_iterator<string> it(words);
        while (words.eof() != true){
            result.push_back(remove_punct(*it));
            ++it;
        }
    }
    return result;
}
