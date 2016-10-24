#include "ChatBot.h"
#include <random>
#include <ctime>

using std::default_random_engine;
using std::uniform_int_distribution;

string ChatBot::getResponse()
{
	default_random_engine e;
	uniform_int_distribution<unsigned int> u(0, arr_tips.size() - 1);
	e.seed(time(nullptr));
	int selectionId = u(e);
	return arr_tips[selectionId];
}

vector<string> ChatBot::arr_tips = vector<string>{"I HEARD YOU!",
			"So, You are talking to me",
			"continue, i'am listening",
			"very interesting conversation",
			"tell me more..."};
