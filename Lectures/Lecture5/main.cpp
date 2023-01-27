/***
 *  Sorts an array then does a binary search
 *  in the sorted array
 * 
***/

#include <iostream>

using namespace std;

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return;
};

void BubbleSort(int *array)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (array[j] < array[i]){
                Swap(array, i, j);
            }
        }
    }
};



int main()
{
    int A[10] = {23, 4, 6, 77, 3, 98, 12, 87, 33, 100};

    BubbleSort(A);

    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << ' ';
    }
}