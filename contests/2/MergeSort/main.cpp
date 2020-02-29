#include "ReadWriter.h"
#include "MergeSort.h"
//iostream, fstream включены в ReadWriter.h

//Не рекомендуется добавлять собственные вспомогательные классы и методы.
//Необходимо использовать уже имеющиеся классы и методы, добавив реализацию, соответствующую описанию.
using namespace std;

//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
void MergeSort::sort(int *arr, int length)
{
    divide_and_merge(arr, 0, length - 1);
}

void MergeSort::merge(int* arr, int first, int second, int end)
{
    int i = first, j = second + 1;
    int* new_array = new int[end + 1];
    for (int k = first; k <= end; ++k)
    {
        if (i == second + 1)
        {
            while (j <= end)
            {
                new_array[k++] = arr[j];
                ++j;
            }
            break;
        }

        if (j == end + 1)
        {
            while (i <= second)
            {
                new_array[k++] = arr[i];
                i++;
            }
            break;
        }

        if (arr[i] <= arr[j])
        {
            new_array[k] = arr[i];
            ++i;
        }
        else
        {
            new_array[k] = arr[j];
            ++j;
        }
    }

    for (int m = first; m <= end; ++m)
        arr[m] = new_array[m];

    delete[] new_array;
}

void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        divide_and_merge(arr, left, mid);
        divide_and_merge(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read data from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}
