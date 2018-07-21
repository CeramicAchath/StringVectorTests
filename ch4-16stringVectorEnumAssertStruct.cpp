/*
@Description: Defines the entry point for the console application.
@Author: Nicholas Morgan
@Version: first build 07/19/2018
@known bugs:


*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//constants
const int MINVECTORSIZE = 10;

//function protos #3
void funPrintVectorDouble(vector<double> vectorToPrint);
void funPrintVectorInt(vector<int> vectorToPrint);

//function protos #4
void funWeightCalculation(void);
int funGetWeights(void);
void funWeightAverage(double averageWeight);

// functions protos #5
void funNumberVectorCalculation(void);
int funGetNumbers(void);
void funNumberAverage(vector<int> vectorToAverage);
void funPrintNumberAverageAndSum(int numberOfElements, int sum, int average);
void funCleanVector(vector<int> vectorToClean);

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

	//Get and average numbers using vectos

	funNumberVectorCalculation();



	system("pause");
	return 0;
}

void funPrintVectorDouble(vector<double> vectorToPrint)
{
	// locals var
	int i = 1;

	for (i = 0; i < vectorToPrint.size(); i++)
	{
		cout << "Guesstimated weight is " << vectorToPrint[i] << " firkins\n";
	}
}

void funPrintVectorInt(vector<int> vectorToPrint)
{
	int i = 1;

	for (i = 0; i >vectorToPrint.size(); i++)
	{
		cout << "Guesstimated weight is " << vectorToPrint[i] << " firkins";
	}
}

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
	int currentCount = 0;
	int userInput = 0;
	int resizeAmount = MINVECTORSIZE;

	//vector for #4
	vector<int> userNumberHolding;

	userNumberHolding.reserve(MINVECTORSIZE);
	funCleanVector(userNumberHolding);

	do
	{
		//increase vector size by 1 if bigger than 10
		if (currentCount = MINVECTORSIZE)
		{
			resizeAmount = resizeAmount + 1;
			userNumberHolding.resize(resizeAmount);
		}

		//get users number
		userInput = funGetNumbers();

		//check if positive int and add to vector
		if (userInput > 0)
		{
			userNumberHolding.push_back(userInput);
			currentCount++;
		}
	
		//increase count
	
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
void funNumberAverage(vector<int> vectorToAverage)
{
	//local variables
	int i = 0;
	int sum = 0;
	double average = 0;
	int size = 0;
	
	size = vectorToAverage.size();

	//add each vector elemtn
	for (i = 0; i < vectorToAverage.size(); i++)
	{
		sum = sum + vectorToAverage.at(i);
	}

	//average the sum
	average = sum / vectorToAverage.size();

	//send to printing
	funPrintNumberAverageAndSum(size, sum, average);

}

void funPrintNumberAverageAndSum(int size, int sum, int average)
{
	cout << "Your sum was " << sum << ", made up of " << size << " parts, and had an average of " << average << endl;
}

void funCleanVector(vector<int> vectorToClean)
{
	//local variables
	int size = MINVECTORSIZE;
	int i = 0; 
	
	size = vectorToClean.size();
	
	for (i = 0; i > size; i++)
	{
		vectorToClean.at(i) = 0;
	}

}