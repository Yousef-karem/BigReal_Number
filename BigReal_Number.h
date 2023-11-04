#ifndef BIGREAL_NUMBER_BIGREAL_NUMBER_H
#define BIGREAL_NUMBER_BIGREAL_NUMBER_H

#include<bits/stdc++.h>
using namespace std;
class BigReal_Number{
private:
    bool isValidReal (string realNumber); // True if correct real
    int compare(BigReal_Number Real1,BigReal_Number Real2);
public:
    string Integer;
    string Decimal;
    // true ='+',false='-'
    bool sign;
    BigReal_Number();
    BigReal_Number(string s);
    BigReal_Number(double number);
    bool operator< (BigReal_Number anotherReal);
    bool operator> (BigReal_Number anotherReal);
    bool operator== (BigReal_Number anotherReal);
friend ostream &operator<<(ostream&out,BigReal_Number n);


};
#endif //BIGREAL_NUMBER_BIGREAL_NUMBER_H
