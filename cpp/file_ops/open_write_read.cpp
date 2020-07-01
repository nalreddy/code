#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    ofstream out;
    ifstream in;

    out.open("test.txt");
    if(!out)
    {
        cout << "failed to open test file for writting " << endl;
        //exit  with errror no
    }
    out << "hello" << endl;
    out.close();

    in.open("test.txt");
    if(!in)
    {
        cout << "failed to open test file for reading " << endl;
        //exit  with errror no
    }
    string line;
    getline(in, line);
    cout << line << endl;

    in.close();
    return 0;
}
