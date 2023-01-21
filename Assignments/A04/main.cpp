/*****************************************************************************
*                    
*  Author:           Jered Stevens / Terry Griffin
*  Email:            j.stevens8185@gmail.com
*  Label:            A04
*  Title:            Circular queue class
*  Course:           CMPS 3013
*  Semester:         Spring 2023
* 
*  Description:
*           This program creates a circular array based queue. It keeps track of the front, rear,
*           and size of the queue. It's public functions allow the user to push and pop items
*           to and from the queue. It also allows for printing the contents of the queue using the
*           << operator.
*        
*  Usage: 
*           To use this program the user simply runs the code. Modification may be made to change
*           the values pushed and popped to and from the queue        
*
*       
*  Files:            
*       main.cpp    : driver program 
*****************************************************************************/

#include <iostream>

using namespace std;

/****************************************************************************
 * Class:           CircularArrayQue
 * 
 * Description:     This class implements a circular queue using and array
 *                  Circular queues may be used in any context where data
 *                  must repeat, such as setting a playlist of songs to 
 *                  repeat.
 * 
 * Private Methods:
 *      int*        Container
 *      int         Front
 *      int         Rear
 *      int         QueSize;
 *      int         CurrentSize
 *      void        init
 *      bool        Full
 * 
 * Public Methods:
 *                  CircularArrayQue()
 *                  CircularArrayQue(int)
 *      void        Push(int item)
 *      int         Pop()
 *      ostream     operator<<
 *      
 * 
 * Usage:
 *      CircularArrayQue()              // Create default array with 10 items
 *      
 *      CircularArrayQue(int size)      // Create array with 'size' items
 * 
 *      Push(int item)                  // Insert 'item' into back of queue
 * 
 *      Pop()                           // Remove and return first item in queue
*****************************************************************************/

class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;

    /**
     * Private : init
     * 
     * Description:
     *      initialize que to be emtpy
     * 
     * Params:
     *      [int]       :       Size of queue   
     * 
     * Returns:
     *      void
     */

    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private : Full
     * 
     * Description:
     *      Returns true if queue is at max capacity
     * 
     * Params:
     *      none  
     * 
     * Returns:
     *      True if queue is full, otherwise false
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:

    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      default constructor for CircularArrayQue. Sets size to 10
     * 
     * Params:
     *      none 
     * 
     * Returns:
     *     
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    
    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      overloaded constructor for CircularArrayQue. Sets size to passed in value
     * 
     * Params:
     *      [int]   :   size    --  set size of queue
     * 
     * Returns:
     *     
     */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push
     * 
     * Description:
     *      Insert value at end of queue
     * 
     * Params:
     *      [int]   :   item    --  value to be pushed to queue
     * 
     * Returns:
     *     void
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Public : Pop
     * 
     * Description:
     *      Removes front value of queue and returns it. Decreases 
     *      current size of queue and moves front to next value
     * 
     * Params:
     *      none 
     * 
     * Returns:
     *     int  -- value at front of queue at time of pop
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    /**
     * Public : operator<<
     * 
     * Description:
     *      Allows printing of queue with the << operator
     * 
     * Params:
     *      [ostream&]  os
     *      [const CircularArrayQue&] other
     * 
     * Returns:
     *     ostream&
     */
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}