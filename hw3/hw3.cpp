#include <iostream>
using namespace std;
class rational{
  public:
    rational(int _num,int _den);
    rational(int wholenumber);
    rational();
    void gcd();
    friend istream& operator >>(istream& input,rational& ra);
    friend ostream& operator <<(ostream& output,rational& ra);
    friend rational operator +(rational& ra1,rational& ra2);
    friend rational operator -(rational& ra1,rational& ra2);
    friend rational operator *(rational& ra1,rational& ra2);
    friend rational operator /(rational& ra1,rational& ra2);
  private:
    int numerator,denominator;
};
void gcd(int num1,int num2);
rational::rational(int _num,int _den)
{
  numerator = _num;
  denominator = _den;
}
rational::rational(int wholenumber)
{
  numerator = wholenumber;
  denominator = 1;
}
rational::rational()
{
  numerator = 0;
  denominator = 1;
}
void rational::gcd()
{
  int a = denominator,b = numerator,r;
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
  if((numerator<0&&denominator<0)||(numerator>0&&denominator<0))
  {
    numerator *= -1;
    denominator *= -1;
  }
}
rational operator +(rational& ra1,rational& ra2)
{
  int result_nu,result_de;
  result_de = ra1.denominator * ra2.denominator;
  result_nu = ra1.numerator * ra2.denominator + ra2.numerator * ra1.denominator;
  gcd(result_nu,result_de);
  return rational(result_nu,result_de);
}
rational operator -(rational& ra1,rational& ra2)
{
  int result_nu,result_de;
  result_de = ra1.denominator * ra2.denominator;
  result_nu = ra1.numerator * ra2.denominator - ra2.numerator * ra1.denominator;
  gcd(result_nu,result_de);
  return rational(result_nu,result_de);
}
rational operator *(rational& ra1,rational& ra2)
{
  int result_nu,result_de;
  result_nu = ra1.numerator * ra2.numerator;
  result_de = ra1.denominator * ra2.denominator;
  gcd(result_nu,result_de);
  return rational(result_nu,result_de);
}
rational operator /(rational& ra1,rational& ra2)
{
 int result_nu,result_de;
 result_nu = ra1.numerator * ra2.denominator;
 result_de = ra1.denominator * ra2.numerator;
 gcd(result_nu,result_de);
 return rational(result_nu,result_de);
}
istream& operator >>(istream& input,rational& ra)
{
  int topnumber,buttonnumber;
  char line;
  input>>topnumber;
  input>>line;
  if(line == '/')
    input>>buttonnumber;
  else 
    buttonnumber = 1;
  ra.numerator = topnumber;
  ra.denominator = buttonnumber;
  return input;
}
ostream& operator <<(ostream& output,rational& ra)
{
  if(ra.denominator == 0)
    output<<"Undefine\n";
  else
    output<<ra.numerator<<"/"<<ra.denominator<<"\n";
  return output;
}
void gcd(int num1,int num2)
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
int main()
{
  rational a,b,result1,result2,result3,result4;
  cout<<"Please input 2 numbers"<<endl;
  cin>>a;
  cin>>b;
  a.gcd();
  b.gcd();
  cout<<"A="<<a;
  cout<<"B="<<b;
  result1 = a+b;
  result2 = a-b;
  result3 = a*b;
  result4 = a/b;
  cout<<"A+B="<<result1;
  cout<<"A-B="<<result2;
  cout<<"A*B="<<result3;
  cout<<"A/B="<<result4;
  return 0;
}
