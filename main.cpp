#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <string>


using namespace std;

double simpleAction(char Token, double firNum, double secNum = 0) //firNum receives "arrNum[arrNum.size() - 2]"
{                                                             //secNum receives "arrNum[arrNum.size() - 1]"
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

double Sin(double num)
{
    return sin(3.1415 / 180 * num);
}
double Cos(double num)
{
    return cos(3.1415 / 180 * num);
}
double Ctg(double num)
{
    return 1/tan(3.1415 / 180 * num);
}
double Tg(double num)
{
    return tan(3.1415 / 180 * num);
}
double Ln(double num)
{
    return log(num) / log(2.7183);
}
double Log(double num)
{
    return log(num) / log(10);
}


int priorityAction(char action)
{
    if (action == '^' || action == 's' || action == 'c' || action == 'g' || action == 't' || action == 'n' || action == 'a')
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
    while (true)
    {
        vector<double> arrNum;
        vector<char> arrToken;
        string f;
        cin >> f;

        f = f + "+0";

        for (int i = 0; i < f.size(); i++)
        {
            const char* c_f = f.c_str();

            if (c_f[i] == '-' || c_f[i] == '+' || c_f[i] == '/' || c_f[i] == '*' || c_f[i] == '^' || c_f[i] == '(' || c_f[i] == ')' || (c_f[i] == 's' && c_f[i + 1] == 'i' && c_f[i + 2] == 'n') || (c_f[i] == 'c' && c_f[i + 1] == 'o' && c_f[i + 2] == 's') || (c_f[i] == 'c' && c_f[i + 1] == 't' && c_f[i + 2] == 'g') || (c_f[i] == 't' && c_f[i + 1] == 'g') || (c_f[i] == 'l' && c_f[i + 1] == 'n') || (c_f[i] == 'l' && c_f[i + 1] == 'o' && c_f[i + 2] == 'g'))
            {
                if (c_f[i] == 's' && c_f[i + 1] == 'i' && c_f[i + 2] == 'n')
                {
                    arrToken.push_back('s');
                    i += 2;
                }
                else if (c_f[i] == 'c' && c_f[i + 1] == 'o' && c_f[i + 2] == 's')
                {
                    arrToken.push_back('c');
                    i += 2;
                }
                else if (c_f[i] == 'c' && c_f[i + 1] == 't' && c_f[i + 2] == 'g')
                {
                    arrToken.push_back('g');
                    i += 2;
                }
                else if (c_f[i] == 't' && c_f[i + 1] == 'g')
                {
                    arrToken.push_back('t');
                    i += 1;
                }
                else if (c_f[i] == 'l' && c_f[i + 1] == 'n')
                {
                    arrToken.push_back('n');
                    i += 1;
                }
                else if (c_f[i] == 'l' && c_f[i + 1] == 'o' && c_f[i + 2] == 'g')
                {
                    arrToken.push_back('l');
                    i += 2;
                }
                else if (arrNum.size() < 2)
                {
                    if (c_f[i] == ')')
                    {

                        while (arrToken[arrToken.size() - 1] != '(')
                        {
                            arrNum[arrNum.size() - 2] = simpleAction(arrToken[arrToken.size() - 1], arrNum[arrNum.size() - 2], arrNum[arrNum.size() - 1]);
                            arrToken.pop_back();
                            arrNum.pop_back();

                        }
                        if (arrToken.size() >= 2)
                        {
                            switch (arrToken[arrToken.size() - 2])
                            {
                            case 's':
                                arrNum[arrNum.size() - 1] = Sin(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'c':
                                arrNum[arrNum.size() - 1] = Cos(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'g':
                                arrNum[arrNum.size() - 1] = Ctg(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 't':
                                arrNum[arrNum.size() - 1] = Tg(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'n':
                                arrNum[arrNum.size() - 1] = Ln(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'l':
                                arrNum[arrNum.size() - 1] = Log(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            }
                        arrToken.pop_back();
                        //i++;
                        }
                        
                    }
                    else 
                    {
                        arrToken.push_back(c_f[i]);
                    }
                    if (c_f[i] == '(' && c_f[i + 1] == '-')
                    {
                        arrNum.push_back(0);

                    }
                    
                    
                    
                    //;

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

                            arrNum[arrNum.size() - 2] = simpleAction(arrToken[arrToken.size() - 1], arrNum[arrNum.size() - 2], arrNum[arrNum.size() - 1]);

                            arrNum.pop_back();
                            arrToken.pop_back();
                        }
                        arrToken.push_back(c_f[i]);
                    }
                    else if (c_f[i] == ')')
                    {

                        while (arrToken[arrToken.size() - 1] != '(')
                        {
                            arrNum[arrNum.size() - 2] = simpleAction(arrToken[arrToken.size() - 1], arrNum[arrNum.size() - 2], arrNum[arrNum.size() - 1]);
                            arrToken.pop_back();
                            arrNum.pop_back();

                        }
                        if (arrToken.size() >= 2)
                        {
                            switch (arrToken[arrToken.size() - 2])//на этом моменте программа крашиться из-за arrToken.size() = 0
                            {
                            case 's':
                                arrNum[arrNum.size() - 1] = Sin(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'c':
                                arrNum[arrNum.size() - 1] = Cos(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'g':
                                arrNum[arrNum.size() - 1] = Ctg(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 't':
                                arrNum[arrNum.size() - 1] = Tg(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'n':
                                arrNum[arrNum.size() - 1] = Ln(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            case 'l':
                                arrNum[arrNum.size() - 1] = Log(arrNum[arrNum.size() - 1]);
                                arrToken.pop_back();
                                break;
                            }
                            arrToken.pop_back();
                            //i++;
                        }
                    }
                    else
                    {

                        arrToken.push_back(c_f[i]);
                    }
                }

            }
            else
            {
                float num = 0;
                string snum;
                int j = i;
                int count = 0;
                while (c_f[j] == '0' || c_f[j] == '1' || c_f[j] == '2' || c_f[j] == '3' || c_f[j] == '4' || c_f[j] == '5' || c_f[j] == '6' || c_f[j] == '7' || c_f[j] == '8' || c_f[j] == '9')
                {
                    snum += c_f[j];
                    j++;
                }
                num += stoi(snum);
                snum.erase();
                if (c_f[j] == '.')
                {
                    j++;
                    while (c_f[j] == '0' || c_f[j] == '1' || c_f[j] == '2' || c_f[j] == '3' || c_f[j] == '4' || c_f[j] == '5' || c_f[j] == '6' || c_f[j] == '7' || c_f[j] == '8' || c_f[j] == '9')
                    {
                        snum += c_f[j];
                        count++;
                        j++;
                    }
                    num += pow(10, -count) * stoi(snum);
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
    }
    return 0;
}