/*
Comment 1:
Name - Balaji Saravana Gupta
This program is for Assignment 1, it utilizes 2D arrays and passes them to
different functions to evaluate them and provide data to the user.
e.g.: Providing the user with the total of an array or the total in a certain row of an array.
*/

// Comment 2:
// <iostream> is included for cout/endl so the program can print its results to the
// I also included limits since I use numeric limits max and min
#include <iostream>
#include <limits>
using namespace std;

// Comment 3:
// COLS is declared as a global constant because a 2D array parameter in C++ must specify
// its column size at compile time (int array[][COLS]). Making it global means every
// function prototype and definition below refers to the same fixed column count of 5.
const int COLS = 5;

// Comment 4:
// These are the function declarations, they basically tell the compiler what the function will return, its name and what arguments it expects.
int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);


// Comment 5:
// The main function declares the 2D array holding the test data for the current sample
// run, then calls each of the six functions in turn and prints their return values to
// the console so that every function required by the assignment is demonstrated.
int main()
{
	// Comment 6:
	// ROWS is declared as a local constant set to 4, giving a 4x5 array of 20 elements.
	// It is passed to the functions that need to traverse every row so they know how far
	// to loop, since the row count cannot be recovered from the array parameter itself.
	const int ROWS = 4;

	// Comment 7:
	// This is the 2D array of test data for the sample run that is currently active.
	// The values below belong to Sample Run 1. To produce Sample Runs 2 through 5,
	// comment out this block, uncomment the matching block underneath, and recompile.

	// Test 1
	int testArray[ROWS][COLS] =
	{
		{ 23,  7, 41, 15, 62 },
		{ 88, 34,  9, 50, 27 },
		{ 12, 71, 46, 33, 58 },
		{ 65, 19, 84,  3, 40 }
	};
	

	/* Test 2
	int testArray[ROWS][COLS] =
	{
		{  5, 90, 18, 47, 31 },
		{ 76, 22, 63,  8, 55 },
		{ 39, 14, 81, 26, 70 },
		{ 52, 97, 11, 44, 29 }
	};
	*/

	/* Test 3
	int testArray[ROWS][COLS] =
	{
		{ 100, 250,  75, 310, 145 },
		{ 420,  60, 185, 230,  95 },
		{ 275, 340, 110, 165, 390 },
		{  50, 205, 460, 130, 285 }
	};
	*/

	/* Test 4
	int testArray[ROWS][COLS] =
	{
		{ -12,  45, -33,  67,  -8 },
		{  29, -54,  71, -19,  36 },
		{ -41,  82,  -6,  53, -27 },
		{  94, -15,  38, -62,  17 }
	};
	*/

	/* Test 5
	int testArray[ROWS][COLS] =
	{
		{ -12,  45, -33,  67,  -8 },
		{  29, -54,  71, -19,  36 },
		{ -41,  82,  -6,  53, -27 },
		{  94, -15,  38, -62,  17 }
	};
	*/

	// Test 6
	/*
	int testArray[ROWS][COLS] =
	{
		{ 7,  7,  7,  7,  7 },
		{ 3, 11,  3, 11,  3 },
		{ 9,  1,  9,  1,  9 },
		{ 5,  5, 20, 20,  5 }
	};
	*/

	// Comment 8:
	// This call passes the whole array and the row count to getTotal, which adds up every
	// one of the 20 elements and returns their sum, demonstrating the getTotal function.
	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;


	// Comment 9:
	// This call demonstrates getAverage, which divides the sum of all elements by the
	// total number of elements and returns a double so that any fractional part of the
	// average is preserved rather than being truncated away by integer division.
	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;


	// Comment 10:
	// This call demonstrates getRowTotal by passing 0 as the row subscript, so the
	// function sums only the five elements sitting in the very first row of the array.
	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;


	// Comment 11:
	// This call demonstrates getColumnTotal by passing 2 as the column subscript, so the
	// function walks downward through the array and sums the element at index 2 of every
	// row. The row count is also passed so the loop knows how many rows to descend.
	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;


	// Comment 12:
	// This call demonstrates getHighestInRow by passing 2 as the row subscript, so the
	// function scans across the third row and returns the single largest value it finds.
	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;


	// Comment 13:
	// This call demonstrates getLowestInRow by passing 2 as the row subscript, so the
	// function scans that same third row and returns the smallest value found there.
	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;

	// Comment 14:
	// The system("PAUSE") call from the starter file is left commented out because this
	// program was written and run on macOS, where that Windows-only command does not
	// exist. The console output was captured from the terminal instead.
	// system("PAUSE");
	return 0;
}

/*
Comment 15:
This function takes in 2 arguments:
int array[][COLS] - A 2D array (Passed by value not reference so it makes a copy in local memory)
int rows - The number of rows in the array

Using these 2 arguments the function is able to traverse the 2d array and calculate the total value of all the elements in the array.
It uses a nested loop: the outer loop steps down through each row, and the inner loop walks
across every column of that row, adding each element it lands on into a running total.

Returns: an integer representing the total value of all elements in the array.
*/
int getTotal(int array[][COLS], int rows)
{
	int total = 0;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			total += array[i][j];
		}
	}
	return total;
}

/*
Comment 16:
This function takes in 2 arguments:
int array[][COLS] - A 2D array (Passed by value not reference so it makes a copy in local memory)
int rows - The number of rows in the array

Using these 2 arguements it is able to calculate the average value of all elements in the 2D array.
It actually uses the getTotal function within it in order to calculate the sum of the array to then calculate the average.

Formula: Average of all elements in the array = Total/(# of elements)
Total - given by getTotal
# of elements can be calculated by rows*column as it is a uniform array.

The return value of getTotal is cast to a double before the division is performed. Without
that cast both operands would be integers, so C++ would use integer division and throw away
the fractional part of the average (for example giving 10 instead of 10.5).

Returns: A Double representing the average of all elements in the array.

*/
double getAverage(int array[][COLS], int rows)
{
    return (double)getTotal(array, rows)/(rows*COLS);
}


/*
Comment 17:
This function takes in 2 arguments:
int array[][COLS] - A 2D array (Passed by value not reference so it makes a copy in local memory)
int rowToTotal - The row to total up

Using these 2 arguements it is able to calculate the total value of all elements in the specified row.
Only a single loop is needed here because the row is already fixed by rowToTotal, so the loop
simply moves across the columns of that one row while the row subscript stays constant.

Returns: an integer representing the total value of all elements in the specified row.
*/
int getRowTotal(int array[][COLS], int rowToTotal)
{
	int total = 0;
	for(int i = 0; i < COLS; i++)
	{
		total += array[rowToTotal][i];
	}
	return total;
}

/*
Comment 18:
This function takes in 3 arguments:
int array[][COLS] - A 2D array (Passed by value not reference so it makes a copy in local memory)
int colToTotal - The column to total up
int rows - The number of rows in the array

Using these 3 arguments it is able to calculate the total value of all elements in the specified column.
This is the mirror image of getRowTotal: the column subscript stays fixed at colToTotal while
the loop counter moves down through the rows, which is why the row count must be passed in.

Returns: an integer representing the total value of all elements in the specified column.
*/
int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
	int total = 0;
	for(int i = 0; i < rows; i++)
	{
		total += array[i][colToTotal];
	}	
	return total;
}


/*
Comment 19:
This function takes in 2 arguments:
int array[][COLS] - A 2D array (Passed by value not reference so it makes a copy in local memory)
int rowToSearch - The row to search for the highest value in

Using these 2 arguments it is able to calculate the highest value in the specified row.
The loop compares each element in the row against the largest value seen so far, and
replaces it whenever a bigger one turns up, so by the end the variable holds the maximum.

I used std::numeric_limits<int>::min() to get the smallest possible value for an integer to start with, since
no matter what an integer value cannot be smaller than that. This makes it so that even if the array has
no values it will not cause an error without excessive error handling. I could have used the first value
but that would require checking if the array has any values.

Returns: an integer representing the highest value in the specified row.
*/
int getHighestInRow(int array[][COLS], int rowToSearch)
{
     int highest = std::numeric_limits<int>::min();
	 for(int i = 0; i < COLS; i++)
	 {
		if(highest < array[rowToSearch][i])
		{
			highest = array[rowToSearch][i];
		}
	 }
	 return highest;
}

/*
Comment 20:
This function takes in 2 arguments:
int array[][COLS] - A 2D array (Passed by value not reference so it makes a copy in local memory)
int rowToSearch - The row to search for the lowest value in

I used std::numeric_limits<int>::max() to get the largest possible value for an integer to start with,
since no matter what an integer value cannot be larger than that. (Same case as previous function)

Using these 2 arguments it is able to calculate the lowest value in the specified row.
The comparison is simply flipped from the previous function: an element replaces the stored
value whenever it is smaller, so the variable ends up holding the minimum of that row.

Returns: an integer representing the lowest value in the specified row.
*/
int getLowestInRow(int array[][COLS], int rowToSearch)
{
	int lowest = std::numeric_limits<int>::max();
	for(int i = 0; i < COLS; i++)
	{
		if(lowest > array[rowToSearch][i])
		{
			lowest = array[rowToSearch][i];
		}
	}
	return lowest;
}
