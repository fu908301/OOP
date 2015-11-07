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
int main()
{
  rational a;
  cin>>a;
  a.gcd();
  cout<<a;
  return 0;
}
