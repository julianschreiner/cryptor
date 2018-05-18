#pragma once
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Encryption
{
private:
	std::string _hash;
	std::vector<char> _dict;
	std::vector<int> _numbers;

public:
	Encryption();
	~Encryption();
	void setHash(int length);
	std::string getHash();
};

