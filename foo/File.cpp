#include "stdafx.h"
#include "File.h"


File::File(std::string fileName){
	this->_fileName = fileName;
}


File::~File(){

}

bool File::renameFile() {
	bool ok;

	/* CREATE RANDOM HASH FOR NEW FILE NAME */
	if (this->encrypt()) {
		/* THEN ASSIGN IT TO NEW FILE NAME */
		ok = rename(this->_fileName.c_str(), this->getHashName().c_str());	//TODO EXTENSION GETS LOST , DETECT IT FROM ORIGINAL
	}

	return ok;	
}

bool File::encrypt() {
	myEncrypt = new Encryption();

	myEncrypt->setHash(10);

	this->setHashName(myEncrypt->getHash());

	if (this->getHashName().length() > 0) return true;
	else return false;
}

bool File::decrypt() {
	return true;
}

void File::setHashName(std::string hashName) {
	this->_hashName = hashName;
}
std::string File::getHashName() {
	return this->_hashName;
}