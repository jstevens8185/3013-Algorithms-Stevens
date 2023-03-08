/**
 * Assignment:  P01
 *       
 * @file        main.cpp
 * 
 * @author      Jered Stevens | jstevens@altruiststudios.com
 * 
 * @brief       Opens a json file with person data and 
 *              inserts data into avl trees for fast searching
 *          
 * @version     0.1
 * @date        2023-03-07
 * 
 **/

#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "TreeManager.hpp"
#include "timer.hpp"


using json = nlohmann::json;


void openFiles(std::ifstream& infile, std::ofstream& outfile);

int main()
{
    TreeManager treeManager;
    Timer t;
    double s;
    long m;
    std::ifstream in;
    std::ofstream out;
    openFiles(in, out);
    json Person = json::parse(in);
    const int PersonSize = Person.size();


    // Create array to hold all people
    c_Employee empList[PersonSize];


    for (int i = 0; i < PersonSize; i++)
    {
        // Create new c_Employee pointer for each person
        c_Employee *temp = new c_Employee(Person[i]["id"], Person[i]["first_name"],
                                          Person[i]["last_name"], Person[i]["email"], Person[i]["address"],
                                          Person[i]["city"], Person[i]["state"], Person[i]["latitude"],
                                          Person[i]["longitude"], Person[i]["car"], Person[i]["car_model"],
                                          Person[i]["car_color"], Person[i]["favorite_movie"],
                                          Person[i]["pet"], Person[i]["job_title"], Person[i]["phone_number"]);

        // Populate each persons stock portfolio
        for (std::string j : Person[i]["stocks"])
        {
            temp->pushStock(j);
        }

        // Push the person insto the array
        empList[i] = *temp;
    }

    // Give address of every person to the treeManager to insert into AVL trees 
    for (int i = 0; i < PersonSize; i++)
    {
        treeManager.insert(&empList[i]);
    }

    // Perform linear search for city "Wichita Falls"
    out << "Searching for city 'Wichita Falls' in empList...\n";
    t.Start();
    for(int i = 0; i < PersonSize; i++)
    {
        if (empList[i].getCity() == "Wichita Falls"){
            out << i+1 << " comparisons were made\n";
            out << *empList[i].getEmployee() << std::endl;
            
            break;
        }
        
    }
    t.End();
    s = t.Seconds();
    out << "Found in " << s << " seconds\n\n";

    // Perform search for city "Wichita Falls in the database"
    out << "Searching for 'Wichita Falls' in tree...\n";
    c_Employee *temp;
    t.Start();
    temp = treeManager.searchByCity("Wichita Falls", out);
    t.End();
    s = t.Seconds();

    out << *temp << std::endl;
    out << "Found in " << s << " seconds\n\n";
}


/****************************************************************
 *          Open Files Function
 *  Name:   openFiles(ifstream&, ofStream&)
 * 
 *  Args:   ifstream& infile, ofstream& outfile
 * 
 *  Rtrn:   void
 * 
 *  Func:   Opens input and output files of users choice
 * 
 *  Logic:  Declare char arrays to hold user specified
 *          input and output file names. Get names from user.
 *          Open files
 ****************************************************************/

void openFiles(std::ifstream& infile, std::ofstream& outfile)
{
    char inFileName[40];
    char outFileName[40];
    std::cout << "Enter the input file name: ";
    std::cin >> inFileName;
    infile.open(inFileName); //open input file
    //infile.open("program1_input2.txt");
    std::cout << "Enter the output file name: ";
    std::cin >> outFileName;
    outfile.open(outFileName);//open out putfile
    //outfile.open("out.txt");
};