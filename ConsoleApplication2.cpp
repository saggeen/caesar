
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
