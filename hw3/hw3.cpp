/*
 * TITLE: OOP HW3
 * PURPOSE:Define a class for rational numbers 
 * AUTHOR:CHENG-AN FU 
 * ID NUMBER:B023040018
 * DATE:2015/11/14
 * VERSION:2.1
 * LANGUAGE:C++
 */
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>
using namespace std;
class rational{
  public:
    rational(int _num,int _den);//constructor
    rational(int wholenumber);
    rational();
    void gcd();//normalization
    int get_numerator();
    int get_denominator();
    friend istream& operator >>(istream& input,rational& ra);//operator overload
    friend ostream& operator <<(ostream& output,rational& ra);
    friend rational operator -(rational& ra1);
    friend rational operator +(rational& ra1,rational& ra2);
    friend rational operator -(rational& ra1,rational& ra2);
    friend rational operator *(rational& ra1,rational& ra2);
    friend rational operator /(rational& ra1,rational& ra2);
    friend bool operator ==(rational& ra1,rational& ra2);
    friend bool operator <(rational& ra1,rational& ra2);
    friend bool operator <=(rational& ra1,rational& ra2);
    friend bool operator >(rational& ra1,rational& ra2);
    friend bool operator >=(rational& ra1,rational& ra2);
    friend void Test(rational& ra1,rational& ra2);
  private:
    int numerator,denominator;
};
bool re_input = false;//if it have to reinput or not.
void gcd(int &num1,int &num2);
rational::rational(int _num,int _den)//constructor
{
  numerator = _num;
  denominator = _den;
}
rational::rational(int wholenumber)//constructor
{
  numerator = wholenumber;
  denominator = 1;
}
rational::rational()//constructor
{
  numerator = 0;
  denominator = 1;
}
int rational::get_numerator()
{
  return numerator;
}
int rational::get_denominator()
{
  return denominator;
}
void rational::gcd()//normalization
{
  int a = denominator,b = numerator,r;
  if(denominator == 0)
  {
    denominator = 0;
    numerator = 0;
  }
  else//use Euclid algorithm to fraction
 {
   if(b<0)
     b *= -1;
   if(a<0)
     a *= -1;
   while(b>0)
   {
     r = a%b;
     a = b;
     b = r;
   }
   numerator /= a;
   denominator /= a;
   if((numerator<0&&denominator<0)||(numerator>0&&denominator<0))//
   {
      numerator *= -1;
      denominator *= -1;
    }
  }
}
rational operator -(rational& ra1)//make the number to inverse
{
  int temp;
  ra1.gcd();
  temp = ra1.numerator * -1;
  return rational(temp,ra1.denominator);
}
rational operator +(rational& ra1,rational& ra2)//ra1+ra2
{
  if(ra1.denominator == 0 || ra2.denominator == 0)//if denominator is 0
    return rational(0,0);//output 0/0
  else
  {
    int result_nu,result_de;
    result_de = ra1.denominator * ra2.denominator;
    result_nu = ra1.numerator * ra2.denominator + ra2.numerator * ra1.denominator;
    gcd(result_nu,result_de);
    return rational(result_nu,result_de);
  }
}
rational operator -(rational& ra1,rational& ra2)
{
  if(ra1.denominator == 0 || ra2.denominator == 0)
    return rational(0,0);
  else
  {
    int result_nu,result_de;
    result_de = ra1.denominator * ra2.denominator;
    result_nu = ra1.numerator * ra2.denominator - ra2.numerator * ra1.denominator;
    gcd(result_nu,result_de);
    return rational(result_nu,result_de);
  }
}
rational operator *(rational& ra1,rational& ra2)
{
  if(ra1.denominator == 0|| ra2.denominator == 0)
    return rational(0,0);
  else
  {
    int result_nu,result_de;
    result_nu = ra1.numerator * ra2.numerator;
    result_de = ra1.denominator * ra2.denominator;
    gcd(result_nu,result_de);
    if(result_de == 0)
      return rational(0,0);
    else
      return rational(result_nu,result_de);
  }
}
rational operator /(rational& ra1,rational& ra2)
{
  if(ra1.denominator == 0|| ra2.denominator == 0)
    return rational(0,0);
  else
  {
    int result_nu,result_de;
    result_nu = ra1.numerator * ra2.denominator;
    result_de = ra1.denominator * ra2.numerator;
    gcd(result_nu,result_de);
    if(result_de == 0)
      return rational(0,0);
    else
      return rational(result_nu,result_de);
  }
}
bool operator ==(rational& ra1,rational& ra2)
{
  if((ra1.numerator*ra2.denominator) == (ra1.denominator*ra2.numerator))
    return true;
  else 
    return false;
}
bool operator <(rational& ra1,rational& ra2)
{
  if((ra1.numerator*ra2.denominator) < (ra1.denominator*ra2.numerator))
    return true;
  else 
    return false;
}
bool operator <=(rational& ra1,rational& ra2)
{
  if((ra1.numerator*ra2.denominator) <= (ra1.denominator*ra2.numerator))
    return true;
  else 
    return false;
}
bool operator >(rational& ra1,rational& ra2)
{
  if((ra1.numerator*ra2.denominator) > (ra1.denominator*ra2.numerator))
    return true;
  else 
    return false;
}
bool operator >=(rational& ra1,rational& ra2)
{
  if((ra1.numerator*ra2.denominator) >= (ra1.denominator*ra2.numerator))
    return true;
  else
    return false;
}
istream& operator >>(istream& input,rational& ra)
{
  char line;
  string s;
  int temp = 0;
  input >> s;//input to s
  int _size = (int)s.size();
  istringstream is(s);//string to stream and to is
  for(int i=0;i<_size;i++)
  {
    if(s[0] == '/')//if first char is '/'  then break
      break;
    if(s[i] == '-')//if first char is '-' then go to next char
      i++;
    if(isdigit(s[i]) == true)//when char is not '/' and it is digit
      continue;
    else if(isdigit(s[i]) == false)
    {
      if(s[i] == '/')//if the char is '/'
      {
        is>>ra.numerator;//number to numerator
        is>>line;// '/' to one char 
        re_input = true;
        temp = i+1;
        break;
      }
      else
        break;
    }
  }
  if(temp == _size)//if the input like 987/  then break
    re_input = false;
  if(re_input == true)
  {
    for(int j=temp;j<_size;j++)
    {
      if(s[j] == '-')//if char is '-' then go to next
        j++;
      if((isdigit(s[j]) == true) && (j == _size-1))
      {
        is>>ra.denominator;//number to denominator
        re_input = true;
        break;
      }
      else if(isdigit(s[j]) == false)//if the char is not digitt 
      {
        re_input = false;
        break;
      }
    }
  }
  return input;
}
ostream& operator <<(ostream& output,rational& ra)
{
  output<<ra.numerator<<"/"<<ra.denominator;
  return output;
}
void gcd(int &num1,int &num2)
{
  int a = num1,b = num2,r;
  if(a<0)
    a *= -1;
  if(b<0)
    b *= -1;
  while(b>0)
  {
    r = a%b;
    a = b;
    b = r;
  }
  num1 /= a;
  num2 /= a;
  if((num1<0&&num2<0)||(num1>0&&num2<0))
  {
    num1 *= -1;
    num2 *= -1;
  }
}
void Test(rational& ra1,rational& ra2)
{
  rational result;
  cout<<"[Test Program]"<<endl;
  cout<<"Rational1 = "<<ra1<<" Rational2 = "<<ra2<<endl;
  ra1.gcd();
  ra2.gcd();
  cout<<"After normalization"<<endl;
  cout<<"Rational1 = "<<ra1<<" Rational2 = "<<ra2<<endl;
  result = ra1 + ra2;
  cout<<"Rational1 + Rational2 = "<<result<<endl;
  result = ra1 - ra2;
  cout<<"Rational1 - Rational2 = "<<result<<endl;
  result = ra1 * ra2;
  cout<<"Rational1 * Rational2 = "<<result<<endl;
  result = ra1 / ra2;
  cout<<"Rational1 / Rational2 = "<<result<<endl;

  if(ra1.denominator == 0 || ra2.denominator == 0)
    cout<<"Can not compare the Rationals"<<endl;
  else
  {
   if(ra1 == ra2)
     cout<<"Rationals are equal"<<endl;
   if(ra1 < ra2)
     cout<<"Rational1 is less than Rational2"<<endl;
   if(ra1 > ra2)
     cout<<"Rational1 is greater than Rational2"<<endl;
   if(ra1 <= ra2)
     cout<<"Rational1 is less than or equal to Rational2"<<endl;
   if(ra1 >= ra2)
     cout<<"Rational1 is greater than or equal to Rational2"<<endl;
  }
}
int main()
{
  rational r0,temp;
  cout<<"R0's numerator:"<<r0.get_numerator()<<" denominator:"<<r0.get_denominator()<<endl;
  cout<<"R0 = "<<r0<<endl;
  rational r1(10);
  cout<<"R1's numerator:"<<r1.get_numerator()<<" denominator:"<<r1.get_denominator()<<endl;
  temp = -r1;
  cout<<"-R1 = "<<temp<<endl; 

  rational r2(4,-6);
  Test(r1,r2);
  rational r3,r4;
  cout<<"Enter the Rational1:";
  cin>>r3;
  while(1)
  {
    if(re_input == true)
      break;
    else
    {
      cout<<"Error (Input format:int/int)"<<endl;
      cout<<"Please enter again:";
      cin>>r3;
    }
  }
  re_input = false;
  cout<<"Enter the Rational2:";
  cin>>r4;
  while(1)
  {
    if(re_input == true)
      break;
    else
    {
      cout<<"Error (Input format:int/int)"<<endl;
      cout<<"Please enter again:";
      cin>>r4;
    }
  }
  Test(r3,r4);
  return 0;
}
