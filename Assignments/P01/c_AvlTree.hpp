///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Jered Stevens
// Email:            jstevens@altruiststudios.com
// Title:            c_Employee
// Semester:         Spring 2023
// Date:             7 March 2023
//
// Description:
//       This is a data into an AVL tree. To be used in
//          conjunction with Employee.hpp and TreeManager.hpp
//       
// Usage: 
//      This file is not meant to be used on its own.
//      Refer to TreeManager.hpp for usage.
/////////////////////////////////////////////////////////////////////////////////

#include "Employee.hpp"

#ifndef _C_AVLTREE_HPP
#define _C_AVLTREE_HPP

class c_Node
{
public:
    c_Node *Left;
    c_Node *Right;
    c_Node *Parent;
    c_Employee *Employee;
    short int AvlValue;
    c_Node()
    {
        Left = nullptr;
        Right = nullptr;
        Parent = nullptr;
        Employee = nullptr;
        AvlValue = 0;
    }
    c_Node(c_Employee *emp)
    {
        Left = Right = Parent = nullptr;
        Employee = emp;
        AvlValue = 0;
    }
    c_Node *getLeft();
    c_Node *getRight();
    c_Node *parent();
    c_Employee *getEmployee();
    int getId();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    std::string getAdress();
    std::string getCity();
    std::string getState();
    std::string getCar();
    std::string getCarModel();
    std::string getCarColor();
};

class c_AvlTree
{
private:
    c_Node *root;
    void insertNodeByID(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByFirstName(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByLastName(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByEmail(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByAdress(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByCity(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByState(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByCar(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByCarModel(c_Node *&nodePtr, c_Node *&newNode);
    void insertNodeByCarColor(c_Node *&nodePtr, c_Node *&newNode);
    void computeAvlValues(c_Node *&nodePtr);
    int avlValue(c_Node *nodePtr);
    void rotateRight(c_Node *&nodePtr);
    void rotateLeft(c_Node *&nodePtr);
    bool rightHeavy(c_Node *nodePtr);
    bool leftHeavy(c_Node *nodePtr);
    int height(c_Node *nodePtr);

public:
    c_AvlTree();
    ~c_AvlTree();
    c_Node* getRoot();
    int treeHeight();
    void insertByID(c_Employee *emp);
    void insertByFirstName(c_Employee *emp);
    void insertByLastName(c_Employee *emp);
    void insertByEmail(c_Employee *emp);
    void insertByAdress(c_Employee *emp);
    void insertByCity(c_Employee *emp);
    void insertByState(c_Employee *emp);
    void insertByCar(c_Employee *emp);
    void insertByCarModel(c_Employee *emp);
    void insertByCarColor(c_Employee *emp);
};

c_Node *c_Node::getLeft()
{
    return Left;
}
c_Node *c_Node::getRight()
{
    return Right;
}
c_Node *c_Node::parent()
{
    return Parent;
}
c_Employee *c_Node::getEmployee()
{
    return Employee->getEmployee();
}
int c_Node::getId()
{
    return Employee->getID();
}
std::string c_Node::getFirstName()
{
    return Employee->getFirstName();
}
std::string c_Node::getLastName()
{
    return Employee->getLastName();
}
std::string c_Node::getEmail()
{
    return Employee->getEmail();
}
std::string c_Node::getAdress()
{
    return Employee->getAddress();
}
std::string c_Node::getCity()
{
    return Employee->getCity();
}
std::string c_Node::getState()
{
    return Employee->getState();
}
std::string c_Node::getCar()
{
    return Employee->getCar();
}
std::string c_Node::getCarModel()
{
    return Employee->getCarModel();
}
std::string c_Node::getCarColor()
{
    return Employee->getCarColor();
}
c_AvlTree::c_AvlTree()
{
    root = nullptr;
}
c_AvlTree::~c_AvlTree()
{
}
c_Node* c_AvlTree::getRoot()
{
    return root;
}
void c_AvlTree::insertByID(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByID(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertByFirstName(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByFirstName(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertNodeByID(c_Node *&nodePtr, c_Node *&newNode)
{

    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->Employee->getID() <= nodePtr->Employee->getID())
    {
        newNode->Parent = nodePtr;
        insertNodeByID(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByID(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertNodeByFirstName(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getFirstName() <= nodePtr->getFirstName())
    {
        newNode->Parent = nodePtr;
        insertNodeByFirstName(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByFirstName(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertByLastName(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByLastName(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertNodeByLastName(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getLastName() <= nodePtr->getLastName())
    {
        newNode->Parent = nodePtr;
        insertNodeByLastName(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByLastName(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertByEmail(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByEmail(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertNodeByEmail(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getEmail() <= nodePtr->getEmail())
    {
        newNode->Parent = nodePtr;
        insertNodeByEmail(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByEmail(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertByAdress(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByAdress(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertByCity(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByCity(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertByState(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByState(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertByCar(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByCar(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertByCarModel(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByCarModel(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertByCarColor(c_Employee *emp)
{
    c_Node *newNode;

    newNode = new c_Node(emp);
    insertNodeByCarColor(root, newNode);
    computeAvlValues(root);
}
void c_AvlTree::insertNodeByAdress(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getAdress() <= nodePtr->getAdress())
    {
        newNode->Parent = nodePtr;
        insertNodeByAdress(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByAdress(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertNodeByCity(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getCity() <= nodePtr->getCity())
    {
        newNode->Parent = nodePtr;
        insertNodeByCity(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByCity(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertNodeByState(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getState() <= nodePtr->getState())
    {
        newNode->Parent = nodePtr;
        insertNodeByState(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByState(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertNodeByCar(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getCar() <= nodePtr->getCar())
    {
        newNode->Parent = nodePtr;
        insertNodeByCar(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByCar(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertNodeByCarModel(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getCarModel() <= nodePtr->getCarModel())
    {
        newNode->Parent = nodePtr;
        insertNodeByCarModel(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByCarModel(nodePtr->Right, newNode);
    }
}
void c_AvlTree::insertNodeByCarColor(c_Node *&nodePtr, c_Node *&newNode)
{
    if (nodePtr == NULL)
    {
        nodePtr = newNode;
    }
    else if (newNode->getCarColor() <= nodePtr->getCarColor())
    {
        newNode->Parent = nodePtr;
        insertNodeByCarColor(nodePtr->Left, newNode);
    }
    else
    {
        newNode->Parent = nodePtr;
        insertNodeByCarColor(nodePtr->Right, newNode);
    }
}
void c_AvlTree::computeAvlValues(c_Node *&nodePtr)
{
    if (nodePtr)
    {
        computeAvlValues(nodePtr->Left);
        computeAvlValues(nodePtr->Right);
        nodePtr->AvlValue = avlValue(nodePtr);
        if (nodePtr->AvlValue > 1)
        {
            rotateLeft(nodePtr);
        }
        else if (nodePtr->AvlValue < -1)
        {
            rotateRight(nodePtr);
        }
    }
}
void c_AvlTree::rotateRight(c_Node *&SubRoot)
{
    if (rightHeavy(SubRoot->Left))
    {
        rotateLeft(SubRoot->Left);
    }

    c_Node *Temp;

    Temp = SubRoot->Left;
    SubRoot->Left = Temp->Right;
    Temp->Right = SubRoot;
    SubRoot = Temp;

    computeAvlValues(SubRoot);
}
void c_AvlTree::rotateLeft(c_Node *&SubRoot)
{

    if (leftHeavy(SubRoot->Right))
    {
        rotateRight(SubRoot->Right);
    }

    c_Node *Temp;

    Temp = SubRoot->Right;
    SubRoot->Right = Temp->Left;
    Temp->Left = SubRoot;
    SubRoot = Temp;

    computeAvlValues(SubRoot);
}
int c_AvlTree::avlValue(c_Node *nodePtr)
{
    return height(nodePtr->Right) - height(nodePtr->Left);
}
bool c_AvlTree::leftHeavy(c_Node *nodePtr)
{
    return height(nodePtr->Left) > height(nodePtr->Right);
}

bool c_AvlTree::rightHeavy(c_Node *nodePtr)
{
    return height(nodePtr->Right) > height(nodePtr->Left);
}
int c_AvlTree::height(c_Node *nodePtr)
{
    int left_height = 0;
    int right_height = 0;
    if (nodePtr == NULL)
        return 0;
    else
    {
        left_height = height(nodePtr->Left);
        right_height = height(nodePtr->Right);
    }
    if (left_height > right_height)
        return 1 + left_height;
    else
        return 1 + right_height;
}
int c_AvlTree::treeHeight()
{
    return height(root);
}

#endif