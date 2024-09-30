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
      {"������", 92.71},
      {"����", 103.47},
      {"����", 13.22},
      {"����", 124.2},
      {"����", 0.63}
    };

    const int numCurrencies = sizeof(currencies) / sizeof(currencies[0]);

    while (true) {
        double rub;
        cout << "������� ����� ������: ";
        cin >> rub;

        for (int i = 0; i < numCurrencies; ++i) {
            cout << i + 1 << ") " << currencies[i].name << endl;
        }

        int choice;
        cout << "������� ��� �����: ";
        cin >> choice;

        if (choice < 1 || choice > numCurrencies) {
            cout << "������������ ����.\n";
            continue;
        }

        double amount = rub / currencies[choice - 1].rate;
        double commission = amount * 0.05;

        cout << fixed << setprecision(2);
        cout << "�� ������ ������ " << amount - commission << " " << currencies[choice - 1].name << ".\n";
        cout << "��������: " << commission << " " << currencies[choice - 1].name << endl;

        char repeat;
        cout << "\n������ ��������� �����? (y/n): ";
        cin >> repeat;
        if (repeat != 'y') {
            break;
        }
    }

    cout << "�� ��������!\n";
    return 0;
}

