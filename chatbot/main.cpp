#include "ChatBot.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
	string line;
	while (getline(cin, line)){
		cout << "  =====  " << ChatBot::getResponse() << endl;
	}
	return 0;
}