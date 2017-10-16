/*
 * document.h
 *
 *  Created on: Oct 11, 2017
 *      Author: samue
 */

#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <string>
#include <vector>
#include "tokenizer.h"
#include "stopword.h"

class Document {
public:
	Document();
	Document(std::string fileName);
	Document(std::string fileName, std::string stopwordsfile);
	struct TermDoc {
		// Members
		std::string term;
		int freq;

		// Not equal operator
		bool operator!=(const TermDoc& a) {
			if (a.term != term) {
				return true;
			} else {
				return false;
			}
		}

		// Equal operator
		bool operator==(const TermDoc& a) {
			if (a.term == term) {
				return true;
			} else {
				return false;
			}
		}
	};
	stopword filter;
	friend const operator<<(std::ostream & os,
			Document doc);
	const std::string name(); 	// Return document filename
	const int size();			// Return size in characters
	const Document content();	// Return content
	void processFile();
	std::string containsPunctuation(std::string word);
	void increment(int index);
	bool isStopWord(std::string word, std::vector<std::string> stopWords);
	bool sortTerms();
	int findIndex(std::string word);
	bool compareEntries(TermDoc term, std::string word);
	std::string getFileName();
	void setFileName(std::string newFileName);
	int getLongestWord();
	void setLongestWord(int newLongest);
	std::vector<std::string> getContents();
	void setContents(std::vector<std::string>);
	virtual ~Document();

private:
	std::string fileName;
	std::vector<TermDoc> dict;
	unsigned longestWord;
	std::vector<std::string> contents;
};

#endif /* DOCUMENT_H_ */
