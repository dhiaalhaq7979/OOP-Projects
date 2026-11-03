// Encapsulation: the balance is private and can only change through deposit() and withdraw().
#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    BankAccount(const std::string& owner, double opening) : owner(owner), balance(opening > 0 ? opening : 0) {}

    bool deposit(double amount) {
        if (amount <= 0) return false;
        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        return true;
    }

    double getBalance() const { return balance; }
    std::string getOwner() const { return owner; }
};

int main() {
    BankAccount acc("Ali", 1000);
    std::cout << "Owner: " << acc.getOwner() << ", balance: " << acc.getBalance() << '\n';
    std::cout << "Deposit 500   -> " << (acc.deposit(500) ? "ok" : "rejected") << ", balance: " << acc.getBalance() << '\n';
    std::cout << "Withdraw 2000 -> " << (acc.withdraw(2000) ? "ok" : "rejected") << ", balance: " << acc.getBalance() << '\n';
    std::cout << "Withdraw 300  -> " << (acc.withdraw(300) ? "ok" : "rejected") << ", balance: " << acc.getBalance() << '\n';
    std::cout << "Deposit -50   -> " << (acc.deposit(-50) ? "ok" : "rejected") << ", balance: " << acc.getBalance() << '\n';
    return 0;
}
