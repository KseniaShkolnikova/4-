#include <stdio.h>
#include <iostream>
using namespace std;

class BankAcccount {
private:
    int accountNumber;
    double balance;
    double interestRate;
    // приватный класс, который принимает в себя номер аакаунта, баланс и процентную ставкку
public:
    BankAcccount createAccount(int AccountNumber, double InitialBalance) {
        BankAcccount account;
        account.accountNumber = AccountNumber;
        account.balance = InitialBalance;
        account.interestRate = 0.0;
        return account;
        //Конструктор для создания аккаунта пользователя и возвращает перемнную типа BankAcccount
    }

    void deposit(BankAcccount* account, double amount) {
        account->balance += amount;
        // пополнение баланса полученного аккаунта на полученную сумму
    }

    void withdraw(BankAcccount* account, double amount) {
        if (amount <= account->balance) {
            account->balance -= amount;
            cout << " Сняли!\n";
        }
        else {
            cout << " У вас не столько денег(((\n";
        }
        // Снятие средств с проверкой на достаточное количество денег
    }

    double getBalance(BankAcccount* account) {
        return account->balance;
        // возвращает баланса аккаунта
    }

    double getInterest(BankAcccount* account) {
        return account->balance * account->interestRate * (1.0 / 12);
        // возвращает итог умножения баланса аккаунта, процента и 1/12
    }

    void setInterestRate(BankAcccount* account, double newRate) {
        account->interestRate = newRate;
        // устанавливает новый процент в аккаунте
    }

    int getAccountNumber(BankAcccount* account) {
        return account->accountNumber;
        // возвращает номер аккаунта
    }

    bool transfer(BankAcccount* from, BankAcccount* to, double denga) {
        if (from->balance >= denga) {
            from->balance -= denga;
            to->balance += denga;
            return true;
        }
        else {
            cout << " У вас не столько денег(((\n";
            
        }
        //проверка на достаточное количества денег с помощью условия, вычитание средств с баланса отправителя
        //добавление средств на аккаунт получателя
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    int accountNumber_1;
    double balance;
    int accountNumber_2;
    double balance2;
    double denga;
    double denga_1;
    double denga_2;
    bool gg = false;
    // создание необходимых переменных
    cout << "--------------Банк 'Солидити и С++'--------------\n";
    cout << " Введите номер вашего счёта: ";
    cin >> accountNumber_1;
    cout << " Введите баланс вашего счёта: ";
    cin >> balance;
    cout << " Супер! а теперь создадим второй счет\n";
    cout << " Введите номер второго счёта: ";
    cin >> accountNumber_2;
    cout << " Введите баланс второго счёта: ";
    cin >> balance2;
    // ввод пользователем необходимых данных
    BankAcccount bank;
    BankAcccount account1 = bank.createAccount(accountNumber_1, balance);
    BankAcccount account2 = bank.createAccount(accountNumber_2, balance2);
    //вызов конструктора и запись данных в переменные 
    while (true)
    {
        cout << " Выберите, что хотите сделать:\n  1. Пополнить баланс\n  2. Снять деньги\n  3. Вывести деньги\n  4. Посмотреть, сколько заработал\n  5. Новая процентная ставка\n  6. Мой номер счёта\n  7. Перевести на другой счет\n  8. Выйти\n";
        int vibor;
        cin >> vibor;
        //выбор функции через case
        switch (vibor)
        {
        case 1:
            cout << " Введите сумму денег, на которую хотите пополнить ваш счет: ";
            try
            {
                cin >> denga;
            }
            catch (const std::exception&)
            {
                cout << " Введите пожалуйста сумму";
                break;
            }
            bank.deposit(&account1, denga);
            cout << " Пополнили!\n";
            break;
            //пополнение с проверкой на ошибку и вызовом функции
        case 2:
            cout << " Введите сумму, которую хотите вывести: ";
            try
            {
                cin >> denga;
            }
            catch (const std::exception&)
            {
                cout << " Введите пожалуйста сумму";
                break;
            }
            bank.withdraw(&account1, denga);
            break;
            //снятие средств с на ошибку проверкой и вызовом функции
        case 3:
            denga = bank.getBalance(&account1);
            cout << " Баланс вашего счета: " << denga << endl;
            break;
            //вывод с вызовом функции
        case 4:
            denga = bank.getInterest(&account1);
            cout << " Вот сколько вы заработаете за год: " << denga << endl;
            break;
            //пополнение с вызовом функции
        case 5:
            cout << " Введите новую процентную ставку: ";
            try
            {
                cin >> denga;
            }
            catch (const std::exception&)
            {
                cout << " Введите пожалуйста сумму";
                break;
            }
            bank.setInterestRate(&account1, denga);
            break;
            //обновление процента с проверкой на ошибку и вызовом функции
        case 6:
            accountNumber_1 = bank.getAccountNumber(&account1);
            cout << " Вот номер вашего счёта: " << accountNumber_1 << endl;
            break;
            //вывод номера аккаунта с вызовом функции
        case 7:
            cout << " Введите сумму, которую хотите перевести: ";
            try
            {
                cin >> denga;
            }
            catch (const std::exception&)
            {
                cout << " Введите пожалуйста сумму";
                break;
            }
            gg = bank.transfer(&account1, &account2, denga);
            if (gg = true) {
                denga_1 = bank.getBalance(&account1);
                denga_2 = bank.getBalance(&account2);
                cout << "Перевод выполнен. Баланс вашего аккаунта: " << denga_1 << ", Баланс второго аккаунта: " << denga_2 << endl;
            }
            else {
                cout << "Не получилось. Ошибка!";
            }
            // присваивание новым переменным балансы аккаунтов
            break;
            //перевод средств с проверкой на ошибку  и вызовом функции
        case 8:
            cout << " Обязательно возвращайтесь!!!";
            exit(0);
            //выход из программы
        default:
            cout << " Нужно вводить номер варианта";
            break;
            // в случае ошибочного ввода
        }
    }
}