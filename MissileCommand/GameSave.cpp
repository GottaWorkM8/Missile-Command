#include "GameSave.h"

const std::string GameSave::FILENAME = "savefile.txt";
const std::string GameSave::ENCRYPTION_KEY = "YourEncryptionKey";
int GameSave::currentLevel = 1;
int GameSave::maxScores[5];

int GameSave::GetCurrentLevel() {
    return currentLevel;
}

int GameSave::GetMaxScore(int difficulty) {
    return maxScores[difficulty - 1];
}

void GameSave::Update(int difficulty, int score, bool won) {

    if (won)
        UnlockNextLevel(difficulty);

    UpdateHighscore(difficulty, score);
    SaveToFile();
}

void GameSave::LoadFromFile() {

    std::ifstream file(FILENAME);

    if (file.is_open()) {

        std::stringstream encryptedData;
        encryptedData << file.rdbuf();

        std::string decryptedData = DecryptData(encryptedData.str());
        std::istringstream decryptedStream(decryptedData);
        int loadedLevel;
        decryptedStream >> loadedLevel;

        if (Verifier::ValidLevel(loadedLevel)) {

            int loadedScores[Globals::LEVELS_NUM];

            for (int i = 0; i < Globals::LEVELS_NUM; ++i) {

                decryptedStream >> loadedScores[i];

                if (!Verifier::ValidScore(loadedScores[i])) {

                    file.close();
                    Reset();
                    return;
                }
            }

            currentLevel = loadedLevel;

            for (int i = 0; i < Globals::LEVELS_NUM; ++i)
                maxScores[i] = loadedScores[i];
        }

        else {

            file.close();
            Reset();
        }
    }

    else Reset();
}

void GameSave::UpdateHighscore(int difficulty, int score) {

    if (maxScores[difficulty - 1] < score)
        maxScores[difficulty - 1] = score;
}

void GameSave::UnlockNextLevel(int difficulty) {

    if (difficulty < Globals::LEVEL_MAX)
        currentLevel = difficulty + 1;

    else currentLevel = Globals::LEVEL_MAX;
}

void GameSave::SaveToFile() {

    std::ofstream file(FILENAME);

    if (file.is_open()) {

        std::ostringstream saveData;
        saveData << currentLevel << std::endl;

        for (int i = 0; i < Globals::LEVELS_NUM; ++i)
            saveData << maxScores[i] << std::endl;

        std::string encryptedData = EncryptData(saveData.str());
        file << encryptedData;
        file.close();
    }
}

void GameSave::Reset() {

    currentLevel = 1;

    for (int i = 0; i < Globals::LEVELS_NUM; i++)
        maxScores[i] = 0;

    SaveToFile();
}

std::string GameSave::EncryptData(const std::string& data) {

    std::string encryptedData;

    for (size_t i = 0; i < data.size(); ++i)
        encryptedData += data[i] ^ ENCRYPTION_KEY[i % ENCRYPTION_KEY.size()];

    return encryptedData;
}

std::string GameSave::DecryptData(const std::string& encryptedData) {

    return EncryptData(encryptedData);
}