#pragma once
#include "Hash.h"

class CountVowelsHash : public Hash
{
public:
	int CalcHash(const char* sir) override;
};

