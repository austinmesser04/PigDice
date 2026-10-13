// Austin Messer: Pig Dice 2.0

#include "PDGame.h"

#include <iostream>
#include <ostream>

PDGame::PDGame()
{
    m_gameOver=false;
    m_gameScore=0;
    m_myTurn.setParentGame(this); // 7. Added call to “part” object’s (Turn) public method to set the parent game object’s “whole" pointer from the “whole” constructor and pass the “whole” part object’s address
    displayRules();
    playGame();
}
int PDGame::getGameScore() const // 2. Added implementation for public getter of m_gameScore
{
    return m_gameScore;
}
void PDGame::displayRules()
{
    std::cout << "Let's Play PIG Dice!" << std::endl;
    std::cout << std::endl;

    std::cout << "* See how many turns it takes you to get to 20 points." << std::endl;
    std::cout << "* Turn ends when you hold or roll a 1." << std::endl;
    std::cout << "* If you roll a 1, you lose all points for the turn." << std::endl;
    std::cout << "* If you hold, you bank all points for the turn to the game score." << std::endl;
}
void PDGame::playGame()
{
    while(!m_gameOver)
    {
        m_myTurn.takeTurn();
        m_gameScore+=m_myTurn.getScoreThisTurn();

        if(m_gameScore>=20)
        {
            m_gameOver=true;
        }
        else
        {
            m_myTurn.resetTurnOver();
            m_myTurn.resetScoreThisTurn();
        }
    }

    std::cout<<"\nYou finished with a final score of ";
    std::cout<<m_gameScore;
    std::cout<<" in " <<m_myTurn.getTurnCount()<<" turns!";
    std::cout<<"\nThanks for playing PIG Dice!"<<std::endl;
}