#include "quiz_question.h"
#include "rand_int.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

#include <random>

//Single quiz question

quiz_question::quiz_question()
{

}

quiz_question::quiz_question(const std::string &q, const std::string &a)
{
    vec_questions.push_back(q);
    vec_answers.push_back(a);
}

quiz_question::~quiz_question()
{
    //dtor
}

quiz_question::quiz_question(const quiz_question& other)
{
    //copy ctor
    vec_questions = other.vec_questions;
    vec_answers = other.vec_answers;
}

quiz_question& quiz_question::operator=(const quiz_question& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    vec_questions = rhs.vec_questions;
    vec_answers = rhs.vec_answers;

    return *this;
}

void quiz_question::addQuestion(const std::string q)
{
    vec_questions.push_back(q);
}

void quiz_question::addAnswer(const std::string a)
{
    vec_answers.push_back(a);
}

std::string quiz_question::question()
{
    int sz = vec_questions.size();
    if(sz==0) throw std::out_of_range{"Using uninitialized Quiz_question object"};

    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(0, sz-1);
    int idx = uniform_dist(e1);

    return vec_questions[idx];
}

bool quiz_question::isCorrect(const std::string &s)
{
    for(std::string a: vec_answers)
        if(s==a) return true;

    return false;
}
