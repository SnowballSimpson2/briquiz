#include <iostream>
#include <limits>
#include "unit_test.h"
#include "quiz_question.h"

Unit_test::Unit_test()
{
    //ctor
}

void Unit_test::smoke_test()
{
    using namespace std;

	//We initialize a question object with a few vectors then add a few
	//questions and answers
    vector<string> vq {"Question1","Question2","Question3","Question4"};
    vector<string> va {"Answer1","Answer2","Answer3","Answer4"};

    quiz_question qq1(vq,va);

    qq1.addQuestion("Question5");
    qq1.addAnswer("Answer5");
    qq1.addQuestion("Question6"); //we won't add a question so q.size != a.size

	vq.push_back("Question5");
	vq.push_back("Question6");


	//Now we will generate questions in a loop to make sure random is weel distributed
    string temp;
	const int numQuestions = 6;

    vector<int> stats(numQuestions, 0);

    const int trials = 100;

    for(int i=0; i<trials; i++)
    {
        temp = qq1.question();

        for(int j=0; j<numQuestions; j++)
            if(temp == vq[j])
                stats[j]++;
    }
    // Print the results
    int minval = numeric_limits<int>::max(), maxval=0;
    for(int i=0; i<numQuestions;i++)
    {
        if(stats[i] < minval)
            minval = stats[i];
        if(stats[i] > maxval)
            maxval = stats[i];

        //cout << i+1 << ":" << stats[i] << " ";
    }

    //cout << " variation: " << maxval-minval << endl;

    //Now get the lowest and highest values and compare to threashold

    if((maxval-minval) == 0 || (maxval-minval) > trials/5)
        cout << "FAIL - Random question selection in question() is supicious." << endl;
    else
        cout << "PASS - Smoketest" << endl;
    cout << endl;



}

void Unit_test::Empty_questionObect()
{
    using namespace std;

    quiz_question qq1;
    try
        {cout << qq1.question() << endl;}
    catch(...)
        {cout << "PASS - Empty_questionObect()" << endl;};
}


void Unit_test::ask_test()
{
    using namespace std;

    string q1 = "What color is a stop sign?";
    string q2 = "Color of a cherry";
    string a1 = "red";
    string a2 = "rojo";

    quiz_question quiz1("Hint its red", "RED");
    quiz1.addQuestion(q1);
    quiz1.addAnswer(a1);
    quiz1.addQuestion(q2);
    quiz1.addAnswer(a2);

    cout << "Question: " << quiz1.question() <<": ";
    std::string ans;
    std::getline(cin, ans);

    if(quiz1.isCorrect(ans))
        cout << "CORRECT!" << endl;
    else
        cout << "WRONG!" << endl;
}
