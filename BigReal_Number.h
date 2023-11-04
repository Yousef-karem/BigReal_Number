#ifndef BIGREAL_NUMBER_BIGREAL_NUMBER_H
#define BIGREAL_NUMBER_BIGREAL_NUMBER_H

#include<bits/stdc++.h>
using namespace std;
class BigReal_Number{
private:
    bool isValidReal (string realNumber); // True if correct real
    string Integer;
    string Decimal;
    // true ='+',false='-'
    bool sign;
public:
    BigReal_Number();
    BigReal_Number(string s);
    BigReal_Number(double number);


};
#endif //BIGREAL_NUMBER_BIGREAL_NUMBER_H
