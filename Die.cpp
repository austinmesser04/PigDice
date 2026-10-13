#include <random> //Global 
#include "Die.h" //local

Die::Die() // Default Constructor
{
    m_dieValue=0;
}

void Die::rollDie()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(1, 6);

    m_dieValue=dis(gen);
}

int Die::getDieValue() const
{
    return m_dieValue; // Rules for accessing the data
}