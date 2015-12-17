#include <iostream>
#include <cstdlib>
using namespace std;
class my_answer{
  public:
    my_answer();
    void input_time();
    void produce_rand();
    void copy_array();
    void unsort_print();
    void sorted_print();
    void selection_sort();
    void find_min_and_max();
    void print_3M();
  private:
    int A[51],B[51],times,Max,Min,max_mark,min_mark,INTERVAL;
};
my_answer::my_answer()
{
  INTERVAL = 21;
}
void my_answer::input_time()
{
  cout<<"Please input how many elements you want to print in one line"<<endl;
  cin>>times;
}
void my_answer::produce_rand()
{
  srand((unsigned)time(NULL));
  int temp,result;
  for(int i=0;i<=50;i++)
  {
    temp = rand()%2;
    result = rand()%INTERVAL;
    if(temp == 0)
      A[i] = result;
    else if(temp == 1)
    {
      result *= -1;
      A[i] = result;
    }
  }
}
void my_answer::copy_array()
{
  for(int i = 0;i <= 50;i++)
  {
    B[i] = A[i];
  }
}
void my_answer::unsort_print()
{
  int temp = times - 1;
  cout<<"The content in array"<<endl;
  for(int i = 0;i<=50;i++)
  {
    if(i!=0 && i%times == temp)
      cout<<"["<<i<<"]"<<A[i]<<endl;
    else  
      cout<<"["<<i<<"]"<<A[i]<<"   ";
  }
  cout<<endl;
}
void my_answer::sorted_print()
{
  int temp = times - 1;
  cout<<"The previous 26 elements after selection sort"<<endl;
  for(int i = 0;i<=25;i++)
  {
    if(i!=0 && i%times == temp)
      cout<<"["<<i<<"]"<<B[i]<<endl;
    else
      cout<<"["<<i<<"]"<<B[i]<<"   ";
  }
  cout<<endl;
}
void my_answer::selection_sort()
{
  int mi;
  for(int i=0;i<50;i++)
  {
    mi = i;
    for(int j = i+1;j<51;j++)
      if(B[mi]>B[j])
        mi = j;
    swap(B[i],B[mi]);
  }
}
void my_answer::find_min_and_max()
{
  Max = A[0];
  Min = A[1];
  for(int i = 0;i <= 50;i++)
  {
    if(A[i] > Max)
    {
      Max = A[i];
      max_mark = i;
    }
    if(A[i] < Min)
    {
      Min = A[i];
      min_mark = i;
    }
  }
}
void my_answer::print_3M()
{
  cout<<"Max is "<<Max<<" "<<"and its mark is "<<max_mark<<endl;
  cout<<"Min is "<<Min<<" "<<"and its mark is "<<min_mark<<endl;
  cout<<"Medium is "<<B[25]<<endl;
}
int main()
{
  my_answer help;
  help.input_time();
  help.produce_rand();
  help.copy_array();
  help.selection_sort();
  help.unsort_print();
  help.sorted_print();
  help.find_min_and_max();
  help.print_3M();
  return 0;
}
