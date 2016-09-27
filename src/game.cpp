#include "game.h"

game::game(std::string fileName)
{
    srand(std::time(NULL));
    wordList = readWordList(fileName);
}

std::vector<std::string> game::readWordList(std::string fileName)
{
    std::ifstream inFile(fileName.c_str());
    std::vector<std::string> v;
    std::string s;
    while(!inFile.eof())
    {
        getline(inFile,s);
        v.push_back(s);
    }
    return v;
}

std::string game::setWordToFind()
{
    steps = 0;
    wordToFind = wordList[rand()%wordList.size()];
    return wordToFind;
}

std::string game::setWordToFind(int length)
{
    steps = 0;
    wordToFind = "";
    while(wordToFind.length()!=length){
        wordToFind = wordList[rand()%wordList.size()];
    }
    return wordToFind;
}

bool game::setWordToFind(std::string word)
{
    steps = 0;
    std::vector<std::string>::iterator it;
    it = find(wordList.begin(),wordList.end(),word);

    if (it != wordList.end())
    {
        wordToFind = word;
        return true;
    }
    else
    {
        return false;
    }

}

bool game::tryWord(std::string word){
    lastGuess = word;

    std::string tmpWordToFind = wordToFind;
    cows = 0;
    bulls = 0;
    win = 0;

    if (word.length() != wordToFind.length())
    {
        std::stringstream ss;
        ss<<wordToFind.length();
        errorMessage = "The size of the guess is not equal to the size of the word. The right size is: " + ss.str();
        errorCode = 1;
        return false;
    }

    std::vector<std::string>::iterator it;
    it = find(wordList.begin(),wordList.end(),word);

    if (it == wordList.end())
    {
        errorMessage = "The guessed word does not exists in the wordList.";
        errorCode = 2;
        return false;
    }

    for (unsigned int i=0;i<word.length();i++){

        int pos = tmpWordToFind.find(word[i]);
        if (pos != std::string::npos)
        {
            cows++;
            tmpWordToFind.erase(pos,1);
        }
    }


    for (unsigned int i=0;i<word.length();i++){
        if (word[i]==wordToFind[i])
            bulls++;
    }
    cows -= bulls;

    if (bulls == word.length())
        win = 1;

    steps++;
    return true;
}

std::string game::printWord(int number)
{
    return wordList[number];
}

int game::getWordLength()
{
    return wordToFind.length();
}

std::vector<std::string> game::getWordList()
{
    return wordList;
}

int game::getBulls()
{
    return bulls;
}

int game::getCows()
{
    return cows;
}

int game::getWin()
{
    return win;
}

std::string game::printInfo()
{
    std::stringstream infoss;
    if (errorMessage != ""){
        std::string tmpErrorMessage = errorMessage;
        errorMessage = "";
        return tmpErrorMessage;
    }

    infoss<<"Last guess:"<<lastGuess;
    if(!win)
    {
        infoss<<"\t Bulls:"<<bulls;
        infoss<<"\t Cows:"<<cows<<"\n";
    }
    else
    {
        infoss<<"You won the game";
    }

    return infoss.str();
}

void game::tryAlgorithm(findWordAlgo* fwa,int numberOfWords, std::ostream& out, bool debug)
{
    double sumSteps;
    for (int i=0;i<numberOfWords;i++)
    {
        std::string word = this->setWordToFind();
        fwa->initAlgo(word.length());
        win = 0;
        while (!win){
            std::string guess = fwa->newGuess();
            if (this->tryWord(guess))
            {
                fwa->result(bulls,cows);
            }
            else
            {
                out<<errorMessage<<std::endl<<"The test stopped!";
                return;
            }

            if (debug)
            {
                out<<"Word to find: "<<wordToFind<<" Guessed word: "<<guess<<" Result: Bulls:"<<bulls<<" Cows:"<<cows<<"\n";
            }
        }
        out<< "Word to find: "<<wordToFind<<" in "<<steps<<" steps.\n";
        sumSteps += steps;
    }

    out<<"The average steps: "<<sumSteps/numberOfWords<<"\n";
}
