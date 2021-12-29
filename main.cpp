#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>


using namespace std;

int main()
{
int sizeArrNum = 0;
    int sizeArrToken = 0;
    vector<float> arrNum;
    vector<char> arrToken;

    string f;
    cin >> f;

    for (int i = 0; i < f.size(); i++)
    {
        const char* c_f = f.c_str();

        if (c_f[i] == '-' || c_f[i] == '+' || c_f[i] == '/' || c_f[i] == '*')
        {
            arrToken.push_back(c_f[i]);
        }
        else
        {
            arrNum.push_back(float(f[i]) - float('0'));
        }
    }

    cout << "numbers:" << endl;
    for (int i = 0; i < arrNum.size(); i++)
    {
        cout << arrNum[i] << endl;
    }
    cout << "tokens:" << endl;
    for (int i = 0; i < arrToken.size(); i++)
    {
        cout << arrToken[i] << endl;
    }

    return 0;
}