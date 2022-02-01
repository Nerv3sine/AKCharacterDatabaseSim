
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;


void fileRead(const string& fileName, vector<string>& stringList);
string upper(string &in);

int main() {

	srand(time(nullptr));

	cout << "Generating random list of operators...\n\n";
	vector<string> classes = {"Supporter", "Sniper", "Guard", "Medic", "Specialist", "Caster", "Vanguard", "Defender"};
	vector<int> used;
	vector<string> words;
	fileRead("names.txt", words);

	for(int x = 0; x < 50; x++){
		int r = rand() % words.size();
		
		while(true){
			int b = 0;
			for(int i = 0; i < used.size(); i++){
				if(used.at(i) == r){
					b = 1;
					break;
				}
			}
			if(b){
				r = rand() % words.size();
			}else{
				break;
			}
		}
		used.push_back(r);
		cout << words.at(r) << ", ";

		r = rand() % 6 + 1;
		cout << r << ", ";

		r = rand() % classes.size();
		cout << classes.at(r) << ", ";

		r = rand() % 40 + 1;
		cout << r << ", ";

		r = rand() % 4000 + 1;
		cout << r << ", ";

		r = rand() % 1200 + 1;
		cout << r << ", ";

		r = rand() % 1000 + 1;
		cout << r << ", ";

		r = rand() % 50 + 1;
		cout << r;

		cout << "\n";
	}
}

void fileRead(const string& fileName, vector<string>& sList){
	fstream file(fileName);

	if(file.fail()){
		cout << "Fuck\n";
	}

	while(true){
		string s;
		file >> s;

		if(s != ""){
			
			sList.push_back(upper(s));
		}

		if(file.eof() && file.fail()){
			break;
		}
	}

	file.close();
}

string upper(string &in){
	char temp = in.at(0);
	if(temp > 96 && temp < 123){
		temp -= 32;
	}
	string out = "";
	out += temp;
	for(int x = 1; x < in.size(); x++){
		out += in.at(x);
	}

	return out;
}