///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jered Stevens
// Email:            jstevens@altruiststudios.com
// Title:            Tree Manager
// Semester:         Spring 2023
// Date:             7 March 2023
//
// Description:
//       This is a class to manage avl trees that store person data. To be 
//          used in conjunction with c_AvlTree.cpp and Employee.hpp
//       
// Usage: 
//      #include "TreeManager.hpp"
//      
//      TreeManager t;
//      c_Employee* temp;
//
//      for (int i = 0; i < EmployeeList.size(); i++)
//      {
//          t.insert(c_Employee* EmployeeList[i]);
//      }
//      
//      temp = t.searchByID(int 437);
//
//      cout << "Found employee " << *temp;
//
//      temp = t.searchByLastName(string "Stevens");
//
//      cout << "Found employee" << *temp;
//
// Public Functions:
//      insert(c_Employee *emp);
//      printHeights();
//      searchByID(int key, std::ofstream &out);
//      searchByFirstName(std::string key, std::ofstream &out);
//      searchByLastName(std::string key, std::ofstream &out);
//      searchByEmail(std::string key, std::ofstream &out);
//      searchByAdress(std::string key, std::ofstream &out);
//      searchByCity(std::string key, std::ofstream &out);
//      searchByState(std::string key, std::ofstream &out);
//      searchByCar(std::string key, std::ofstream &out);
//      searchByCarColor(std::string key, std::ofstream &out);
//      searchByCarModel(std::string key, std::ofstream &out);
/////////////////////////////////////////////////////////////////////////////////
#include "c_AvlTree.hpp"
#include "Employee.hpp"
#include <string>

#ifndef _TREEMANAGER_HPP
#define _TREEMANAGER_HPP

class TreeManager
{
private:
    c_AvlTree IdTree;
    c_AvlTree firstNameTree;
    c_AvlTree lastNameTree;
    c_AvlTree emailTree;
    c_AvlTree addressTree;
    c_AvlTree cityTree;
    c_AvlTree stateTree;
    c_AvlTree carTree;
    c_AvlTree carModelTree;
    c_AvlTree carColorTree;
    c_AvlTree favMovieTree;
    c_AvlTree petTree;
    c_AvlTree jobTitleTree;
    c_AvlTree phoneNumberTree;

public:
    TreeManager();
    void insert(c_Employee *emp);
    void printHeights();
    c_Employee *searchByID(int key, std::ofstream &out);
    c_Employee *searchByFirstName(std::string key, std::ofstream &out);
    c_Employee *searchByLastName(std::string key, std::ofstream &out);
    c_Employee *searchByEmail(std::string key, std::ofstream &out);
    c_Employee *searchByAdress(std::string key, std::ofstream &out);
    c_Employee *searchByCity(std::string key, std::ofstream &out);
    c_Employee *searchByState(std::string key, std::ofstream &out);
    c_Employee *searchByCar(std::string key, std::ofstream &out);
    c_Employee *searchByCarColor(std::string key, std::ofstream &out);
    c_Employee *searchByCarModel(std::string key, std::ofstream &out);
};

TreeManager::TreeManager()
{
}

//************************************************************************
// Method Name: insert
//
// Public
//
// Purpose: Inserts a node into every binary tree
//
// Arguments: pointer to c_Employee
//
// Returns: Nothing.
//*************************************************************************
void TreeManager::insert(c_Employee *emp)
{
    IdTree.insertByID(emp);
    firstNameTree.insertByFirstName(emp);
    lastNameTree.insertByLastName(emp);
    emailTree.insertByEmail(emp);
    addressTree.insertByAdress(emp);
    cityTree.insertByCity(emp);
    stateTree.insertByState(emp);
    carTree.insertByCar(emp);
    carModelTree.insertByCarModel(emp);
    carColorTree.insertByCarColor(emp);
}

//************************************************************************
// Method Name: printHeights
//
// Public
//
// Purpose: used for debugging. Prints the heights of every BST
//
// Arguments: none
//
// Returns: Nothing.
//*************************************************************************
void TreeManager::printHeights()
{
    std::cout << "IdTree height is:" << IdTree.treeHeight() << std::endl;
    std::cout << "firstNameTree height is:" << firstNameTree.treeHeight() << std::endl;
    std::cout << "lastNameTree height is:" << lastNameTree.treeHeight() << std::endl;
    std::cout << "emailTree height is:" << emailTree.treeHeight() << std::endl;
    std::cout << "addressTree height is:" << addressTree.treeHeight() << std::endl;
    std::cout << "cityTree height is:" << cityTree.treeHeight() << std::endl;
    std::cout << "stateTree height is:" << stateTree.treeHeight() << std::endl;
    std::cout << "carTree height is:" << carTree.treeHeight() << std::endl;
    std::cout << "carModelTree height is:" << carModelTree.treeHeight() << std::endl;
    std::cout << "carColorTree height is:" << carColorTree.treeHeight() << std::endl;
}

//************************************************************************
// Method Name: searchByID
//
// Public
//
// Purpose: Searches the IdTree for an integer that matches the input
//
// Arguments: int to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************

c_Employee *TreeManager::searchByID(int key, std::ofstream &out)
{
    c_Node *nodePtr = IdTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getId() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getId())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByFirstName
//
// Public
//
// Purpose: Searches the firstNameTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByFirstName(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = firstNameTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getFirstName() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getFirstName())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchBylastName
//
// Public
//
// Purpose: Searches the lastNameTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByLastName(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = lastNameTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getLastName() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getLastName())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByEmail
//
// Public
//
// Purpose: Searches the EmailTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByEmail(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = emailTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getEmail() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getEmail())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByAdress
//
// Public
//
// Purpose: Searches the AdressTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByAdress(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = addressTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getAdress() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getAdress())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByCity
//
// Public
//
// Purpose: Searches the CityTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByCity(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = cityTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        count++;
        if (nodePtr->getCity() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getCity())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByState
//
// Public
//
// Purpose: Searches the StateTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByState(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = stateTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getState() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getState())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByCar
//
// Public
//
// Purpose: Searches the CarTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByCar(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = carTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getCar() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getCar())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByCarColor
//
// Public
//
// Purpose: Searches the CarColorTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByCarColor(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = carColorTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getCarColor() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getCarColor())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
//************************************************************************
// Method Name: searchByCarModel
//
// Public
//
// Purpose: Searches the CarModelTree for string that matches the input
//
// Arguments: string to be searched for, ofstream& to output file
//
// Returns: pointer to a c_Employee
//*************************************************************************
c_Employee *TreeManager::searchByCarModel(std::string key, std::ofstream &out)
{
    c_Node *nodePtr = carModelTree.getRoot();
    int count = 0;
    while (nodePtr)
    {
        if (nodePtr->getCarModel() == key)
        {
            out << "Looked at " << count << " nodes\n";
            return nodePtr->getEmployee();
        }
        else if (key < nodePtr->getCarModel())
            nodePtr = nodePtr->Left;
        else
            nodePtr = nodePtr->Right;
    }
    out << "Item not found\n";
    return nullptr;
}
#endif