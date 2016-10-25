#ifndef _CHATBOT_H_
#define _CHATBOT_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace zhyh2010{
	typedef struct _RECORD{
		string input;
		vector<string> responses;

		_RECORD(string input, vector<string> responses) :input(input), responses(responses){}
	}RECORD;

	/**
	* This is a ChatBot class which is used to do some AI talking with you
	* @date			2016.10.21
	*/
	class ChatBot
	{
	public:
		/**
		*	get a response.
		*  @param input 输入的提示
		*  @return		string
		*/
		static string getResponse(const string & input);

	private:
		static vector<RECORD> arr_tips;   /**< this is something like the database for the AI tips */

		static vector<string> findMatches(string input);   /**< 查找与输入input 匹配的参考回复库资料 */

		static int getRandomId(int size);   /**< 返回参考资料库中选择的资料语句的id */

		static string ToUpper(string line); /**< 将字符串大写 */
	};
}
#endif // _CHATBOT_H_
