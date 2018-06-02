#include "StringUtils.h"

using HttpServer::Infrustructure::Utils::StringUtils;
using namespace std;

const string StringUtils::DefaultLineSeparatedString = "\r\n";
const int StringUtils::DefaultBufferSizeForFormatting = 100;

string StringUtils::GetFormattedEnumValue(string enumNonFormattedValue)
{
	return enumNonFormattedValue.substr(enumNonFormattedValue.find_last_of(": ") + 1);
}

string StringUtils::ConcatStrings(vector<string> strings)
{
	string resultString;
	for (auto str : strings)
	{
		resultString += str;
	}
	return resultString;
}

string StringUtils::GetSeparatedString(vector<string> strings, string separatedValue)
{
	string resultString;
	for(unsigned int i = 0; i < strings.size() - 1; i++)
	{
		resultString += strings[i];
		resultString += separatedValue;
	}
	return resultString + strings[strings.size() - 1];
}

string StringUtils::GetCommaSeparatedString(vector<string> strings)
{
	return GetSeparatedString(strings, ",");
}

string StringUtils::GetDefaultSeparatedString(vector<string> strings)
{
	return GetSeparatedString(strings, DefaultLineSeparatedString);
}

string StringUtils::TimesRepeat(string stringToRepeating, unsigned int times)
{
	string resultString = string();
	for (unsigned i = 0; i < times; i++)
	{
		resultString += stringToRepeating;
	}
	return resultString;
}

vector<string> StringUtils::SplitString(string stringForSpliting, string splitStr)
{
	return vector<string>();
}
