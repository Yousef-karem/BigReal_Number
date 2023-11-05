#include "BigReal_Number.h"
BigReal_Number::BigReal_Number()
{
    Integer="0";
    Decimal="";
    sign=true;
}
BigReal_Number BigReal_Number::abs(BigReal_Number tmp) {
    tmp.sign=1;
    return tmp;
}
BigReal_Number::BigReal_Number(string s) {
    if(isValidReal ( s))
    {
        if(find(s.begin(),s.end(),'.')==s.end())
        {
            int start=!isdigit(s[0]);
            Integer=s.substr(start);
            Decimal="";
            sign=(s[0]=='+'|| isdigit(s[0]));
            return;
        }
        if(s[0]=='.')
        {
            Integer="0";
            Decimal=s.substr(1);
            sign=true;
            return;
        }
        else if(!isdigit(s[0])&&s[1]=='.')
        {
            Integer="0";
            Decimal=s.substr(2);
            sign=(s[0]=='+');
            return;
        }
        int dotPos=find(s.begin(),s.end(),'.')-s.begin();
        int start=!isdigit(s[0]);
        Integer= s.substr(start,dotPos);
        reverse(Integer.begin(),Integer.end());
        // delete zeros from the beginning of  integer .
        while(!Integer.size()>1&&Integer.back()=='0')
        {
            Integer.pop_back();
        }
        reverse(Integer.begin(),Integer.end());
        Decimal=s.substr(dotPos+1);
        // delete zeros from the end of the decimal part.
        while(!Decimal.empty()&&Decimal.back()=='0')
        {
           Decimal.pop_back();
        }
        sign=(s[0]=='+'|| isdigit(s[0]));
    }
    else
    {
        cout<<"The Value is not Valid\n";
        throw invalid_argument(("The Value is not Valid\n"));
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

bool BigReal_Number::operator<(BigReal_Number anotherReal) {
     BigReal_Number num;
     num.Integer=Integer;
     num.Decimal=Decimal;
     num.sign=sign;
    return(compare(num,anotherReal)==2);
}

int BigReal_Number::compare(BigReal_Number Real1, BigReal_Number Real2) {
    if(Real1.sign!=Real2.sign)
    {
        return (Real1.sign?1:2);
    }
    int szINT1=Real1.Integer.size(),szINT2=Real2.Integer.size();
    int szDecimal1=Real1.Decimal.size(),szDecimal2=Real2.Decimal.size();
    if (szINT1!=szINT2)
    {
        if(sign)
            return ((szINT1>szINT2) ?1:2);
        else
            return ((szINT1>szINT2) ?2:1);
    }
    for (int i = 0; i < szINT1; ++i)
    {
        if(Real1.Integer[i]!=Real2.Integer[i])
        {
            if(sign)
                return ((Real1.Integer[i]>Real2.Integer[i]) ?1:2);
            else
                return ((Real1.Integer[i]>Real2.Integer[i]) ?2:1);
        }
    }
    for (int i = 0; i < min(szDecimal1,szDecimal2); ++i)
    {
        if(Real1.Decimal[i]!=Real2.Decimal[i])
        {
            if(sign)
                return ((Real1.Decimal[i]>Real2.Decimal[i]) ?1:2);
            else
                return ((Real1.Decimal[i]>Real2.Decimal[i]) ?2:1);
        }
    }
    if (szDecimal1!=szDecimal2)
    {
        if(sign)
            return ((szDecimal1>szDecimal2) ?1:2);
        else
            return ((szDecimal1>szDecimal2) ?2:1);
    }
    return 0;
}

bool BigReal_Number::operator>(BigReal_Number anotherReal) {
    BigReal_Number num;
    num.Integer=Integer;
    num.Decimal=Decimal;
    num.sign=sign;
    return(compare(num,anotherReal)==1);

}

bool BigReal_Number::operator==(BigReal_Number anotherReal) {
    BigReal_Number num;
    num.Integer=Integer;
    num.Decimal=Decimal;
    num.sign=sign;
    return(compare(num,anotherReal)==0);
}
ostream &operator<<(ostream&out,BigReal_Number n){
        // Print the sign.
        if(!n.sign){
            cout<<'-';
        }
        out << n.Integer;
        // if we have a decimal part print the decimal point.
        if (!n.Decimal.empty()) {
            out << ".";
        }
        out<<n.Decimal;
        // Print the Decimal part.
        return out;

}

BigReal_Number BigReal_Number::operator+(BigReal_Number other) {
    BigReal_Number result;
    if (other.sign!=sign)
    {
        BigReal_Number num;
        num.Integer=Integer,num.sign=sign;num.Decimal=Decimal;
        result= abs(num)-abs(other);

        result.sign=!(other.sign)?1:0;
        return result;

    }
    int remaining=0;
    pair<string,int>tmp=add(Decimal,other.Decimal,remaining);
    result.Decimal=tmp.first;
    remaining=tmp.second;
    tmp=add(Integer,other.Integer,remaining);
    result.Integer=tmp.first;
    remaining=tmp.second;
    if(remaining)
    {
        int val=remaining+(result.Integer[0]-'0');
        result.Integer= to_string(val)+result.Integer;
    }
    result.sign=sign;
    return result;
}

pair<string, int> BigReal_Number::add(string num1, string num2, int remaining) {
    string result;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + remaining;
        remaining = sum / 10;
        result += to_string(sum % 10);
        i--,j--;
    }
    reverse(result.begin(), result.end());
    return {result, remaining};
}

pair<string, int> BigReal_Number::subtract(string num1, string num2, int remaining)  {
    std::string result;
    if(num1<num2)
        swap(num1,num2);
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    while (i >= 0 || j >= 0 || remaining > 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int diff = digit1 - digit2 - remaining;
        if (diff < 0) {
            diff += 10;
            remaining = 1;
        } else {
            remaining = 0;
        }
        result += std::to_string(diff);
        i--,j--;
    }
    std::reverse(result.begin(), result.end());
    return std::make_pair(result, remaining);
}

BigReal_Number BigReal_Number::operator-(BigReal_Number other) {
    BigReal_Number result,num;
    num.Integer=Integer,num.sign=sign;num.Decimal=Decimal;
    if(sign!=other.sign)
    {
        result= abs(num)+abs(other);
        result.sign=((abs(num)>abs(other))?!sign:sign);
        return result;
    }
    int remaining=0;
    pair<string,int>tmp=subtract(Decimal,other.Decimal,remaining);
    result.Decimal=tmp.first;
    remaining=tmp.second;
    tmp=subtract(Integer,other.Integer,remaining);
    result.Integer=tmp.first;
    remaining=tmp.second;
    if(remaining)
        result.Integer=to_string(remaining)+result.Integer;
    num.sign=other.sign=1;
    result.sign=((num>other)?sign:!sign);
    return result;
}




