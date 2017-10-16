/*
 * tokenizer.h
 *
 *  Created on: Oct 11, 2017
 *      Author: samue
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <vector>
#include <string>

class tokenizer {
public:
	tokenizer();
	tokenizer(std::string);
	std::vector<std::string> getTerms();
	void setTerms(std::vector<std::string> t);
	std::vector<std::string> readFile(std::string inputFile);
	std::string containsPunctuation(std::string word);
private:
	std::vector<std::string> terms;
};

#endif /* TOKENIZER_H_ */
