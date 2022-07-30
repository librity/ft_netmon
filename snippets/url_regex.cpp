// SOURCE: https://www.geeksforgeeks.org/check-if-an-url-is-valid-or-not-using-regular-expression/

// g++ url_regex.cpp && ./a.out

// C++ program to validate URL
// using Regular Expression
#include <iostream>
#include <regex>
using namespace	std;

// Function to validate URL
// using regular expression
bool	isValidURL(string url)
{
	// Regex to check valid URL
	const regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
	// If the URL
	// is empty return false
	if (url.empty())
	{
		return (false);
	}
	// Return true if the URL
	// matched the ReGex
	if (regex_match(url, pattern))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

// Driver Code
int	main(void)
{
	string	url;

	url = "https://www.geeksforgeeks.org";
	if (isValidURL(url))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return (0);
}

// This code is contributed by yuvraj_chandra
