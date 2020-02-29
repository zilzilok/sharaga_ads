#include <iostream>

void merge(int* array, int left, int mid, int right)
{
    int i = left, j = mid + 1;
    int* new_array = new int[right + 1];
    for (int k = left; k <= right; ++k) {
        if (i == mid + 1) {
            while (j <= right) {
                new_array[k++] = array[j];
                ++j;
            }
            break;
        }

        if (j == right + 1) {
            while (i <= mid){
                new_array[k++] = array[i];
                i++;
            }
            break;
        }

        if (array[i] <= array[j])
            new_array[k] = array[i++];
        else
            new_array[k] = array[j++];
    }

    for (int m = left; m <= right; ++m)
        array[m] = new_array[m];

    delete[] new_array;
}

void print_array(int* array, int length)
{
    for (int i = 0; i < length; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int* array = new int[10] {1, 2, 2, 9, 9, 1, 1, 3, 5, 7};
    print_array(array, 10);
    merge(array, 0, 4, 9);
    print_array(array, 10);
    return 0;
}
