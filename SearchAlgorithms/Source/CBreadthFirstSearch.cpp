#include "CBreadthFirstSearch.h"
#include "utility.h"

#include <algorithm>
#include <iostream>
#include <queue>

typedef CNode::State State;

CBreadthFirstSearch::CBreadthFirstSearch()
{
}

CBreadthFirstSearch::~CBreadthFirstSearch()
{
}

bool CBreadthFirstSearch::Search(const CMaze& maze) const
{
	CNode node{ maze.GetInitialNode() };
	std::queue<CNode> frontier;
	std::vector<CNode> reached;

	CNode goal{ maze.GetGoalNode() };
	if (node == goal)
	{
		CreatePath(node, maze);
		return true;
	}

	frontier.push(node);
	while (!frontier.empty())
	{
		node = frontier.front();
		frontier.pop();
		reached.push_back(node);

		for (const CNode& neighbor : maze.GetNeighbors(node))
		{
			if (neighbor == goal)
			{
				CreatePath(neighbor, maze);
				return true;
			}

			if (std::find(
				reached.begin(), 
				reached.end(), 
				 neighbor) == reached.end()
				)
			{
				frontier.push(neighbor);
			}
		}
	}

	return false;
}

void CBreadthFirstSearch::CreatePath(const CNode node, const CMaze& maze) const
{
	CNode* nodePtr{ node.GetParent() };
	std::vector<int> pathIndices;

	while (nodePtr->GetParent())
	{
		pathIndices.push_back(nodePtr->GetIndex());
		nodePtr = nodePtr->GetParent();
	}

	std::reverse(pathIndices.begin(), pathIndices.end());

	std::cout << "Path found!\n";
	int counter{ 0 };
	const auto mazeSet{ maze.GetMaze() };
	for (const CNode& node : mazeSet)
	{
		if (std::find(
			pathIndices.begin(),
			pathIndices.end(),
			node.GetIndex()) != pathIndices.end()
			)
		{
			std::cout << 'o';
		}
		else
		{
			switch (node.GetState())
			{
			case State::Empty:
				std::cout << '-';
				break;
			case State::Obstacle:
				std::cout << '#';
				break;
			case State::Initial:
				std::cout << 'I';
				break;
			case State::Goal:
				std::cout << 'G';
				break;
			}
		}

		++counter;
		if (counter >= maze.GetColumnsNumber())
		{
			std::cout << '\n';
			counter = 0;
		}
		else
		{
			std::cout << ' ';
		}
	}
}
