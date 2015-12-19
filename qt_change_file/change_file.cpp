#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
class result{
public:
    result();
    void open_file();
    void close_file();
    void save_to_map();
    void map_to_file();
    void print();
private:
    ifstream input;
    ofstream output;
    char input_string[100];
    map<string,int> my_map;
    map<int,int> test_map;
    int LINE_LENGTH;
    char temp[11];
    map<string,int>::iterator pr;
};
result::result(){
  LINE_LENGTH = 100;
}
void result::open_file()
{
    input.open("o20140102_020.csv");
    output.open("A.cht");
    if(input.fail())
        cout<<"Input file open fail"<<endl;
    if(output.fail())
        cout<<"Output file open fail"<<endl;
    if(!input.fail() && !output.fail())
        cout<<"All file open success"<<endl;
}
void result::close_file()
{
    input.close();
    output.close();
    cout<<"Change success!"<<endl;
}
void result::save_to_map()
{
    cout<<"Changing......"<<endl;
    while(input.getline(input_string,LINE_LENGTH))
    {
        for(int i = 0;i < 10;i++)
        {
            temp[i] = input_string[i];
        }
        temp[10] = '\0';
        string st(temp);
        pr = my_map.find(st);
        if(pr == my_map.end())
          my_map.insert ( pair <string , int>  ( st, 1 ) );
        else 
          my_map[st]++;
    }
    
}
void result::map_to_file()
{
    for ( pr = my_map.begin(); pr != my_map.end(); pr++ )
        output<<pr->first<<","<<pr->second<<","<<"#99e600"<<" ";
}
/*void result::print()
{
    while(input.getline(input_string,LINE_LENGTH))
    {
        for(int i = 0;i < 10;i++)
        {
            temp[i] = input_string[i];
        }
        temp[10] = '\0';
        cout<<temp<<endl;
    }

}*/
int main()
{
    result change;
    change.open_file();
    //change.print();
    change.save_to_map();
    change.map_to_file();
    change.close_file();
    return 0;
}
