#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
double valid_amount(string message) {
    double amount;
    do {
        cout << message;
        cin >> amount;
        if (amount < 0) {
            cout << "Invalid input!\n"; }
    } while (amount < 0);
    return amount; }
int main() {
    int months;
    double a_trate;
    double balance;
    cout << fixed << setprecision(2);
    cout << "Enter yearly tax deduction rate: ";
    cin >> a_trate;
    cout << "Enter initial account balance: ";
    cin >> balance;
    cout << "Enter total number of months: ";
    cin >> months;
    double deposit[months];
    double withdrawl[months];
    double taxe[months];
    double taxR = a_trate / 12 / 100;
    double t_deposit = 0;
    double t_withdrawl = 0;
    double t_tax = 0;
    for (int i = 0; i < months; i++) {
        cout << "\n Month " << i + 1 << " ---\n";
        deposit[i] = valid_amount("Enter deposited amount: ");
        balance += deposit[i];
        t_deposit += deposit[i];
        withdrawl[i] = valid_amount("Enter withdrawaal amount: ");
        balance -= withdrawl[i];
        t_withdrawl += withdrawl[i];
        taxe[i] = balance * taxR;
        balance -= taxe[i];
        t_tax += taxe[i]; }
    cout << "Account: \n";
    cout << "Final Balance: " << balance << endl;
    cout << "Total Deposited: " << t_deposit << endl;
    cout << "Total Withdrawn: " << t_withdrawl << endl;
    cout << "Total Tax Deducted: " << t_tax << endl; }
