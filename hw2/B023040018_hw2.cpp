#include <iostream>
using namespace std;
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
  cout<<coinvalue<<" cents can be given as "<<quarters<<" quarter(s) "<<dimes<<" dime(s) "<<" and "<<cent<<" penny(pennies)"<<endl;
}
int main()
{
  int input;
  cin>>input;
  while(1)
  {
    if(input<100&&input>0)
      break;
    else 
    {
      cout<<"Out of range!Please input again."<<endl;
      cin>>input;
    }
  }
  compute_coin(input);
  return 0;
}
