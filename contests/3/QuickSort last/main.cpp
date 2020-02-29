#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

//Можно создавать любое количество любых вспомогательных классов, структур и методов для решения задачи.
void swap_int(int& first, int& second)
{
    int tmp = first;
    first = second;
    second = tmp;
}

void _quickSort(int* numbers, int left, int right)
{
    if(left >= right)
        return;
    int key_elem = numbers[right];
    int i = left, j = right;
    while (i <= j)
    {
        while (numbers[i] < key_elem)
            i++;
        while (numbers[j] > key_elem)
            j--;
        if (i > j)
            break;
        swap_int(numbers[i], numbers[j]);
        i++;
        j--;
    }
    _quickSort(numbers, left, j);
    _quickSort(numbers, i, right);
}
//Необходимо реализовать алгоритм быстрой сортировки.
//В качестве опорного элемента выбирать последний
void quickSort(int *numbers, int array_size)
{
    _quickSort(numbers, 0, array_size - 1);
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
    quickSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}