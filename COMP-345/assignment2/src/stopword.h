/*
 * stopword.h
 *
 *  Created on: Oct 11, 2017
 *      Author: samue
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>

#ifndef STOPWORD_H_
#define STOPWORD_H_

class stopword {
public:
	//default
	stopword();
	//parameter
	stopword(std::string filename);
	bool operator()(std::string token);
	friend std::ostream& operator<<(std::ostream& Out, const stopword &stopword);

private:
	std::vector<std::string> stopwords;
};

#endif /* STOPWORD_H_ */
