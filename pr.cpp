#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int num_chars, num_uppercase, num_special, num_passwords;
    char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?0123456789";

    // Запрос у пользователя количества символов каждого типа и количества паролей
    cout << "Введите количество обычных символов: ";
    cin >> num_chars;
    cout << "Введите количество символов в верхнем регистре: ";
    cin >> num_uppercase;
    cout << "Введите количество специальных символов: ";
    cin >> num_special;
    cout << "Введите количество паролей: ";
    cin >> num_passwords;

    // Генерация паролей
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int k = 0; k < num_passwords; k++) {
        string password = "";
        for (int i = 0; i < num_chars; i++) {
            password += lowercase_chars[rand() % 26];
        }
        for (int i = 0; i < num_uppercase; i++) {
            password[i] = uppercase_chars[rand() % 26];
        }
        for (int i = 0; i < num_special; i++) {
            password[i] = special_chars[rand() % 29];
        }

        // Перемешивание символов в пароле
        for (int i = 0; i < password.length(); i++) {
            int j = rand() % password.length();
            char temp = password[i];
            password[i] = password[j];
            password[j] = temp;
        }

        // Вывод пароля на экран
        cout << "Сгенерированный пароль " << k+1 << ": " << password << endl;
    }

    return 0;
}