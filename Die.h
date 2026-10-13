//
// Austin Messer: Pig Dice 2.0
//

#ifndef DIE_H
#define DIE_H

class Die
{
private:
    int m_dieValue;

public:
    Die();
    void rollDie();
    int getDieValue() const;
};

#endif