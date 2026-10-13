#ifndef PIGDICE_TURN_H
#define PIGDICE_TURN_H
#include "Die.h"
// #include "PDGame.h"

class PDGame; // 3. Added forward declaration of "whole" class (PDGame) so the "part" class (Turn) knows it exists

class Turn
{
    private:
        int m_turnCount;
        int m_scoreThisTurn;
        bool m_turnOver;
        char m_choice;
        Die m_myDie;
        PDGame* m_parentGame=nullptr; // 4. Added a back pointer to the "whole" initialized to null pointer (defensive programming)

    public:
        Turn();
        void setParentGame(PDGame* parentGame); // 5. add interface for public setter function to connection “whole” class (PDGame) to “part” class (Turn)
        void takeTurn();
        int getScoreThisTurn() const;
        void resetTurnOver();
        int getTurnCount();
        void resetScoreThisTurn();

    private:
        void roll();
};


#endif //PIGDICE_TURN_H
