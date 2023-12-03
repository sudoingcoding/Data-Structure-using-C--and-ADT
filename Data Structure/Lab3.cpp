#include <iostream>
#include <cmath>

using namespace std;

class Prime {
private:
    int r1;
    int r2;
    int counter;
    int num[100];

    bool isPrime(int number) {
        if (number < 2)
            return false;

        for (int i = 2; i <= number; i++) {
            if (number % i == 0)
                return false;
        }
        return true;
    }

public:
    Prime(int range1, int range2) {
        if (range1 >= range2) {
            cout << "r1 must be smaller than r2." << endl;
            return;
        }

        r1 = range1;
        r2 = range2;
        counter = 0;
    }

    void gprime() {
        for (int i = r1; i <= r2; i++) {
            if (isPrime(i))
                num[counter++] = i;
        }
    }

    void printStructure() {
        cout << "Prime Number Structure:" << endl;
        cout << "Range: " << r1 << " to " << r2 << endl;
        cout << "Number of Primes: " << counter << endl;
        cout << "Prime Numbers: ";
        for (int i = 0; i < counter; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int r1, r2;
    cout << "Enter the range (r1 and r2): ";
    cin >> r1 >> r2;

    Prime* p = new Prime(r1, r2);
    p->gprime();

    p->printStructure();

    delete p;

    return 0;
}