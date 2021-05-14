// Child.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "---- Создание Процесса Потомка ----\n";
    cout << "Я потомок процесса" << endl;
    cout << "---- Окончание Процесса Потомка ----\n";
    exit(0);
}

