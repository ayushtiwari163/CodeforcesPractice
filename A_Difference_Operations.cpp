// converting decimal to hexadecimal in c++
#include <bits/stdc++.h>
using namespace std;
// function to convert decimal to hexadecimal in c++
void convertHexa(int number)
{
    cout << hex << number << endl;
}
// drive code
int main()
{
    int number; // store decimal number
    cin >> number;
    // calling function to convert decimal to hexadecimal in c++
    convertHexa(number);
}