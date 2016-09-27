/// in the game the newGuess function will be called first time
/// after each guess one of the result function will be called. This depends on the type of the game.
/// between new words the object will not be destructed and reconstructed. Just the initAlgo function will be called.

#include "exampleAlgo.h"
#include <cstdlib>
#include <iostream>

void exampleAlgo::initAlgo(int wordLength)
{
    this->wordLength = wordLength;
    /// inialize your algorithm here.

}

std::string exampleAlgo::newGuess()
{
    int i = rand()%wordList.size();
    while(wordList[i].length() != wordLength){
        i = rand()%wordList.size();
        //std::cout<<wordList[i]<<std::endl;
    }
    return wordList[i];
}

void exampleAlgo::result(int bulls, int cows)
{

}

void exampleAlgo::result(int cows)
{

}
