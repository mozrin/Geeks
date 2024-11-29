#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    ofstream MyFileWrite ("filename.txt");

    MyFileWrite << "Hello File!";

    MyFileWrite.close ();

    string RandomText;

    ifstream MyFileRead ("filename.txt");

    while (getline (MyFileRead, RandomText))
    {
      cout << RandomText;
    }

    MyFileRead.close ();

    return 0;
}