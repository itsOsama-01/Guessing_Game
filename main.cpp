#include <iostream>
#include "Header.h"

using namespace std;


int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        cout << "                  ############################################################\n";
        cout << "                  #                          My Guessing Game                #\n";
        cout << "                  ############################################################\n";
        cout << endl;
        cout << endl;
        cout << "                                             1 Play Game" << endl;
        cout << endl;
        cout << endl;
        cout << "                                             2 Reset Highscore" << endl;
        cout << endl;
        cout << endl;
        cout << "                                             3 Exit" << endl;
        cout << endl;
        cout << endl;
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 3:
            cout << "                                ### Thanks For Playing, Bye ####\n";
            std::cout << std::endl;
            return 0;
        case 2:
            Highscore_Reset();
            break;
        case 1:
            Play_Game();
            break;
        default:

            cout << "can't load the game due to an unknown error! :(" << endl;
            break;
        }
    } while (choice != 0);
}