#include <iostream>
#include <cctype>

using namespace std;

int main(){
     //判断字符
     char c;
     cin>>c;
     if(isalpha(c)){
        if(islower(c)){
            cout<<c<<" is lower"<<endl;
        }
        if(isupper(c)){
            cout<<c<<" is upper"<<endl;
        }
     }
     

     char a ='A';
     char t=tolower(a);
     cout<<t<<endl;
     return 0;
}