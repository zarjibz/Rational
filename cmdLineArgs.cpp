/*   Created  by rbh 08/01/15
*   Modified by nas 12/01/17
*/

#include <iostream>
#include <sstream>
#include <string>

#include "rational.h"

/* Basic command line interface for experimenting with rational arithmetic.
* Three command-line arguments are expected (in addition to the implicit file path):
*
* 1st - A string representation of a rational number (see Rational.h)
*
* 2nd - One of the four operators: + , - , * , /
*
* 3rd - A string representation of a rational number (see Rational.h)
*
* For example: ./cmdLineArgs 1/3 + 4/9
*/

using std::cout;
using std::endl;

int main(int argc, const char * argv[])
{
	// Remember, argv[0] is the filename
	if (argc != 4)
	{
		cout << "Incorrect number of arguments, expected 3: Rational Operator Rational" << endl;
		cout << "For example: " << argv[0] << " 2/3 + 1/9" << endl;
		return 1;
	}

	std::string op = argv[2];
	std::istringstream xstr(argv[1]);
	std::istringstream ystr(argv[3]);

	Rational x, y;
	xstr >> x;
	ystr >> y;

	Rational result;
	if (op == "+")
	{
		result = x + y;
	}
	else if (op == "-")
	{
		result = x - y;
	}
	else if (op == "*")
	{
		result = x * y;
	}
	else if (op == "/")
	{
		result = x / y;
	}
	else
	{
		cout << "Unrecognised operator" << endl;
		return 1;
	}
	cout << result << endl;

	return 0;
}