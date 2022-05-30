#pragma once
#include "Hash.h"

class CountAsciiHash : public Hash
{
public:
	int CalcHash(const char* sir) override;
};

