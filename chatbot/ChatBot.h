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
		*  @param input �������ʾ
		*  @return		string
		*/
		static string getResponse(const string & input);

	private:
		static vector<RECORD> arr_tips;   /**< this is something like the database for the AI tips */

		static vector<string> findMatches(string input);   /**< ����������input ƥ��Ĳο��ظ������� */

		static int getRandomId(int size);   /**< ���زο����Ͽ���ѡ�����������id */

		static string ToUpper(string line); /**< ���ַ�����д */
	};
}
#endif // _CHATBOT_H_
