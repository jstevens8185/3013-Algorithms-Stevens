#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "timer.hpp"
#include "mygetch.hpp"
#include "termcolor.hpp"
#include <termios.h>
#include <thread>
#include <unistd.h>



struct wordNode
{
    std::string word;
    wordNode *next;
    wordNode *prev;

    wordNode()
    {
        word = " ";
        next = nullptr;
    };
    wordNode(std::string wrd)
    {
        word = wrd;
        next = nullptr;
    }
};

class wordList
{
private:
    wordNode *head;
    wordNode *tail;
    int Size;

public:
    wordList()
    {
        head = tail = nullptr;
        Size = 0;
    }
    wordList(std::string wrd)
    {
        head = tail = new wordNode(wrd);
        Size = 1;
    }
    wordList(wordNode *node)
    {
        head = tail = node;
        Size = 1;
    }
    wordList(wordNode node)
    {
        head = tail = &node;
        Size = 1;
    }
    void insert(std::string str)
    {
        if (!head)
        {
            head = tail = new wordNode(str);
            Size = 1;
        }
        else
        {
            tail->next = new wordNode(str);
            tail->next->prev = tail;
            tail = tail->next;
            Size++;
        }
    }
    int size()
    {
        return Size;
    }
    wordNode* getHead()
    {
        return head;
    }

    void printFirst10()
    {
        wordNode *temp;
        temp = head;
        for (int i = 0; i < 10; i++)
        {
            std::cout << temp->word << " ";
            temp = temp->next;
        }
    }
    void printLast10()
    {
        wordNode *temp;
        temp = tail;
        for (int i = 0; i < 10; i++)
        {
            std::cout << temp->word << " ";
            temp = temp->prev;
        }
    }
};

std::vector<std::string> FindWords(wordList array, std::string substring) {
    std::vector<std::string> matches; // to hold any matches
    size_t found;           // size_t is an integer position of
                            // found item. -1 if its not found.

    wordNode* current = array.getHead();

    while (current != nullptr) { // loop through array
        found = current->word.find(substring);    // check for substr match
        if (found != std::string::npos) {              // if found >= 0 (its found then)
            matches.push_back(current->word);     // add to matches
        }
        current = current->next;
    }

    return matches;
}

int main()
{
    wordList Dictionary;
    char k;
    int loc;                // location of substring to change its color
    std::vector<std::string> animals; // array of animal names
    std::vector<std::string> matches; // any matches found in vector of animals
    std::string word = "";
    std::ifstream input;
    input.open("dictionary.txt");
    std::string temp = "";

    Timer T;
    T.Start();
    while (!input.eof())
    {
        input >> temp;
        Dictionary.insert(temp);
    }
    T.End();

    std::cout << "Loaded list in " << T.MilliSeconds() << " milliseconds\n";

    std::cout << "Type keys and watch what happens. Type capital Z to quit." << std::endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z')
    {
        T.Start(); // start it
        // Tests for a backspace and if pressed deletes
        // last letter from "word".
        if ((int)k == 127)
        {
            if (word.size() > 0)
            {
                word = word.substr(0, word.size() - 1);
            }
        }
        else
        {
            // Make sure a letter was pressed and only letter
            if (!isalpha(k))
            {
                std::cout << "Letters only!" << std::endl;
                continue;
            }

            // We know its a letter, lets make sure its lowercase.
            // Any letter with ascii value < 97 is capital so we
            // lower it.
            if ((int)k < 97)
            {
                k += 32;
            }
            word += k; // append char to word
        }

        // Find any animals in the array that partially match
        // our substr word
        matches = FindWords(Dictionary, word);

        if ((int)k != 32)
        { // if k is not a space print it
            T.End();
            std::cout << T.NanoSeconds() << " nano" << std::endl;
            std::cout << "Keypressed: " << termcolor::blue << k << " = " << (int)k << termcolor::reset << std::endl;
            std::cout << "Current Substr: " << termcolor::red << word << termcolor::reset << std::endl;
            std::cout << "Animals Found: ";
            std::cout << termcolor::green;
            // This prints out all found matches
            for (int i = 0; i < matches.size(); i++)
            {
                // find the substring in the word
                loc = matches[i].find(word);
                // if its found
                if (loc != std::string::npos)
                {
                    // print one letter at a time turning on red or green
                    //  depending on if the matching subtring is being printed
                    for (int j = 0; j < matches[i].size(); j++)
                    {
                        // if we are printing the substring turn it red
                        if (j >= loc && j <= loc + word.size() - 1)
                        {
                            std::cout << termcolor::red;
                        }
                        else
                        {
                            std::cout << termcolor::green;
                        }
                        std::cout << matches[i][j];
                    }
                    std::cout << termcolor::green;
                }
                std::cout << " ";
            }
            std::cout << termcolor::reset << std::endl
                 << std::endl;
        }
    }
    return 0;
}
