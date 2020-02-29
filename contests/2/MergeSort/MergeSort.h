class MergeSort
{
private:
    /*
    * Method to merge two sorted sections of the array to one sorted section.
    *
    * For instance:
    * if you pass array [ 7, 1, 3, 5, 7, 2, 4, 6, 1 ] with start_first == 1, start_second == 5 and end == 8 then
    * the array must be [ 7, 1, 2, 3, 4, 5, 6, 7, 1 ] after the method execution.
    *
    *  Parameters:
    *  int* arr         - array, which has two sorted sections and needs to merge them to one sorted section.
    *  int start_first  - index of the start of the first sorted section of the array (inclusive). Non-negative integer value.
    *  int start_second - index of the start of the second sorted section of the array (inclusive). Non-negative integer value.
    *  int end          - bound of both sorted sections (exclusive). Strictly positive integer value.
    */
    void merge(int* arr, int start_first, int start_second, int end);

    /*
    * Recursively splits array into two parts and merges it within bounds [ left (inclusively), right (exclusively) ]
    *
    * Parameters:
    *  int* arr  - array to sort.
    *  int left  - left bound (inclusive). Non-negative integer value.
    *  int right - right bound (exclusive). Strictly positive integer value.
    */
    void divide_and_merge(int *arr, int left, int right);

public:
    /*
    * This is the main method of sorting.
    *
    * Parameters:
    *  int* arr - array to sort.
    *  int n    - size of the array to sort. Strictly positive integer value.
    */
    void sort(int* arr, int n);
};
