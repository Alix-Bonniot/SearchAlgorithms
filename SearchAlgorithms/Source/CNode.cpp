#include "CNode.h"
#include "utility.h"

#include <iostream>
#include <utility>

CNode::CNode()
: m_state{ State::Empty }
, m_parentPtr{ nullptr }
, m_pathCost{ -1.0f }
, m_index{ -1 }
{
}

CNode::CNode(const State state, const int index)
: m_state{ state }
, m_parentPtr{ nullptr }
, m_pathCost{ -1.0f }
, m_index{ index }
{
}

CNode::CNode(const CNode& node)
: m_state{ node.m_state }
, m_parentPtr{ nullptr }
, m_pathCost{ node.m_pathCost }
, m_index{ node.m_index }
{

    if (node.m_parentPtr)
    {
        m_parentPtr = DBG_NEW CNode{};
        *m_parentPtr = *node.m_parentPtr;
    }
}

CNode& CNode::operator=(const CNode& node)
{
    m_state = node.m_state;
    m_pathCost = node.m_pathCost;
    m_index = node.m_index;

    if (&node == this)
    {
        return *this;
    }

    delete m_parentPtr;

    if (node.m_parentPtr)
    {
        m_parentPtr = DBG_NEW CNode{};
        *m_parentPtr = *node.m_parentPtr;
    }

    return *this;
}

CNode::CNode(CNode&& node) noexcept
: m_state{ node.m_state }
, m_parentPtr{ node.m_parentPtr }
, m_pathCost{ node.m_pathCost }
, m_index{ node.m_index }
{

    node.m_parentPtr = nullptr;
}

CNode& CNode::operator=(CNode&& node) noexcept
{
    m_state = node.m_state;
    m_pathCost = node.m_pathCost;
    m_index = node.m_index;

    if (&node == this)
    {
        return *this;
    }

    delete m_parentPtr;

    m_parentPtr = node.m_parentPtr;
    node.m_parentPtr = nullptr;

    return *this;
}

CNode::~CNode()
{
    delete m_parentPtr;
}

CNode::State CNode::GetState() const
{
    return m_state;
}

CNode* CNode::GetParent() const
{
    return m_parentPtr;
}

int CNode::GetIndex() const
{
    return m_index;
}

void CNode::SetParent(CNode* parentPtr)
{
    if (m_parentPtr)
    {
        delete m_parentPtr;
    }

    m_parentPtr = parentPtr;
}

void CNode::SetPathCost(const float pathCost)
{
    m_pathCost = pathCost;
}

bool operator==(const CNode& lhs, const CNode& rhs)
{
    return (lhs.m_state == rhs.m_state) &&
           (lhs.m_index == rhs.m_index);
}

bool operator!=(const CNode& lhs, const CNode& rhs)
{
    return !(lhs == rhs);
}