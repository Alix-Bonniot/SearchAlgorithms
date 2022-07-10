#include "CMaze.h"
#include "utility.h"

#include <algorithm>
#include <iostream>

typedef CNode::State State;

CMaze::CMaze(const std::string_view& mazeFile, const int nRows,
	const int nColumns)
: m_nRows{ nRows }
, m_nColumns{ nColumns }
, m_initialNodeIndex{ -1 }
, m_goalNodeIndex{ -1 }
{
	int index{ 0 };
	for (const char character : mazeFile)
	{
		if (character == '\n')
		{
			continue;
		}

		switch (character)
		{
		case '-':
			m_maze.push_back(CNode{ State::Empty, index });
			break;
		case '#':
			m_maze.push_back(CNode{ State::Obstacle, index });
			break;
		case 'I':
			m_maze.push_back(CNode{ State::Initial, index });
			m_initialNodeIndex = index;
			break;
		case 'G':
			m_maze.push_back(CNode{ State::Goal, index });
			m_goalNodeIndex = index;
			break;
		}
		
		++index;
	}
}

CMaze::~CMaze()
{
	m_maze.clear();
	std::cout << "CMaze::~CMaze()\n";
}

std::vector<CNode> CMaze::GetNeighbors(const CNode& node) const
{
	const int nodeIndex{ node.GetIndex() };
	const int nodeRow{ nodeIndex / m_nRows };
	const int nodeColumn{ nodeIndex - (nodeRow * m_nRows) };

	std::vector<CNode> neighbors;
	for (int offset{ -1 }; offset <= 1; offset += 2)
	{
		const int row{ (nodeRow + offset) };
		if ((row >= 0) && (row < m_nRows))
		{
			const int index{ (row * m_nRows) + nodeColumn };
			if (m_maze[index].GetState() != State::Obstacle)
			{
				CNode neighbor{ m_maze[index] };
				neighbor.SetParent(DBG_NEW CNode{ node });
				neighbors.push_back(neighbor);
			}
		}

		const int column{ (nodeColumn + offset) };
		if ((column >= 0) && (column < m_nColumns))
		{
			const int index{ (nodeRow * m_nRows) + column };
			if (m_maze[index].GetState() != State::Obstacle)
			{
				CNode neighbor{ m_maze[index] };
				neighbor.SetParent(DBG_NEW CNode{ node });
				neighbors.push_back(neighbor);
			}
		}
	}

	return  neighbors;
}

CNode CMaze::GetInitialNode() const
{
	return m_maze[m_initialNodeIndex];
}

CNode CMaze::GetGoalNode() const
{
	return m_maze[m_goalNodeIndex];
}

int CMaze::GetColumnsNumber() const
{
	return m_nColumns;
}

std::vector<CNode> CMaze::GetMaze() const
{
	return m_maze;
}
