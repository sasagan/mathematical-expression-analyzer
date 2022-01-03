﻿#include <iostream>
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
            int j = i;
            int count = 0;
            while (c_f[j] == '0' || c_f[j] == '1' || c_f[j] == '2' || c_f[j] == '3' || c_f[j] == '4' || c_f[j] == '5' || c_f[j] == '6' || c_f[j] == '7' || c_f[j] == '8' || c_f[j] == '9')
            {
                count++;
                j++;
            }
            for (int l = 0; count > l; count--)
            {
                
                num += (double(c_f[j-count]) - double('0')) * pow(10, count-1);
            }
            i = j - 1;
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