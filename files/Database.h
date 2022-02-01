#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "Operator.h"

using namespace std;

class Database{

    vector<ROperator> allInfo;
    vector<ROperator> activeData;

    public:

    Database();

    Database(vector<ROperator> preset);

    ROperator getOperator(int index) const;

    ROperator getOperatorOG(int index) const;

    int getOperatorIndex(string operatorName) const;

    int getSize()const;

    
    void removeOperator(string operatorName);

    void addOperator(ROperator newOp);

    void addOperator(string info);


    void pre_set(string fileName);

    void updateDatabase(string fileName);

    string getAllData();


    void invertCurrent();

    void sortByName();

    void sortByRarity();

    void sortByClass();

    void sortByCost();

    void sortByHP();

    void sortByDMG();

    void sortByDEF();

    void sortByRES();
};

#endif