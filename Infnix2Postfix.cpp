#include<iostream>
#include<string>
#include<stack>

using namespace std;
bool alphanumeric(char &op)
{
    if (op>='0'&&op<='9') return true;
    else if (op<='z'&&op>='a') return true;
    else if(op<='Z'&&op>='A') return true;
    else return false;

}

bool IsOperator(char &op)
{
    if (op=='+'||op=='-'||op=='*'||op=='/') return true;
    else
        return false;

}
int getoperatorweight(char &op)
{
    int weight=-1;
    if (op=='-'||op=='+')
        weight =1;
    else if (op=='*'||op=='/')
        weight=2;
    return weight;

}

bool HasHigherPrecedence(char &op1,char &op2)
{
    int op1weight=getoperatorweight(op1);
    int op2weight=getoperatorweight(op2);
    return op1weight>op2weight?true:false;

}

string infnixtopostfix(string &exp)
{
    stack <char>s;
    string postfix="";
    for(int i=0; i<exp.size(); i++)
    {
        if (alphanumeric(exp[i]))
        {
            postfix+=exp[i];
        }
        else if (IsOperator(exp[i]))
        {
            if (!s.empty()&&s.top()!='('&&!HasHigherPrecedence(exp[i],s.top()))
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
        else if (exp[i]=='(')
            s.push(exp[i]);
        else if (exp[i]==')')
        {
            while (s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();

        }
    }

    while (!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    return postfix;

}



