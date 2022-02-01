#include "Operator.h"

using namespace std;

ROperator::ROperator(string codeName, int rarity, string opClass, int cost, 
int HP, int DMG, int DEF, int RES)
: codeName(codeName), rarity(rarity), opClass(opClass), cost(cost)
,HP(HP), DMG(DMG), DEF(DEF), RES(RES)
{

}

//getter methods
string ROperator::getCodeName() const{
    return codeName;
}

int ROperator::getRarity() const{
    return rarity;
}

string ROperator::getOpClass() const{
    return opClass;
}

int ROperator::getCost() const{
    return cost;
}

int ROperator::getHP() const{
    return HP;
}

int ROperator::getDMG() const{
    return DMG;
}

int ROperator::getDEF() const{
    return DEF;
}

int ROperator::getRES() const{
    return RES;
}

//special operators for potential later use
bool ROperator::operator==(ROperator a){
    if(a.getCodeName() == codeName){
        return true;
    }
    return false;
}

bool ROperator::operator!=(ROperator a){
    if(a.getCodeName() != codeName){
        return true;
    }
    return false;
}

bool ROperator::operator>(ROperator a){
    if(codeName > a.getCodeName()){
        return true;
    }
    return false;
}

bool ROperator::operator<(ROperator a){
    if(codeName < a.getCodeName()){
        return true;
    }
    return false;
}

//method for quick extraction of operator info
string ROperator::getInfo(){
    string output;
    output += codeName + ", ";
    output += to_string(rarity) + ", ";
    output += opClass + ", ";
    output += to_string(cost) + ", ";
    output += to_string(HP) + ", ";
    output += to_string(DMG) + ", ";
    output += to_string(DEF) + ", ";
    output += to_string(RES);

    return output;
}

//sorting option variants
bool ROperator::sortByRarity(ROperator &A, ROperator &B)const{
    if(A.getRarity() == B.getRarity()){
        return A < B;
    }else{
        return A.getRarity() > B.getRarity();
    }
}

bool ROperator::sortByClass(ROperator &A, ROperator &B)const{
    if(A.getOpClass() == B.getOpClass()){
        return A < B;
    }else{
        return A.getOpClass() < B.getOpClass();
    }
}

bool ROperator::sortByCost(ROperator &A, ROperator &B)const{
    if(A.getCost() == B.getCost()){
        return A < B;
    }else{
        return A.getCost() > B.getCost();
    }
}

bool ROperator::sortByHP(ROperator &A, ROperator &B)const{
    if(A.getHP() == B.getHP()){
        return A < B;
    }else{
        return A.getHP() > B.getHP();
    }
}

bool ROperator::sortByDMG(ROperator &A, ROperator &B)const{
    if(A.getDMG() == B.getDMG()){
        return A < B;
    }else{
        return A.getDMG() > B.getDMG();
    }
}

bool ROperator::sortByDEF(ROperator &A, ROperator &B)const{
    if(A.getDEF() == B.getDEF()){
        return A < B;
    }else{
        return A.getDEF() > B.getDEF();
    }
}

bool ROperator::sortByRES(ROperator &A, ROperator &B)const{
    if(A.getRES() == B.getRES()){
        return A < B;
    }else{
        return A.getRES() > B.getRES();
    }
}