#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
bool IsDigit(string& c);
void compute_coin(int coinvalue);
void compute_coin(int coinvalue)
{
  int quarters=0,dimes=0,cent=0,pennies=0;
  cent=coinvalue;
  if(cent>=25)
  {
    pennies=cent%25;
    quarters=cent/25;
    cent=pennies;
    if(cent>=10)
    {
      pennies=cent%10;
      dimes=cent/10;
      cent=pennies;
    }
  }
  cout<<coinvalue<<" cents can be given as\n"<<quarters<<" quarter(s) "<<dimes<<"dime(s) "<<" and "<<cent<<" penny(pennies)"<<endl;
}
bool IsDigit(string& c)
{
  bool flag = true;
  for(int i=0;i<c.length();i++)
  {
    if(!isdigit(c[i]))
    {
      flag=false;
      break;
    }
  }
  return flag;
}
int main()
{
  string input;
  int change;
  cout<<"Please enter 1 to 99(cents) or 'q' to quit."<<endl;
  cin>>input;
  while(1)
  {
    if(input[0]=='q'&&input[1]==0)
      break;
    if(IsDigit(input))
    {
      istringstream is(input);
      is>>change;
      if(change<100&&change>0)
      {
        compute_coin(change);
        cin>>input;
      }
      else 
      {
        cout<<"Please enter 1 to 99(cents) or 'q' to quit."<<endl;
        cin>>input;
      }
    }
    else
    {
      cout<<"Please enter 1 to 99(cents) or 'q' to quit."<<endl;
      cin>>input;
    }
  }
  return 0;
}
