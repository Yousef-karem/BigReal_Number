#include "BigReal_Number.h"
BigReal_Number::BigReal_Number()
{
    Integer="0";
    Decimal="0";
    sign=true;
}
BigReal_Number::BigReal_Number(string s) {
    if(isValidReal ( s))
    {
        int sz=s.size();
        auto dotPos=find(s.begin(),s.end(),'.')-s.begin();
        Integer= s.substr(0,dotPos);
        Decimal=s.substr(s.find('.')+1);
        sign=(s[0]=='+'|| isdigit(s[0]));
    }
    else
    {
        (cout<<"The Value is not Valid");
        return;
    }

}

BigReal_Number::BigReal_Number(double number)
{
    int tmp=int(number);
    Integer= to_string(tmp);
    Decimal=number-tmp;
    sign=(number>=0);
}

bool BigReal_Number::isValidReal(string realNumber) {
    return true;
}