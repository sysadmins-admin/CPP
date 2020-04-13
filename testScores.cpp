/*
Author: sysadmins-admin
Project: Write a program that calculates, averages, and rearranges Test Scores
in ascending order.
*/

#include <iostream>		
#include <memory>			//I used the memory header file to use the 'new' operator. 
#include <iomanip>
#include <cstdlib>
using namespace std;

//Function prototypes:
void sortArrays(double [], double);
void swap(int &, int &);				//I used reference variables here so I could carry over original values and not just memory locations.
double getAverage(double *, double);

int main()
{
	//I used double because the scores entered my be floating point numbers.
	double scores;

	cout << "Please enter the number of test scores that you will enter: ";
	cin >> scores;

	//This while loop tests to not accept negative numbers.
	while (scores < 0)
	{
		cout << "Please enter a number of test scores that are greater than or equal to zero: \n";
		cin >> scores;
	}
	/*I am dynamically alocating memory here for an unknown amount of elements/variables.
	Here I am initializing the pointer vriable while dynamically allocating memory.*/
	double *testScores(new double[scores]);

	cout << "\nEnter the test scores below: " << endl;

	for (int index = 0; index < scores; index++)
	{
		cout << "\nTest Score Number " << (index + 1) << ": ";
		cin >> testScores[index];
		
		//This while loop also tests to see if scores entered are positive. 
		while (testScores[index] < 0)
		{
			cout << "Please enter a non-negative test score: \n";
			cin >> testScores[index];
		}
	}
		//This functiion call is used to rearrange the scores in ascending order.
		//I chose to use the bubble sort.
		sortArrays(testScores, scores);
		cout << "\nSorted test scores are listed below:" << endl;
		cout << "- - - - -  - - - - - - - - - - - - - \n";

		for (int index = 0; index < scores; index++)
			cout << testScores[index] << setprecision(3) << "%\n";
		
		/*This function call calculates the average of the number after they have been
		sorted in ascending order from the previous function call.*/
		double average = getAverage(testScores, scores);
		
		cout << "\n- - - - - - - - - - - - - - - - - - \n";
		cout << "\nThe test score(s) average is: " << fixed << showpoint << setprecision(2) << average << "%" << endl;

	cout << "\n", system("pause");
	return 0;
}

//This function utilizes the bubble sort.
void sortArrays(double array[], double size)
{
	int maxElement, index;

	//This for loop is stepping through each element in the arrays.
	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			/*As long as the previous element is greater than the next element,
			the if statement will move to the swap function to rearrange elements.*/ 
			if (array[index] > array[index + 1])
			{
				//It is imperative that you place the preceding element first so the swap works as intended.
				swap(array[index], array[index + 1]);
			}
		}
	}
}

//This swap function allows the arrays to be swapped.
void swap(int &a, int &b)
{
	int holder = a;
	a = b;
	b = holder;
}

//This function calculates the average of the scores entered.
double getAverage(double *scores, double num)
{
	double average, total = 0.0;

	for (int count = 0; count < num; count++)
		total += scores[count];

	average = total / num;

	return average;
}

/*
Author: sysadmins-admin
*/