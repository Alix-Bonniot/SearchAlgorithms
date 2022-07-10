#ifndef CNODE_H
#define CNODE_H

class CNode
{
public:
    enum class State
    {
        Empty,
        Obstacle,
        Initial,
        Goal
    };

public:
    CNode();
    CNode(const State state, const int index);

    // Copy constructor - assignment
    CNode(const CNode& node);
    CNode& operator=(const CNode& node);

    // Move constructor - assignment
    CNode(CNode&& node) noexcept;
    CNode& operator=(CNode&& node) noexcept;

    ~CNode();

    // Getters
    State GetState() const;
    CNode* GetParent() const;
    int GetIndex() const;

    // Setters
    void SetParent(CNode* parentPtr);
    void SetPathCost(const float pathCost);

    // Oprator overloading
    friend bool operator==(const CNode& lhs, const CNode& rhs);
    friend bool operator!=(const CNode& lhs, const CNode& rhs);

private:
    State m_state; // State
    CNode* m_parentPtr; // Parent
    float m_pathCost; // Path cost
    int m_index;
};

#endif