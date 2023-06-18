#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include "Globals.h"
#include "Verifier.h"

/// <summary>
/// Class responsible for managing player's save file, i.e. tracking player's progress in the game
/// </summary>
class GameSave {

    static const std::string FILENAME;
    static const std::string ENCRYPTION_KEY;
    static int currentLevel;
    static int highscores[Globals::LEVELS_NUM];
    
    // Updates the highscore present in the save file for the given level
    static void UpdateHighscore(int difficulty, int score);
    // Unlocks the option for the player to play the next level
    static void UnlockNextLevel(int difficulty);
    // Saves important progress data to the save file
    static void SaveToFile();
    // Resets the content of the save file (used when inconsistencies appear in the save file)
    static void Reset();
    // Ecrypts data that is later placed in the save file to ensure that it is not unintentionally manipulated
    static std::string EncryptData(const std::string& data);
    // Decrypts the data present in the save file to import it into the class
    static std::string DecryptData(const std::string& encryptedData);

public:

    // Returns the integer representing the current level
    static int GetCurrentLevel();
    // Returns the highest score ever achieved by the player for the given level
    static int GetHighscore(int difficulty);

    // Updates all data present in the save file with the most current data
    static void Update(int difficulty, int score, bool won);
    // Loads data present in the save file into the class
    static void LoadFromFile();
};