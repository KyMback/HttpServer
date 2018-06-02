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
			private:
				static string GetFormattedEnumValue(string enumNonFormattedValue);
			public:
				static const string DefaultLineSeparatedString;
				static const int DefaultBufferSizeForFormatting;

				static string ConcatStrings(vector<string> strings);
				static string GetSeparatedString(vector<string> strings, string separatedValue);
				static string GetCommaSeparatedString(vector<string> strings);
				static string GetDefaultSeparatedString(vector<string> strings);
				static string TimesRepeat(string stringToRepeating, unsigned int times);
				template<typename T>
				static string GetLocalizedEnumValue(T enumValue);
				static vector<string> SplitString(string stringForSpliting, string splitStr);
			};

			template<typename T>
			string StringUtils::GetLocalizedEnumValue(T enumValue)
			{
				return GetFormattedEnumValue(typeid(enumValue).name()) + "." + std::to_string(static_cast<int>(enumValue));
			}
		}
	}
}
