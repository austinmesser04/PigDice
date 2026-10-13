#ifndef PIGDICE_PDGAME_H
#define PIGDICE_PDGAME_H
#include "Turn.h"

class PDGame
{
    private:
        Turn m_myTurn;
        bool m_gameOver;
        int m_gameScore;

    public:
        PDGame();
        int getGameScore() const; // 1. Added interface for public getter method to return private m_gameScore from “whole”

    private:
        void displayRules();
        void playGame();
};


#endif //PIGDICE_PDGAME_H
