#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

//Можно создавать любое количество любых вспомогательных классов, структур и методов для решения задачи.
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

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main() 
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    heapSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}