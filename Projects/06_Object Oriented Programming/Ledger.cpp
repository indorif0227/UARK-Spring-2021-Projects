#include "Ledger.h"
using namespace std;

//---------------------------------------------------------------------------
// Name: Ledger
// Parameters: none
// Returns: none
// Purpose: Constructor. Initializes everything to nothing.
//---------------------------------------------------------------------------
Ledger::Ledger()
{
	for (int i = 0; i < MAX_CROPS; i++)
	{
		crops[i] = "NO_CROP";
		amounts[i] = -1;
	}
	numCrops = 0;
}

//---------------------------------------------------------------------------
// Name: ~Ledger
// Parameters: none
// Returns: none
// Purpose: Destructor
//---------------------------------------------------------------------------
Ledger::~Ledger()
{
}

//---------------------------------------------------------------------------
// Name: copy
// Parameters: TODO - The object from which the information is being copied
// Returns: nothing
// Purpose: Copy information from one ledger to another
//---------------------------------------------------------------------------
void Ledger::copy(Ledger source)
{
	numCrops = source.numCrops;

	// copies the amounts and crop names from the source into the current object
	for (int n = 0; n < numCrops; n++)
	{
		amounts[n] = source.amounts[n];
		crops[n] = source.crops[n];
	}
}

//---------------------------------------------------------------------------
// Name: printContents
// Parameters: none
// Returns: none
// Purpose: Prints the content's of the amounts and crops arrays to the console
//---------------------------------------------------------------------------
void Ledger::printContents() const
{
	for (int i = 0; i < numCrops; i++)
	{
		cout << fixed << setprecision(2) << amounts[i] << " | " << crops[i] << endl;
	}
}

//---------------------------------------------------------------------------
// Name: readFile
// Parameters: string filename - contains the path to the input file
// Returns: nothing
// Purpose: Reads information from Jessie's account and stores it in the ledger
//---------------------------------------------------------------------------
void Ledger::readFile(string filename)
{
	//Opens the file so that it can be read
	ifstream infile;
	infile.open(filename);

	for (int n = 0; n < MAX_CROPS; n++)
	{
		string crop;
		float amount;

		//Reads the first and second entries in the input stream, which should be the amount and the crop
		infile >> amount >> crop;

		if (validAmount(amount) && validCrop(crop))
		{
			// Populates the array with amount and crop values
			amounts[n] = amount;
			crops[n] = crop;

			// Sets the number of crops to the array value plus 1
			numCrops = n + 1;
		}
		if (validAmount(amount) == false || validCrop(crop) == false)
		{
			//Sets the array value back 1 in the case that either the crop or amount was not valid
			n--;
		}
		// Breaks the loop if it encounters an empty crop value because otherwise it would go on infinitely
		if (crop == "")
		{
			break;
		}
	}
}

//---------------------------------------------------------------------------
// Name: generateStats
// Parameters: string filename - string that contains the filename that will be written
// Returns: none
// Purpose: Writes additional stats on Jesse's ledger to a designated text file
//---------------------------------------------------------------------------
void Ledger::generateStats(string filename)
{
	int wheat = 0;
	int potato = 0;
	int pumpkin = 0;
	int beet = 0;

	countCrops(wheat, potato, pumpkin, beet);

	ofstream outfile;
	outfile.open(filename);
	outfile << "Statistics" << endl
					<< fixed << setprecision(2) << "Your average profit is: $" << calculateAverage() << endl
					<< "Number of fields by crop:" << endl
					<< wheat <<"| Wheat" << endl
					<< potato <<"| Potato" << endl
					<< pumpkin << "| Pumpkin" << endl
					<< beet << "| Beet" << endl
					<< "You can still plant " << MAX_CROPS - numCrops << " more fields.";
	outfile.close();
}

//---------------------------------------------------------------------------
// Name: validAmount
// Parameters: float amount - The amount value read from an account
// Returns: bool (true or false)
// Purpose: Verifies that a valid float amount was entered in the account.txt file
//---------------------------------------------------------------------------
bool Ledger::validAmount(float amount)
{
	// Returns true if amount is between the desired values and returns false otherwise
	bool temp = (amount >= 1000 && amount <= 2500) ? true : false;
	return temp;
}

//---------------------------------------------------------------------------
// Name: validCrop
// Parameters: string crop - The crop value read from an account
// Returns: bool (true or false)
// Purpose: Verifies that a valid string was entered in the account.txt file
//---------------------------------------------------------------------------
bool Ledger::validCrop(string crop)
{
	// Returns true if the crop name matches any of the provided, false by default
	bool temp = (crop == "Wheat" || crop == "Potato" || crop == "Pumpkin" || crop == "Beet") ? true : false;
	return temp;
}

//---------------------------------------------------------------------------
// Name: calculateAverage
// Parameters: none
// Returns: float - average profit of the amounts stored in the current ledger object
// Purpose: Calculates the average of amounts in the current ledger object
//---------------------------------------------------------------------------
float Ledger::calculateAverage()
{
	float total;

	for (int n = 0; n < numCrops; n++)
	{
		total += amounts[n];
	}

	return total / numCrops;
}

//---------------------------------------------------------------------------
// Name: countCrops
// Parameters: int &wheat, int &potato, int &pumpkin, int &beet;
// Returns: none
// Purpose: Counts the number of each type of crop
//---------------------------------------------------------------------------
void Ledger::countCrops(int &wheat, int &potato, int &pumpkin, int &beet)
{
	for (int n = 0; n < numCrops; n++)
	{
		if (crops[n] == "Wheat")
		{
			wheat++;
		}
		if (crops[n] == "Potato")
		{
			potato++;
		}
		if (crops[n] == "Pumpkin")
		{
			pumpkin++;
		}
		if (crops[n] == "Beet")
		{
			beet++;
		}
	}
}

//---------------------------------------------------------------------------
// Name: sortProfit
// Parameters: none
// Returns: none
// Purpose: Sorts the ledger from greatest to least in terms of profit
//---------------------------------------------------------------------------

void Ledger::sortProfit()
{
	bool sorted = false;
	while (sorted == false)
	{
		int sortCount = 0;
		for (int n = 0; n < numCrops; n++)
		{
			if (amounts[n] < amounts[n + 1])
			{
				float tempAmount = amounts[n];
				amounts[n] = amounts[n + 1];
				amounts[n + 1] = tempAmount;
				string tempCrop = crops[n];
				crops[n] = crops[n + 1];
				crops[n + 1] = tempCrop;
			}
			else
			{
				sortCount++;
			}
		}
		sorted = (sortCount == numCrops) ? true : false;
	}
}

//---------------------------------------------------------------------------
// Name: prayForRain
// Parameters: none
// Returns: none
// Purpose: Allows Jessie to pray to the rain gods for a bigger harvest, also
// has a slight chance of instead summoning a swarm of locusts. Honestly just
// depends on their mood.
//---------------------------------------------------------------------------
void Ledger::prayForRain()
{
	srand(numCrops); //Seeds the random number generator

	for(int n = 0; n < numCrops; n++)
	{
		float divineIntervention = 1 + ((rand() % 30 - 15) / 100.00);
		amounts[n] *= divineIntervention;
	}
}