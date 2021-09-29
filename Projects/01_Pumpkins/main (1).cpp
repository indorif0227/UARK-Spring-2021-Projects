/******************************************************************************

Name: Furqaan Indori

Instructor: Lora Streeter

Assignment: Homework 1 - Pumpkin farm

Description: A program that will determine the number of pumpkins and the worth
of the harvest given the area of farmland

*******************************************************************************/
//Include Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Main Function
int main(){
  //Part 1
  cout << "Part 1)\n";
  
  //Obtaining user input
  float farmWidth;
  float farmLength;

  cout << "Farm Width(ft): ";
  cin >> farmWidth;
  cout << "Farm Length(ft): ";
  cin >> farmLength;
  
  //Area of Farm
  float farmArea = farmLength * farmWidth;
  
  cout << "Farm Area(sqft): " << farmArea <<endl;
  
  //Maintenance Costs
  float maintenanceCost = 0.06 * farmArea;
  
  cout << "Maintenance Cost: $" << fixed << setprecision(2) << maintenanceCost << endl;
  
  //Pumpkin Capacity
  int pumpkinsPerWidth = (farmWidth / 4);
  int pumpkinsPerLength = (farmLength / 4);
  int pumpkinCapacity = pumpkinsPerLength * pumpkinsPerWidth;

  cout << "Pumpkin Capacity: " << pumpkinCapacity << endl;
  
  //Part 2
  cout << "\nPart 2)\n";
  
  //Yield Volume
  float pumpkinVolume = (3.14 * (4.0/3.0));
  float yieldVolume = pumpkinCapacity * pumpkinVolume;
  
  cout << "Yield Volume(ft^3): " << yieldVolume << endl;
  
  //Transportation
  int trailerVolume = 8 * 14 * 6;
  int tripsRequired = ceil(yieldVolume / trailerVolume);
  float gasExpenses = tripsRequired * 33.63;
  
  cout << "Trips Required: " << tripsRequired << endl;
  cout << "Gas Expenses: $" << gasExpenses << endl;
  
  //Profit
  float grossProfit = 5.25 * pumpkinCapacity;
  float netProfit = grossProfit - (gasExpenses + maintenanceCost);
  
  cout << "Gross Profit: $" << grossProfit << endl;
  cout << "Net Profit: $" << netProfit << endl;
}




