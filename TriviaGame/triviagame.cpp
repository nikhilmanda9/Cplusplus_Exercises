//Implementation file for the trivia game class

#include "triviagame.h"
#include "question.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Constructor
   TriviaGame::TriviaGame(string inputFileName)
   {
      ifstream inputFile;
      playerOneScore = 0;
      playerTwoScore = 0;
      playerOneAvgScore = 0.0;
      playerTwoAvgScore = 0.0;
      avgGameScore = 0.0;

      inputFile.open(inputFileName.c_str()); //open the input file

      if(inputFile.fail()) //checks to see if the file opened or not
      {
         cout << "Error! File could not be opened." << endl;
      }
      else
      {
         getline(inputFile, tempString); //read in a single unsigned integer for the number of questions
         numQuestions = std::stoi(tempString); //converts string to integer and stores it in the number of questions

         pQuestions = new Question[numQuestions]; //dynamically allocate memory for the number of questions

         string tempQuestion; //holds the arbitrary question from the input file

         unsigned int tempCorrectChoice; //holds the number of the correct answer from the input file
         string tempChoice[NUM_CHOICES]; //holds an array of temporary answer choices

         for(unsigned int i = 0; i < numQuestions; i++) //for each question
         {

            getline(inputFile, tempQuestion); //reads in the question name

            for(int j = 0; j < NUM_CHOICES; j++) //for each of the answer choices
            {
               getline(inputFile, tempChoice[j]); //reads in all answer choices

            }
            getline(inputFile, tempString); //reads in the correct answer choice

            //converts the string version of the correct answer number to an integer and stores it in tempCorrectChoice
            tempCorrectChoice = std::stoi(tempString);

            //sets the temporary variables to the private data members from the question class
           pQuestions[i].setQuestionName(tempQuestion);
           pQuestions[i].setAnswerChoices(tempChoice);
           pQuestions[i].setCorrectAnswer(tempCorrectChoice);
         }
      }
   }

   //Destructor
   TriviaGame::~TriviaGame()
   {
     pQuestions = nullptr; //initializes the address of pQuestions to zero
   }

   unsigned int TriviaGame::getNumQuestions() const
   {
      return numQuestions;
   }

   bool TriviaGame::checkAnswerChoice(unsigned int questionNumber, unsigned int userChoice)
   {
      //checks if the correct answer to a question number from the input file matches the user's selected answer
      if(pQuestions[questionNumber - 1].getCorrectAnswer() == userChoice)
      {
         return true; //both answers match meaning it is the correct answer
      }
      else
      {
         return false; //user answer does not match the answer number in the input file and therefore, is the wrong answer
      }
   }
   unsigned int TriviaGame::getPlayerOneScore() const
   {
      return playerOneScore;
   }
   unsigned int TriviaGame::getPlayerTwoScore() const
   {
      return playerTwoScore;
   }
   Question* TriviaGame::getQuestionsPtr()
   {
      return pQuestions; //returns the address of pQuestions
   }
   void TriviaGame::setPlayerOneScore(unsigned int playerOnePoints)
   {
      playerOneScore = playerOnePoints;
   }
   void TriviaGame::setPlayerTwoScore(unsigned int playerTwoPoints)
   {
      playerTwoScore = playerTwoPoints;
   }
