#include <iostream>
using namespace std;
int main()
{
  int T=0,O=0,G=0,D=0,times=0;
  for(T=0;T<10;T++)
    for(O=0;O<10;O++)
      for(G=0;G<10;G++)
        for(D=0;D<10;D++)
        {
          if(T==O||T==G||T==D||O==G||O==D||G==D)
           continue ;
          else if(T*400+O*40+O*4==G*1000+O*100+O*10+D)
          {
           times++;
           cout<<"Answer "<<times<<endl;
           cout<<"T="<<T<<endl;
           cout<<"O="<<O<<endl;
           cout<<"G="<<G<<endl;
           cout<<"D="<<D<<endl; 
          }
        }
  return 0;
}