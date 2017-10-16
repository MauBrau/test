/*
 * stopword.cpp
 *
 *  Created on: Oct 11, 2017
 *      Author: samue
 */

#include "stopword.h"
#include "tokenizer.h"

stopword::stopword() {
}

stopword::stopword(std::string filename){
	tokenizer getContents(filename);
	stopwords = getContents.getTerms();

}

bool stopword::operator()(std::string token){
	for (std::vector<std::string>::const_iterator i = stopwords.begin(); i != stopwords.end(); ++i){
		if ((*i).compare(token))
			return true;
	}
	return false;
}

//std::ostream& operator<<(std::ostream& os, const stopword &stopword){
//	std::ostringstream buffer;
//	buffer << stopword.stopwords;
//
//}


