//Specification file for the Trivia Game class
#ifndef TRIVIAGAME_H
#define TRIVIAGAME_H

//includes
#include "question.h"
#include <string>

//Trivia Game class declaration

class TriviaGame
{
   private:
      unsigned int numQuestions; //holds the even number of questions from the input file
      std::string tempString; //initially holds a arbitrary temporary string
      unsigned int playerOneScore; //holds the number of points for player 1
      unsigned int playerTwoScore; //holds the number of points for player 2
      double playerOneAvgScore; //holds the average number of points for player 1
      double playerTwoAvgScore; //holds the average number of points for player 2
      double avgGameScore; //holds the average number of points for the entire game
      Question *pQuestions; //holds a pointer to each question

   public:
      TriviaGame(std::string inputFileName); //constructor
      ~TriviaGame(); //destructor

   //Member functions
      unsigned int getNumQuestions() const;
      unsigned int getPlayerOneScore() const;
      unsigned int getPlayerTwoScore() const;
      bool checkAnswerChoice(unsigned int questionNumber, unsigned int userChoice);
      Question* getQuestionsPtr();

      void setPlayerOneScore(unsigned int playerOnePoints);
      void setPlayerTwoScore(unsigned int playerTwoPoints);

};

#endif
