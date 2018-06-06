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

				static string GetSeparatedString(vector<string> strings, string separatedValue);
				template<typename T>
				static string GetLocalizedEnumValue(T enumValue);
			};

			template<typename T>
			string StringUtils::GetLocalizedEnumValue(T enumValue)
			{
				return GetFormattedEnumValue(typeid(enumValue).name()) + "." + std::to_string(static_cast<int>(enumValue));
			}
		}
	}
}
