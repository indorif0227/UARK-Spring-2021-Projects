//-------------------------------------------------------------------------------------------------
// Assignment: Homework 4a
// Name: Furqaan Indori
// ID: 010852950
// Date: February 28, 2021
// Description: Garden Simulator
//-------------------------------------------------------------------------------------------------

//Include Libraries
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------------------
// Name: getMenuChoice
// Parameters: choice: int, pass by reference so that the user's choice is changed when the function finishes
// Returns: Nothing
// Purpose: This function sets the parameter's choice value based on the user's integer response
//-------------------------------------------------------------------------------------------------
void getMenuChoice(int &choice)
{
  cout << "\nPlease choose an option (1-6): ";
  cout << "\n  [1]  Choose seed type\n  [2]  Plant seed\n  [3]  Water Crops\n  [4]  Harvest & Sell Crops\n";
  cout << "  [5]  Display Garden\n  [6]  Quit Program\n";
  cout << "\nEnter choice: ";
  cin >> choice;
  cout << endl;

  while (choice < 1 || choice > 6)
  {
    cout << "\nInvalid Choice. Please choose an option (1-6): ";
    cout << "\n  [1]  Choose seed type\n  [2]  Plant seed\n  [3]  Water Crops\n  [4]  Harvest & Sell Crops\n";
    cout << "  [5]  Display Garden\n  [6]  Quit Program\n";
    cout << "\nEnter choice: ";
    cin >> choice;
    cout << endl;
  }
}

//-------------------------------------------------------------------------------------------------
// Name: chooseSeedType
// Parameters: seedType: string, pass by reference so that the type of seed is changed in main
// Returns: Nothing
// Purpose: This function sets the parameter's type of seed value based on the user's integer response
//-------------------------------------------------------------------------------------------------
void chooseSeedType(string &seedType)
{
  int seedNumber;

  cout << "\nWhich seeds would you like to plant?\n";
  cout << "  [1] Potato\n  [2] Beet\n  [3] Wheat\n  [4] Pumpkin\n  [5] Tomato\n";
  cin >> seedNumber;

  while (seedNumber < 1 || seedNumber > 5)
  {
    cout << "Enter a valid number between 1 and 5: ";
    cin >> seedNumber;
  }

  switch (seedNumber)
  {
  case 1:
    seedType = "Potato";
    break;
  case 2:
    seedType = "Beet";
    break;
  case 3:
    seedType = "Wheat";
    break;
  case 4:
    seedType = "Pumpkin";
    break;
  case 5:
    seedType = "Tomato";
    break;
  default:
    cout << "Error.";
    break;
  }
}

//-------------------------------------------------------------------------------------------------
// Name: getYorN
// Parameters: question: string, the Y or N question to ask
// Returns: char: the character the user entered. Must be 'y', 'Y', 'n', or 'N'
// Purpose: This function returns the user's response to a yes/no question
//-------------------------------------------------------------------------------------------------
char getYorN(const string question)
{
  char choice;

  cout << question << "  Enter Y or N: ";
  cin >> choice;
  choice = toupper(choice);

  while (choice != 'Y' && choice != 'N')
  {
    cout << "Invalid character. Please enter either (Y) for yes or (N) for no.\n";
    cout << question << "  Enter Y or N: ";
    cin >> choice;
    choice = toupper(choice);
  }

  return choice;
}

//-------------------------------------------------------------------------------------------------
// Name: setRowPrice
// Parameters: row: integer, pass by value, the current row
//             seedType: string, pass by value, the current seed type
//             currentPrice: float, pass by reference, the price of the current row
//             numSeeds: int, pass by value, the number of seeds to plant
//             row1Cost: float, pass by reference, the cost of the first row
//             row2Cost: float, pass by reference, the cost of the second row
//             row3Cost: float, pass by reference, the cost of the third row
//             row4Cost: float, pass by reference, the cost of the fourth row
//             row5Cost: float, pass by reference, the cost of the fifth row
// Returns: Nothing
// Purpose: This function gets the price of the whole row and adds it to ONE of the appropriate row cost variables.
//-------------------------------------------------------------------------------------------------
void setRowPrice(const int row, const string seedType, float &currentPrice, const int numSeeds, float &row1Cost,
                 float &row2Cost, float &row3Cost, float &row4Cost, float &row5Cost)
{
  // Arbitrary prices for each of the seeds
  if (seedType == "Potato")
  {
    currentPrice = (currentPrice + 4.99) * numSeeds;
  }
  else if (seedType == "Beet")
  {
    currentPrice = (currentPrice + 3.99) * numSeeds;
  }
  else if (seedType == "Wheat")
  {
    currentPrice = (currentPrice + 1.99) * numSeeds;
  }
  else if (seedType == "Pumpkin")
  {
    currentPrice = (currentPrice + 8.99) * numSeeds;
  }
  else // Tomato case
  {
    currentPrice = (currentPrice + 5.99) * numSeeds;
  }

  switch (row)
  {
  case 0:
    row1Cost += currentPrice;
    break;
  case 1:
    row2Cost += currentPrice;
    break;
  case 2:
    row3Cost += currentPrice;
    break;
  case 3:
    row4Cost += currentPrice;
    break;
  case 4:
    row5Cost += currentPrice;
    break;
  }
}

//-------------------------------------------------------------------------------------------------
// Name: plantSeed
// Parameters: currentRow: integer, pass by value, the current row in the garden
//             seedType: string, pass by value, the current seed type of the row
//             crop1: string, pass by reference, the first row's seed type
//             crop2: string, pass by reference, the second row's seed type
//             crop3: string, pass by reference, the third row's seed type
//             crop4: string, pass by reference, the fourth row's seed type
//             crop5: string, pass by reference, the fifth row's seed type
// Returns: Nothing
// Purpose: This function sets the value for ONE of the appropriate global rowXCrop variable
//-------------------------------------------------------------------------------------------------
void plantSeed(const int currentRow, string seedType, string &crop1, string &crop2, string &crop3, string &crop4,
               string &crop5)
{
  switch (currentRow)
  {
  case 0:
    crop1 = seedType;
    break;
  case 1:
    crop2 = seedType;
    break;
  case 2:
    crop3 = seedType;
    break;
  case 3:
    crop4 = seedType;
    break;
  case 4:
    crop5 = seedType;
    break;
  }
}

//-------------------------------------------------------------------------------------------------
// Name: waterPlants
// Parameters: rows: integer, pass by reference, the total number of rows planted.
//             allWatered: boolean, pass by reference, tells whether or not there is enough space to plant
// Returns: boolean - if true, then the crops are watered
// Purpose: This function sets the allWatered boolean to the appropriate value
//-------------------------------------------------------------------------------------------------
bool waterPlants(int &rows, bool &allWatered)
{
  allWatered = false;

  if (rows > 0)
  {
    allWatered = true;
    cout << "\n		+ 		.			.  *			+	\n";
    cout << "*	.		.		*			+		.\n";
    cout << "				Crops watered!		*	     +\n";
    cout << "	.		+ 	.		+			   .\n";
    cout << "    +		.			*			*	+\n\n";
  }

  return allWatered;
}

//-------------------------------------------------------------------------------------------------
// Name: harvestCrops
// Parameters: crop1: string, pass by value, the first row's seed type.
//             crop2: string, pass by value, the second row's seed type.
//             crop3: string, pass by value, the third row's seed type.
//             crop4: string, pass by value, the fourth row's seed type.
//             crop5: string, pass by value, the fifth row's seed type.
// Returns: Nothing
// Purpose: This function outputs the harvested crops from the garden.
//-------------------------------------------------------------------------------------------------
void harvestCrops(const string crop1, const string crop2, const string crop3, const string crop4, const string crop5)
{
  cout << "\n-----------------------------------------";
  cout << "\n=            Crops Harvested            =";
  cout << "\n-----------------------------------------\n";

  cout << "You harvested: ";

  if (crop1 != "NA")
    cout << crop1;

  if (crop2 != "NA")
    cout << ", " << crop2;

  if (crop3 != "NA")
    cout << ", " << crop3;

  if (crop4 != "NA")
    cout << ", " << crop4;

  if (crop5 != "NA")
    cout << ", " << crop5;

  cout << endl;
}

//-------------------------------------------------------------------------------------------------
// Name: sellHarvest
// Parameters: row1Cost: float, pass by reference, the cost of the first row
//             row2Cost: float, pass by reference, the cost of the second row
//             row3Cost: float, pass by reference, the cost of the third row
//             row4Cost: float, pass by reference, the cost of the fourth row
//             row5Cost: float, pass by reference, the cost of the fifth row
// Returns: HarvestPrice
// Purpose: This function returns the total value of the whole garden and resets each row's costs
//-------------------------------------------------------------------------------------------------
float sellHarvest(float &row1Cost, float &row2Cost, float &row3Cost, float &row4Cost, float &row5Cost)
{
  float harvestPrice = row1Cost + row2Cost + row3Cost + row4Cost + row5Cost;

  row1Cost = 0.0;
  row3Cost = 0.0;
  row2Cost = 0.0;
  row4Cost = 0.0;
  row5Cost = 0.0;

  return harvestPrice;
}

//-------------------------------------------------------------------------------------------------
// Name: clearFields
// Parameters: crop1: string, pass by reference, the first row's seed type
//             crop2: string, pass by reference, the second row's seed type
//             crop3: string, pass by reference, the third row's seed type
//             crop4: string, pass by reference, the fourth row's seed type
//             crop5: string, pass by reference, the fifth row's seed type
// Returns: Nothing
// Purpose: This function resets the names of each row's crops to "NA"
//-------------------------------------------------------------------------------------------------
void clearFields(string &crop1, string &crop2, string &crop3, string &crop4, string &crop5)
{
  crop1 = "NA";
  crop2 = "NA";
  crop3 = "NA";
  crop4 = "NA";
  crop5 = "NA";
}

//-------------------------------------------------------------------------------------------------
// Name: displayGarden
// Parameters: rowsTaken: integer, pass by value, the number of rows planted
// Returns: Nothing
// Purpose: To display the rows that are taken or empty.
//-------------------------------------------------------------------------------------------------
void displayGarden(const int rowsTaken)
{
  int currentRow = rowsTaken;
  string EMPTY = "\n  | o o o o o o o o o o o o o o o o o o o o o|";
  string PLANTED = "\n  | x x x x x x x x x x x x x x x x x x x x x|";

  cout << "\n   __________________________________________";
  for (int row = 1; row <= 5; row++)
  {
    if (currentRow > 0)
      cout << PLANTED;
    else
      cout << EMPTY;

    currentRow--;
  }
  cout << "\n   ------------------------------------------";
  cout << "\n  o = empty\n  x = planted\n";
}

//-------------------------------------------------------------------------------------------------
//                           This is the main program that needs to be written
//-------------------------------------------------------------------------------------------------
int main()
{
  cout << fixed << setprecision(2);

  string row1Crop = "NA"; // Crop of the first row
  string row2Crop = "NA"; // Crop of the second row
  string row3Crop = "NA"; // Crop of the third row
  string row4Crop = "NA"; // Crop of the fourth row
  string row5Crop = "NA"; // Crop of the fifth row

  float row1Cost = 0.0; // Cost of the first row
  float row2Cost = 0.0; // Cost of the second row
  float row3Cost = 0.0; // Cost of the third row
  float row4Cost = 0.0; // Cost of the fourth row
  float row5Cost = 0.0; // Cost of the fifth row

  string currentSeedType = "EMPTY"; // Type of the current seed

  int currentRow = 0;    // Current row to plant the seeds
  int choice = 0;        // The user's choice
  int numSeeds = 0;      // Number of seeds per row
  int totalHarvests = 0; // Number of total harvests

  float totalPrice = 0.0;   // The total price of all harvests
  float harvestPrice = 0.0; // The price of a harvest, that will be added to total price after each harvest
  float price = 0.0;        // The price of each row

  bool dontLeave = true;   // to tell if user wants to quit program or not
  bool allWatered = false; // to tell if ALL crops are watered before harvesting

  cout << "\nName: Furqaan Indori";
  cout << "\nUAID: 010852950\n";

  cout << "\n----------------------------------------";
  cout << "\n=          Garden Simulator            =";
  cout << "\n----------------------------------------\n\n";

  // Loop until the user is done
  while (dontLeave == true)
  {
    // Print the main menu to get the users choice for what they'd like to do
    getMenuChoice(choice);

    // If user chooses 1, we get ask how many seeds the user wants to have (make sure to reiterate what type of seed they chose)
    if (choice == 1)
    {
      // Ask which type of seed the user wants to plant
      chooseSeedType(currentSeedType);

      //Ask for quantity of seeds
      cout << "How many " << currentSeedType << " seeds would you like to plant? (1-21)" << endl;
      cin >> numSeeds;

      // Use a loop to guarantee that the user enters a number between 1 and 21
      while (numSeeds < 1 || numSeeds > 21)
      {
        cout << "Invalid input. Please choose an integer between 1 and 21." << endl;
        cin >> numSeeds;
      }

      // User confirmation
      cout << endl
           << "You have chosen to plant " << numSeeds << " " << currentSeedType << " seeds." << endl;
    }

    // If user chooses 2, this is where we plant seeds.

    // If user hasn't chosen a seed type yet, DON'T allow them to plant any seeds. Then check whether
    // there is enough space in the garden function.
    if (choice == 2 && currentSeedType != "EMPTY")
    {
      // If enough space, then ask if they want fertilizer. If yes, set price to 1.99 before
      if (currentRow > 4)
      {
        cout << "It looks like your garden is full and there are no more empty rows to plant seeds in." << endl;
      }
      else
      {
        // calling setPrice() for the row's crops, otherwise set price to 0.0 before calling setPrice()
        if (getYorN("Do you want fertilizer?") == 'Y')
        {
          price = 1.99;
        }
        else
        {
          price = 0.00;
        }
        setRowPrice(currentRow, currentSeedType, price, numSeeds, row1Cost, row2Cost, row3Cost, row4Cost, row5Cost);

        // Finally, plant the seeds!
        plantSeed(currentRow, currentSeedType, row1Crop, row2Crop, row3Crop, row4Crop, row5Crop);

        // Display message telling them how many seeds they planted, the type of seed they planted,
        // and how much money this row will make
        cout << "You have planted " << numSeeds << " " << currentSeedType << " seeds. This row will make $" << price << endl;

        // Update the row number and notice that now, not all of our crops are watered...
        currentRow++;
        allWatered = false;
        // Also, reset numSeeds and currentSeedType since you do not have any seeds left
        numSeeds = 0;
        currentSeedType = "EMPTY";
      }
    }
    else if (choice == 2 && currentSeedType == "EMPTY")
    {
      cout << "Oh no! It looks like you can't plant anything without choosing your seed type." << endl;
    }

    // If user chooses 3, water all crops to let them grow! If no crops to water, let user know of the error.
    if (choice == 3)
    {
      if (currentRow != 0)
      {
        waterPlants(currentRow, allWatered);
      }
      else
      {
        cout << "It looks like you have no crops to water, please plant some before watering them." << endl;
      }
    }

    // If user chooses 4, harvest the crops, sell all the rows, clear the fields, reset currentRow, and update
    // the total amount of money and harvests. User can only harvest crops if all crops are watered.
    if (choice == 4)
    {
      if (allWatered == true)
      {
        harvestCrops(row1Crop, row2Crop, row3Crop, row4Crop, row5Crop);
        harvestPrice = sellHarvest(row1Cost, row2Cost, row3Cost, row4Cost, row5Cost);
        totalPrice += harvestPrice;
        totalHarvests++;
        cout << "You just made $" << harvestPrice << " from this harvest, bringing your total profits to $" << totalPrice << endl;
        currentRow = 0;
      }
      else
      {
        cout << "Your crops have not been watered yet, so they cannot be harvested." << endl;
      }
    }

    // If user chooses 5, display the garden.
    if (choice == 5)
    {
      displayGarden(currentRow);
    }

    // If user chooses 6, quit the program.
    if (choice == 6)
    {
      // When the user decides to quit the program, print out the total money the user earned, and number of
      // harvests it took.
      cout << "Total money earned: $" << totalPrice << endl
           << "Number of harvests: " << totalHarvests << endl;
      dontLeave = false;
    }
  }

  return 0;
}
