//Specification file for the Question class
#ifndef QUESTION_H
#define QUESTION_H


#include<iostream>
#include<string>

const int NUM_CHOICES = 4;

//Question class declaration
class Question
{
   private:
   std::string questionName; //holds the name of the question
   std::string answerChoices[NUM_CHOICES]; //holds an array of 4 answer choices of type string for each question
   unsigned int correctAnswer; //holds the number of the correct answer that ranges from 1 to 4

   public:
   //Constructors go here
   Question();
   Question(std::string q, std::string answers[], unsigned int correctChoice);

   //Member functions
   void setQuestionName(std::string quest);
   void setAnswerChoices(std::string choices[]);
   void setCorrectAnswer(unsigned int correct);
   std::string getQuestionName() const;
   std::string* getAnswerChoices();
   unsigned int getCorrectAnswer() const;
};



#endif
