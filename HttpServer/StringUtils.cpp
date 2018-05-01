#include "StringUtils.h"

using HttpServer::Infrustructure::Utils::StringUtils;

string StringUtils::ConcatStrings(vector<string>& strings)
{
	string resultString;
	for (auto str : strings)
	{
		resultString += str;
	}
	return resultString;
}

string StringUtils::GetSeparatedString(vector<string>& strings,const char* separatedValue)
{
	string resultString;
	for(unsigned int i = 0; i < strings.size() - 1; i++)
	{
		resultString += strings[i];
		resultString += *separatedValue;
	}
	return resultString + strings[strings.size() - 1];
}

string StringUtils::GetCommaSeparatedString(vector<string>& strings)
{
	return GetSeparatedString(strings, ",");
}
