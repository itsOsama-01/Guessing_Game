#ifndef HEADER
#define HEADER

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>

using namespace std;
void Highscores_compare(int guess_count);
void print_NumberOfGuesses( vector<int> vector );
void Play_Game();
void Highscore_Reset();

//                  All the function definations are here :

void Highscores_compare(int guess_count)
{

    //  This is where the High score comparesion is done using fstream.

    std::ifstream Input_file("Track_HighScore.txt");
    int Highest_Score;

    Input_file >> Highest_Score;

    if (!Input_file.is_open())
    {

        cout << "Sorry there was an error!!\n";
        return;
    }

    if (guess_count < Highest_Score)
    {

        cout << "\n******Awsome!!You made a new High score!!\n******You Guessed the number in " << guess_count << " tries!!";
        ofstream Output_file("Track_HighScore.txt");
        int New_HighScore = guess_count;

        if (!Output_file.is_open())
        {
            cout << "Sorry there was an error!!\nUnable to read file containing highscores";
            return;
        }

        Output_file << New_HighScore;
    }
    else
    {

        cout << "\nFewest tries/High Score: " << Highest_Score << "\n";
    }
    //**********************************************//
}

//Although not requiered i wanted the game to interact with palyers so.. :D

void print_NumberOfGuesses(vector<int> vector)
{
    if (vector.size() == 1)
    {
        cout << "OMG You are a Legend you got it in First try!!!" << endl;
    }
    else if (vector.size() > 1 && vector.size() <= 3)
    {
        cout << "Awsome!! it took You less than 3 turns to figure out the seceret number" << endl;
    }
    else if (vector.size() > 3 && vector.size() <= 5)
    {
        cout << "Nice it took you less than 5 turns to figure the secret numbet\n";
    }
    else if (vector.size() == 3)
    {
        cout << "Wow you guessed the secret number in exactly 3 turns." << endl;
    }
    else if (vector.size() == 5)
    {
        cout << "Fantastic you guessed the secret number in exactly 5 turns." << endl;
    }
    else if (vector.size() == 10)
    {
        cout << "Hmm, Looks like you guessed the number in exactly 10 turns." << endl;
    }
    else if (vector.size() > 5 && vector.size() <= 10)
    {
        cout << "You figured out the answer in less than 10 turns." << endl;
    }
    else if (vector.size() > 10)
    {
        cout << "It took you more than 10 turns to figure the number Thats shameful lol.\n";
    }
}

// This is basically the main part, the actual functionality of the game is defined here.

void Play_Game()
{

    vector<int> guesses;

    cout << "******** Hello this is a simple Number guessing game.***********\n******** You have to guess a secret number that lies in the range 0 to 20.*********\n******** Lets begin the game.*********" << endl;
    std::cout << std::endl;
    std::cout << std::endl;
    int random = rand() % 21;
    int guess;

    while (true)
    {

        cout << "Guess the Secret number: ";
        cin >> guess;
        guesses.push_back(guess);

        if (guess == random)
        {
            cout << "Wow! you won!!\n\n";

            break;
        }
        else if (guess < random)
        {
            cout << "Too Low!!\n"
                 << endl;

            cout << "Try again...\n";
        }
        else if (guess > random)
        {
            cout << "Too High!!\n"
                 << endl;

            cout << "Try again\n";
        }
    }

    cout << "Your tries: " << guesses.size() << endl;

    print_NumberOfGuesses(guesses);
    Highscores_compare(guesses.size());

    cout << endl;

    cout << "\npress 1 to play again\n"
         << endl;

    cout << "Press 0 button to exit\n"
         << endl;
    int choice2;
    cin >> choice2;
    if (choice2 == 1)
    {

        Play_Game();
    }
}

//This Function Refsets High score
void Highscore_Reset()
{
    ofstream Output_file("Track_HighScore.txt");
    Output_file << 100;
}

#endif