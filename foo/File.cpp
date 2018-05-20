#include "stdafx.h"
#include "File.h"



File::File(std::string fileName){
	this->_fileName = fileName;
}


File::~File(){
	delete myEncrypt;
}

bool File::renameFile() {
	int ok;

	this->setExtension();

	if (this->encrypt()) {
		std::string newHash = this->getHashName();
		newHash += this->getExtension();

		//std::ofstream _file(this->_fileName.c_str(), std::ofstream::app);
		
		ok = rename(this->_fileName.c_str(), newHash.c_str());

		//_file.close();
	}
	

	return ok == 0 ? true : false;	
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
	std::string fileNameCop = this->_fileName;

	this->_origExtension = fileNameCop.erase(0, pos-1);
}

std::string File::getExtension() {
	return this->_origExtension;
}
