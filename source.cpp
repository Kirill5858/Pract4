#include <iostream>
#include <string>
#include <cstdlib>
#include "crypto1.h"
using namespace std;
using namespace CryptoPP;
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Программа шифрования: " << endl;
    unsigned op, cip;
    string FIn, FOut, Pass;
    do {
        cout << "\nВыберете действие: (0 - exit, 1 - encrypt, 2 - decrypt): ";
        cin >> op;
        if (op != 0) {
            cout << "\nВыберете алгоритм: " << endl;
            cout << "1 - AES" << endl;
            cout << "2 - DES" << endl;
            cout << "Введите номер выбранного алгоритма: ";
            cin >> cip;
        }
        if (op > 2) {
            cerr << "Ошибка!\n";
        }
        else if (op > 0) {
            cout << "Укажите путь файла : " << endl;
            cin >> FIn;
            cout << "Укажите путь файла для сохранения: " << endl;
            cin >> FOut;
            cout << "Введите пароль: " << endl;
            cin >> Pass;
            if (cip == 1) {
                AES_CRYP aes(FIn, FOut, Pass);
                if (op == 1) {
                    if (aes.encrypt())
                        cout << "Успешно зашифровано." << endl;
                    else
                        cout << "Не удалось зашифровать." << endl;
                }
                else {
                    if (aes.decrypt())
                        cout << "Успешно расшифровано." << endl;
                    else
                        cout << "Не удалось расшифровать" << endl;
                }
            }
            else if (cip == 2) {
                DES_CRYP des(FIn, FOut, Pass);

                if (op == 1) {
                    if (des.encrypt())
                        cout << "Успешно зашифровано." << endl;
                    else
                        cout << "Не удалось зашифровать." << endl;
                }
                else {
                    if (des.decrypt())
                        cout << "Успешно расшифровано." << endl;
                    else
                        cout << "Не удалось расшифровать." << endl;
                }
            }
            else {
                cerr << "Ошибка!\n";
            }
        }
    } while (op != 0);

    return 0;
}
