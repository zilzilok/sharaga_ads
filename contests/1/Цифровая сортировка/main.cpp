#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

typedef unsigned int uint;
typedef unsigned char uchar;

union Number
{
    uint full;
    uchar parts[4];
};

// Функция цифровой сортировки
void radixSort(int *numbers, int array_size)
{
    // Создаем указатель на массив юнион чисел
    auto* union_numbers = new Number[array_size];
    int i;
    for (i = 0; i < array_size; ++i)
        union_numbers[i].full = numbers[i];

    int index, size = 256;
    uint* tmp = new uint[size];
    // 4 раза, т.к. uint это 4 байта (как и uchar[4])
    for (index = 0; index < 4; ++index)
    {
        // Сортировка посчетом
        for (i = 0; i < size; ++i)
            tmp[i] = 0;

        for (i = 0; i < array_size; ++i)
            tmp[union_numbers[i].parts[index]]++;

        for (i = 1; i < size; ++i)
            tmp[i] += tmp[i - 1];

        for (i = array_size - 1; i >= 0; --i)
            numbers[--tmp[union_numbers[i].parts[index]]] = union_numbers[i].full;

        for (i = 0; i < array_size; ++i)
            union_numbers[i].full = numbers[i];
    }
    delete[] tmp;

    delete[] union_numbers;
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
    radixSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
