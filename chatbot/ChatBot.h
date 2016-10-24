#ifndef _CHATBOT_H_
#define _CHATBOT_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

/**
* This is a ChatBot class which is used to do some AI talking with you
* @date			2016.10.21
*/
class ChatBot
{
public:
	/**
	*	get a response. 
	*  @return		string  
	*/
	static string getResponse();

private:
	static vector<string> arr_tips;   /**< this is something like the database for the AI tips */
};

#endif // _CHATBOT_H_
