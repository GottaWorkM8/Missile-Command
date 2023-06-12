#pragma once
#include <fstream>
#include <string>


class GameSave
{
private:
    static int currentLevel;
    static int maxScores[5];

public:
    static void WonLevel(int score);
    static void NextLevel();
    static int GetMaxScore();
    static int GetCurrentLevel();
    static void SaveToFile(const std::string& filename);
    static void LoadFromFile(const std::string& filename);
};