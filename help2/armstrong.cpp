#include <iostream>
using namespace std;
int main()
{
  int first_num,sec_num,thd_num,armstorng;
  for(int i = 100;i <= 999;i++)
  {
    thd_num = i % 10;
    sec_num = i / 10 % 10;
    first_num = i / 100;
    armstorng = first_num * first_num * first_num + sec_num * sec_num * sec_num + thd_num * thd_num * thd_num;
    if(armstorng == i)
      cout<<i<<" is armstorng."<<endl;
  }
  return 0;
}
