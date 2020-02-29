#include <iostream>

// начало HeapSort-a
void heapify(int* numbers, int curr_length, int index)
{
    // Находим индек максимального элемента
    int max = index, left = 2 * index + 1, right = 2 * index + 2;
    if (left <= curr_length - 1 && numbers[left] > numbers[index])
        max = left;
    if (right <= curr_length - 1 && numbers[right] > numbers[max])
        max = right;

    if (max != index)
    {
        // Ставим максимальный элемент в вершину
        int tmp = numbers[max];
        numbers[max] = numbers[index];
        numbers[index] = tmp;
        // Рекурсивно обеспечиваем свойство кучи для вершины-потомка, в котором был максимальный элемент
        heapify(numbers, curr_length, max);
    }
}

void buildHeap(int* numbers, int array_size)
{
    // (array_size - 2) / 2 - последний родитель
    for (int i = (array_size - 2) / 2; i >= 0; --i)
        heapify(numbers, array_size, i);
}
//Функция сортировки на куче
//Необходимо реализовать данную функцию.
//Результат должен быть в массиве numbers.
void heapSort(int *numbers, int array_size) {
    buildHeap(numbers, array_size);
    for (int i = array_size - 1; i >= 0; --i)
    {
        int tmp = numbers[i];
        numbers[i] = numbers[0];
        numbers[0] = tmp;
        heapify(numbers, i, 0);
    }
}
// конец HeapSort-a

void input(int* left_borders, int* right_borders, int length){
    int numb;
    for (int i = 0; i < length; ++i) {
        std::cin >> numb;
        left_borders[i] = numb;
        std::cin >> numb;
        right_borders[i] = numb;
    }
}

int countMemesForLeftBound(int numb, const int* array, int length){
    // Бинарный поиск (если нет элемента, то выдает самый ближний слева)
    int left = 0, right = length, mid = 0;
    while(left < right){
        mid = (left + right) / 2;
        if (numb < array[mid])
            right = mid;
        else
            left = mid + 1;
    }
    int result = right - 1;
    while (result != -1 && array[result] > numb)
        result--;

    return length - 1 - result;
}

int countMemesForRightBound(int numb, const int* array, int length){
    // Бинарный поиск (если нет элемента, то выдает самый ближний справа)
    int left = 0, right = length, mid = 0;
    while(left < right){
        mid = (left + right) / 2;
        if (numb > array[mid])
            left = mid + 1;
        else
            right = mid;
    }
    int result = left;
    while (result != length && array[result] < numb)
        result++;

    return result;
}

void check(int numb, int* left_borders, int* right_borders, int length){
    int k = countMemesForLeftBound(numb, left_borders, length) +
            countMemesForRightBound(numb, right_borders, length);
    std::cout << length - k << "\n";
}

int main() {
    int length;
    std::cin >> length;
    int* left_borders = new int[length];
    int* right_borders = new int[length];
    input(left_borders, right_borders, length);
    // Сортируем для бинарного поиска
    heapSort(left_borders, length);
    heapSort(right_borders, length);
    int n;
    std::cin >> n;
    int numb;
    for (int i = 0; i < n; ++i) {
        std::cin >> numb;
        check(numb, left_borders, right_borders, length);
    }
    delete[] left_borders;
    delete[] right_borders;
}
