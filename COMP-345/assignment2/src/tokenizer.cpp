/*
 * tokenizer.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: samue
 */

#include "tokenizer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

tokenizer::tokenizer(){
}

tokenizer::tokenizer(std::string fileName) {
	terms = readFile(fileName);
}


std::vector<std::string> tokenizer::readFile(std::string inputFile){
	std::ifstream fin(inputFile);
	std::vector<std::string> allTokens;
	std::string currentWord;

	if (!fin) {
		throw "Error opening input file. Closing";
	}

	while (fin >> currentWord) {
		// Remove punctuation
		currentWord = containsPunctuation(currentWord);
		// Transform term to lower case using built in method
		transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);

		//std::cout << currentWord << std::endl;
		allTokens.push_back(currentWord);

	}
	fin.close();
	return allTokens;
}

// If a word contains a character specified in the array, it will remove it.
std::string tokenizer::containsPunctuation(std::string word) {
	word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
	return word;
}

std::vector<std::string> tokenizer::getTerms(){
	return terms;
}

void tokenizer::setTerms(std::vector<std::string> t){
	terms = t;
}







