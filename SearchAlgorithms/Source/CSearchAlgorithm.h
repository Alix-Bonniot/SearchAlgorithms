#ifndef CSEARCH_ALGORITHM_H
#define CSEARCH_ALGORITHM_H

#include "CMaze.h"

class CSearchAlgorithm
{
public:
	virtual bool Search(const CMaze& maze) const = 0;
};

#endif