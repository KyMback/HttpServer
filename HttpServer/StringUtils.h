#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace HttpServer
{
	namespace Infrustructure
	{
		namespace Utils
		{
			class StringUtils
			{
			public:
				static string ConcatStrings(vector<string>& strings);
				static string GetSeparatedString(vector<string>& strings, const char* separatedValue);
				static string GetCommaSeparatedString(vector<string>& strings);
			};
		}
	}
}
