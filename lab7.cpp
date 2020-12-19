#include <iostream>
using namespace std;
#include <variant>
#include <vector>

struct MyException : public exception
{
    const char* what() const throw() { return "exception"; }
};

double divide(int a, int b)
{
    if (b == 0) {
        throw MyException();
    }
    return a / b;
}

int main()
{

    int a, b;
    cout << "podaj a" << endl;
    cin >> a;
    cout << "podaj b" << endl;
    cin >> b;
    /*
    try {
        cout << divide(a, b) << endl;
    }

    catch (const MyException& e) {
        cout << e.what() << endl;
    }
    */
    try {
        vector< int >          wektor(a, 0);
        variant< int, string > wariant;
        if (b % 2 == 0) {
            wariant = 42;
        }
        else {
            cout << "nieparzyste" << endl;
        }

        cout << get< int >(wariant) << endl;
    }
    catch (const bad_alloc& e) {
        cout << e.what() << " alloc" << endl;
    }
    catch (const bad_variant_access& e) {
        cout << e.what() << " var" << endl;
    }

    cout << "end" << endl;
}
