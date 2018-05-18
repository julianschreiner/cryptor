#pragma once
#include <string>
#include <stdio.h>
#include "Encryption.h"
#include <string.h>

class File
{

private:
	std::string _fileName;
	std::string _hashName;
	Encryption *myEncrypt;

public:
	File(std::string fileName);
	~File();
	bool renameFile();
	bool encrypt();
	bool decrypt();
	void setHashName(std::string hashName);
	std::string getHashName();

};

