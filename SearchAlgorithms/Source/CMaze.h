#ifndef CMAZE_H
#define CMAZE_H

#include "CNode.h"

#include <string_view>
#include <vector>

class CMaze
{
public:
	CMaze(const std::string_view& mazeFile, const int nRows, 
		const int nColumns);
	~CMaze();

	std::vector<CNode> GetNeighbors(const CNode& node) const;
	CNode GetInitialNode() const;
	CNode GetGoalNode() const;

	int GetColumnsNumber() const;

	std::vector<CNode> GetMaze() const;

private:
	const int m_nRows;
	const int m_nColumns;

	std::vector<CNode> m_maze;
	int m_initialNodeIndex;
	int m_goalNodeIndex;
};

#endif