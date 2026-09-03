#include <iostream>
#include <ctime>
#include <cstdlib>


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


// Function Prototypes:
void play_game(GameState &g);
void take_turn(GameState &g);
void roll(GameState &g);
void hold(GameState &g);


int main()
{
   GameState my_game; // instantiate a GameState object
   std::cout<<"Game Score is: "<<my_game.game_score<<std::endl;
  // display_rules(); // call the display_rules function
  play_game(my_game); // call the play_game function and pass the GameState object
   return 0;
}


// Function Definitions:


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
   std::cout<<" in "<<g.turn_over<<" turns!";
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
   std::cout<<"Score Banked This Turn: "<<g.score_this_turn;
}


void roll(GameState &g)
{
   srand(time(NULL));
   int die = rand() % 6 + 1;
   std::cout<<"Die: "<<die;
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
}


void hold(GameState &g)
{
   g.game_over = true;
}
