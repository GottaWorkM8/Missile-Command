#include "GameSave.h"

int GameSave::currentLevel = 1;
int GameSave::maxScores[5];

void GameSave::WonLevel(int score)
{
    if (maxScores[currentLevel - 1] < score)
    {
        maxScores[currentLevel - 1] = score;
    }
}

int GameSave::GetCurrentLevel()
{
    return currentLevel;
}

int GameSave::GetMaxScore()
{
    return maxScores[currentLevel - 1];
}

void GameSave::NextLevel()
{
    currentLevel++;
}

void GameSave::SaveToFile(const std::string& filename)
{
    std::ofstream outputFile(filename);

    if (outputFile.is_open())
    {
        outputFile << currentLevel << std::endl;

        for (int i = 0; i < 5; ++i)
        {
            outputFile << maxScores[i] << std::endl;
        }

        outputFile.close();
    }
}

void GameSave::LoadFromFile(const std::string& filename)
{
    std::ifstream inputFile(filename);

    if (inputFile.is_open())
    {
        inputFile >> currentLevel;

        for (int i = 0; i < 5; ++i)
        {
            inputFile >> maxScores[i];
        }

        inputFile.close();
    }
    else
    {
        SaveToFile(filename);
    }
}