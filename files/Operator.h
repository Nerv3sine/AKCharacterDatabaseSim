#ifndef ROPERATOR_H
#define ROPERATOR_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

class ROperator{

    string codeName;
    int rarity;
    string opClass;

    int cost;
    int HP;
    int DMG;
    int DEF;
    int RES;

    public:

    ROperator(string codeName, int rarity, string opClass, int cost
    , int HP, int DMG, int DEF, int RES);

    string getCodeName() const;

    int getRarity() const;

    string getOpClass() const;

    int getCost() const;

    int getHP() const;

    int getDMG() const;

    int getDEF() const;

    int getRES() const;

    bool operator==(ROperator a);

    bool operator!=(ROperator a);

    bool operator>(ROperator a);

    bool operator<(ROperator a);

    string getInfo();


    bool sortByRarity(ROperator &A, ROperator &B)const;

    bool sortByClass(ROperator &A, ROperator &B)const;
    
    bool sortByCost(ROperator &A, ROperator &B)const;

    bool sortByHP(ROperator &A, ROperator &B)const;

    bool sortByDMG(ROperator &A, ROperator &B)const;

    bool sortByDEF(ROperator &A, ROperator &B)const;

    bool sortByRES(ROperator &A, ROperator &B)const;
};

#endif