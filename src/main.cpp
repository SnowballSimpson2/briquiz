#include <iostream>
#include "quiz_question.h"
#include <cstdlib>
#include <ctime>
#include "unit_test.h"





int main()
{
    using namespace std;
    srand((unsigned)time(0));

    Unit_test test;
    test.Empty_questionObect();
    test.smoke_test();
    //test.ask_test();
    return 0;
}
