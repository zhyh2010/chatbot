#include "ChatBot.h"
#include <random>
#include <ctime>
#include <exception>
#include <algorithm>

using std::default_random_engine;
using std::uniform_int_distribution;

namespace zhyh2010{
	string ChatBot::getResponse(const string & input)
	{
		try{
			auto tips = ChatBot::findMatches(input);
			//return tips[getRandomId(tips.size())];   /**< operator[] 没有异常机制直接崩溃 */
			return tips.at(getRandomId(tips.size()));
		}catch (std::exception){
			if (input == "BYE")
				return "bye";
			return "sorry, I cannot understand what you say!!";
		}		
	}

	vector<RECORD> ChatBot::arr_tips = vector<RECORD>{
		RECORD( "WHAT IS YOUR NAME",
		{ "MY NAME IS CHATTERBOT2.",
		"YOU CAN CALL ME CHATTERBOT2.",
		"WHY DO YOU WANT TO KNOW MY NAME?" }
		),

		{ "HI",
		{ "HI THERE!",
		"HOW ARE YOU?",
		"HI!" }
		},

		{ "HOW ARE YOU",
		{ "I'M DOING FINE!",
		"I'M DOING WELL AND YOU?",
		"WHY DO YOU WANT TO KNOW HOW AM I DOING?" }
		},

		{ "WHO ARE YOU",
		{ "I'M AN A.I PROGRAM.",
		"I THINK THAT YOU KNOW WHO I'M.",
		"WHY ARE YOU ASKING?" }
		},

		{ "ARE YOU INTELLIGENT",
		{ "YES,OFCORSE.",
		"WHAT DO YOU THINK?",
		"ACTUALY,I'M VERY INTELLIGENT!" }
		},

		{ "ARE YOU REAL",
		{ "DOES THAT QUESTION REALLY MATERS TO YOU?",
		"WHAT DO YOU MEAN BY THAT?",
		"I'M AS REAL AS I CAN BE." }
		}
	};

	vector<string> ChatBot::findMatches(string input)
	{
		vector<string> res;
		for (auto item : arr_tips){
			if (ToUpper(item.input) == ToUpper(input))
				res = std::move(item.responses);
		}
		return res;
	}

	int ChatBot::getRandomId(int size)
	{
		default_random_engine e;
		uniform_int_distribution<unsigned int> u(0, size - 1);
		e.seed(time(nullptr));
		return u(e);
	}

	string ChatBot::ToUpper(string line)
	{
		std::transform(line.begin(), line.end(), line.begin(), toupper);
		return line;
	}
}


