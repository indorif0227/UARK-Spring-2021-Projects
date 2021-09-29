//---------------------------------------------------------------------------
//Spring 2021 Programming Foundations I
//Author: Furqaan Indori
//Date: April 4, 2021
//Purpose: The goal of this assignment is to get comfortable using multiple files and
//implementing classes into our code. We will be creating a ledger class that will store
//crop type, the number of crops, profits, and then will output them to a file that farmer
//Jessie can use as a record.
//---------------------------------------------------------------------------

#include <iostream>
#include "Ledger.h"
using namespace std;

int main()
{
	cout << "Homework 6 written by Furqaan Indori." << endl;
	
	//Create ledger objects
	Ledger Master;
	Ledger Copy;

	//Read the source file, make a copy, and print the master ledger
	Master.readFile("JessiesAccount.txt");
	Copy.copy(Master);
	cout << endl << "Unsorted:" << endl;
	Master.printContents();

	//Create another file with Jessie's farm stats
	Master.generateStats("Jessie's Farm Statistics.txt");

	//Sort the master ledger by profit and print the modified version
	Master.sortProfit();
	Copy.sortProfit();
	cout << endl << "Sorted:" << endl;
	Master.printContents();

	//Prays for rain and hopefully not locusts
	Copy.prayForRain();
	cout << endl << "Divine Intervention:" << endl;
	Copy.generateStats("Intervention Stats.txt");
	Copy.printContents();
	Copy.sortProfit();
	cout << endl << "Divine Intervention (Sorted):" << endl;
	Copy.printContents();

	cout << endl << "(The divine intervention matricies use a second object which had it's values copied over from the first)" << endl;

	return 0;
}

