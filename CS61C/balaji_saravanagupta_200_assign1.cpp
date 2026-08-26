#include <iostream>
using namespace std;

const int COLS = 5;

int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
	const int ROWS = 4;  
	
	
	int testArray[ROWS][COLS] =
					{ { 1,   2,  3,  4,  5 },
					{   6,   7,  8,  9, 10 },
					{  11,  12, 13, 14, 15 },
					{  16,  17, 18, 19, 20 } };
   
	
	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;
   

	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;


	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;


	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;

     
	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;


	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;
        
    // system("PAUSE");  Im on MAC OS so this is not necessary.
	return 0;
}


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


double getAverage(int array[][COLS], int rows)
{
    return (double)getTotal(array, rows)/(rows*COLS);
}


int getRowTotal(int array[][COLS], int rowToTotal)
{
	int total = 0;
	for(int i = 0; i < COLS; i++)
	{
		total += array[rowToTotal][i];
	}
	return total;
}


int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
	int total = 0;
	for(int i = 0; i < rows; i++)
	{
		total += array[i][colToTotal];
	}	
	return total;
}


int getHighestInRow(int array[][COLS], int rowToSearch)
{
     int max = std::numeric_limits<int>::min();
	 for(int i = 0; i < COLS; i++)
	 {
		if(max < array[rowToSearch][i])
		{
			max = array[rowToSearch][i];
		}
	 }
	 return max;
}


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