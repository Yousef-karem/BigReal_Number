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

bool BigReal_Number::operator<(BigReal_Number anotherReal) {
     BigReal_Number num;
     num.Integer=Integer;
     num.Decimal=Decimal;
     num.sign=sign;
    return(compare(num,anotherReal)==2);
}

int BigReal_Number::compare(BigReal_Number Real1, BigReal_Number Real2) {
    BigReal_Number num;
    int size1,size2,size11,size22;
    size1=(Real1.Integer).size();//size of integer part of 1st
    size2=(Real2.Integer).size();//size of integer part of 2st
    size11=(Real1.Decimal).size();//size of decimal part of 1st
    size22=(Real2.Decimal).size();//size of decimal part of 2st
    bool done =1;
    if(Real1.sign&&!Real2.sign){
        //1st is +ve & 2nd is -ve
        num=1;
        done= 0 ;
    }else if(!Real1.sign&&Real2.sign){
       // 1st is -ve & 2nd is +ve
        num=2;
        done=0 ;
    }else if(Real1.sign&&(size1!=size2)){
        //both are +ve
        if(size1>size2){
            //integer part of 1st is graeter
            num =1;
            done=0;
        }else if(size2>size1){
            //integer part of 2st is graeter
            num =2;
            done=0;
        }
    }else if(!Real1.sign&&size1!=size2){
        //both are -ve
        if(size1>size2){
            //integer part of 1st is graeter
            num =2;
            done=0;
        }else if(size2>size1){
            //integer part of 2st is graeter
            num =1;
            done= 0;
        }
    }else {
        //integer part of both are equal in length
        if(size11>size22){
            int dif=size11-size22;
            for(int i=0;i<dif;i++){
                Real2.Decimal+='0';
            }
        }else if(size22>size11){
            int dif =size22-size11;
            for (int i = 0; i < dif; ++i) {
                Real1.Decimal+='0';
            }
        }
    }
    if( done){
        for (int i = 0; i < size1; ++i) {
            if((Real1.Integer[i]-'0')!=(Real2.Integer[i]-'0')){
                if((Real1.Integer[i]-'0')>(Real2.Integer[i]-'0')){
                    if(Real1.sign){
                    num=1;}
                    else {
                        num=2;
                    }
                    done=0;
                    break;
                }else {
                    if(Real2.sign){
                    num=2;}
                    else {
                        num=1;
                    }
                    done=0;
                    break;
                }
            }
        }
   for (int i = 0; i < size11; ++i) {
            if((Real1.Decimal[i]-'0')!=(Real2.Decimal[i]-'0')){
                if((Real1.Decimal[i]-'0')>(Real2.Decimal[i]-'0')){
                    if(Real1.sign){
                    num=1;}
                    else {
                        num=2;
                    }
                    done=0;
                    break;
                }else {
                    if(Real2.sign){
                    num=2;}
                    else {
                        num=1;
                    }
                    done=0;
                    break;
                }
            }
        }
    }
    if( done){
        num=0;
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
        if(n.sign){
            cout<<'+';
        } else{
            cout<<'-';
        }
        // delete zeros from the beginning of  integer .
        int i = 1;
        while (i < n.Integer.size() && n.Integer[i] == '0') {
            i++;
        }
        out << n.Integer.substr(i);

        // if we have a decimal part print the decimal point.
        if (!n.Decimal.empty()) {
            out << ".";
        }

        // delete zeros from the end of the decimal part.
        int k = n.Decimal.length() - 1;
        while (k>= 0 && n.Decimal[k] == '0') {
            k--;
        }

        // Print the Decimal part.
        out << n.Decimal.substr(0, k + 1);
        out<<'\n';

        return out;

}
