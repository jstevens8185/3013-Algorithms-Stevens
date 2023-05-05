/*****************************************************************************
 *
 *  Author:           Jered Stevens
 *  Email:            j.stevens8185@gmail.com
 *  Label:            P03
 *  Title:            AutoComplete using trie
 *  Course:           3013 Algorithms
 *  Semester:         Sp23
 *
 *  Description:
 *        This program reads in a list of words from dictionary.txt
 *           The words are stored in a Trie. When a user begins
 *           typing, the Trie is searched for words that match what the
 *           user has entered. 10 words are displayed that begin with
 *           the same letters as what has been entered.
 *
 *  Usage:
 *        Run the program and type words to see if they are in the dictionary
 *
 *  Files:            main.cpp
 *                    mygetch.hpp
 *                    termcolor.hpp
 *                    timer.hpp
 *                    dictionary.txt
 *****************************************************************************/

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

/**
 * Struct wordNode
 *
 * Description:
 *      holds a string, a wordNode pointer 'next' to the next wordNode, and
 *          a wordNode pointer 'prev' to the previous wordNode
 *
 * Public Methods:
 *      wordNode()
 *      wordNode(string)
 *
 *
 * Usage:
 *
 *      to be used in conjunction with wordList. wordNode takes in a parameter of
 *          type string. wordList handles the rest.
 *
 */
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

/**
 * Class wordList
 *
 * Description:
 *      Creates and manages a linked list containing wordNodes.
 *          Can be searched to see if specific words are in
 *          the dictionary
 *
 *
 * Public Methods:
 *      - wordList()
 *      - wordList(std::string wrd)
 *      - wordList(wordNode *node)
 *      - wordList(wordNode node)
 *      - insert(std::string str)
 *          returns void
 *      - size()
 *          returns int
 *      - getHead()
 *          returns wordNode*
 *      - printFirst10()
 *          returns void
 *      - printLast10()
 *          returns void
 *      - FindWords(wordList array, std::string substring)
 *          returns std::vector<std::string>
 *
 *
 * Private Methods:
 *      none
 *
 * Usage:
 *      declare a wordList then pass strings into it one at a time to
 *          populate the list. Call FindWords to enter characters in to 
 *          see if anything in the list matches what youve typed
 *
 */
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
    /**
     * Public : insert
     * 
     * Description:
     *      inserts a string into the linked list
     * 
     * Params:
     *      - std::string str
     *      
     * 
     * Returns:
     *      - returns void
     */
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
    /**
     * Public : size
     * 
     * Description:
     *      returns the how many elements are in the linked list
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      - int
     */
    int size()
    {
        return Size;
    }
    /**
     * Public : getHead
     * 
     * Description:
     *      used to get the head of the list
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      - wordNode* to the head of the list
     */
    wordNode *getHead()
    {
        return head;
    }

    /**
     * Public : FindWords
     * 
     * Description:
     *      searches the list and compares what has been typed with
     *          the beginning of words that are already in the list.
     *          only compares the number of characters that the user
     *          has entered. If matches are found they are stored in
     *          a vector to be returned
     * 
     * Params:
     *      - wordList array
     *      - std::string substring
     * 
     * Returns:
     *      - std::vector<std::string>
     */
   
    std::vector<std::string> FindWords(wordList array, std::string substring)
    {
        std::vector<std::string> matches; // to hold any matches
        size_t found;                     // size_t is an integer position of
                                          // found item. -1 if its not found.
        std::string word;
        wordNode *current = array.getHead();

        while (current != nullptr)
        {                         // loop through array
            word = current->word; // check for substr match
            if (word.substr(0, substring.length()) == substring)
            {                            // check for substring match at beginning of word
                matches.push_back(word); // add to matches
            }
            current = current->next;
        }

        return matches;
    }
};

int main()
{
    wordList Dictionary;
    char k;
    int loc;                          // location of substring to change its color
    std::vector<std::string> animals; // array of animal names
    std::vector<std::string> matches; // any matches found in vector of animals
    std::string word = "";
    std::ifstream input;
    input.open("dictionary.txt");
    std::string temp = "";

    Timer T; // start the timer
    T.Start();
    while (!input.eof()) // load the words into list
    {
        input >> temp;
        Dictionary.insert(temp);
    }
    T.End(); // end the timer

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

                    // Find any words in the array that partially match
                    // our substr word
        matches = Dictionary.FindWords(Dictionary, word);

        if ((int)k != 32)
        {           // if k is not a space print it
            T.End();
            std::cout << T.MilliSeconds() << " Milli" << std::endl;
            std::cout << "Keypressed: " << termcolor::blue << k << " = " << (int)k << termcolor::reset << std::endl;
            std::cout << "Current Substr: " << termcolor::red << word << termcolor::reset << std::endl;
            std::cout << "Words Found: ";
            std::cout << termcolor::green;
                    // This prints out all found matches
            for (int i = 0; i < 10; i++)
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
