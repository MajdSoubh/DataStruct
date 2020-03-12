#include<iostream>
#include"Infnix2Postfix.cpp"
#include"BalancedParathence.cpp"
using namespace std;

int PostfixEvaluation(string &exp)
{
    stack<int> s;
    for (int i=0; i<exp.size(); i++)
    {
        if (!IsOperator(exp[i]))
        {
            s.push(exp[i]-'0');
        }
        else if (IsOperator(exp[i]))
        {
            int second=s.top();
            s.pop();
            int first=s.top();
            s.pop();
            switch(exp[i])
            {
            case '+':
            {
                s.push(first+second);
                break;
            }
            case '-':
            {
                s.push(first-second);
                break;
            }
            case '*':
            {
                s.push(first*second);
                break;
            }
            case '/':
            {
                s.push(first/second);
                break;
            }

            }
        }
    }

    return s.top();
}

int main()
{
    string exp;
    cout<<"Enter The Expression :\n";

    cin>>exp;
    if(!isbalanced(exp))
        cout<<"Invaild Expression !\n";
    else
    {
        string postfix=infnixtopostfix(exp);
        cout<<"Postfix :\n"<<postfix<<endl;
        cout<<"Postfix Evaluation :\n"<<PostfixEvaluation(postfix);
    }
}
