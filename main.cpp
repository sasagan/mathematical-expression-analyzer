#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>


using namespace std;

double action(char Token, double firNum, double secNum) //firNum receives "arrNum[arrNum.size() - 2]"
{                                                       //secNum receives "arrNum[arrNum.size() - 1]"
    switch (Token)
    {
    case '+':
        return firNum + secNum;
        break;
    case '-':
        return firNum - secNum;
        break;
    case '*':
        return firNum * secNum;
        break;
    case '/':
        return firNum / secNum;
        break;
    case '^':
        return pow(firNum, secNum);
        break;
    }
}

int priorityAction(char action)
{
    if (action == '^')
    {
        return 3;
    }
    else if (action == '*' || action == '/')
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

        if (c_f[i] == '-' || c_f[i] == '+' || c_f[i] == '/' || c_f[i] == '*' || c_f[i] == '^' || c_f[i] == '(' || c_f[i] == ')')
        {
            if (arrNum.size() < 2)
            {
                if (c_f[i] == '(' && c_f[i + 1] == '-')
                {
                    arrNum.push_back(0);
                }
                arrToken.push_back(c_f[i]);
            }
            else if (arrNum.size() >= 2)
            {
                if (c_f[i] == '(' && c_f[i + 1] == '-')
                {
                    arrNum.push_back(0);
                    arrToken.push_back(c_f[i]);
                }
                else if (c_f[i] != ')' && priorityAction(c_f[i]) != 0 && priorityAction(arrToken[arrToken.size() - 1]) >= priorityAction(c_f[i]))
                {

                    while (arrNum.size() >= 2 && priorityAction(arrToken[arrToken.size() - 1]) >= priorityAction(c_f[i]) && priorityAction(arrToken[arrToken.size() - 1]) != 0)
                    {
                        arrNum[arrNum.size() - 2] = action(arrToken[arrToken.size() - 1], arrNum[arrNum.size() - 2], arrNum[arrNum.size() - 1]);
                        arrNum.pop_back();
                        arrToken.pop_back();
                    }
                    arrToken.push_back(c_f[i]);
                }
                else if (c_f[i] == ')')
                {

                    while (arrToken[arrToken.size() - 1] != '(')
                    {
                        arrNum[arrNum.size() - 2] = action(arrToken[arrToken.size() - 1], arrNum[arrNum.size() - 2], arrNum[arrNum.size() - 1]);
                        arrToken.pop_back();
                        arrNum.pop_back();
                    }

                    arrToken.pop_back();
                }
                else
                {

                    arrToken.push_back(c_f[i]);
                }
            }

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

                num += (double(c_f[j - count]) - double('0')) * pow(10, count - 1);
            }
            i = j - 1;
            arrNum.push_back(num);
        }
    }

    /*cout << "numbers:" << endl;
    for (int i = 0; i < arrNum.size(); i++)
    {
        cout << arrNum[i] << endl;
    }
    cout << "tokens:" << endl;
    for (int i = 0; i < arrToken.size(); i++)
    {
        cout << arrToken[i] << endl;
    }*/

    cout << arrNum[0] << endl;

    return 0;
}