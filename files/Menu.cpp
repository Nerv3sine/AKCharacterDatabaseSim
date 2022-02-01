#include "Menu.h"

using namespace std;

Menu::Menu(){

}

//starts up the entire database program
void Menu::startUp(){
    loading();
    infoHub = new Database();
    spacing();
    cout << "\tWELCOME to the PRTS Operator Database\n";
    mainLoop();
}

//formatting purposes
void Menu::spacing() const{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

//a message for the user if the program loading takes too long
void Menu::loading() const{
    cout << "Loading . . . \n";
}


//loop that controls the branches of options
void Menu::mainLoop(){

    string currentMode = "Main";

    while(currentMode != "Quit"){

        //resets the database sorting
        infoHub->sortByName();

        if(currentMode == "Main")
        {
            currentMode = mainScreen();
        }else if(currentMode == "Edit"){
            currentMode = findMenu();
        }
        else if(currentMode == "View")
        {
            currentMode = viewMain();
        }else if(currentMode == "Add")
        {
            currentMode = addOp();
        }
    }

    //shuts down the program
    cout << "Shutting Down...\n";

    //updates the text file for next time
    infoHub->updateDatabase("database.txt");

    delete infoHub;
}


//main menu
string Menu::mainScreen(){

    int choice = 0;
    while(true){

        //provides the user interface and choices
        string userInput = "";
        cout << "\t\t    Main Menu\n\n";
    
        cout << "1) View Operators\n";
        cout << "2) Search/Remove Operators\n";
        cout << "3) Add Operators\n";
        cout << "4) Quit\n\n";
        cout << "(Please enter the number of your desired choice)\n";
        
        //user interaction
        cin >> userInput;
        spacing();
        try{
            choice = stoi(userInput);
        }catch(...){
            //catches error if the user inputs anything other than numbers
        }

        if(choice > 0 && choice < 5){
            break;
        }
    }
    
    //sets which choice to branch off on
    switch(choice){
        case 1:
            return "View";
            break;
        case 2:
            return "Edit";
            break;
        case 3:
            return "Add";
            break;
        case 4:
            return "Quit";
            break;
        default:
            cout << ("Choice making in main menu malfunctioning");
            return "Error";
    }
}


//Vew operators interface
string Menu::viewMain(){
    
    int choice = 0;

    //settings
    int page = 0;
    string filter = "Code Name";
    bool details = false;

    while(true){
        
        //displays the operators(moved to seperate method)
        //moved due to having 2 settings for operator details
        displayOperators(page + 1, ((infoHub->getSize())/10 + 1), details);

        //using the userInput variable so there's one less variable to deall with
        string userInput = "";
        cout << "(enter a letter and then press enter to continue) ";
        cin >> userInput;

        //current settings
        cout << "___________________\n";
        cout << "Sorted by: " << filter << "\n";
        cout << "Details: " << getBool(details) << "\n";
        cout << "\n";
        
        //choices avaiable for the user
        cout << "1)Change Sort Mode\n";
        cout << "2)Invert List\n";
        cout << "3)Toggle Details\n";
        cout << "4)Previous Page\n";
        cout << "5)Next Page\n";
        cout << "6)Select Page\n";
        cout << "7)Exit\n";
        cout << "(Please enter the number of your desired choice)\n";
        
        //gets and checks user input
        while(true){

            cin >> userInput;
            try{
                choice = stoi(userInput);
                if(choice > 0 && choice < 8){
                    break;
                }
            }catch(...){

            }
        }
        
        spacing();

        //acts on the choice that the user has provided
        switch(choice){
            case 1:
                filter = sortSelection(filter, 1);
                spacing();
                break;
            case 2:
                //inverts the current database
                infoHub->invertCurrent();
                break;
            case 3:
                //toggles details
                details = !details;
                break;
            case 4:
                //goes to previous page(or the last page)
                page--;
                if(page < 0){
                    page = (infoHub->getSize())/10;
                }
                break;
            case 5:
                //goes to next page(or the first page)
                page++;
                if(page > (infoHub->getSize())/10){
                    page = 0;
                }
                break;
            case 6:
                //code here has been moved to the getPage method
                choice = getPage(infoHub->getSize());
                spacing();
                if(choice > 0){
                    page = choice - 1;
                }
                break;
            case 7:
                //exits to main menu
                return "Main";
                break;
        }

    }
}

//gets user input on what page the user would like to jump to
int Menu::getPage(int size){
    cout << "Which page would you like to jump to?\n";
    cout << "(range from 1 to " << (size/10 + 1) 
    << ", or input 0 to cancel)\n";

    //gets user input
    string s = "";
    int output = 0;

    while(true){

        cin >> s;
        try{
            output = stoi(s);
            if(output >= 0 && output <= (size/10 + 1)){
                break;
            }
        }catch(...){

        }
    }

    return output;
}

//displays a list of operators, list max size is 10
void Menu::displayOperators(int current, int limit, bool details)const{
    
    if(!details){
        cout << "\tArchives\n\n";

        //prints the operators of a certain range
        cout << "Code Name" << "\t" << "Class\n";
        cout << "________________________\n";
        for(int x = 10 * (current - 1); x < infoHub->getSize() && x < 10 * (current); x++){
            ROperator current = infoHub->getOperator(x);
            cout << tabSpacing(current.getCodeName()) << current.getOpClass();
            cout << "\n";
        }
        
    }else{
        cout << "\t\t\t    Archives\n\n";

        //prints the operators of a certain range
        cout << "Code Name" << "\t" << "Rarity" << "\t" << "Class" <<
        "\t\t" << "Cost" << "\t" << "HP" << "\t" << "DMG" << "\t" << "DEF"
        << "\t" << "RES\n";

        //formatting purposes
        cout << "_________________________________"
        << "_________________________________"
        << "_________\n";

        //prints out information for up to 10 operators
        for(int x = 10 * (current - 1); x < infoHub->getSize() && x < 10 * (current); x++){
            ROperator current = infoHub->getOperator(x);
            cout << tabSpacing(current.getCodeName());
            cout << current.getRarity() << "\t";
            cout << tabSpacing(current.getOpClass());
            cout << current.getCost() << "\t";
            cout << current.getHP() << "\t";
            cout << current.getDMG() << "\t";
            cout << current.getDEF() << "\t";
            cout << current.getRES() << "\t";
            cout << "\n";
        }
        
    }

    //displays current page
    cout << "\nPage " << current 
    << " of " << limit << "\n\n";
    
}

//gets user input on what sorting that the list should be in
string Menu::sortSelection(string prevSetting, int type){
    if(type){
        cout << "How would you like to sort the operators by?\n";
    }
    else{
        cout << "What field would you like to search by?\n";
    }

    //provides choices for sorting
    cout << "--------------------------------------------\n";
    cout << "1)Operator Code Names\n";
    cout << "2)Rarity Level\n";
    cout << "3)Operator Class\n";
    cout << "4)Deployment Cost\n";
    cout << "5)Health Capacity\n";
    cout << "6)Damage Capability\n";
    cout << "7)Defense Capacity\n";
    cout << "8)Resistance Capacity\n";

    if(type){
        cout << "0)Cancel re-sort\n";
    }else{
        cout << "0)Return to Main Menu\n";
    }
    
    //gets user input
    cout << "\n";
    cout << "(Please enter the number of your desired choice)\n";
    int choice = 0;

    while(true){
        string userInput = "";
        
        cin >> userInput;
        try{
            choice = stoi(userInput);
            if(choice > -1 && choice < 9){
                break;
            }
        }catch(...){

        }
    }

    //sorts according to input provided
    switch(choice){
        case 1:
            infoHub->sortByName();
            return "CodeName";
            break;
        case 2:
            infoHub->sortByRarity();
            return "Rarity";
            break;
        case 3:
            infoHub->sortByClass();
            return "Operator Class";
            break;
        case 4:
            infoHub->sortByCost();
            return "Deployment Cost";
            break;
        case 5:
            infoHub->sortByHP();
            return "Health Points";
            break;
        case 6:
            infoHub->sortByDMG();
            return "Damage Output";
            break;
        case 7:
            infoHub->sortByDEF();
            return "Defense Points";
            break;
        case 8:
            infoHub->sortByRES();
            return "Resistance Points";
            break;
        case 0:
            return prevSetting;
        default:
            return "Error";
            break;
        
    }
}


//Add operator interface
//gets user input, creates an operator if all fields are filled
string Menu::addOp(){
    
    //different messages for different info fields
    vector<string> msgs =
    {
        "Code Name: ",
        "Rarity: ",
        "Class: ",
        "Deployment Cost: ",
        "HP: ",
        "DMG: ",
        "DEF: ",
        "RES: "
    };

    int currentField = 0;

    //stores what the user has inputted so far
    vector<string> fields = {"", "", "", "", "", "", "", ""};
    while(currentField < 9){
        bool trigger = false;

        cout << "\t    Operator Recruitment\n\n";

        //checks if the name has already been used
        if(currentField == 1 && infoHub->getOperatorIndex(fields.at(0)) != -1){
            currentField--;
            cout << "<<ERROR, THE OPERATOR ALREADY EXISTS IN THE DATABASE>>\n";
        }

        //prints out the different fields of information
        for(int x = 0; x < 8; x++){
            cout << "Operator " << msgs.at(x);
            
            //checks if the current field needs to be filled
            if(currentField == x){
                
                //allows user to fill the current field if need be
                if(!recordInput(currentField, fields)){

                    if(currentField == 0){
                        spacing();
                        return "Main";
                    }else{
                        currentField--;
                        trigger = true;
                        break;
                    }

                }

                currentField++;
                trigger = true;
                break;
            }

            //prints out automatically for fields already filled
            cout << fields.at(x);
            cout << "\n";
        }

        //checks for confirmation of recruitment
        if(currentField == 8 && !trigger){
            cout << "Press (1) to confirm recruitment, (2) to go back\n";
            
            string input = "";
            while(true){
                cin >> input;
                if(input == "1"){
                    break;
                }
                if(input == "2"){
                    currentField--;
                    break;
                }
            }

            if(input == "1"){
                ROperator newOP(
                    fields.at(0),
                    stoi(fields.at(1)),
                    fields.at(2),
                    stoi(fields.at(3)),
                    stoi(fields.at(4)),
                    stoi(fields.at(5)),
                    stoi(fields.at(6)),
                    stoi(fields.at(7))
                );
                infoHub->addOperator(newOP);
                break;
            }
        }
        spacing();
    }
    
    //returns to main menu
    spacing();
    return "Main";
}

//records the user input according to the field required, adapts accordingly
int Menu::recordInput(int index, vector<string> &output){

    string input = "";
    if(index == 0 || index == 2){
        cout << "(Please input a word/name, no commas, enter -1 to go to previous)\n";
    }else{
        cout << "(Please input a number greater than ";
        if(index == 7){
            cout << "-1";
        }else{
            cout << "0";
        }
        cout << ", or enter -1 to go to previous)\n";
    }

    //creates a loop for reinforcement against incorrect input
    while(true){
        cin >> input;
        
        //checks if the user wants to return/go to previous field
        if(input == "-1"){
            return 0;
        }

        if(find(begin(input), end(input), ',') != end(input)){
            continue;
        }

        //checks if the current field that this is input for a string
        if(index != 0 && index != 2){
            
            //if not, test for an integer and if it works
            try{
                int test = stoi(input);
                if((index == 7 && test >= 0) || ((index < 7) && test > 0)){
                    output.at(index) = input;
                    return 1;
                }
            }catch(...){
                //catches any errors that the user may cause
            }

        }else{

            //tests if the string is empty
            if(input != ""){
                output.at(index) = input;
                return 1;
            }
        }
    }
    return 0;
}


//find operators option
string Menu::findMenu(){

    string choice = "";
    while(true){

        cout << "\tSearch Menu\n\n";
        
        //gets the choice that the user wants to search at
        choice = sortSelection("None", 0);
        
        if(choice == "None"){
            break;
        }
        spacing();
        
        findSubMenu(choice);
        
    }

    //returns to main menu
    spacing();
    return "Main";
}

//sub menu after the find menu
void Menu::findSubMenu(string setting){

    int type = 0;
    if(setting == "CodeName" || setting == "Operator Class"){
        type = 1;
    }else if(setting == "Rarity"){
        type = 2;
    }

    //search use
    string sField = "";
    int intA = 0;
    int intB = 0;

    //search results
    vector<string> opsFound;

    getUserInput(sField, intA, intB, type);
    getResults(sField, intA, intB, setting, opsFound);
    spacing();

    //format settings
    bool details = true;
    int page = 0;

    while(true){

        displayOperators(opsFound, page + 1, opsFound.size() / 10 + 1, details);

        //using the userInput variable so there's one less variable to deall with
        string userInput = "";
        cout << "(enter a letter and then press enter to continue) ";
        cin >> userInput;

        //current settings
        cout << "___________________\n";
        cout << "Searching by: " << setting << "\n";
        cout << "Details: " << getBool(details) << "\n";
        cout << "Current Search Input: ";
        
        if(type == 1){
            cout << "\"" << sField << "\"";
        }else if(type == 2){
            cout << intA;
        }else{
            cout << "[" << intA << ", " << intB << "]";
        }
        cout << "\n\n";
        
        //choices avaiable for the user

        if(type == 0){
            cout << "1)Change Search Range\n";
        }else{
            cout << "1)Change Search Input\n";
        }

        cout << "2)Invert List\n";
        cout << "3)Toggle Details\n";
        cout << "4)Previous Page\n";
        cout << "5)Next Page\n";
        cout << "6)Select Page\n";
        
        if(opsFound.size() > 0){
            cout << "7)Remove an Operator\n";
            cout << "8)Exit/change search field\n";
        }else{
            cout << "7)Exit/change search field\n";
        }
        
        cout << "(Please enter the number of your desired choice)\n";
        
        int choice = 0;

        //gets and checks user input
        while(true){

            cin >> userInput;
            try{
                choice = stoi(userInput);
                if(choice > 0 && choice < 8){
                    break;
                }
                if(opsFound.size() > 0 && choice == 8){
                    break;
                }
            }catch(...){

            }
        }

        spacing();

        //acts on the choice that the user has provided
        switch(choice){
            case 1:
                //gets a new user search desire
                getUserInput(sField, intA, intB, type);
                getResults(sField, intA, intB, setting, opsFound);
                page = 0;
                spacing();
                break;
            case 2:
                //inverts the current database
                reverse(begin(opsFound), end(opsFound));
                break;
            case 3:
                //toggles details
                details = !details;
                break;
            case 4:
                //goes to previous page(or the last page)
                page--;
                if(page < 0){
                    page = (opsFound.size())/10;
                }
                break;
            case 5:
                //goes to next page(or the first page)
                page++;
                if(page > (opsFound.size())/10){
                    page = 0;
                }
                break;
            case 6:
                //code here has been moved to the getPage method
                choice = getPage(opsFound.size());
                spacing();
                if(choice > 0){
                    page = choice - 1;
                }
                break;
            case 7:
                if(opsFound.size() > 0){
                    if(removeOperator(opsFound)){
                        afterSort(setting);
                        getResults(sField, intA, intB, setting, opsFound);
                    }
                    spacing();
                    break;
                }else{
                    //exits to main menu
                    spacing();
                    return;
                    break;
                }
            case 8:
                //exits to main menu
                spacing();
                return;
                break;
        }
    }

}

//gets user input and adjust the fields accordingly
void Menu::getUserInput(string &inputS, int &inputA, int &inputB, int &current){
    string tempS = inputS;
    int tempA = inputA, tempB = inputB;
    string userInput = "";
    
    if(current == 1){
        cout << "\nSearch Input (a word/name)(-1 to cancel): ";
        cin >> tempS;
        if(tempS == "-1"){
            return;
        }
    }
    else if(current == 2)
    {
        while(true){
            cout << "\nSearch Input (a positive number, less than 7)(-1 to cancel): ";
            cin >> userInput;
            try{
                tempA = stoi(userInput);
                if(tempA == -1){
                    return;
                }
                if(tempA < 7 && tempA > 0){
                    break;
                }
            }catch(...){

            }
        }
        
    }
    else
    {
        int bounds = 1;
        while(true){

            cout << "\nSearch ";
            if(bounds == 1){
                cout << "Lower Bound (greater than or equal to 0)(-1 to cancel): ";
            }else{
                cout << "Upper Bound (greater than the lower bound)(-1 to re-set lower bound): ";
            }

            cin >> userInput;
            try{
                if(bounds == 1){
                    tempA = stoi(userInput);
                    if(tempA == -1){
                        return;
                    }
                    if(tempA > -1){
                        bounds++;
                    }
                }else{
                    tempB = stoi(userInput);
                    if(tempB == -1){
                        bounds--;
                    }
                    if(tempB > tempA){
                        break;
                    }
                }
            }catch(...){

            }
        }
    }

    inputA = tempA;
    inputB = tempB;
    inputS = tempS;
}

//displays the operators that fulfill the requirements of the search
void Menu::displayOperators(vector<string> list, int current, int limit, bool details)const{

    if(!details){
        cout << "    Search Results\n\n";

        //prints the operators of a certain range
        cout << "\tCode Name" << "\t" << "Class\n";
        cout << "________________________________\n";

        if(list.size() == 0){
            cout << "No Results found\n";
        }else{
            for(int x = 10 * (current - 1); x < list.size() && x < 10 * (current); x++){
                cout << x + 1 << "\t";
                ROperator current = infoHub->getOperatorOG(infoHub->getOperatorIndex(list.at(x)));
                cout << tabSpacing(current.getCodeName()) << current.getOpClass();
                cout << "\n";
            }
        }
        
    }else{
        cout << "\t\t\tSearch Results\n\n";

        //prints the operators of a certain range
        cout << "\tCode Name" << "\t" << "Rarity" << "\t" << "Class" <<
        "\t\t" << "Cost" << "\t" << "HP" << "\t" << "DMG" << "\t" << "DEF"
        << "\t" << "RES\n";

        //formatting purposes
        cout << "_________________________________________"
        << "_________________________________"
        << "_________\n";
        
        if(list.size() == 0){
            cout << "No Results found\n";
        }else{
            for(int x = 10 * (current - 1); x < list.size() && x < 10 * (current); x++){
                cout << x + 1 << "\t";
                ROperator current = infoHub->getOperatorOG(infoHub->getOperatorIndex(list.at(x)));
                cout << tabSpacing(current.getCodeName());
                cout << current.getRarity() << "\t";
                cout << tabSpacing(current.getOpClass());
                cout << current.getCost() << "\t";
                cout << current.getHP() << "\t";
                cout << current.getDMG() << "\t";
                cout << current.getDEF() << "\t";
                cout << current.getRES() << "\t";
                cout << "\n";
            }
        }
        
    }

    //displays current page
    cout << "\nPage " << current 
    << " of " << limit << "\n\n";
}

//searches and collcets the results of the search
void Menu::getResults(string sField, int aField, int bField, string current, vector<string> &output){
    
    output.clear();
    
    //searches and collects information according to the "current" setting
    if(current == "CodeName"){
        int i = infoHub->getOperatorIndex(sField);
        if(i > -1){
            output.push_back(infoHub->getOperator(i).getCodeName());
        }
        return;
    }
    else if(current == "Rarity")
    {

        bool found = false;
        for(int x = 0; x < infoHub->getSize(); x++){
            
            if(aField == infoHub->getOperator(x).getRarity()){
                output.push_back(infoHub->getOperator(x).getCodeName());
                if(!found){
                    found = false;
                }
                continue;
            }
            if(found){
                return;
            }
        }

    }
    else if(current == "Operator Class")
    {

        bool found = false;
        for(int x = 0; x < infoHub->getSize(); x++){
            
            if(sField == infoHub->getOperator(x).getOpClass()){
                output.push_back(infoHub->getOperator(x).getCodeName());
                if(!found){
                    found = false;
                }
                continue;
            }
            if(found){
                return;
            }
        }

    }
    else if(current == "Deployment Cost")
    {

        for(int x = 0; x < infoHub->getSize(); x++){
            
            if(aField > infoHub->getOperator(x).getCost()){
                return;
            }

            if(bField > infoHub->getOperator(x).getCost()){
                output.push_back(infoHub->getOperator(x).getCodeName());
            }
        }

    }
    else if(current == "Health Points")
    {

        for(int x = 0; x < infoHub->getSize(); x++){
            if(aField > infoHub->getOperator(x).getHP()){
                return;
            }

            if(bField > infoHub->getOperator(x).getHP()){
                output.push_back(infoHub->getOperator(x).getCodeName());
            }
        }

    }
    else if(current == "Damage Output")
    {

        for(int x = 0; x < infoHub->getSize(); x++){
            
            if(aField > infoHub->getOperator(x).getDMG()){
                return;
            }

            if(bField > infoHub->getOperator(x).getDMG()){
                output.push_back(infoHub->getOperator(x).getCodeName());
            }
        }

    }
    else if(current == "Defense Points")
    {

        for(int x = 0; x < infoHub->getSize(); x++){
            
            if(aField > infoHub->getOperator(x).getDEF()){
                return;
            }

            if(bField > infoHub->getOperator(x).getDEF()){
                output.push_back(infoHub->getOperator(x).getCodeName());
            }
        }

    }
    else if(current == "Resistance Points")
    {

        for(int x = 0; x < infoHub->getSize(); x++){
            
            if(aField > infoHub->getOperator(x).getRES()){
                return;
            }

            if(bField > infoHub->getOperator(x).getRES()){
                output.push_back(infoHub->getOperator(x).getCodeName());
            }
        }

    }
    else
    {
        cout << "Error has occured";
    }
}

//remove operator method, gives confirmations as well
int Menu::removeOperator(const vector<string> &input){
    
    string userInput = "";
    int choice = 0;
    while(true){
        while(true){
            cout << "Which Operator Would you like to remove?\n";
            cout << "(Enter a number from 1 to " << input.size() << " or -1 to cancel)\n";
            cin >> userInput;
            try{
                choice = stoi(userInput);
                if(choice == -1){
                    return 0;
                }
                if(choice > 0 && choice < input.size() + 1){
                    break;
                }
            }catch(...){

            }

        }

        int confirmation = 0;

        while(true){
            cout << "\nAre you sure you want to remove: " << input.at(choice - 1) << "?\n";
            cout << "(1 - yes, 2 - no)\n";
            cin >> userInput;
            try{
                confirmation = stoi(userInput);
                if(confirmation == 1){
                    infoHub->removeOperator(input.at(choice - 1));
                    return 1;
                }
                if(confirmation == 2){
                    break;
                }
            }catch(...){

            }
        }
        
    }
    
}

//method for database re-sorting after an edit of the database
void Menu::afterSort(string setting){
    if(setting == "CodeName"){
        infoHub->sortByName();
        return;
    }
    else if(setting == "Rarity")
    {
        infoHub->sortByRarity();
        return;
    }
    else if(setting == "Operator Class")
    {
        infoHub->sortByClass();
        return;
    }
    else if(setting == "Deployment Cost")
    {
        infoHub->sortByCost();
        return;
    }
    else if(setting == "Health Points")
    {
        infoHub->sortByHP();
        return;
    }
    else if(setting == "Damage Output")
    {
        infoHub->sortByDMG();
        return;
    }
    else if(setting == "Defense Points")
    {
        infoHub->sortByDEF();
        return;
    }
    else if(setting == "Resistance Points")
    {
        infoHub->sortByRES();
        return;
    }
    else
    {
        cout << "sort error\n";
    }
}


//other helper methods
string Menu::tabSpacing(string input)const{
    if(input.size() > 7){
        input += "\t";
    }else{
        input += "\t\t";
    }
    return input;
}

//returns true or false according to the boolean given
string Menu::getBool(bool arg) const{
    if(arg){
        return "true";
    }
    return "false";
}
