// a5.cpp

/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Jason Cai
// St.# : ----------
// Email: jason_cai_4@sfu.ca
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include<iostream>

#include "Menu.h"
#include "Database.h"
#include "Operator.h"

using namespace std;

int main(){
    cout << "running program...\n";
    Menu* mainProgram = new Menu();
    mainProgram->startUp();
    delete mainProgram;
}