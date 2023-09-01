#include <iostream>
#include "Date.h"
using namespace std;

bool testConstructor();
bool testString();
bool testAddOperators();
bool testExtractionOperators();
bool testProgramIsFreeOfError();
bool checkCase(string name, bool condition);
bool final_criteria=true;


int main()
{
    cout << "Date Class Testing!" << endl;
    bool c1,c2,c3,c4;
    
    c1=testConstructor();

    c2=testString();

    c2=testAddOperators();

    c3=testExtractionOperators();

    c4=testProgramIsFreeOfError();

    return 0;
}


bool testConstructor()
{
    cout << "\nCriteria 01: Constructors in correct format:" << endl;
    bool flag = true;
    flag&=checkCase("One Argument Constructor", Date(2018).toString() == "Jan 1, 2018");
    flag&=checkCase("Two Argument Constructor", Date(2018, 7).toString() == "Jul 1, 2018");
    final_criteria&=flag;
    if(flag)
        cout<<"\nCriteria 01: 20 Points."<<endl<<endl;
    else
        cout<<"\nCriteria 01: 0 Points."<<endl<<endl;
    return flag;
}

bool testString(){
    cout << "\nCriteria 02: toString() method is able to return correct format:" << endl;
    Date dd(2018, 9, 10);
    Date d = dd;
    bool flag=checkCase("String test", (d).toString() == "Sep 10, 2018");
    final_criteria&=flag;
    if(flag)
        cout<<"\nCriteria 02: 20 Points."<<endl<<endl;
    else
        cout<<"\nCriteria 02: 0 Points."<<endl<<endl;
    return flag;
}

bool testAddOperators(){
    cout << "\nCriteria 03: toString() method is able to return correct format and operator+ correctly calculates the number of days:" << endl;
    Date dd(2018, 9, 10);
    Date d = dd;
    bool flag = true;
    d = dd; flag&=checkCase("Operator+ test 1", (d + 23).toString() == "Oct 3, 2018");
    d = dd; flag&=checkCase("Operator+ test 2", (d + 38).toString() == "Oct 18, 2018");
    d = dd; flag&=checkCase("Operator+ test 3", (d + 56).toString() == "Nov 5, 2018");
    d = dd; flag&=checkCase("Operator+ test 4", (d + 91).toString() == "Dec 10, 2018");
    d = dd; flag&=checkCase("Operator+ test 5", (d + 134).toString() == "Jan 22, 2019");
    if(flag)
        cout<<"\nCriteria 03: 20 Points."<<endl<<endl;
    else
        cout<<"\nCriteria 03: 0 Points."<<endl<<endl;
    final_criteria&=flag;
    return flag;
}

bool testExtractionOperators(){
    cout << "\nCriteria 04: operator << displays the date in the correct format:" << endl;
    Date dd(2018, 9, 10);
    stringstream sout;
    sout << dd;
    bool flag=checkCase("Text Extraction Operator", sout.str() == "Sep 10, 2018");
    final_criteria&=flag;
    if(flag)
        cout<<"\nCriteria 04: 20 Points."<<endl<<endl;
    else
        cout<<"\nCriteria 04: 0 Points."<<endl<<endl;
    return flag;
}

bool testProgramIsFreeOfError()
{
    cout << "\nCriteria 05: Program is free of errors and passes all test cases " << endl;
    checkCase("Program is free of errors and passes all test cases: ",final_criteria);
    if(final_criteria)
        cout<<"\nCriteria 05: 20 Points."<<endl<<endl;
    else
        cout<<"\nCriteria 05: 0 Points."<<endl<<endl;
    return final_criteria;
}

bool checkCase(string name, bool condition)
{
    if(!condition)
    {
        cout << name << ": Failed" << endl;
    }
    else{
        cout << name << ": Passed" << endl;
    }

    return condition;
}
