﻿// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

bool isValidCharacter(char c) 
{
    return (isalnum(c) || c == '.' || c == '-' || c == '!' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '*' ||
        c == '+' || c == '/' || c == '=' || c == '?' || c == '^' || c == '_' || c == '{' || c == '}' || c == '|' || c == '~' || c == '`');
}

bool isValidEmail(const string & email) 
{
    int atIndex = -1;
    for (int i = 0; i < email.length(); ++i) 
    {
        if (email[i] == '@') 
        {
            if (atIndex != -1)
            {
                return false;
            }
            atIndex = i;
        }
        else if (!isValidCharacter(email[i])) 
        {
            return false;
        }
    }

    if (atIndex <= 0 || atIndex >= email.length() - 1)
    {
        return false;
    }

    string firstPart = email.substr(0, atIndex);
    string secondPart = email.substr(atIndex + 1);

    if (firstPart.length() < 1 || firstPart.length() > 64 || secondPart.length() < 1 || secondPart.length() > 63)
    {
        return false;
    }

    if (firstPart[firstPart.length() - 1] == '.' || secondPart[0] == '.' || secondPart[secondPart.length() - 1] == '.')
    {
        return false;
    }

    for (int i = 0; i < firstPart.length(); ++i)
    {
        if (firstPart[i] == '.' && firstPart[i + 1] == '.')
        {
            return false;
        }
    }

    for (int i = 0; i < firstPart.length(); ++i)
    {
        if (!isValidCharacter(firstPart[i]))
            return false;
    }

    for (int i = 0; i < secondPart.length(); ++i) 
    {
        if (!isalnum(secondPart[i]) && secondPart[i] != '.')
        {
            return false;
        }
    }

    return true;
}

int main() 
{
    setlocale(LC_ALL, "RU");
    string email;
    cout << "Введите email адрес: ";
    cin >> email;

    if (isValidEmail(email)) 
    {
        cout << "Успех!\n";
    }
    else 
    {
        cout << "Введите корректные данные!\n";
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
