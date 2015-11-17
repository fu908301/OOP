#include <iostream>
using namespace std;
class myvector{
  public:
    myvector();
    myvector(int value);
    void  input();
    void output();
    friend myvector operator +(myvector &myv1,myvector &myv2);
  private:
    int *myarray,n;
};
myvector::myvector(){}
myvector::myvector(int value)
{
  n = value;
  myarray = new int[value];
}
void myvector::input()
{
  for(int i=0;i<n;i++)
  {
    cin>>myarray[i];
  }
}
void myvector::output()
{
  for(int i=0;i<n;i++)
  {
    cout<<myarray[i]<<" ";
  }
  cout<<endl;
}
myvector operator +(myvector &myv1,myvector &myv2)
{
  myvector result(myv1.n);
  for(int i=0;i<myv1.n;i++)
  {
    result.myarray[i] = myv1.myarray[i] + myv2.myarray[i];
  }
  return result;
}
int main()
{
  int n;
  cin>>n;
  myvector myvectorA(n),myvectorB(n),myvectorC(n);
  myvectorA.input();
  myvectorA.output();
  myvectorB.input();
  myvectorB.output();
  myvectorC = myvectorA + myvectorB;
  myvectorC.output();
  return 0;

}
