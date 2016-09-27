#include <iostream>
#include "findWordAlgo.h"
#include "exampleAlgo.h"
#include "game.h"


#include <fstream>

using namespace std;

const bool manual = false;

int main()
{
    ofstream oFile("debug.txt");

    game BullsCows("dictionary_english.dic");

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
        BullsCows.tryAlgorithm(algo,10,cout,0);
    }

    return 0;
}
