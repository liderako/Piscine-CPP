#include <iostream>
#include "Replace.hpp"
// CONSTRUCT
Replace::Replace(void) {
	this->s1 = "null";
	this->s2 = "null";
	this->fileName = "null.replace";
}

Replace::Replace(std::string s1, std::string s2, std::string fileName) {
	this->s1 = s1;
	this->s2 = s2;
	this->fileName = fileName;

	for (size_t i = 0; i < fileName.length(); ++i) {
		fileName[i] = toupper(fileName[i]);
	}
	this->createFileName = std::string(fileName + ".replace");
}

// DESTRUCT
Replace::~Replace(void) {
	return ;
}

// SETS
void Replace::setS1(std::string s) {
	this->s1 = s;
}
void Replace::setS2(std::string s) {
	this->s2 = s;
}
void Replace::setFileName(std::string fileName) {
	this->fileName = fileName;
}

// GETS
std::string Replace::getS1(void) {
	return (this->s1);
}
std::string Replace::getS2(void) {
	return (this->s2);
}
std::string Replace::getFileName(void) {
	return (this->fileName);
}

std::string Replace::getCreateFileName(void) {
	return (this->createFileName);
}

// Validation

void 	Replace::validation(void) {
	if (this->s1.length() == 0 || this->s2.length() == 0) {
		std::cout << "empty string\n";
		std::exit(1);
	}
}