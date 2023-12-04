#include "usefulfunctions.h"

class Game 
{
public:
    int id = 0;
    int maxRed = 0;
    int maxGreen = 0;
    int maxBlue = 0;
};

Game ParseGame(std::string gameString);

bool GamePossible(Game game);

int ExecuteDay2();