/*
    Author: Ariana Rajewski
    Date: 4/21/2021
    Description: It's a zombie conga party! This program generates a conga line of zombies and allows
        the user to determine how many rounds the party goes on for. Each round, a random action
        affects the party!
*/
#include <iostream>
#include <string>
#include "List.h"
#include "Zombie.h"

// Brains Actions
void engine(LinkedList<Zombie>*, Zombie);
void caboose(LinkedList<Zombie>*, Zombie);
void jumpInLine(LinkedList<Zombie>*, Zombie, int);
void everyoneOut(LinkedList<Zombie>*, Zombie);
void youreDone(LinkedList<Zombie>*, Zombie);
void brains(LinkedList<Zombie>*, Zombie);
void rainbowBrains(LinkedList<Zombie>*, Zombie);

using std::cout;
using std::cin;
using std::endl;
using std::to_string;

int main(int argc, char** argv)
{
    srand((unsigned)time(0));

    // Create beginning conga line
    cout << "Welcome to the Zombie Party!" << endl;
    LinkedList<Zombie>* congaList = new LinkedList<Zombie>(); // initialize conga line

    // Get a random char to start the conga line with
    int randChar = rand() % 5 + 1;
    char zombieChar;
    switch (randChar)
    {
        case(1):
            zombieChar = 'R';
            break;
        case(2):
            zombieChar = 'Y';
            break;
        case(3):
            zombieChar = 'G';
            break;
        case(4):
            zombieChar = 'B';
            break;
        case(5):
            zombieChar = 'M';
            break;
        case(6):
            zombieChar = 'C';
            break;
    }

    rainbowBrains(congaList, Zombie()); // fill conga line with rainbowBrains action
    
    // Run random number of Brains actions
    int numActions = rand() % 3 + 2; // random number between 2 and 5
    while (numActions > 0)
    {
        int randAction = rand() % 7 + 1; // random action between 1 and 7
        int randZombie = rand() % congaList->length() + 1; // random zombie index between the first zombie and the last zombie
        int randPos = rand() % congaList->length() + 1; // get random position in conga line
        Zombie zombie = congaList->retrieve(randZombie);
        
        switch (randAction)
        {
            case 1:
                engine(congaList, zombie);
                break;
            case 2:
                caboose(congaList, zombie);
                break;
            case 3:
                jumpInLine(congaList, zombie, randPos);
                break;
            case 4:
                everyoneOut(congaList, zombie);
                break;
            case 5:
                youreDone(congaList, zombie);
                break;
            case 6:
                brains(congaList, zombie);
                break;
            case 7:
                rainbowBrains(congaList, zombie);
                break;
        }
        numActions--;
    }
    // Display beginning conga line
    cout << "Here comes the conga line!\nZombies [" << to_string(congaList->length()) << "]: ";
    congaList->printList();

    // User Interface
    int numRounds;
    int count = 1;
    
    while (1)
    {
        // Prompt user for amount of rounds to play
        cout << endl << "\nHow many rounds would you like to play? (0 - Exit)\n\nSelection >> ";
        cin >> numRounds;

        if (numRounds == 0)
        {
            delete congaList;
            return 0;
        }

        while (numRounds > 0)
        {
            // Print round output
            cout << endl << endl << "---------- ROUND " << to_string(count) << " ----------" << endl << "Here comes the Zombie Party!" << endl;
            congaList->printList();

            if (congaList->length() == 0) // check if conga list is empty
            {
                cout << "I guess the party's over. There's no one left in the conga line!" << endl;
                delete congaList;
                return 0;
            }

            if (count != 1 && (count % 5) == 0) // every five rounds, remove one from front and end
                cout << "The conga line just got shorter! Say goodbye to " << congaList->removeFromFront() << " and " << congaList->removeFromEnd() << "." << endl;

            // Pick random action, zombie, and position
            int randAction = rand() % 7 + 1; // random action between 1 and 7
            int randZombie = rand() % congaList->length() + 1; // random zombie index between the first zombie and the last zombie
            int randPos = rand() % congaList->length() + 1; // get random position in conga line
            Zombie zombie = congaList->retrieve(randZombie);

            switch (randAction)
            {
                case 1:
                    engine(congaList, zombie);
                    cout << "[Engine] " << zombie << " is front and center at this party! They're leading the conga line!" << endl;
                    break;
                case 2:
                    caboose(congaList, zombie);
                    cout << "[Caboose] " << zombie << " knows the party is in the back." << endl;
                    break;
                case 3:
                    jumpInLine(congaList, zombie, randPos);
                    cout << "[Jump in Line] " << zombie << " knows where the brains are at. They jumped to position " << to_string(randPos) << "!" << endl;
                    break;
                case 4:
                    everyoneOut(congaList, zombie);
                    cout << "[Everyone Out] " << zombie << " and their friends got kicked out. Feelsbadman." << endl;
                    break;
                case 5:
                    youreDone(congaList, zombie);
                    cout << "[You're Done] Between you and me, I didn't like " << zombie << " either. They've mysteriously left the conga line!" << endl;
                    break;
                case 6:
                    brains(congaList, zombie);
                    cout << "[Brains] Didn't expect this, but apparently " << zombie << " has friends! They've joined the conga line!" << endl;
                    break;
                case 7:
                    rainbowBrains(congaList, zombie);
                    cout << "[Rainbow Brains] " << zombie << " has got the connections! Impressive." << endl;
                    break;
            }
            // Display conga line
            cout << "Here comes the conga line!\nZombies [" << to_string(congaList->length()) << "]: ";
            congaList->printList();

            numRounds--; // decrement number of rounds
            count++; // increment count
        }
    }
}

void engine(LinkedList<Zombie>* congaList, Zombie zombie)
/*
    Places this zombie at the front of the line.
*/
{
    congaList->addToFront(zombie);
}


void caboose(LinkedList<Zombie>* congaList, Zombie zombie)
/*
    Places this zombie at the end of the line.
*/
{
    congaList->addToEnd(zombie);
}


void jumpInLine(LinkedList<Zombie>* congaList, Zombie zombie, int position)
/*
    Inserts this zombie at the given position in the line.
*/
{
    congaList->addAtIndex(zombie, position);
}


void everyoneOut(LinkedList<Zombie>* congaList, Zombie zombie)
/*
    Remove all zombies that match the inputted zombie from the line.
*/
{
    congaList->removeAllOf(zombie);
}

void youreDone(LinkedList<Zombie>* congaList, Zombie zombie)
/*
    Remove the first matching zombie from the line.
*/
{
    congaList->removeTheFirst(zombie);
}


void brains(LinkedList<Zombie>* congaList, Zombie zombie)
/*
    Add two more matching zombies to the list: one at the front, one at the end, and one in the middle.
*/
{
    congaList->addToFront(zombie);
    congaList->addToEnd(zombie);
    
    int index = congaList->length() / 2;
    congaList->addAtIndex(zombie, index);
}


void rainbowBrains(LinkedList<Zombie>* congaList, Zombie zombie)
/*
    Places one zombie at the start of the conga line, and fills the conga line with one of each color zombie.
*/
{
    congaList->addToFront(zombie);
    congaList->addToEnd(Zombie('R'));
    congaList->addToEnd(Zombie('Y'));
    congaList->addToEnd(Zombie('G'));
    congaList->addToEnd(Zombie('B'));
    congaList->addToEnd(Zombie('M'));
    congaList->addToEnd(Zombie('C'));
}
