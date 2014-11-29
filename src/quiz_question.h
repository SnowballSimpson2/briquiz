#ifndef QUIZ_QUESTION_H
#define QUIZ_QUESTION_H

#include <string>
#include <vector>

class quiz_question
{
    public:
        quiz_question();
        ~quiz_question();

        quiz_question(const quiz_question&); //copy constructor
        quiz_question(const std::string&, const std::string&);
        quiz_question(const std::vector<std::string>&q, const std::vector<std::string>&a):
            vec_questions {q}, vec_answers{a} {};
        quiz_question& operator=(const quiz_question& other);

        void addQuestion(const std::string);
        void addAnswer(const std::string);
        std::string question();

        bool isCorrect(const std::string &);

        std::vector<std::string>& answers() {return vec_answers;}
        std::vector<std::string>& questions() {return vec_questions;}
    protected:
    private:
        std::vector<std::string> vec_questions;
        std::vector<std::string> vec_answers;
};

#endif // QUIZ_QUESTION_H
