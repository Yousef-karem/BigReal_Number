#ifndef BIGREAL_NUMBER_BIGREAL_NUMBER_H
#define BIGREAL_NUMBER_BIGREAL_NUMBER_H

#include<bits/stdc++.h>
using namespace std;
class BigReal_Number{
private:
    bool isValidReal (string realNumber); // True if correct real
    //Compare Two strings and return 3 values
    // 1 for (Real1 > Real2) ,2 for (Real1 < Real2),0 for (Real1 == Real2)
    int compare(BigReal_Number Real1,BigReal_Number Real2);
    //two Functions to add or subtract two strings and return the value and the remaining value
    pair<string,int> add(string num1,string num2,int remaining);
    pair<string, int> subtract(string num1, string num2, int remaining);
public:
    string Integer;
    string Decimal;
    // true ='+',false='-'
    bool sign;
    BigReal_Number abs(BigReal_Number tmp);
    BigReal_Number();
    BigReal_Number(string s);
    BigReal_Number(double number);
    bool operator< (BigReal_Number anotherReal);
    bool operator> (BigReal_Number anotherReal);
    bool operator== (BigReal_Number anotherReal);
    friend ostream &operator<<(ostream&out,BigReal_Number n);
    BigReal_Number operator+ (BigReal_Number other);
    BigReal_Number operator- (BigReal_Number other);


};
#endif //BIGREAL_NUMBER_BIGREAL_NUMBER_H
