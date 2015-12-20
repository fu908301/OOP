#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class result{
public:
    result();//Constructor
    void input_file_name();
    void open_file();
    void close_file();
    void save_to_map();
    void map_to_file();
    void print();
private:
    ifstream input;
    ofstream output;
    char file_name[20];
    char input_string[100];
    map<string,int> my_map;
    //map<int,int> test_map;
    int LINE_LENGTH;
    char temp[11];
    map<string,int>::iterator pr;
};
result::result(){
  LINE_LENGTH = 100;
}
void result::input_file_name()
{
    cout<<"Please input the file name you want to change."<<endl;
    cin>>file_name;//input the file name
}
void result::open_file()
{
    input.open(file_name);
    output.open("A.cht");
    if(input.fail())//if open fail,then finish
    {
        cout<<"Input file open fail"<<endl;
        exit(1);
    }
    if(output.fail())
    {
        cout<<"Output file open fail"<<endl;
        exit(1);
    }

    if(!input.fail() && !output.fail())
        cout<<"All file open success"<<endl;
}
void result::close_file()//close file
{
    input.close();
    output.close();
    cout<<"Change success!"<<endl;
}
void result::save_to_map()
{
    cout<<"Changing......"<<endl;
    int length;
    if(file_name[0] == 'f')//like f20140102_020.csv,first item has 5 characters.
        length = 5;
    else if(file_name[0] == 'o')//the first item of o20140102_020.csv has 10 characters.
        length = 10;
    while(input.getline(input_string,LINE_LENGTH))//get one line
    {
        for(int i = 0;i < length;i++)
        {
            temp[i] = input_string[i];//copy the first item to the char array
        }
        temp[length] = '\0';//add finish character to the last.
        //cout<<temp<<endl;
        string st(temp);//change char array to string
        pr = my_map.find(st);//find the item
        if(pr == my_map.end())//if can't find
          my_map.insert ( pair <string , int>  ( st, 1 ) );//then insert a new one to map
        else//if find
          my_map[st]++;//count plus
    }

}
void result::map_to_file()
{
    srand((unsigned)time(NULL));
    char my_color[10];
    char space = 10;
    for ( pr = my_map.begin(); pr != my_map.end(); pr++ )//from the fist of the map to the last of the map
    {
        int color = rand()%10;//use random number to choose color
        switch(color)
        {
            case 0:
                strcpy(my_color,"#99e600");
                break;
            case 1:
                strcpy(my_color,"#99cc00");
                break;
            case 2:
                strcpy(my_color,"#99b300");
                break;
            case 3:
                strcpy(my_color,"#9f991a");
                break;
            case 4:
                strcpy(my_color,"#a48033");
                break;
            case 5:
                strcpy(my_color,"#a9664d");
                break;
            case 6:
                strcpy(my_color,"#ae4d66");
                break;
            case 7:
                strcpy(my_color,"#b33380");
                break;
            case 8:
                strcpy(my_color,"#a64086");
                break;
            case 9:
                strcpy(my_color,"#994d8d");
                break;
    }
        output<<pr->first<<","<<pr->second<<","<<my_color<<space;//print the item and its count to chart file
    }

}
/*void result::print()                 //this is for test
{
    ifstream test;
    test.open("qtdata2.cht");
    char c;
    while(test.get(c))
    {
        printf("%c %d\n",c,c);
    }
    test.close();
}*/
int main()
{
    result change;
    change.input_file_name();
    change.open_file();
    change.save_to_map();
    change.map_to_file();
    change.close_file();
    //change.print();
    return 0;
}
