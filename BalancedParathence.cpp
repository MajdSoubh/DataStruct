#include<iostream>
#include<stack>
using namespace std;

stack<char>s;
bool arepaired(char &first,char &second)
{
    if (first=='['&&second==']')
        return true;
    else if(first=='{'&&second=='}')
        return true;
    else if(first=='('&&second==')')
        return true;

    else
        return false;

}

bool isbalanced(string &exp)
{
    for(int i=0; i<exp.size(); i++)
    {
        if (exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            s.push(exp[i]);
        }
        else if (exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if (s.empty()||!arepaired(s.top(),exp[i]))
                return 0;
            else

                s.pop();


        }

    }


if (s.empty())
    return true;
else
    return false;

}




