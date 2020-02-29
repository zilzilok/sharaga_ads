#include "ReadWriter.h"
//iostream, fstream, Student_and_Ski.h включены в ReadWriter.h
using namespace std;

//Можно создавать любое количество любых вспомогательных методов для решения задачи.
//Рекомендуется использовать имеющиеся классы Student и Ski для решения задачи.

void quickSortById(Ski *skis, Student *students, int left, int right) {
    if (left >= right)
        return;
    int key_elem = students[(left + right) / 2].id;
    int i = left, j = right;
    while (i <= j) {
        while (students[i].id < key_elem)
            i++;
        while (students[j].id > key_elem)
            j--;
        if (i > j)
            break;
        swap(students[i], students[j]);
        swap(skis[i], skis[j]);
        i++;
        j--;
    }
    quickSortById(skis, students, left, j);
    quickSortById(skis, students, i, right);
}

int getKeyIndexSki(Ski *skis, Student *students, int left, int right) {
    int keyIndex_student = (left + right) / 2;
    Student key_student = students[keyIndex_student];
    int i = left, j = right;
    int keyIndex_ski = -1;
    while (i <= j) {
        while (compare(key_student, skis[i]) == -1)
            i++;
        if (compare(key_student, skis[i]) == 0) {
            keyIndex_ski = i++;
            while (i <= right && compare(key_student, skis[i]) == -1)
                i++;
        }
        while (compare(key_student, skis[j]) == 1)
            j--;
        if (compare(key_student, skis[j]) == 0)
            keyIndex_ski = j;
        if (i > j)
            break;
        if (keyIndex_ski == j)
            keyIndex_ski = i;
        swap(skis[i], skis[j]);
        i++;
        j--;
    }

    swap(skis[keyIndex_ski], skis[j]);
    keyIndex_ski = j;

    swap(students[keyIndex_ski], students[keyIndex_student]);
    return keyIndex_ski;
}

void sortSkiesByKeyIndexSki(Ski *skis, Student *students, int left, int right, int keyIndex_ski) {
    Ski key_ski = skis[keyIndex_ski];
    int i = left, j = right;
    while (i <= j) {
        while (compare(students[i], key_ski) == 1)
            i++;
        while (compare(students[j], key_ski) == -1)
            j--;
        if (i > j)
            break;
        swap(students[i], students[j]);
        i++;
        j--;
    }
}

void recursiveSort(Ski *skis, Student *students, int left, int right) {
    if (left >= right)
        return;
    int keyIndex_ski = getKeyIndexSki(skis, students, left, right);
    sortSkiesByKeyIndexSki(skis, students, left, right, keyIndex_ski);
    recursiveSort(skis, students, left, keyIndex_ski - 1);
    recursiveSort(skis, students, keyIndex_ski + 1, right);
}

//Задача - реализовать этот метод.
//Ответ должен быть упорядочен по возрастанию номеров студентов(!), то есть их id.
//Ответы должны быть в этих же массивах.
void findPairs(Student *students, Ski *skis, int n) {
    recursiveSort(skis, students, 0, n - 1);
    quickSortById(skis, students, 0, n - 1);
}

int main() {
    ReadWriter rw;

    Student *students = nullptr;
    Ski *skis = nullptr;
    int n;

    //Read n from file
    n = rw.readInt();

    //Create arrays
    students = new Student[n];
    skis = new Ski[n];

    //read Students and Skis from file
    rw.readStudents(students, n);
    rw.readSkis(skis, n);

    //Find pairs
    findPairs(students, skis, n);

    //Write answer to file
    rw.writeStudentsAndSkis(students, skis, n);

    delete[] students;
    delete[] skis;
    return 0;
}
