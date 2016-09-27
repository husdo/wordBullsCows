#ifndef GAME_H
#define GAME_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <sstream>

#include "findWordAlgo.h"


class game
{
    public:
        game(std::string FileName);

        std::string setWordToFind();
        std::string setWordToFind(int wordLength);
        bool setWordToFind(std::string word);

        bool tryWord(std::string word);
        std::string printWord(int number);

        int getWordLength();
        std::vector<std::string> getWordList();
        int getBulls();
        int getCows();
        int getWin();

        std::string printInfo();

        void tryAlgorithm(findWordAlgo* fwa, int numberOfWords, std::ostream&out, bool debug = false);

    protected:

    private:
        game();
        std::vector<std::string> wordList;
        std::string wordToFind,lastGuess,errorMessage;
        int steps,cows,bulls,win,errorCode;
        std::vector<std::string> readWordList(std::string fileName);
};

#endif // GAME_H
