// /***************************************************************
//  * File:        Heap.cpp
//  *
//  * Purpose:     Basic implementation of a heap data structure
//  *              Heaps are good for priority such as who uses
//  *              a printer first: everyones order goes to the
//  *              print queue but the boss always skips the line.
//  *
//  * SideNote:    A heap is a binary tree that stays complete
//  *              and can be stored in an array.
//  ****************************************************************/

// #include <iostream>

// using namespace std;

// /**
//  * Heaps come in 2 flavors: min-heap and max-heap
//  * in min heap the parent is less than child.
//  * in max heap the parent is bigger than the child.
//  *  
//  * Full = every inner node has all of its children
//  * Complete = Filled in from left to right
//  * 
//  * 
//  *  More efficient to store in an array than a list
//  *  Left = 2 * i
//  *  Right = 2 * i + 1
//  *  Parent = i/2
//  */

// class Heap
// {
//     int *heap;
//     int size;
//     int last;
//     int Left(int i)
//     {
//         return 2 * i;
//     }
//     int Right(int i)
//     {
//         return 2 * i + 1;
//     }

//     int Parent(int i)
//     {
//         return i / 2;
//     }
//     void BubbleUp(int i)
//     {
//         int p = i / 2;
//         if (heap[i] < heap[p])
//         {
//             Swap(i, p);
//         }
//     }
//     void Swap(int a, int b)
//     {
//         int temp = heap[a];
//         heap[a] = heap[b];
//         heap[b] = temp;

//         return;
//     }

// public:
//     Heap()
//     {
//         heap = new int[10];
//         size = 10;
//         last = 1;
//     }
//     void insert(int x)
//     {
//         heap[last = x];
//         BubbleUp(last);
//     }
//     void Heapify()
//     {
//         int i = size / 2;
//         // H = A;
//         // Next = size;
//         // HeapSize = size - 1;

//         for (int j = i; j >= 1; j--){

//         }
//     }
// };

// int main()
// {
// }