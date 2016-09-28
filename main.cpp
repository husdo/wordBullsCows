#include <iostream>
#include "findWordAlgo.h"
#include "exampleAlgo.h"
#include "game.h"


#include <fstream>

using namespace std;

const bool manual = false;
const int randomSeed = 20160928;

int main()
{
    ofstream oFile("debug.txt");

    game BullsCows("dictionary_english.dic");
    BullsCows.setRandomSeed(randomSeed);

    if (manual)
    {
        bool win = false;
        cout<<BullsCows.setWordToFind(4);
        while (!win)
        {
            string guess;
            cin>>guess;
            if(!BullsCows.tryWord(guess))
            {
                cout<<BullsCows.printInfo()<<endl;
                return -1;
            }
            cout<<BullsCows.printInfo();
            win = BullsCows.getWin();
        }
    }
    else
    {
        exampleAlgo ea(BullsCows.getWordList());
        findWordAlgo *algo = &ea;
        BullsCows.tryAlgorithm(algo,-1,cout,0); /// if the 2nd parameter is -1 than it will test with 100 element from the random seed.
    }

    return 0;
}
