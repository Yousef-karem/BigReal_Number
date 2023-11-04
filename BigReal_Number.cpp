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
        if(realNumber.empty()){
            return false;
        }
        //if the real number contains invalid sign or characters
        for(int i=0;i<realNumber.size();i++){
            if((!isdigit(realNumber[i])&&realNumber[i]!='+'&&realNumber[i]!='-'&&realNumber[i]!='.')){
                return false;
            }
        }
        //if the real number starts with a '-' or'+' sign followed by non digit 
        if((!isdigit(realNumber[1])&&realNumber[1]!='.')&&(realNumber[0]=='-'||realNumber[0]=='+')) {
            return false;

        }
        //if the real number contains more than decimal point 
        if(realNumber.find('.')!= realNumber.rfind('.')){
            return false;
        }
        return true;
    }
