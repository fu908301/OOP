#include <iostream>
#include <cstdlib>
using namespace std;
void produce_rand(int A[],int INTERVAL);
void copy_array(int A[],int B[]);
void print(int A[],int times);
void print(int A[],int times,char c);
void selection_sort(int A[]);
void find_min_and_max(int A[],int &Max,int &Min,int &max_mark,int &min_mark);
void produce_rand(int A[],int INTERVAL)
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
void copy_array(int A[],int B[])
{
  for(int i = 0;i <= 50;i++)
  {
    B[i] = A[i];
  }
}
void print(int A[],int times)
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
void print(int A[],int times,char c)
{
  int temp = times - 1;
  cout<<"The previous 26 elements after selection sort"<<endl;
  for(int i = 0;i<=25;i++)
  {
    if(i!=0 && i%times == temp)
      cout<<"["<<i<<"]"<<A[i]<<endl;
    else
      cout<<"["<<i<<"]"<<A[i]<<"   ";
  }
  cout<<endl;
}
void selection_sort(int A[])
{
  int mi;
  for(int i=0;i<50;i++)
  {
    mi = i;
    for(int j = i+1;j<51;j++)
      if(A[mi]>A[j])
        mi = j;
    swap(A[i],A[mi]);
  }
}
void find_min_and_max(int A[],int &Max,int &Min,int &max_mark,int &min_mark)
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

int main()
{
  int A[51] ,B[51],times,Max,Min,max_mark,min_mark;
  int INTERVAL=21;
  char c ='a';
  cout<<"Please input how many elements you want to print in one line"<<endl;
  cin>>times;
  produce_rand(A,INTERVAL);
  copy_array(A,B);
  selection_sort(B);
  print(A,times);
  print(B,times,c);
  find_min_and_max(A,Max,Min,max_mark,min_mark);
  cout<<"Max is "<<Max<<" "<<"and its mark is "<<max_mark<<endl;
  cout<<"Min is "<<Min<<" "<<"and its mark is "<<min_mark<<endl;
  cout<<"Medium is "<<B[25]<<endl;
  return 0;
}
