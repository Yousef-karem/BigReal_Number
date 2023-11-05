#include "BigReal_Number.h"
int main()
{
    //Check the Validate of the algorithms
    cout<<"Num1:";
    string num1;cin>>num1;
    cout<<"Num2:";
    string num2;cin>>num2;
    BigReal_Number A(num1),B(num2);
    cout<<"Num1 + Num2 = "<<A+B<<endl;
    cout<<"Num1 - Num2 = "<<A-B<<endl;
    if(A>B)
        cout<<A<<" > "<<B<<endl;
    else if(B>A)
        cout<<A<<" < "<<B<<endl;
    else cout<<A<<" == "<<B<<endl;
}

