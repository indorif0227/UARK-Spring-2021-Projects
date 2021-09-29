#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Ledger
{
public:
	Ledger();
	~Ledger();

	void copy(Ledger source);
	void printContents() const;
	void readFile(string filename);
	void generateStats(string filename);
	bool validAmount(float amount);
	bool validCrop(string crop);
	float calculateAverage();
	void countCrops(int &wheat, int &potato, int &pumpkin, int &beet);
	void sortProfit();
	void prayForRain();

private:
	static const int MAX_CROPS = 15; // the maximum number of crops
	float amounts[MAX_CROPS];
	string crops[MAX_CROPS];
	int numCrops; // keeps track of how many crops you have added to your arrays
};
