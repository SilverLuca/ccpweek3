#include <iostream>
#include <string>

using namespace std;

// sum for int
int sum(int argc, char *argv[])
{
    int output;
    // loop to sum the input
    for (int idx = 1; idx != argc; ++idx)
    {
	int input = stoul(argv[idx]);
	output += input;
    }
    return output;
}

// sum for double
double sum(int argc, char *argv[], bool dot)
{
    double output;
    // loop to sum the input
    for (int idx = 1; idx != argc; ++idx)
    {
	double input = stod(argv[idx]);
	output += input;
    }
    return output;
}

int main(int argc, char *argv[])
{
    bool dot = false;
    // loop over the args
    for (int idx = 1; idx != argc; ++idx)
    {
	string input (argv[idx]);
	// if there is a . then set dot = true
	if (input.find(".") < input.length())
	{
	    dot = true;
	    break;
	}
    }
    // choose the correct funtion based on dot
    if (dot)
	cout << sum(argc, argv, dot) << '\n';
    else
	cout << sum(argc, argv) << '\n';
}
