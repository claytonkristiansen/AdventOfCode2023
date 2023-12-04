#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "day2.h"

using namespace std;

// Returns max number of red, green, and blue for game
Game ParseGame(string gameString) {
    Game game;

    stringstream gameStringStream(gameString);

    gameStringStream.ignore(5);
    string idString;
    getline(gameStringStream, idString, ':');
    game.id = stoi(idString);    

    string handful;
    while (getline(gameStringStream, handful, ';')) {
        stringstream handfulStream(handful);
        string dieCount;
        while (getline(handfulStream, dieCount, ',')) {
            stringstream dieCountStream(dieCount);
            dieCountStream.ignore(1);
            string count;
            string color;
            getline(dieCountStream, count, ' ');
            getline(dieCountStream, color);
            if (color == "red" && stoi(count) > game.maxRed) {
                game.maxRed = stoi(count);
            } 
            else if (color == "green" && stoi(count) > game.maxGreen) {
                game.maxGreen = stoi(count);
            }
            else if (color == "blue" && stoi(count) > game.maxBlue) {
                game.maxBlue = stoi(count);
            }
        }
    }

    return game;
}

bool GamePossible(Game game) {
    // number of available cubes
    int redCubes = 12;
    int greenCubes = 13;
    int blueCubes = 14;

    if (game.maxRed > redCubes || game.maxGreen > greenCubes || game.maxBlue > blueCubes) {
        return false;
    }
    
    return true;
}

int ExecuteDay2() {
    vector<string> input; 
    MyTools::ParseInput(input, "input.txt");

    int possibleGames = 0;
    int sumOfIds = 0;
    int sumOfAllIds = 0;
    int sumOfAllPowers = 0;

    for (string line : input) {
        Game game = ParseGame(line);
        if (GamePossible(game)) {
            ++possibleGames;
            sumOfIds += game.id;
        }
        sumOfAllIds += game.id;
        sumOfAllPowers += game.maxRed * game.maxGreen * game.maxBlue;
    }

    cout << "The sum of the ids of possible games is: " << sumOfIds << "\n\n";
    cout << "The sum of all ids is: " << sumOfAllIds << "\n\n";
    cout << "The sum of all powers is: " << sumOfAllPowers << "\n\n";

    return 0;
}