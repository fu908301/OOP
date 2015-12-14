/*
TITLE: OOP HW4
PURPOSE:Write a recursive function that takes as input the number of rows,n,and outputs the total number of pins that would exist in a pyramid with n rows.
AUTHOR:CHENG-AN FU 
ID NUMBER:B023040018
DATE:2015/12/14
VERSION:1.0
LANGUAGE:C++
 */
#include <iostream>
using namespace std;
int pluss(int input);
int pluss(int input)
{
  if(input == 1)//if input is 1 then return 1
    return 1;
  else 
    return pluss(input - 1) + input;//if input = 2,then (pluss(2-1) = 1)+(input=2) = 3
}
int main()
{
  int input,output;
  while(input != 0)
  {
   cin>>input; //input
   output = pluss(input);
   cout<<output<<endl;//output
  }
  return 0;
}
