# Assignment 1 - Database
**Jered Stevens**

### Overview
This project takes in a json file thats populated with people and their
information, such as their name, address, phone number, ect. and inserts
them into a database structure so that they are easily looked up by 
different search fields. The lookups happen in O(log n) time.

The program times the lookups and compares them to a lookup done in linear
time to show the difference in speed.

### Files
| # | Name | Description |
|---|------|-------------|
| 0 | [main.cpp](./main.cpp) | Main driver of program |
| 1 | [json.hpp](./json.hpp) | Allows json file to be used |
| 2 | [Employee.hpp](./Employee.hpp) | Provides structure of employees to be stored in database |
| 3 | [c_AvlTree.hpp](./c_AvlTree.hpp) | Provides database with the trees that will be used for storage and searching |
| 4 | [TreeManager.hpp](./TreeManager.hpp) | This is the database. All user functionality happens through this class |
| 5 | [timer.hpp](./timer.hpp) | Allows timing of searches |
| 6 | [random_person_data1.json](./random_person_data1.json) | Data used to test program |
| 7 | [output.txt](./output.txt) | Output of program |
| 8 | [banner.txt](./banner.txt) | Text file with course number, assignment number, and name |

### Instructions

**This program will not run unless [json.hpp](./json.hpp) is included.**
When ran, you will be prompted to enter your input file name (which must be a .json file),
and an output file name.
By default the program searches for the city "Wichita Falls" in linear fashion and outputs the
employee found and time taken to find, then searches for the same city in the database and outputs
the employee and time taken to find.

