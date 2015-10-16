/*
 TITLE:OOP Homework 2
 PURPOSE:Write a program that tells what coins to give out for any amount of change from 1 cent to 99 cents.
 AUTHOR:CHENG-AN FU 
 DATE:2015/10/16
 VERSION:1.0
 LANGUAGE:C++
*/
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
bool IsDigit(string& c);//This function is to check if the input string is integer
void compute_coin(int coinvalue);//To compute the purpose 
void compute_coin(int coinvalue)
{
  int quarters=0,dimes=0,cent=0,pennies=0;
  cent=coinvalue;
  if(cent>=10&&cent<25)//If the value is not enough for quarter
  {
    pennies=cent%10;
    dimes=cent/10;
    cent=pennies;
  }
  else if(cent>=25)//If the value is enough for quarter
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
  cout<<coinvalue<<" cents can be given as\n"<<quarters<<" quarter(s) "<<dimes<<" dime(s) "<<"and "<<cent<<" penny(pennies)"<<endl;
}
bool IsDigit(string& c)
{
  bool flag = true;//Declare a bool and initial it as true
  for(int i=0;i<c.length();i++)//Use for loop to check
  {
    if(!isdigit(c[i]))//If one of the char in string is not integer
    {
      flag=false;//Then the bool change to false
      break;
    }
  }
  return flag;
}
int main()
{
  string input;//input 
  int change;//The integer changed after by the input
  cout<<"Please enter 1 to 99(cents) or 'q' to quit."<<endl;
  cin>>input;
  while(1)
  {
    if(input[0]=='q'&&input[1]==0)//If input is only 'q'
      break;//Then finish this program
    if(IsDigit(input))//If the input is integer
    {
      istringstream is(input);//String change to integer
      is>>change;
      if(change<100&&change>0)//If the input is not out of range 
      {
        compute_coin(change);//Then compute the purpose
        cin>>input;
      }
      else //Input out of range
      {
        cout<<"Please enter 1 to 99(cents) or 'q' to quit."<<endl;
        cin>>input;//Input again
      }
    }
    else//If the input string is not integer
    {
      cout<<"Please enter 1 to 99(cents) or 'q' to quit."<<endl;
      cin>>input;
    }//Input again
  }
  return 0;
}
