#include <iostream>
#include <vector>
#include<fstream>
#include <string>
#include <algorithm>

#include "hangman.h"
using namespace std;

void model::movieRandomizer(string& movie) {

    srand(time(0));
    int  totalLines = 0;

    //input file stream
    ifstream file("movies.txt");

    //count number of total lines in the file and setting seek to the beginning
    string unused;
    while (getline(file, unused))
        totalLines++;
    file.clear();
    file.seekg(0);

    //get random movie
    int lineCounter = 0, desiredNum = rand()%totalLines;
    while (getline(file, movie))
    {
        lineCounter++;
        if (desiredNum == lineCounter)
            break;
    }
};

void model::movieCensorer(string movie, string& censoredMovie) {
    censoredMovie = movie;
    replace_if(censoredMovie.begin(), censoredMovie.end(), ::isalpha, '_'); // replace all letters to '_'
};

char controller::userEntry() {
    char charGuess;
    cin >> charGuess;
    return charGuess;
};

bool controller::checkLetter(char charGuess, string movie) {
    if ((movie.find(charGuess)!= string::npos) || (movie.find(toupper(charGuess)) != string::npos))
        return true;
    else 
        return false;
};

void controller::updateLives(int &lives) {
    lives--;
};

void controller::updateMovieDisplay(string movie, string &censoredMovie, char charGuess) {
    int position = 0;
    while ((position = movie.find(charGuess, position)) != string::npos)
    {
        censoredMovie[position] = movie[position];
        position += 1;
    }
    position = 0;
    while ((position = movie.find(toupper(charGuess), position)) != string::npos)
    {
        censoredMovie[position] = movie[position];
        position += 1;
    }
};

bool controller::checkGameOver(int lives, string censoredMovie) {
    if (lives > 0 && censoredMovie.find('_') != string::npos)
        return 1;
    else
        return 0;
};

void view::refreshScreen(model m) {
    system("cls");
    displayCurrentProgress(m.movie, m.censoredMovie, m.lives);
    displayUsedLetters(m.usedLetters);
    displayHangman(m.lives);
};

void view::displayCurrentProgress(string movie, string censoredMovie, int lives) {
    cout << "Lives: " << lives << endl;
    cout << "Movie: " << movie << endl;
    cout << "Movie: " << censoredMovie << endl;
};
void view::displayUsedLetters(vector <char> &usedLetters) {
    cout << "Used letters: ";
    for (int i = 0; i < usedLetters.size(); i++)
        cout << usedLetters[i] <<" ";
    cout << endl;
};
void view::displayHangman(int lives) {
    switch(lives) {
    case 0:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /   O  " << endl <<
                "|/   /|\\" << endl <<
                "|     |  " << endl <<
                "|    / \\" << endl <<
                "|        " << endl <<
                "|________" << endl;
        break;

    case 1:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /   O  " << endl <<
                "|/   /|\\" << endl <<
                "|     |  " << endl <<
                "|    /   " << endl <<
                "|        " << endl <<
                "|________" << endl;
        break;

    case 2:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /   O  " << endl <<
                "|/   /|\\" << endl <<
                "|     |  " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|________" << endl;
        break;
    
    case 3:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /   O  " << endl <<
                "|/   /|\\" << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|________" << endl;
        break;

    case 4:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /   O  " << endl <<
                "|/   /|  " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|________" << endl;
        break;
    case 5:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /   O  " << endl <<
                "|/    |  " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|________" << endl;
        break;
    case 6:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /   O  " << endl <<
                "|/       " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|________" << endl;
        break;
    case 7:
        cout << "_______  " << endl <<
                "|  /  |  " << endl <<
                "| /      " << endl <<
                "|/       " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|        " << endl <<
                "|________" << endl;
            break;
    }
};
