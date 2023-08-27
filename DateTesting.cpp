#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch_amalgamated.hpp"

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

TEST_CASE( "Criteria01" ) {
    REQUIRE( testConstructor());
}

TEST_CASE( "Criteria02") {
    REQUIRE( testString());
}

TEST_CASE( "Criteria03") {
    REQUIRE( testAddOperators());
}


TEST_CASE( "Criteria04" ) {
    REQUIRE( testExtractionOperators());
}

TEST_CASE( "Criteria05" ) {
    REQUIRE(testProgramIsFreeOfError());
}


bool testConstructor()
{
    cout << "\n Criteria 01: Constructors in correct format:" << endl;
    bool flag = true;
    flag&=checkCase("One Argument Constructor", Date(2018).toString() == "Jan 1, 2018");
    flag&=checkCase("Two Argument Constructor", Date(2018, 7).toString() == "Jul 1, 2018");
    final_criteria&=flag;
    return flag;
}

bool testString(){
    cout << "\n Criteria 02: toString() method is able to return correct format:" << endl;
    Date dd(2018, 9, 10);
    Date d = dd;
    bool flag=checkCase("String test", (d).toString() == "Sep 10, 2018");
    final_criteria&=flag;
    return flag;
}

bool testAddOperators(){
    cout << "\n Criteria 03: toString() method is able to return correct format and operator+ correctly calculates the number of days:" << endl;
    Date dd(2018, 9, 10);
    Date d = dd;
    bool flag = true;
    d = dd; flag&=checkCase("Operator+ test 1", (d + 23).toString() == "Oct 3, 2018");
    d = dd; flag&=checkCase("Operator+ test 2", (d + 38).toString() == "Oct 18, 2018");
    d = dd; flag&=checkCase("Operator+ test 3", (d + 56).toString() == "Nov 5, 2018");
    d = dd; flag&=checkCase("Operator+ test 4", (d + 91).toString() == "Dec 10, 2018");
    d = dd; flag&=checkCase("Operator+ test 5", (d + 134).toString() == "Jan 22, 2019");
    final_criteria&=flag;
    return flag;
}

bool testExtractionOperators(){
    cout << "\n Criteria 04: operator << displays the date in the correct format:" << endl;
    Date dd(2018, 9, 10);
    stringstream sout;
    sout << dd;
    bool flag=checkCase("Text Extraction Operator", sout.str() == "Sep 10, 2018");
    final_criteria&=flag;
    return flag;
}

bool testProgramIsFreeOfError()
{
    cout << "\n Criteria 05: Program is free of errors and passes all test cases " << endl;

    return checkCase("Program is free of errors and passes all test cases: ",final_criteria);
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
