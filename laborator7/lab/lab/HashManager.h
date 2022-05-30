#pragma once
#include "Hash.h"
class HashManager
{
	struct HashWithNames
	{
		Hash* hash;
		char* name;
	};
	HashWithNames hashes[50];
	int count;
public:
	HashManager() : count(0) {};
	Hash*& operator[](const char* name);
	void print_hashes(const char* sir);
};

