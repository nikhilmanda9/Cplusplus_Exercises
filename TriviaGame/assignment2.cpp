//driver program

#include "question.h"
#include "triviagame.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void PlayGame(TriviaGame game); //Function prototype

int main()
{
   string inputFile;
   cout << "Enter file name" << endl;
   cin >> inputFile;

   TriviaGame gameOne(inputFile); //create an instance of the trivia game class using the read in input file name

   PlayGame(gameOne); //uses the instance of the trivia game class to call the function


   return 0;
}

void PlayGame(TriviaGame game)
{

   unsigned int userChoice; //stores the answer number entered by the user
   bool userOneResult; //determines if player 1 got a question correct or incorrect
   bool userTwoResult; //determines if player 2 got a question correct or incorrect
   unsigned int nQuestions; //holds the number of questions
   unsigned int tempOneScore; //holds a temporary score for player 1
   unsigned int tempTwoScore; //holds a temporary score for player 2
   unsigned int playerOneFinalScore; //holds the final score for player 1
   unsigned int playerTwoFinalScore; //holds the final score for player 2
   double playerOneAvgScore; //holds the average score for player 1 based on their final score
   double playerTwoAvgScore; //holds the average score for player 2 based on their final score
   double gameAverageScore; //holds the average score for the entire trivia game based on both players final scores

   Question* pQuestions = game.getQuestionsPtr(); //stores the address of pQuestions
   nQuestions = game.getNumQuestions(); //returns the number of questions from the input file and stores it in nQuestions

   cout << "This game consists of 2 players, each answering " << (nQuestions / 2) << " questions." << endl;
   cout << "The player with the most points will win the game." << endl;
   cout << endl;

   //questions 1 to (nQuestions / 2) are for player 1 while questions (nQuestions / 2) + 1 to nQuestions are for player 2
   for(unsigned int i = 0; i < (nQuestions / 2); i++)
   {
      //player one
      cout << "Question # " << (i + 1) << " for player 1" << endl;
      cout << pQuestions[i].getQuestionName() << endl; //returns the question text for player 1
      cout << endl;
      cout << "Pick from the following answers:" << endl;
      string * tempStr = pQuestions[i].getAnswerChoices(); //returns all the answer choices for the given question text

      //access all answer choices through a temporary string for player 1
      cout << "A # 1" << ": " << tempStr[0]<< endl;
      cout << "A # 2" << ": " << tempStr[1] << endl;
      cout << "A # 3" << ": " << tempStr[2] << endl;
      cout << "A # 4" << ": " << tempStr[3] << endl;
      cout << endl;

      cout << "Enter your answer:"  << endl;
      cin >> userChoice; //player 1 enters their answer

      userOneResult = game.checkAnswerChoice((i+1), userChoice); //checks player 1 answer

      //player two
      cout << endl;
      cout << "Question # " << (i+1) << " for player 2" << endl;
      cout << pQuestions[(nQuestions / 2) + i ].getQuestionName() << endl; //returns the question text for player 2
      cout << endl;
      cout << "Pick from the following answers:" << endl;
      tempStr = pQuestions[(nQuestions / 2) + i].getAnswerChoices(); //returns all the answer choices for the given question text

      //access all answer choices through a temporary string for player 2
      cout << "A # 1" << ": " << tempStr[0]<< endl;
      cout << "A # 2" << ": " << tempStr[1] << endl;
      cout << "A # 3" << ": " << tempStr[2] << endl;
      cout << "A # 4" << ": " << tempStr[3] << endl;
      cout << endl;

      cout << "Enter your answer:"  << endl;
      cin >> userChoice; //player 2 enters their answer

      userTwoResult = game.checkAnswerChoice((nQuestions / 2) + i + 1, userChoice); //checks player 1 answer
      cout << endl;

      if(userOneResult) //checks if player 1 got the correct answer
      {
         cout << "Player 1 had the correct answer for question " << (i + 1) << endl;
         tempOneScore = game.getPlayerOneScore(); //returns the old score for player 1
         game.setPlayerOneScore(tempOneScore + 1); //updates the new score for player 1
      }
      else
      {
         cout << "Player 1 had the incorrect answer for question " << (i + 1) << endl;
      }

      if(userTwoResult)
      {
         cout << "Player 2 had the correct answer for question " << (i + 1) << endl;
         tempTwoScore = game.getPlayerTwoScore(); //returns the old score for player 2
         game.setPlayerTwoScore(tempTwoScore + 1); //updates the new score for player 2
      }
      else
      {
         cout << "Player 2 had the incorrect answer for question " << (i + 1) << endl;
      }
      cout << endl;
   }

   //returns both players final scores
   playerOneFinalScore = game.getPlayerOneScore();
   playerTwoFinalScore = game.getPlayerTwoScore();

   if(playerOneFinalScore > playerTwoFinalScore) //checks if player 1 has more points than player 2
   {
      cout << "Player 1 wins with " << playerOneFinalScore << " points, player 2 received " << playerTwoFinalScore << " points." << endl;
      cout << endl;
   }
   else if(playerOneFinalScore < playerTwoFinalScore) //checks if player 2 has more points than player 1
   {
      cout << "Player 2 wins with " << playerTwoFinalScore << " points, player 1 received " << playerOneFinalScore << " points." << endl;
      cout << endl;
   }
   else
   {
      //displayed if player 1 and player 2 have the same number of points
      cout << "Players 1 and 2 tied with " << playerTwoFinalScore << " points for each player." << endl;
      cout << endl;
   }

   cout << fixed << setprecision(1) << showpoint;

   //calculates the average scores for both players
   //since the number of questions from the input file will be at least 2 and is an even number
   //each player has the same number of questions
   playerOneAvgScore = (((playerOneFinalScore) / (nQuestions / 2.0))) * 100;
   playerTwoAvgScore = (((playerTwoFinalScore) / (nQuestions / 2.0))) * 100;

   //displays the average scores for both players
   cout << "Player 1 mean was " << playerOneAvgScore << "%" << endl;
   cout << "Player 2 mean was " << playerTwoAvgScore << "%" << endl;

   //calculates the average number of points for the entire trivia game
   gameAverageScore = ((playerOneFinalScore + playerTwoFinalScore) / static_cast<double> (nQuestions)) * 100;

   cout << "Game mean was " << gameAverageScore << "%" << endl; //displays the average number of points for the entire game
}
