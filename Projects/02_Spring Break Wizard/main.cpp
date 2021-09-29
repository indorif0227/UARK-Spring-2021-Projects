/******************************************************************************

Name: Furqaan Indori

Instructor: Dr. Lora Streeter

Assignment: Homework 2 - What are you doing over Spring break?

Description: A program that will help the user decide what they will be doing
over spring break

*******************************************************************************/

//Include Statements
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

//Main Function
int main()
{
  //Main Menu

  //Setting float precision for the main function
  cout << fixed << setprecision(2) << endl;

  //Variable Declarations
  const int hBreakLength = 100;
  char activityCode;

  //Prompting user for their activity pereference
  cout << "Welcome to the Spring break genie! In which activity would you like to partake over the break?" << endl
       << setfill('-') << setw(hBreakLength) << '-' << endl
       << "A)Pick up a new hobby" << endl
       << "B)Study for classes" << endl
       << "C)Sleep" << endl
       << "D)Read more books" << endl
       << "E)Start investing money" << endl
       << setfill('-') << setw(hBreakLength) << '-' << endl
       << "Enter your choice here: ";

  //User input
  cin >> activityCode;
  cout << endl;
  activityCode = toupper(activityCode);

  //Activity choice trees
  switch (activityCode)
  {
  case 'A':
    //Declare Local Variables
    char hobbyCode;

    //Prompting the user
    cout << "Sounds like a great idea! What are you interested in?" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "A)Video games" << endl
         << "B)Music" << endl
         << "C)Excercising" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "Enter your choice here: ";

    //User input
    cin >> hobbyCode;
    hobbyCode = toupper(hobbyCode);
    cout << endl;

    switch (hobbyCode)
    {
    case 'A':
      cout << "League of Legends and Overwatch are popular online games that you can play with friends. Have fun!" << endl;
      break;
    case 'B':
      cout << "Picking up an instrument such as guitar or keyboard is relatively cheap and doable with eonugh patience. Rock on!" << endl;
      break;
    case 'C':
      cout << "There are plenty of trails in Arkansas where one could go for a brisk walk or a bike ride. Enjoying nature is one of the best parts of life." << endl;
      break;
    default:
      cout << "Sorry, I didn't recognize that response, cleaning is a pretty useful hobby to pick up though." << endl;
    }
    break;

  case 'B':
    //Declare Local Variables
    char subjectCode;

    //Prompting the user
    cout << "Lame, but reasonable. What subject do you want to study for?" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "A)Programming Foundations" << endl
         << "B)Digital Design" << endl
         << "C)Calculus" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "Enter your choice here: ";

    //User input
    cin >> subjectCode;
    hobbyCode = toupper(subjectCode);
    cout << endl;

    //Responses based on subject chosen
    switch (subjectCode)
    {
    case 'A':
      cout << "Make sure to take regular breaks and stay hydrated. Coding can be pretty engrossing." << endl;
      break;
    case 'B':
      cout << "Designing digital systems eh? Sounds like fun! Maybe you could take apart some old devices and fiddle with them too." << endl;
      break;
    case 'C':
      cout << "Ew, just thinking about it makes my processor hurt. We're usually the ones who end up doing all the calculations." << endl;
      break;
    default:
      cout << "Sorry, I didn't recognize that response. Maybe you should start with learning how to read?" << endl;
    }
    break;

  case 'C':
    //Declare Local Variables
    float hoursSlept;

    //Prompting the user
    cout << "After pulling that many all-nighters, not a bad idea. How long do you usually sleep every night?" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "Number of hours: ";

    //User input
    cin >> hoursSlept;
    cout << endl;

    //Error checking user input (infintely loops when given alphabetic data types)
    while (hoursSlept <= 0 || hoursSlept >= 24)
    {
      cout << "I do not understand, please try again: ";
      cin >> hoursSlept;
      cout << endl;
    }

    //Response based on hours slept
    if (hoursSlept >= 7 && hoursSlept <= 10)
    {
      cout << "Good job, you get " << hoursSlept << " hours of sleep, within the recommended amount! More over the break probably wouldn't hurt, right?" << endl;
    }
    else if (hoursSlept >= 4 && hoursSlept < 7)
    {
      cout << "I don't believe that " << hoursSlept << " hours of sleep is optimal. You humans need your beauty sleep!" << endl;
    }
    else if (hoursSlept > 10 && hoursSlept < 24)
    {
      cout << "Wow, " << hoursSlept << " hours, you must be really pretty because of all that beauty sleep. Well, enjoy getting even more over the break!" << endl;
    }
    else if (hoursSlept > 0 && hoursSlept < 4)
    {
      cout << "Sir, how are you even alive with " << hoursSlept << " hours of sleep? Time to make up for all that lost time!" << endl;
    }
    break;

  case 'D':
    //Declare Local Variables
    float bookCompletionTime;

    //Prompting the user
    cout << "I see you're a fellow bookworm. How long does it usually take you to finish a book?" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "Number of days: ";

    //User input
    cin >> bookCompletionTime;
    cout << endl;

    //Error checking user input (infintely loops when given alphabetic data types)
    while (bookCompletionTime <= 0)
    {
      cout << "I do not understand, please try again: ";
      cin >> bookCompletionTime;
      cout << endl;
    }

    //Response based on book completeion time
    if (bookCompletionTime <= 3)
    {
      cout << "Wow, you're a fast reader! I bet you could read " << (7 / bookCompletionTime) << " books over the break." << endl;
    }
    else if (bookCompletionTime > 3 && bookCompletionTime <= 7)
    {
      cout << "That's pretty good! You could probably read " << (7 / bookCompletionTime) << " books by the end of the break." << endl;
    }
    else if (bookCompletionTime > 7)
    {
      cout << "Not bad! It may take longer than the break, but you could finish " << (7 / bookCompletionTime) << " of a book before the of the break." << endl;
    }
    break;

  case 'E':
    //Declare Local Variables
    float investmentAmount;
    float investmentTime;

    //Prompting the user
    cout << "Smart choice, how much money are you thinking of investing?" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "Amount($): ";

    //User Input
    cin >> investmentAmount;
    cout << endl;

    //Error checking user input (infintely loops when given alphabetic data types)
    while (investmentAmount <= 0)
    {
      cout << "I do not understand, please try again: ";
      cin >> investmentAmount;
      cout << endl;
    }

    //Prompting the user
    cout << "And how long are you planning on leaving it invested?" << endl
         << setfill('-') << setw(hBreakLength) << '-' << endl
         << "Time in months: ";

    //User Input
    cin >> investmentTime;
    cout << endl;

    //Error checking user input (infintely loops when given alphabetic data types)
    while (investmentTime <= 0)
    {
      cout << "I do not understand, please try again: ";
      cin >> investmentTime;
      cout << endl;
    }

    //Output potential growth
    cout << "Wow, in " << investmentTime << " months, $" << investmentAmount << " could potentially turn into $" << (investmentAmount * (1.15 * (investmentTime / 12))) << "! Have fun investing!" << endl;
    break;
  default:
    //Response to undefined or errors
    cout << "Looks like you will be cleaning your house over the break. Time for some Spring cleaning!" << endl;
  }
  return 0;
}