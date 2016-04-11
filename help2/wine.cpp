#include <iostream>
using namespace std;
int main()
{
  int money,wine,bottle,circle,left_money,wine_count;
  cout<<"Type how much I have."<<endl;
  cin>>money;
  wine = money / 50;
  left_money = money % 50;
  wine_count = 0;
  bottle = 0;
  circle = 0;
  while(wine != 0)
  {
    wine--;
    bottle++;
    circle++;
    if(bottle == 2)
    {
      wine++;
      bottle = 0;
    }
    if(circle == 4)
    {
      wine++;
      circle = 0;
    }
    wine_count++;
  }
  cout<<"I drink "<<wine_count<<" bottles of wine and left "<<bottle<<" bottles and "<<circle<<" circles and "<<left_money<<" dollars."<<endl;
  return 0;
}
