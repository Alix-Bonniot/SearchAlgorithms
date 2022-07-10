#ifndef CBREADTH_FIRST_SEARCH
#define CBREADTH_FIRST_SEARCH

#include "CSearchAlgorithm.h"

class CBreadthFirstSearch : public CSearchAlgorithm
{
public:
	CBreadthFirstSearch();
	~CBreadthFirstSearch();

	virtual bool Search(const CMaze& maze) const override;
	void CreatePath(const CNode node, const CMaze& maze) const;
};

#endif