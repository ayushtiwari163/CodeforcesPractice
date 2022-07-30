#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int games1 = 0;
    int stayWins1 = 0;
    int switchWins1 = 0;
    int chosenDoor1;
    int remainingDoor1;
    int revealedDoor1;
    int winningDoor1;
    int choice;

    srand(time(NULL));
    chosenDoor1 = rand() % 3 + 1;
    winningDoor1 = rand() % 3 + 1;

    do
    {
        do
        {
            revealedDoor1 = rand() % 3 + 1;
        } while (revealedDoor1 == chosenDoor1 || revealedDoor1 == winningDoor1);

        do
        {
            remainingDoor1 = rand() % 3 + 1;
        } while (remainingDoor1 == chosenDoor1 || remainingDoor1 == revealedDoor1);

        choice = rand() % 2 + 1;
        if (choice == 1)
        {
            if (chosenDoor1 == winningDoor1)
            {
                stayWins1++;
            }
        }
        if (choice == 2)
        {
            chosenDoor1 = remainingDoor1;
            if (chosenDoor1 == winningDoor1)
            {
                switchWins1++;
            }
        }
        games1++;
    } while (games1 < 10000);

    cout << "Out of 10,000 games1, the contestant won " << stayWins1 << " times by staying with his/her original choice and won " << switchWins1 << " times by switching his/her choice.\n";

    return 0;
}