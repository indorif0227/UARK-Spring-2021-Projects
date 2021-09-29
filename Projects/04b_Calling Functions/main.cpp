/******************************************************************************
  Spring 2021 Programming Foundations I
  Author: Furqaan Indori
  Date: March 16, 2021
  Purpose: For this programming assignment, the objective is to become comfortable 
  making functions in C++. You will be modifying an existing program: homework4b.cpp
  Your task is to implement the seven functions listed in the instructions.

  The main function has already been implemented. As you begin to implement each
  function, uncomment the respective function call in main.
  *******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

//-------------------------------------------------------------------------------------------------
// Title:       Function 1
// Name:        getName
// Parameters:  None
// Returns:     string: the user's input
// Purpose:     This function welcomes the user, and prompts the user to enter in their name.
//              After the user has entered their name, return their answer.
//-------------------------------------------------------------------------------------------------

string getName()
{
  string racer;
  cout << "----------Welcome Racer----------" << endl
       << endl
       << "What is your name?" << endl;
  cin >> racer;

  cout << endl
       << "Welcome to the race " << racer << "!" << endl;

  return racer;
}

//-------------------------------------------------------------------------------------------------
// Title:       Function 2
// Name:        getVehicle
// Parameters:  TRUCK_SPEED: integer, pass by value, a truck's speed.
//              TRUCK_CRASH: integer, pass by value, a truck's crash time when hit.
//              KART_SPEED:  integer, pass by value, a kart's speed.
//              KART_CRASH:  integer, pass by value, a kart's crash time when hit.
//              BIKE_SPEED:  integer, pass by value, a bike's speed.
//              BIKE_CRASH:  integer, pass by value, a bike's crash time when hit
// Returns:     integer: the choice of vehicle with integer options. 1: for truck, 2: for Kart, 3: for bike
// Purpose:     This function prompts the user with a menu that shows the names of the vehicles and
//              the vehicle's specifications. The function gets the user's selection of vehicle
//              and performs error checking to ensure it returns a valid choice: 1, 2, or 3.
//
//-------------------------------------------------------------------------------------------------

int getVehicle(int TRUCK_SPEED, int TRUCK_CRASH, int KART_SPEED, int KART_CRASH, int BIKE_SPEED, int BIKE_CRASH)
{
  int choice;
  cout << "----------Welcome to the cart selection----------" << endl
       << "| Truck    |   Speed: " << TRUCK_SPEED << "    |   Crash time: " << TRUCK_CRASH << " |" << endl
       << "| Kart     |   Speed: " << KART_SPEED << "    |   Crash time: " << KART_CRASH << " |" << endl
       << "| Bike     |   Speed: " << BIKE_SPEED << "    |   Crash time: " << BIKE_CRASH << " |" << endl
       << endl
       << "Choose your cart wisely because they each have different stats" << endl
       << "1.Truck" << endl
       << "2.Kart" << endl
       << "3.Bike" << endl
       << endl
       << "Enter Choice: ";
  cin >> choice;
  cout << endl;

  while (choice > 3 || choice < 1)
  {
    cout << "Invalid selection, please select a valid cart option: ";
    cin >> choice;
    cout << endl;
  }

  return choice;
}

//-------------------------------------------------------------------------------------------------
// Title:       Function 3
// Name:        setVehicle
// Parameters:  playerSpeed: integer, pass by reference, the player's speed.
//              playerCrash: integer, pass by reference, the player's time spent crashing when hit.
//              choice:      integer, pass by value, the user's vehicle choice from previous function range (1-3).
//              TRUCK_SPEED: integer, pass by value, a truck's speed.
//              TRUCK_CRASH: integer, pass by value, a truck's crash time when hit.
//              KART_SPEED:  integer, pass by value, a kart's speed.
//              KART_CRASH:  integer, pass by value, a kart's crash time when hit.
//              BIKE_SPEED:  integer, pass by value, a bike's speed.
//              BIKE_CRASH:  integer, pass by value, a bike's crash time when hit.
// Returns:     void
// Purpose:     This function will utilize the choice returned by getVehicle and will set the
//              specification of the playerSpeed and playerCrash to the vehical stats associated
//              with the vehicle the user selected.
// If this is done correctly, "Player Stats" will display non-zero numbers when printed to the console
//-------------------------------------------------------------------------------------------------

void setVehicle(int &playerSpeed, int &playerCrash, int choice, int TRUCK_SPEED, int TRUCK_CRASH, int KART_SPEED, int KART_CRASH, int BIKE_SPEED, int BIKE_CRASH)
{
  switch (choice)
  {
  case 1:
    playerSpeed = TRUCK_SPEED;
    playerCrash = TRUCK_CRASH;
    break;
  case 2:
    playerSpeed = KART_SPEED;
    playerCrash = KART_CRASH;
    break;
  case 3:
    playerSpeed = BIKE_SPEED;
    playerCrash = BIKE_CRASH;
    break;
  }
}

//-------------------------------------------------------------------------------------------------
// Title:       Function 4
// Name:        checkWinning
// Parameters:  racerProgress:  integer, pass by value, the player's position on the race track, range (0, 100)
//              bowserProgress: integer, pass by value, Bowser's position on the race track, range (0, 100)
//              luigiProgress:  integer, pass by value, Luigi's position on the race track, range (0, 100)
// Returns:     boolean: If any racer has passed the finish line (the finsih line is when progress >= 100),
//                       return True
//                       If no racer has passed the finish line, return false.
// Purpose:     This function checks to see if a racer has passed the finish line.
//-------------------------------------------------------------------------------------------------

bool checkWinning(int racerProgress, int bowserProgress, int luigiProgress)
{
  if (racerProgress > 100 || bowserProgress > 100 || luigiProgress > 100)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//-------------------------------------------------------------------------------------------------
// Title:       Function 5
// Name:        randomBox
// Parameters:  None
// Returns:     string: "shell", "banana", "mushroom", "nothing"
// Purpose:     This function gives the racer an item on the race course. This function has
//              equal probability to randomly select any of the four items listed
//              above. Once an item is randomly picked, return it.
//-------------------------------------------------------------------------------------------------

string randomBox()
{
  string powerUp;
  int choice = rand() % 4;
  switch (choice)
  {
  case 0:
    powerUp = "nothing";
    break;
  case 1:
    powerUp = "shell";
    break;
  case 2:
    powerUp = "banana";
    break;
  case 3:
    powerUp = "mushroom";
    break;
  }
  return powerUp;
}

//-------------------------------------------------------------------------------------------------
// Title:       Function 6
// Name:        racerStatus
// Parameters:  name:  string,  pass by value, holds the racer's name.
//              speed: integer, pass by value, the speed the racer is currently going.
// Returns:     void
// Purpose:     This function prints a statement to console of the racer's name, current speed,
//              and a "yes" or "no" if the racer is stunned.
// Note**       A racer's speed will be 0 if they are stunned.
//-------------------------------------------------------------------------------------------------

void racerStatus(string name, int speed)
{
  string isStunned = "no";
  if (speed == 0)
  {
    isStunned = "yes";
  }
  
  cout << name << "| Speed: " << speed << "|Stunned: " << isStunned << endl;
}

//-------------------------------------------------------------------------------------------------
// Title:       Function 7
// Name:        resetSpeed
// Parameters:  racerSpeed:    integer, pass by reference, is the racer's current speed.
//              bowserSpeed:   integer, pass by reference, is Bowser's current speed.
//              luigiSpeed:    integer, pass by reference, is Luigi's current speed.
//              racerCarSpeed: integer, pass by value, the racer's vehicle speed.
//              TRUCK_SPEED:   integer, pass by value, the speed of a truck.
//              BIKE_SPEED:    integer, pass by value, the speed of a bike.
// Returns:     void
// Purpose:     This function fixes the bug when a user eats a mushroom, the speed is
//              changed for the entire game. The function checks to see if a racer is
//              going faster than their vehicle's speed. If they are going faster than
//              their vehicle's speed, set the racer's speed to their normal vehicle speed.
// Note** racerSpeed has a normal speed of racerCarSpeed
// Note** bowserSpeed has a normal speed of TRUCK_SPEED
// Note** luigiSpeed has a normal speed of BIKE_SPEED
//-------------------------------------------------------------------------------------------------

void resetSpeed(int & racerSpeed, int & bowserSpeed, int & luigiSpeed, int racerCarSpeed, int TRUCK_SPEED, int BIKE_SPEED)
{
  if (racerSpeed > racerCarSpeed)
  {
    racerSpeed = racerCarSpeed;
  }
  if (bowserSpeed > TRUCK_SPEED)
  {
    bowserSpeed = TRUCK_SPEED;
  }
  if (luigiSpeed > BIKE_SPEED)
  {
    luigiSpeed = BIKE_SPEED;
  }
}

/*
  * THIS IS SUPPLIED CODE DO NOT MODIFY attemptDodge
  * Racers try to dodge abilities
  */
bool attemptDodge(int &speed)
{
  bool dodge = false;
  if (speed != 0)
  {
    float myLuck = (1 / (speed / 5.0)) * 100;
    float enemyLuck = rand() % 100 + 50;
    dodge = (myLuck >= enemyLuck);
  }

  if (!dodge)
    speed = 0;
  return dodge;
}

/*
  * THIS IS SUPPLIED CODE DO NOT MODIFY statusBar
  * Prints the progress of a racer with their initial
  */
void statusBar(int &progress, const int speed, const char character)
{
  int barWidth = 100;

  cout << "[";
  int pos1 = progress;

  for (int i = 0; i < barWidth; ++i)
  {
    if (i < pos1)
      cout << "=";
    else if (i == pos1)
      cout << character;
    else
      cout << " ";
  }

  if (progress < 100)
    cout << "] " << int(progress) << " %\n";
  else
    cout << "] " << 100 << " %\n";
  // Increases the racer's progress as well
  progress += speed;
}

/*
  * THIS IS SUPPLIED CODE DO NOT MODIFY grabBox
  * Checks box locations to see if racer has passed one
  */
bool grabBox(const int progress, const int speed)
{
  const int BOX_LOCATIONS[] = {15, 25, 60, 75};
  for (int i = 0; i < 4; i++)
  {
    if (progress >= BOX_LOCATIONS[i] && progress - speed < BOX_LOCATIONS[i])
    {
      return true;
    }
  }
  return false;
}

/*
  * THIS IS SUPPLIED CODE DO NOT MODIFY checkCrash
  * Resets speed after spinout is done
  */
void checkCrash(int &racerSpeed, int &racerCrash, const int racerCarSpeed, const int racerCarCrash,
                int &BOWSER_SPEED, int &BOWSER_CRASH, const int TRUCK_SPEED, const int TRUCK_CRASH,
                int &LUIGI_SPEED, int &LUIGI_CRASH, const int BIKE_SPEED, const int BIKE_CRASH)
{
  // If racers are spinning out, decrease their counters
  if (racerSpeed == 0)
    racerCrash--;

  if (LUIGI_SPEED == 0)
    LUIGI_CRASH--;

  if (BOWSER_SPEED == 0)
    BOWSER_CRASH--;

  // If their spinout counter is 0, increase their speed
  if (racerCrash <= 0)
  {
    racerSpeed = racerCarSpeed;
    racerCrash = racerCarCrash;
  }
  if (LUIGI_CRASH <= 0)
  {
    LUIGI_SPEED = BIKE_SPEED;
    LUIGI_CRASH = BIKE_CRASH;
  }
  if (BOWSER_CRASH <= 0)
  {
    BOWSER_SPEED = TRUCK_SPEED;
    BOWSER_CRASH = TRUCK_CRASH;
  }
}

/*
  * THIS IS SUPPLIED CODE DO NOT MODIFY wasHit
  * Notifies the user if a racer was hit.
  */
void wasHit(const string name, const int racerSpeed, const int racerCrash, const int racerCarCrash)
{
  if (racerSpeed == 0 && racerCrash == racerCarCrash)
  {
    cout << name << " was hit!" << endl
         << endl;
  }
}

/*
  * THIS IS SUPPLIED CODE DO NOT MODIFY ability
  * Racer uses their ability as soon as it is available
  */
void ability(const int racerProgress, const int enemyOneProgress, const int enemyTwoProgress,
             int &racerSpeed, int &enemyOneSpeed, int &enemyTwoSpeed, const string item)
{
  // Increases speed by ten on shell use
  if (item == "mushroom")
  {
    racerSpeed += 10;
  }

  // Tries to hit enemies with shell only if they are in front
  if (item == "shell")
  {
    if (enemyOneProgress > racerProgress)
    {
      if (attemptDodge(enemyOneSpeed))
      {
        if (enemyTwoProgress > racerProgress)
        {
          attemptDodge(enemyTwoSpeed);
        }
      }
    }
    else if (enemyTwoProgress > racerProgress)
    {
      attemptDodge(enemyTwoSpeed);
    }
    else
      cout << "No enemies in front to target with the shell!" << endl
           << endl;
  }

  // Tries to hit enemies with banana only if they are behind
  if (item == "banana")
  {
    if (enemyOneProgress < racerProgress)
    {
      if (attemptDodge(enemyOneSpeed))
      {
        if (enemyTwoProgress < racerProgress)
        {
          attemptDodge(enemyTwoSpeed);
        }
      }
    }
    else if (enemyTwoProgress < racerProgress)
    {
      attemptDodge(enemyTwoSpeed);
    }
    else
      cout << "No enemies behind to target with a banana." << endl
           << endl;
  }
}

//-------------------------------------------------------------------------------------------------
// Title:       main
//              The only editing that is necessary in the main function is to uncomment code that
//              is specified in the report. You should NOT make any new variables or logic.
//-------------------------------------------------------------------------------------------------
int main()
{
  //--------------------------------------------------------
  // All of the variables before the "Function 1" comment
  // should NOT be modified
  //--------------------------------------------------------
  const int BIKE_SPEED = 8;
  const int BIKE_CRASH = 3;

  const int KART_SPEED = 7;
  const int KART_CRASH = 2;

  const int TRUCK_SPEED = 6;
  const int TRUCK_CRASH = 1;

  int BOWSER_SPEED = TRUCK_SPEED;
  int BOWSER_CRASH = TRUCK_CRASH;

  int LUIGI_SPEED = BIKE_SPEED;
  int LUIGI_CRASH = BIKE_CRASH;

  string racer = "p";

  int racerSpeed = 0;
  int racerCrash = 0;

  // Function 1
  racer = getName();

  srand(time(NULL));

  // Function 2
  int choice = getVehicle(TRUCK_SPEED, TRUCK_CRASH, KART_SPEED, KART_CRASH, BIKE_SPEED, BIKE_CRASH);

  // Function 3
  setVehicle(racerSpeed, racerCrash, choice, TRUCK_SPEED, TRUCK_CRASH, KART_SPEED, KART_CRASH, BIKE_SPEED, BIKE_CRASH);

  cout << endl;
  cout << "|------------------------------|" << endl;
  cout << "|        Player Stats          |" << endl;
  cout << "|                              |" << endl;
  cout << "|   Speed: " << racerSpeed << "   Crash time: " << racerCrash << "   |" << endl;
  cout << "|------------------------------|" << endl
       << endl;

  const int racerCarSpeed = racerSpeed;
  const int racerCarCrash = racerCrash;

  int racerProgress = 0;
  int bowserProgress = 0;
  int luigiProgress = 0;

  // Function 4
  while (!checkWinning(racerProgress, bowserProgress, luigiProgress))
  {
    // Function 5
    if (grabBox(racerProgress, racerSpeed))
    {
      string item = randomBox();
      cout << racer << " has picked up a " << item << endl;
      ability(racerProgress, bowserProgress, luigiProgress, racerSpeed, BOWSER_SPEED, LUIGI_SPEED, item);
    }
    if (grabBox(bowserProgress, BOWSER_SPEED))
    {
      string item = randomBox();
      cout << "Bowser "
           << "has picked up a " << item << endl;
      ability(bowserProgress, racerProgress, luigiProgress, BOWSER_SPEED, racerSpeed, LUIGI_SPEED, item);
    }
    if (grabBox(luigiProgress, LUIGI_SPEED))
    {
      string item = randomBox();
      cout << "Luigi "
           << "has picked up a " << item << endl;
      ability(luigiProgress, racerProgress, bowserProgress, LUIGI_SPEED, racerSpeed, BOWSER_SPEED, item);
    }

    cout << endl;
    wasHit(racer, racerSpeed, racerCrash, racerCarCrash);
    wasHit("Bowser", BOWSER_SPEED, BOWSER_CRASH, TRUCK_CRASH);
    wasHit("Luigi", LUIGI_SPEED, LUIGI_CRASH, BIKE_CRASH);

    // Function 6
    racerStatus(racer, racerSpeed);
    racerStatus("Bowser", BOWSER_SPEED);
    racerStatus("Luigi", LUIGI_SPEED);

    cout << endl;

    statusBar(racerProgress, racerSpeed, racer[0]);
    statusBar(bowserProgress, BOWSER_SPEED, 'B');
    statusBar(luigiProgress, LUIGI_SPEED, 'L');

    cout << endl
         << endl;

    // Function 7
    resetSpeed(racerSpeed, BOWSER_SPEED, LUIGI_SPEED,  racerCarSpeed, TRUCK_SPEED, BIKE_SPEED);

    checkCrash(racerSpeed, racerCrash, racerCarSpeed, racerCarCrash,
               BOWSER_SPEED, BOWSER_CRASH, TRUCK_SPEED, TRUCK_CRASH,
               LUIGI_SPEED, LUIGI_CRASH, BIKE_SPEED, BIKE_CRASH);

    this_thread::sleep_for(chrono::milliseconds(750));
  }

  statusBar(racerProgress, 0, racer[0]);
  statusBar(bowserProgress, 0, 'B');
  statusBar(luigiProgress, 0, 'L');

  cout << endl
       << endl;
  cout << "--------------- The Winner is... ---------------" << endl
       << endl;
  if (racerProgress >= 100)
  {
    cout << racer;
  }
  else if (luigiProgress >= 100)
  {
    cout << "Luigi";
  }
  else if (bowserProgress >= 100)
  {
    cout << "Bowser";
  }
  else
    cout << "looks like we need to implement some tasks!" << endl;

  return 0;
}