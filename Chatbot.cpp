#include<iostream>
#include<string>
using namespace std;
string toLower(string str){
    for(int i=0;i<str.length();i++)
        str[i]=tolower(str[i]);
    return str;
}    
 int main(){
     while(true){
     string userinput;
     cout<<"Hello User!! I am your chat bot"<<endl;
     getline(cin,userinput);
     string main=toLower(userinput);
     if(main=="hii"||main=="hello"||main=="hey"||main=="hiiii")
        cout<<"Hello How Can I help You?";
    else if(main=="bye"||main=="goodbye"){
        cout<<"GoodBye, Have A NICE Day!!!"<<endl;
        return 0;
    }
    else
        cout<<"sorry I cant get it...."<<endl;
     }
     return 0;
 }
