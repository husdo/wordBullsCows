#ifndef FINDWORDALGO_H
#define FINDWORDALGO_H

#include <vector>
#include <iostream>

class findWordAlgo
{
    public:
        virtual std::string newGuess() = 0;
        virtual void initAlgo(int wordLength) = 0;
        virtual void result(int bulls, int cows) = 0;
        findWordAlgo(std::vector<std::string> wordList);
    protected:
        std::vector<std::string> wordList;
        int wordLength;
    private:

};



#endif // FINDWORDALGO_H


