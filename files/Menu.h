#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "Operator.h"
#include "Database.h"

using namespace std;

class Menu{

    Database* infoHub;

    public:

    Menu();

    void startUp();

    private:

    void spacing() const;

    void loading() const;


    void mainLoop();


    string mainScreen();


    string viewMain();

    int getPage(int size);

    void displayOperators(int current, int limit, bool details)const;

    string sortSelection(string prevSetting, int type);



    string addOp();

    int recordInput(int index, vector<string> &output);


    string findMenu();

    void findSubMenu(string choice);
    
    void getUserInput(string &sField, int &aField, int &bField, int &current);

    void displayOperators(vector<string> list, int current, int limit, bool details)const;

    void getResults(string sField, int aField, int bField, string current, vector<string> &output);

    int removeOperator(const vector<string> &input);

    void afterSort(string setting);


    string tabSpacing(string input)const;

    string getBool(bool arg)const;

};

#endif