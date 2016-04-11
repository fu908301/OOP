#include <iostream>
#include <string>
using namespace std;
int main()
{
  string pwd("9453");
  string inputpwd;
  for(int i = 0;i < 3;i++)
  {
    cout<<"Please type the password."<<endl;
    cin>>inputpwd;
    if(inputpwd == pwd)
    {
      cout<<"Welcome the ATM system."<<endl;
      return 1;
    }
    cout<<"Login incorrect."<<endl;
  }
  cout<<"You have typed the password over than three times."<<endl;
  return 0;
}
