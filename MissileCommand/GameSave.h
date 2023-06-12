#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include "Globals.h"
#include "Verifier.h"

class Globals;

class GameSave {

    static const std::string FILENAME;
    static const std::string ENCRYPTION_KEY;
    static int currentLevel;
    static int maxScores[Globals::LEVELS_NUM];

    static void UpdateHighscore(int difficulty, int score);
    static void UnlockNextLevel(int difficulty);
    static void SaveToFile();
    static void Reset();
    static std::string EncryptData(const std::string& data);
    static std::string DecryptData(const std::string& encryptedData);

public:

    static int GetCurrentLevel();
    static int GetMaxScore(int difficulty);

    static void Update(int difficulty, int score, bool won);
    static void LoadFromFile();
};