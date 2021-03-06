/*
	@Description: Runs a various Vector tests, passing vectors, increasing vector size, and prints some basic math using vector
	@Version: first build 07/19/2018
	@version2: 07/21/2018 corrected vector growth, removed some defunct code
	@known bugs: input doesnt check for characters, code doesnt repeat but closes on completion
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//constants
const int MINVECTORSIZE = 10; //set a minvector seize, to reduce vector resizing

//function protos #3
void funPrintVectorDouble(vector<double>& vectorToPrint);
//void funPrintVectorInt(vector<int> vectorToPrint); //was created incase it was needed, but code is obsolete
//function protos #4
void funWeightCalculation(void);
int funGetWeights(void);
void funWeightAverage(double averageWeight);

// functions protos #5
void funNumberVectorCalculation(void);
int funGetNumbers(void);
void funNumberAverage(vector<int>& vectorToAverage);
void funPrintNumberAverageAndSum(int numberOfElements, double sum, double average);
void funCleanVector(vector<int>& vectorToClean);

int main()
{
	//vectors for #2
	vector<string> womenInComputerScience{ "Ana Lovelace", "Sister Mary Kenneth Keller" , "Monica S. Lam" };

	//vector for #3
	vector<double> womenInCompSciWeights{ 2.7, 3, 2.5 };

	//print Guesstimated Weights #3
	funPrintVectorDouble(womenInCompSciWeights);

	//Get and average weights with no vectos/arrays
	funWeightCalculation();

	//Get and average integer numbers using vector
	funNumberVectorCalculation();

	system("pause");
	return 0;
}

void funPrintVectorDouble(vector<double>& vectorToPrint)
{
	for (int i = 0; i < vectorToPrint.size(); i++) 
	{
		cout << "Guesstimated weight is " << vectorToPrint[i] << " firkins\n";
	}
}

/*
void funPrintVectorInt(vector<int> vectorToPrint)
{

	for (int i = 0; i >vectorToPrint.size(); i++)
	{
		cout << "Guesstimated weight is " << vectorToPrint[i] << " firkins";
	}
}
*/

void funWeightCalculation(void)
{
	//local variables
	double sum = 0;
	double average = 0;
	int currentCount = 0;
	int newInput = 0;

	
	do
	{
		newInput = funGetWeights();
		
		if (newInput > 0)
		{
			sum = sum + newInput;
			currentCount++;
		}

	} while (newInput >= 0);

	if (currentCount != 0)
	{
		average = sum / currentCount;
	}
	else
	{
		currentCount = 1;
		average = sum / currentCount;
	}

	funWeightAverage(average);
}

int funGetWeights(void)
{
	//local variables
	double userWeight = 0;

	cout << "\nPlease enter a weight (-1 to quit): ";
	cin >> userWeight;
	
	return userWeight;
}

void funWeightAverage(double averageWeight)
{

	cout << "\nThe average of your entries is " << averageWeight << endl;
}

void funNumberVectorCalculation()
{
	//local variables
	int userInput = 0;
	int resizeAmount = MINVECTORSIZE;


	//vector for #4
	vector<int> userNumberHolding;


	userNumberHolding.reserve(MINVECTORSIZE);
	funCleanVector(userNumberHolding);

	do
	{
		//get users number
		userInput = funGetNumbers();

		//check if positive int and add to vector
		if (userInput >= 0)
		{
			userNumberHolding.push_back(userInput);
		}
	
	} while (userInput >= 0);

	funNumberAverage(userNumberHolding);
}

int funGetNumbers(void)
{
	int userNumber = 0;


	cout << "\nPlease enter a number (-1 to quit): ";
	cin >> userNumber;

	return userNumber;
}
void funNumberAverage(vector<int>& vectorToAverage)
{
	//local variables
	double sum = 0; //double in order to return a proper average
	double average = 0;


	//add each vector element
	for (int i = 0; i < vectorToAverage.size(); i++)
	{
		sum = sum + vectorToAverage.at(i);
	}

	//average the sum
	average = sum / vectorToAverage.size();

	//send to printing
	funPrintNumberAverageAndSum(vectorToAverage.size(), sum, average);
}

void funPrintNumberAverageAndSum(int size, double sum, double average)
{
	cout << "Your sum was " << sum << ", made up of " << size << " parts, and had an average of " << average << endl;
}

void funCleanVector(vector<int>& vectorToClean)
{
	for (int i = 0; i > vectorToClean.size(); i++)
	{
		vectorToClean.at(i) = 0;
	}

}
