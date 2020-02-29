
#include <algorithm>
#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

// Функция сортировки подсчетом
void countingSort(int *numbers, int array_size)
{
    int i, max = 0;
    for (i = 0; i < array_size; ++i)
        if (numbers[i] > max)
            max = numbers[i];

    int* tmp = new int[max + 1];
    for (i = 0; i < max + 1; ++i)
        tmp[i] = 0;

    for (i = 0; i < array_size; ++i)
        tmp[numbers[i]]++;

    for (i = 1; i < max + 1; ++i)
        tmp[i] += tmp[i - 1];

    int* res = new int[array_size];

    for (i = array_size - 1; i >= 0; --i)
        res[--tmp[numbers[i]]] = numbers[i];

    for (i = 0; i < array_size; ++i)
        numbers[i] = res[i];

    delete[] tmp;
    delete[] res;
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
    countingSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
