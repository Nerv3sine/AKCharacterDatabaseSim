#include "Database.h"

using namespace std;

Database::Database(){
    pre_set("database.txt");
    activeData = allInfo;
}

Database::Database(vector<ROperator> presetInfo)
:allInfo(presetInfo), activeData(presetInfo)
{
    
}

//get methods for the 2 ROperator vectors
ROperator Database::getOperator(int index) const{
    return activeData.at(index);
}

ROperator Database::getOperatorOG(int index) const{
    return allInfo.at(index);
}

int Database::getOperatorIndex(string operatorName) const{
    int start = 0;
    int end = allInfo.size() - 1;

    while(start <= end){

		int mid = (end + start) / 2;
		if(allInfo.at(mid).getCodeName() == operatorName){

			return mid;

		}else if(allInfo.at(mid).getCodeName() > operatorName){

			end = mid - 1;

		}else if(allInfo.at(mid).getCodeName() < operatorName){

			start = mid + 1;

		}else{

			cout << ("binary search function error");

		}
	}

	return -1;
}

int Database::getSize()const{
    return allInfo.size();
}

//edits the ROperator vectors
void Database::removeOperator(string operatorName){
    
    int i = getOperatorIndex(operatorName);
    allInfo.at(i) = allInfo.at(allInfo.size() - 1);
    allInfo.pop_back();
    sort(begin(allInfo), end(allInfo));
    activeData = allInfo;
}

void Database::addOperator(ROperator newOp){
    allInfo.push_back(newOp);
    sort(begin(allInfo), end(allInfo));    
    activeData = allInfo;
}

void Database::addOperator(string info){
    stringstream sStream(info);

    if(sStream.fail()){
        cout << ("add operator method failed");
    }

    vector<string> container;
    while(true){
        string s;

        sStream >> s;

        if(s != ""){
            container.push_back(s);
        }

        if(sStream.fail() && sStream.eof()){
            break;
        }
    }
    sStream.str("");

    vector<int> numVals = {};
    for(int x = 0; x < container.size(); x++){
        
        if(x != container.size() - 1){

            //this was used to try reduce the character count
            string temp = container.at(x);

            container.at(x) = temp.substr(0, temp.size() - 1);

            if(x != 0 && x != 2){
                numVals.push_back(stoi(container.at(x)));
            }
            continue;
        }

        numVals.push_back(stoi(container.at(x)));
    }

    ROperator newOp(container.at(0), numVals.at(0), container.at(2),
    numVals.at(1), numVals.at(2), numVals.at(3), numVals.at(4), numVals.at(5));

    allInfo.push_back(newOp);
}

//file read and writes
void Database::pre_set(string fileName){
    fstream file(fileName);

    if(file.fail()){
        
        cout  << ("file not found, write override executions here");

    }

    cout << "reading file...\n";

    while (true)
    {
        string s;

        getline(file, s);

        if(s != ""){
            addOperator(s);
        }

        if(file.eof() && file.fail()){
            break;
        }
    }

    file.close();

    sort(begin(allInfo), end(allInfo)); 
}

void Database::updateDatabase(string fileName){
    
    string output = getAllData();

    ofstream outputFile(fileName);

    if(outputFile.fail()){
        
        cout  << ("file not found, write override executions here");

    }

    outputFile << output;

    outputFile.close();
}

//returns a string that has all the information of the operators on the database
string Database::getAllData(){
    string output;
    for(ROperator dataPt : allInfo){
        output += dataPt.getInfo();
        output += "\n";
    }
    return output;
}


//sorting methods
void Database::invertCurrent(){
    reverse(begin(activeData), end(activeData));
}

void Database::sortByName(){
    sort(begin(activeData), end(activeData));
}

void Database::sortByRarity(){
    sort(begin(activeData), end(activeData), [](ROperator a, ROperator b){
        return(a.sortByRarity(a, b));
    });
}

void Database::sortByClass(){
    sort(begin(activeData), end(activeData), [](ROperator a, ROperator b){
        return(a.sortByClass(a, b));
    });
}

void Database::sortByCost(){
    sort(begin(activeData), end(activeData), [](ROperator a, ROperator b){
        return(a.sortByCost(a, b));
    });
}

void Database::sortByHP(){
    sort(begin(activeData), end(activeData), [](ROperator a, ROperator b){
        return(a.sortByHP(a, b));
    });
}

void Database::sortByDMG(){
    sort(begin(activeData), end(activeData), [](ROperator a, ROperator b){
        return(a.sortByDMG(a, b));
    });
}

void Database::sortByDEF(){
    sort(begin(activeData), end(activeData), [](ROperator a, ROperator b){
        return(a.sortByDEF(a, b));
    });
}

void Database::sortByRES(){
    sort(begin(activeData), end(activeData), [](ROperator a, ROperator b){
        return(a.sortByRES(a, b));
    });
}
