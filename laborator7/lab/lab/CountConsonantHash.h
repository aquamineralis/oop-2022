#pragma once
#include "Hash.h"


class CountConsonantHash : public Hash
{
public:
	int CalcHash(const char* sir) override;
};

