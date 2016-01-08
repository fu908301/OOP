#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;
const int students = 26;
class score{
  public:
    score();
    ~score();
    void produce_score();
    void produce_final_score();
    void print();
  private:
    char name[students],max_mark;
    float usually_test[students],midterm_exam[students],final_exam[students];
    int final_score[students],max_score;
};
score::score()
{
  for(int i = 0;i < students;i++)
    name[i] = i+1;
  max_score = 0;
}
score::~score()
{

}
void score::produce_score()
{
  srand((unsigned)time(NULL));
  for(int i = 0;i < students;i++)
  {
    usually_test[i] = rand() % 1000 / 10.0;
    midterm_exam[i] = rand() % 1000 / 10.0;
    final_exam[i] = rand() % 1000 / 10.0;
  }
}
void score::produce_final_score()
{
  float temp;
  for(int i = 0;i < students;i++)
  {
    temp = 0.2 * usually_test[i] + 0.4 * midterm_exam[i] + 0.4 * final_exam[i];
    final_score[i] = 0.2 * usually_test[i] + 0.4 * midterm_exam[i] + 0.4 * final_exam[i];
    if(temp - final_score[i] >= 0.5)
      final_score[i]++;
    if(final_score[i] > max_score)
    {
      max_score = final_score[i];
      max_mark = i + 1;
    }
  }
}
void score::print()
{
  string space1,space2,space3;
  cout<<"Name     Usually     Midterm     Final exam     Final score"<<endl;
  for(int i = 0;i < students;i++)
  {
    name[i] += 64;
    if(usually_test[i] >= 10)
      space1 = "          ";
    else if (usually_test[i] < 10)
      space1 = "           ";
    if(midterm_exam[i] >= 10)
      space2 = "        ";
    else if(midterm_exam[i] < 10)
      space2 = "         ";
    if(final_exam[i] >= 10)
      space3 = "              ";
    else if(final_exam[i] < 10)
      space3 = "               ";
    cout<<fixed<<setprecision(1)<<"  "<<name[i]<<"      "<<usually_test[i]<<space1<<midterm_exam[i]<<space2<<final_exam[i]<<space3<<final_score[i]<<endl;
  }
  max_mark += 64;
  cout<<"The name of the first place student : "<<max_mark<<endl;
  cout<<"And his/her final score is : "<<max_score<<endl;
}
int main()
{
  score result;
  result.produce_score();
  result.produce_final_score();
  result.print();
  return 0;
}
