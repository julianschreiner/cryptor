#include "stdafx.h"
#include "File.h"


File::File(std::string fileName){
	this->_fileName = fileName;
}


File::~File(){

}

bool File::renameFile() {
	bool ok;

	this->setExtension();

	if (this->encrypt()) {
		std::string newHash = this->getHashName();
		//newHash += this->getExtension();

		ok = rename(this->_fileName.c_str(), newHash.c_str());
	}

	return ok;	
}

bool File::encrypt() {
	myEncrypt = new Encryption();

	myEncrypt->setHash(MAXSEEDHASH);

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

void File::setExtension() {
	size_t pos = this->_fileName.find(".");

	this->_origExtension = this->_fileName.erase(0, pos-1);
}

std::string File::getExtension() {
	return this->_origExtension;
}
