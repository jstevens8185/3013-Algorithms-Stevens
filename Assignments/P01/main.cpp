/***
 * build a data structure to sort and search employee files.
 * The included data points are as follows:
 * 
 * int id
 * string first_name
 * string last_name
 * string email
 * string address
 * string city
 * string state
 * double latitude
 * double longitude
 * string car
 * string car_model
 * string car_color
 * string pet
 * string job_title
 * string phone_number
 * vector <string> stocks
 * 
 * 
***/


/***
 * Gameplan:
 * 
 * Build an Employee. Employee will hold a value for each data point
 * Build employee array and load all employees in from data file.
 * Build binary tree node. Each node will hold an employee pointer for each data point
 *  ie. a node will hold employee* ID, employee* first_name, ect.
 * Build BST. Node 0 points to Employee array 0.
 *  ie. Node0->ID = EmployeeArray[0], Node0->first_name = EmployeeArray[0]
 *      Node1->ID = EmployeeArray[1], Node1->first_name = EmployeeArray[1], ect.
 * To sort, compare Node0->ID to Node1->ID. Switch pointers if neccessary. 
 *      Continue to sort all Node->ID until they are all in order.
 * Next, compare Node[0]->first_name to Node[1]->first_name. Switch pointers if neccessary.
 *      Sort all Node->first_name until they are all in order.
 * Repeat with every data value.
 * 
 * After sorting is complete you should be left with a single binary search tree that has all
 *      data values in a sorted order.
 * Node[0]->ID may point to EmployeeArray[5] while Node[0]->first_name may point to EmployeeArray[526].
 * 
***/

#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

int main()
{
    int i = 1;
    std::cout << i;
}