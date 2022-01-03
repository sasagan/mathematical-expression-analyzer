#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>


using namespace std;

int main()
{
    int sizeArrNum = 0;
    int sizeArrToken = 0;
    vector<double> arrNum;
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
            double num = 0;
           // float sum = 0;
            int j = 0;
            int count = 0;
            while (c_f[i] == '0' || c_f[i] == '1' || c_f[i] == '2' || c_f[i] == '3' || c_f[i] == '4' || c_f[i] == '5' || c_f[i] == '6' || c_f[i] == '7' || c_f[i] == '8' || c_f[i] == '9')
            {
                count++;
                i++;
            }
            //i--;
            for (int l = 0; count > l; count--)
            {
                
                num += (double(c_f[i-count]) - double('0')) * pow(10, count-1);
            }
            /*while (c_f[i] == '0' || c_f[i] == '1' || c_f[i] == '2' || c_f[i] == '3' || c_f[i] == '4' || c_f[i] == '5' || c_f[i] == '6' || c_f[i] == '7' || c_f[i] == '8' || c_f[i] == '9')
            {
                num += (float(c_f[i]) - float('0')) / pow(10, j);
                j++;
                i++;
            }*/
            arrNum.push_back(num);
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