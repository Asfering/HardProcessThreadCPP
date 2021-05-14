
// Библиотеки
#include <windows.h>
#include <strsafe.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    // Русский
    setlocale(LC_ALL, "Russian");

    // Необходимые переменные
    STARTUPINFO sti = { 0 };    // Информация для загрузки
    PROCESS_INFORMATION pi = { 0 };     //  Переменная для выявления номера процесса
    DWORD excode;   // Процесс

    wstring CommandLine(L"Child.exe");      // Обращаемся к дочернему проекту
    LPWSTR lpwCmdLine = &CommandLine[0];    // Выстраиваем кмд линию

    cout << "---- Создание Процесса Родителя ----\n";   // Обращение на консоль
    if (!CreateProcess(NULL,
        lpwCmdLine,     // Вводим адрес 
        NULL,
        NULL,
        TRUE,
        NULL,
        NULL,
        NULL,
        &sti,
        &pi
    ))      // Создаем процесс
    {
        cout << "Невозможно создать процесс" << endl;
        return -1;
    }

    _getch();
    
    GetExitCodeProcess(pi.hProcess, &excode);
    cout << "Код процесса: " << excode << endl;

    if (excode != STILL_ACTIVE) {
        cout << "Процесс завершён" << endl;
    }
    else {
        cout << "Процесс работает" << endl;
    }
    cout << "---- Окончание Процесса Родителя ----" << endl;
    _getch();
}

