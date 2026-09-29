#include <random> //Global 
#include "Die.h" //local

Die::Die()
{
    m_numOfSides=6;
    m_dieValue=1;
}

void Die::set_dieValue()
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(1, m_numOfSides);

    m_dieValue=distribution(generator);
}

int Die::get_dieValue()
{
    return m_dieValue;
}


void Die::set_numOfSides(int sides)
{
    switch (sides)
    {
        case 4:
            m_numOfSides=4;
            break;

        case 6:
            m_numOfSides=6;
            break;

        case 8:
            m_numOfSides=8;
            break;

        default:
            m_numOfSides=6;
            break;
    }
}

int Die::get_numOfSides()
{
    return m_numOfSides;
}