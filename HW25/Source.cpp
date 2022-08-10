// Перевантаження чотирьох операторів
// Зверніть увагу, що всі оператори є двійковими
#include <iostream>
using namespace std;
class Digit {
private:
    double dig; // 
public:
    Digit()
    {
        dig = 0;
    }
    Digit(double iDig)
    {
        dig = iDig;
    }
    void Show() {
        cout << dig << "\n";
    }
    Digit operator+(const Digit& N)
    {
        Digit temp;
        temp.dig = dig + N.dig;
        return temp;
       
    }
    Digit operator-(const Digit& N)
    {
        Digit temp;
        temp.dig = dig - N.dig;
        return temp;
    }
    Digit operator*(const Digit& N)
    {
        Digit temp;
        temp.dig = dig * N.dig;
        return temp;
    }
   
    Digit operator^(const Digit& N)
    {
        if (N.dig == 0)
        {
            dig = 1;
            return dig;
        }
        else if (N.dig > 0)
        {
            for (size_t i = 0; i < N.dig; i++)
            {
                dig *= dig;
            }
            return dig;
        }
        else
        {
            dig = 1/dig;
            for (size_t i = 0; i < N.dig + 2 * N.dig; i++)
            {
                dig *= dig;
            }
            return dig;
        }
    }
};
int main()
{
    Digit A(9), B(-7);
    Digit C;
    cout << "Число A:\n";
    A.Show();
    cout << "Число B:\n";
    B.Show();
    cout << "Число С:\n";
    C.Show();
    cout << "\noperator+:\n";
    C = A + B;
    C.Show();
    cout << "\noperator-:\n";
    C = A - B;
    C.Show();
    cout << "\noperator*:\n";
    C = A * B;
    C.Show();
    cout << "\noperator^:\n";
    A = A ^ B;
    A.Show();
}