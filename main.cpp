#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>


using namespace std;

int pAction(char action)
{
    if (action == '*' || action == '/')
    {
        return 2;
    }
    else if (action == '+' || action == '-')
    {
        return 1;
    }
    else if (action == '(' || action == ')')
    {
        return 0;
    }
}

int main()
{
    vector<double> arrNum;
    vector<char> arrToken;

    string f;
    cin >> f;

    f = f + "+0";

    for (int i = 0; i < f.size(); i++)
    {
        const char* c_f = f.c_str();

        if (c_f[i] == '-' || c_f[i] == '+' || c_f[i] == '/' || c_f[i] == '*' || c_f[i] == '(' || c_f[i] == ')')
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

            //
           
            if (arrToken.size() >= 2)
            {
                while (arrToken.size() != 1 && pAction(arrToken[arrToken.size() - 2]) != 0 && pAction(arrToken[arrToken.size() - 2]) >= pAction(arrToken[arrToken.size() - 1]))
                {
                    switch (arrToken[arrToken.size() - 2])
                    {
                    case '*':
                        arrNum[arrNum.size() - 3] = arrNum[arrNum.size() - 3] * arrNum[arrNum.size() - 2];
                        break;
                    case '/':
                        arrNum[arrNum.size() - 3] = arrNum[arrNum.size() - 3] / arrNum[arrNum.size() - 2];
                        break;
                    case '+':
                        arrNum[arrNum.size() - 3] = arrNum[arrNum.size() - 3] + arrNum[arrNum.size() - 2];
                        break;
                    case '-':
                        arrNum[arrNum.size() - 3] = arrNum[arrNum.size() - 3] - arrNum[arrNum.size() - 2];
                        break;
                    }
                    arrNum[arrNum.size() - 2] = arrNum[arrNum.size() - 1];
                    arrNum.pop_back();
                    arrToken[arrToken.size() - 2] = arrToken[arrToken.size() - 1];
                    arrToken.pop_back();
                }
            }
            else
            {
                continue;
            }
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
