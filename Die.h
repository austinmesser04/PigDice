#ifndef DIE_H
#define DIE_H

class Die
{
private:
    int m_numOfSides;
    int m_dieValue;

public:
    Die();
    void set_dieValue();
    int get_dieValue();
    void set_numOfSides(int sides);
    int get_numOfSides();
};

#endif