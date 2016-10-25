#include "ChatBot.h"
#include <string>
#include <iostream>

using namespace std;
using namespace zhyh2010;

int main(){
	string line;
	while (getline(cin, line)){
		cout << "  =====  " << ChatBot::getResponse(line) << endl;
	}
	return 0;
}