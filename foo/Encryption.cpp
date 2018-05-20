#include "stdafx.h"
#include "Encryption.h"


Encryption::Encryption()
{
	this->_dict = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' , 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	this->_numbers = {1,2,3,4,5,6,7,8,9,0};
}


Encryption::~Encryption()
{
}

void Encryption::setHash(int length) {
	std::string createHash;
	int randomSeed = 0;
	int randomSeed2 = 0;
	int state = 0;
	srand(time(NULL));

	for (int i = 0; i < length; i++) {
		if (state == 0) {
			//dict
			randomSeed = rand() % 26;
			createHash += this->_dict.at(randomSeed);
			state = 1;
		}
		else {
			//number
			randomSeed2 = rand() % 10;
			createHash += std::to_string(this->_numbers.at(randomSeed2));
			state = 0;
		}
	}

	//puts(createHash.c_str());

	this->_hash = createHash;
}

std::string Encryption::getHash() {
	return this->_hash;
}