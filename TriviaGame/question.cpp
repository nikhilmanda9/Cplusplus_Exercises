//Implementation file for the question class
#include "question.h"
#include <iostream>
#include <string>

using namespace std;

//Constructors
   Question::Question()
   {

   }
   Question::Question(string q, string answers[], unsigned int correctChoice)
   {
      questionName = q; //obtain the question name

      for(int i = 0; i < NUM_CHOICES; i++)
      {
         answerChoices[i] = answers[i]; //adds each answer choice in answers array to the answer choices array
      }

      correctAnswer = correctChoice; //obtain the correct answer number
   }

//Setter functions
   void Question::setQuestionName(string quest)
   {
      questionName = quest;
   }
   void Question::setAnswerChoices(std::string choices[])
   {
      for(int i = 0; i < NUM_CHOICES; i++)
      {
         answerChoices[i] = choices[i];
      }
   }
   void Question::setCorrectAnswer(unsigned int correct)
   {
      correctAnswer = correct;
   }

   //Getter functions
   string Question::getQuestionName() const
   {
      return questionName;
   }

   string* Question::getAnswerChoices()
   {
       return answerChoices; //returns the address of answerChoices
   }

   unsigned int Question::getCorrectAnswer() const
   {
      return correctAnswer;
   }
