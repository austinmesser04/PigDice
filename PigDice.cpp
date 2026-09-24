#include <iostream>
#include <random>
/*// No longer need
#include <ctime>
#include <cstdlib>*/


// Build your solution starting from this code.

struct GameState
{
   char choice;
   int turn_count = 0;
   int game_score = 0;
   int score_this_turn = 0;
   bool game_over = false;
   bool turn_over = false;
};

// Die Class
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

// Function Prototypes:
void display_rules();
void hold(GameState &g);
void play_game(GameState &g, Die &die);
void take_turn(GameState &g, Die &die);
void roll(GameState &g, Die &die);

/*
// Old Protos
void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
*/

int main()
{
    GameState my_game; // instantiate a GameState object

    // New - instantiate a Die object
    Die my_die;

    display_rules(); // call the display_rules function

    /*// Old Code
    //play_game(my_game); // call the play_game function and pass the GameState object*/

     play_game(my_game, my_die);

    return 0;
}

// Die Class Function Definitions:

// Default Constructor
Die::Die()
{
    // Default die is 6 sided
    m_numOfSides = 6;

    // Starting die Value
    m_dieValue = 1;
}

// Sets the die Value using Mersenne Twister:
void Die::set_dieValue()
{
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(1, m_numOfSides);

    m_dieValue = distribution(generator);
}

// Returns the current die value:
int Die::get_dieValue()
{
    return m_dieValue;
}

// Changes the number of sides:
void Die::set_numOfSides(int sides)
{
    switch (sides)
    {
        case 4:
            m_numOfSides = 4;
            break;

        case 6:
            m_numOfSides = 6;
            break;

        case 8:
            m_numOfSides = 8;
            break;

        default:
            m_numOfSides = 6;
            break;
    }
}

// Returns the number of sides
int Die::get_numOfSides()
{
    return m_numOfSides;
}

// Function Definitions:

void display_rules()
{
    std::cout<<std::endl;
    std::cout<<"\nWelcome to Pig Dice!"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Here are the rules of the game:"<<std::endl;

    std::cout<<"1. See how many turns it takes you to get to 20 points."<<std::endl;
    std::cout<<"2. Turn ends when you hold or roll a 1."<<std::endl;
    std::cout<<"3. If you roll a 1, you lose all points for the turn."<<std::endl;
    std::cout<<"4. If you hold, you bank all points for the turn to the game score"<<std::endl;

    std::cout<<"Let's Play PIG Dice!"<<std::endl;
}

/*//Old Code
void play_game(GameState &g)
{
   while (!g.game_over)
   {
       take_turn(g);
       g.game_score+=g.score_this_turn;
       if (g.game_score>=20)
       {
           g.game_over = true;
       }
       else
       {
           g.turn_over = false;
           g.score_this_turn = 0;
       }
   }
   std::cout<<"\nYou finished with a final score of ";
   std::cout<<g.game_score;
   std::cout<<" in "<<g.turn_count<<" turns!";
   std::cout<<"\nThanks for playing!"<<std::endl;
}

void take_turn(GameState &g)
{
   g.turn_count++;
   std::cout<<"\nTurn "<<g.turn_count<<" - Game Score: "<<g.game_score;
   while (!g.turn_over)
   {
       std::cout<<"\nRoll or Hold? (r/h): ";
       std::cin>>g.choice;
       if(g.choice == 'r')
       {
           roll(g);
       }
       else if(g.choice == 'h')
       {
           hold(g);
       }
       else
       {
           std::cout<<"Invalid choice!";
       }
   }
   std::cout<<"\nScore Banked This Turn: "<<g.score_this_turn;
}


void roll(GameState &g)
{
   srand(time(NULL));
   int die = rand() % 6 + 1;
   std::cout<<"\nDie: "<<die;
   if (die==1)
   {
       std::cout<<"\nTurn over. No score.\n";
       g.score_this_turn = 0;
       g.turn_over = true;
   }
   else
   {
       g.score_this_turn+=die;
       std::cout<<" - Running score this turn: "<<g.score_this_turn;
   }
}*/

// New Code

// Plays game
void play_game(GameState &g, Die &die)
{
    while (!g.game_over)
    {
        take_turn(g, die);

        g.game_score += g.score_this_turn;

        if (g.game_score >= 20)
        {
            g.game_over = true;
        }
        else
        {
            g.turn_over = false;
            g.score_this_turn = 0;
        }
    }

    std::cout<<"\nYou finished with a final score of ";
    std::cout<<g.game_score;
    std::cout<<" in "<<g.turn_count<<" turns!";
    std::cout<<"\nThanks for playing!"<<std::endl;
}

// Takes Turn
void take_turn(GameState &g, Die &die)
{
    g.turn_count++;

    std::cout<<"\nTurn "<<g.turn_count<<" - Game Score: "<<g.game_score;

    while (!g.turn_over)
    {
        std::cout<<"\nRoll or Hold? (r/h): ";
        std::cin>>g.choice;

        if(g.choice=='r')
        {
            // OLD CALL
            // roll(g);

            // NEW CALL
            roll(g, die);
        }
        else if(g.choice=='h')
        {
            hold(g);
        }
        else
        {
            std::cout<<"Invalid choice!";
        }
    }

    std::cout<<"\nScore Banked This Turn: "<<g.score_this_turn;
}

// Roll
void roll(GameState &g, Die &die)
{
    // Roll the Die object
    die.set_dieValue();

    // Get the value that was rolled
    int dieValue=die.get_dieValue();

    std::cout<<"\nDie: "<<dieValue;

    if (dieValue==1)
    {
        std::cout<<"\nTurn over. No score.\n";

        g.score_this_turn=0;
        g.turn_over=true;
    }
    else
    {
        g.score_this_turn+=dieValue;

        std::cout<<" - Running score this turn: "<<g.score_this_turn;
    }
}

void hold(GameState &g)
{
   g.turn_over=true;
}