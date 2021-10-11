#include <iostream>
#include <string>

using namespace std;

string partition(string input)
{
    // initialize pivot, right
    int pivot = 0;
    int right = input.length() - 1;

    // check if string is empty or 1 character
    if (input.length() > 1)
    {
	// check if pivot is in correct location
	while (pivot < right)
	{
	    // check if nect letter is smaller, greater or equal
	    if (tolower(input[pivot]) < tolower(input[pivot + 1]))
	    {
		// if greater, swap with last element
		swap(input[pivot + 1], input[right]);
		--right;
		}
	    else
	    {
		// is smaller or equal, swap with pivot
		swap(input[pivot], input[pivot + 1]);
		++pivot;
	    }
	}
	// divide string in 3 parts
	string lhs = input.substr(0, pivot);
	string rhs = input.substr(pivot + 1, input.length() - 1 - pivot);

	// recursion on the left and right sides
	string leftside = partition(lhs);
	string rightside = partition(rhs);

	// put string back together after sort
	string output = leftside + input[pivot] + rightside;
	return output;
    }
    else
	// no sorting needed of 0 or 1 characters
	return input;
}


int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        string input = argv[1];
    	string output = partition(input);
    	cout << output << '\n';
    }
}
