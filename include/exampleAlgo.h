#ifndef EXAMPLEALGO_H
#define EXAMPLEALGO_H

#include "findWordAlgo.h"

class exampleAlgo : public findWordAlgo
{
    public:
        exampleAlgo(std::vector<std::string> wordList) : findWordAlgo(wordList) {};
        void initAlgo(int wordLength);
        std::string newGuess();
        void result(int bulls, int cows);
        void result(int cows);
    private:
        /// your own variables and functions goes here

};



#endif // EXAMPLEALGO_H
