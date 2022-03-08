#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class task
{
    public:
        ifstream file1;
        ifstream file2;
        ifstream file3;

        task();
        ~task();
        string sc(string word, vector <int> task);
        string unsc(string word, vector <int> task);
};
task::task() 
{
    file1.open("szyfr1.txt");
    file2.open("szyfr2.txt");
    file3.open("szyfr3.txt");
}

task::~task() 
{
    file1.close();
    file2.close();
    file3.close();
}
string task::unsc(string word, vector <int> task) 
{
    int length = word.length();
    for (int i = length; i >= 0; i--) 
	{
        int bb = word[i];
        word[task[i % task.size()] - 1] = bb;
        word[i] = word[task[i % task.size()] - 1];
    }
    return word;
}
string task::sc(string word, vector <int> task) 
{
    int length = word.length();
    for (int i = 0; i < length ; i++) 
	{
        int bb = word[i];
        word[task[i % task.size()]-1] = bb;
        word[i] = word[task[i % task.size()]-1];
    }
    return word;
}

int main()
{
    task c1;
    cout << "76.1:" << endl;
    vector <string> s1;
    for (int i = 0; i < 6; i++) 
	{
        string pro;
        c1.file1 >> pro;
        s1.push_back(pro);
    }
    vector <int> task1;
    while (!c1.file1.eof()) 
	{
        int pro;
        c1.file1 >> pro;
        task1.push_back(pro);
    }
    for (int i = 0; i < 6; i++) 
	{
        cout << c1.sc(s1[i], task1)<<endl;
    }
    
    string s2;
    vector <int> task2;
    c1.file2 >> s2;
    while (!c1.file2.eof()) 
	{
        int pro;
        c1.file2 >> pro;
        task2.push_back(pro);
    }
    cout << endl << "76.2:" << endl;
    cout << c1.sc(s2, task2) << endl;
    cout << endl << "76.3:" << endl;
    string s3;
    c1.file3 >> s3;
    vector <int> task3;
    task3.push_back(6);
    task3.push_back(2);
    task3.push_back(4);
    task3.push_back(1);
    task3.push_back(5);
    task3.push_back(3);
    cout << c1.unsc(s3, task3);
}

