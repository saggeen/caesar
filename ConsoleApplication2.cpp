// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

string encrypt_Caesar(string text, int n) 
{
    string result = "";
    string alphabet = "abcdefghijklmnopqrstuvwxyz"; // алфавит

    for (char c : text) 
    {
        if (isalpha(c)) 
        {
            char shifted = alphabet[(alphabet.find(tolower(c)) + n) % 26];
            if (isupper(c)) 
            {
                result += toupper(shifted);
            }
            else 
            {
                result += shifted;
            }
        }
        else 
        {
            result += c;
        }
    }

    return result;
}

string decrypt_Caesar(string text, int n) 
{
    return encrypt_Caesar(text, 26 - n); // дешифрование сдвигом в обратную сторону
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    string text = "Hello, World!";
    int n;
    cout << "Введите заданный сдвиг: " << endl;
    cin >> n;

    string encryptedText = encrypt_Caesar(text, n);
    string decryptedText = decrypt_Caesar(encryptedText, n);

    cout << "Оригинальный текст: " << text << endl;
    cout << "Зашифрованный текст: " << encryptedText << endl;
    cout << "Расшифрованный текст: " << decryptedText << endl;

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
