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
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
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
  int temp,output,_size;
  char input[50];
  bool _isdigit = true;
  while(1)
  {
    cout<<"Please enter numbers of bowling pins' rows from 1 to 5000 or 'q' to quit."<<endl;
    cin.getline(input,50);//input as string 
    _size = strlen(input);
    if(_size == 1 && input[0] == 'q')//if input is 'q'
      break;//then finish
    for(int i = 0;i < _size;i++)
    {
      if(!isdigit(input[i]))//To sure if all elements are digit
      {
        _isdigit = false;
        break;
      }
    }
    if(_isdigit == false)//If not all elements are digit,then reinput
      continue;
    else if(_isdigit == true)//If all elements are digit
    {
      temp = atoi(input);//Change to integer
      if(temp < 1||temp > 5000)//If out of range
        continue;//Reinput
      else 
      {
        output = pluss(temp);//Do resursive
        cout<<"There are totally "<<output<<" bowling pins."<<endl;//Output the answer
      }
    }
  }
  return 0;
}
