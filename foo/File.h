#pragma once
#include <string>
#include <stdio.h>
#include "Encryption.h"
#include <string.h>

#define MAXSEEDHASH 20

class File
{

private:
	std::string _fileName;
	std::string _hashName;
	std::string _origExtension;
	Encryption *myEncrypt;

public:
	File(std::string fileName);
	~File();
	bool renameFile();
	bool encrypt();
	bool decrypt();
	void setHashName(std::string hashName);
	std::string getHashName();
	void setExtension();
	std::string getExtension();

};

