//Include Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Main Function
int main()
{
  //Variable Initializations
  int cash = 3000; //Investing account balance
  char choice;     //User choice variable
  int hBreakLength = 100;

  //Stock prices
  int aaplPrice = 150;
  int tslaPrice = 800;
  int disPrice = 200;
  int babaPrice = 250;

  //User portfolio
  int aaplQty = 0;
  int tslaQty = 0;
  int disQty = 0;
  int babaQty = 0;

  //Welcome them to the stock market
  cout << "Welcome to the stock market!" << endl;
  cout << fixed << setprecision(2) << endl;

  //Order wizard
  do
  {
    //Initial propmpt
    cout << setfill('-') << setw(hBreakLength) << '-' << endl
         << "You have $" << cash << ". Choose a stock from the list below:" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "A) Apple     $" << aaplPrice << "    Current Shares: " << aaplQty << endl
         << "B) Tesla     $" << tslaPrice << "    Current Shares: " << tslaQty << endl
         << "C) Disney    $" << disPrice << "    Current Shares: " << disQty << endl
         << "D) Alibaba   $" << babaPrice << "    Current Shares: " << babaQty << endl
         << "E) Quit" << endl;

    //User inputs stock choice
    cout << "\n>>";
    cin >> choice;
    choice = toupper(choice);

    //Response to stock choice (w/ error checking for insufficient funds or invalid inputs)
    switch (choice)
    {
    case 'A':
      if (cash >= aaplPrice)
      {
        aaplQty++;
        cout << "\nYou now have " << aaplQty << " share(s) of Apple." << endl;
        cash -= aaplPrice;
      }
      else
      {
        cout << "\nError: You do not have enough funds to purchase another share of Apple." << endl;
      }
      break;
    case 'B':
      if (cash >= tslaPrice)
      {
        tslaQty++;
        cout << "\nYou now have " << tslaQty << " share(s) of Tesla." << endl;
        cash -= tslaPrice;
      }
      else
      {
        cout << "\nError: You do not have enough funds to purchase another share of Tesla." << endl;
      }
      break;
    case 'C':
      if (cash >= disPrice)
      {
        disQty++;
        cout << "\nYou now have " << disQty << " share(s) of Disney." << endl;
        cash -= disPrice;
      }
      else
      {
        cout << "\nError: You do not have enough funds to purchase another share of Disney." << endl;
      }
      break;
    case 'D':
      if (cash >= aaplPrice)
      {
        babaQty++;
        cout << "\nYou now have " << babaQty << " share(s) of Alibaba." << endl;
        cash -= aaplPrice;
      }
      else
      {
        cout << "\nError: You do not have enough funds to purchase another share of Alibaba." << endl;
      }
      break;
    case 'E':
      break;
    default:
      cout << "\nError: Invalid input, please try again." << endl;
    }
  } while (cash >= 150 && choice != 'E');

  //Force quit when funds are too low
  if (choice != 'E')
  {
    cout << "\nYou do not have sufficient funds to continue purchasing stocks.\n"
         << endl;
  }

  //Summary of portfolio
  cout << "You have left the trading business with $" << cash << endl
       << setfill('-') << setw(hBreakLength) << '-' << endl
       << "This is your portfolio:" << endl
       << setfill('-') << setw(hBreakLength) << '-' << endl
       << aaplQty << " Apple shares, each worth $" << aaplPrice << " for a total of $" << aaplPrice * aaplQty << endl
       << tslaQty << " Tesla shares, each worth $" << tslaPrice << " for a total of $" << tslaPrice * tslaQty << endl
       << disQty << " Disney shares, each worth $" << disPrice << " for a total of $" << disPrice * disQty << endl
       << babaQty << " Alibaba shares, each worth $" << babaPrice << " for a total of $" << babaPrice * babaQty << endl
       << "You also have $" << cash << " remaining." << endl
       << "Your net worth is $" << (aaplPrice * aaplQty) + (tslaPrice * tslaQty) + (disPrice * disQty) + (babaPrice * babaQty) + cash << endl
       << endl;

  //Declare variables for loop
  float randChange;
  float aaplNew = aaplPrice;
  float tslaNew = tslaPrice;
  float disNew = disPrice;
  float babaNew = babaPrice;

  //Output yearly reports and portfolios
  for (int year = 1; year <= 3; year++)
  {
    //Changing the random value for every stock
    randChange = 10 - rand() % 15;
    aaplNew = ((randChange / 100) + 1) * aaplNew;

    //Outputting each stock and it's new value
    cout << "============ Year " << year << " Report ============" << endl
         << "Apple changed by " << randChange << "%, and is now worth $" << aaplNew << endl;

    randChange = 10 - rand() % 15;
    tslaNew = ((randChange / 100) + 1) * tslaNew;

    cout << "Tesla changed by " << randChange << "%, and is now worth $" << tslaNew << endl;

    randChange = 10 - rand() % 15;
    disNew = ((randChange / 100) + 1) * disNew;

    cout << "Disney changed by " << randChange << "%, and is now worth $" << disNew << endl;

    randChange = 10 - rand() % 15;
    babaNew = ((randChange / 100) + 1) * babaNew;

    cout << "Alibaba changed by " << randChange << "%, and is now worth $" << babaNew << endl
         << endl;

    //Outputs the new portfolio with adjusted prices
    cout << "This is your portfolio:" << endl
         << aaplQty << " Apple shares, each worth $" << aaplNew << " for a total of $" << (aaplNew * aaplQty) << endl
         << tslaQty << " Tesla shares, each worth $" << tslaNew << " for a total of $" << (tslaNew * tslaQty) << endl
         << disQty << " Disney shares, each worth $" << disNew << " for a total of $" << (disNew * disQty) << endl
         << babaQty << " Alibaba shares, each worth $" << babaNew << " for a total of $" << (babaNew * babaQty) << endl
         << "You also have $" << cash << " cash remaining." << endl
         << "Your net worth is $" << (aaplNew * aaplQty) + (tslaNew * tslaQty) + (disNew * disQty) + (babaNew * babaQty) + cash << endl
         << endl;
  }

  return 0;
}