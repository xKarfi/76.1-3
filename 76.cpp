#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class code
{
    public:
        ifstream f1;
        ifstream f2;
        ifstream f3;
        ofstream fOut;

        code();
        ~code();
        
        string script(string word, vector <int> code);
        string unscript(string word, vector <int> code);
};

code::code() 
{
    f1.open("szyfr1.txt");
    f2.open("szyfr2.txt");
    f3.open("szyfr3.txt");
    fOut.open("wyniki_szyfru.txt");
}

code::~code() 
{
    f1.close();
    f2.close();
    f3.close();
    fOut.close();
}

string code::unscript(string word, vector <int> code) 
{
    int length = word.length();
    for (int i = length; i >= 0; i--) 
	{
        int buf = word[i];
        
        word[i] = word[code[i % code.size()] - 1];
        word[code[i % code.size()] - 1] = buf;
    }
    return word;
}
string code::script(string word, vector <int> code) 
{
    int length = word.length();
    for (int i = 0; i < length ; i++) 
	{
        int buf = word[i];
        
        word[i] = word[code[i % code.size()]-1];
        word[code[i % code.size()]-1] = buf;
    }
    return word;
}

int main()
{
    code c1;
    cout << "76.1:" << endl;
    vector <string> s1;
    for (int i = 0; i < 6; i++) 
	{
        string prov;
        c1.f1 >> prov;
        s1.push_back(prov);
    }
    vector <int> code1;
    while (!c1.f1.eof()) 
	{
        int prov;
        c1.f1 >> prov;
        code1.push_back(prov);
    }
    for (int i = 0; i < 6; i++) 
	{
        cout << c1.script(s1[i], code1)<<endl;
    }
    

    string s2;
    vector <int> code2;
    c1.f2 >> s2;
    while (!c1.f2.eof()) 
	{
        int prov;
        c1.f2 >> prov;
        code2.push_back(prov);
    }
    cout << endl << "76.2:" << endl;
    cout << c1.script(s2, code2) << endl;
    cout << endl << "76.3:" << endl;
    string s3;
    c1.f3 >> s3;
    vector <int> code3;
    code3.push_back(6);
    code3.push_back(2);
    code3.push_back(4);
    code3.push_back(1);
    code3.push_back(5);
    code3.push_back(3);
    cout << c1.unscript(s3, code3);
}

