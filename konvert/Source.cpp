#include <iostream>
#include <iomanip>

using namespace std;

struct CurrencyRate {
    string name;
    double rate;
};

int main() {
    setlocale(LC_ALL, "Russian");
    CurrencyRate currencies[] = {
      {"Доллар", 92.71},
      {"Евро", 103.47},
      {"Юань", 13.22},
      {"Фунт", 124.2},
      {"Йена", 0.63}
    };

    const int numCurrencies = sizeof(currencies) / sizeof(currencies[0]);

    while (true) {
        double rub;
        cout << "Введите сумму рублей: ";
        cin >> rub;

        for (int i = 0; i < numCurrencies; ++i) {
            cout << i + 1 << ") " << currencies[i].name << endl;
        }

        int choice;
        cout << "Введите ваш выбор: ";
        cin >> choice;

        if (choice < 1 || choice > numCurrencies) {
            cout << "Некорректный ввод.\n";
            continue;
        }

        double amount = rub / currencies[choice - 1].rate;
        double commission = amount * 0.05;

        cout << fixed << setprecision(2);
        cout << "Вы можете купить " << amount - commission << " " << currencies[choice - 1].name << ".\n";
        cout << "Комиссия: " << commission << " " << currencies[choice - 1].name << endl;

        char repeat;
        cout << "\nХотите повторить обмен? (y/n): ";
        cin >> repeat;
        if (repeat != 'y') {
            break;
        }
    }

    cout << "До свидания!\n";
    return 0;
}

