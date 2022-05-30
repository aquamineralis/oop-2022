#pragma once
#include "Hash.h"


class EasyHash : public Hash
{
public:
	int CalcHash(const char* sir) override;
};

