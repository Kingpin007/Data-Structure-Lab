#include <iostream>
#include <cstdio>
#include <stack>
#include <cstdlib>
#include <cmath>

using namespace std;
string ITP(string exp);
bool hasHigherPrecedence(char,char);
bool isOpeningParanthesis(char);
bool isOperand(char);
bool isOperator(char);
bool isRightAssociative(char);
int getOperatorWeight(char);
int eval(string);

int main()
{
    cout << "Please Input the infix expression: ";
    string exp;
    getline(cin,exp);
    exp = ITP(exp);
    cout<<"The postfix expression is: "<<exp<<endl;
    int res = eval(exp);
    cout<<"Eval reults in : "<<res<<endl;
    return 0;
}

string ITP(string exp)
{
    stack<char> s;
    string res;
    for(int i=0;i<exp.length();i++)
    {
        if(isOperand(exp[i]))
            res = res + exp[i];
        else if(isOperator(exp[i]))
        {
            while(!s.empty()&&hasHigherPrecedence(s.top(),exp[i])&&!isOpeningParanthesis(s.top()))
            {
                res = res + s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
        else if(exp[i] == '(')
            s.push(exp[i]);
        else if(exp[i] == ')')
        {
            while(!s.empty()&&!isOpeningParanthesis(s.top()))
            {
                res = res + s.top();
                s.pop();
            }
            s.pop();    //pops the last opening paranthesis
        }
    }
    while(!s.empty())
    {
        res = res + s.top();
        s.pop();
    }
    return res;
}

bool isOpeningParanthesis(char x)
{
    if(x=='(')
        return true;
    else
        return false;
}

bool isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='%'||x=='^')
        return true;
    else
        return false;
}

bool isOperand(char x)
{
    if(x >= '0' && x <= '9') return true;
    if(x >= 'a' && x <= 'z') return true;
    if(x >= 'A' && x <= 'Z') return true;
    return false;
}

bool isRightAssociative(char x)
{
    if(x=='^')
        return true;
    else
        return false;
}

int getOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
    {
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        case '^':
            weight = 3;
            break;
    }
    return weight;
}
bool hasHigherPrecedence(char op1, char op2)
{
    int op1Weight = getOperatorWeight(op1);
    int op2Weight = getOperatorWeight(op2);
    if(op1Weight == op2Weight)
    {
        if(isRightAssociative(op1))
            return false;
        else
            return true;
    }
    return op1Weight > op2Weight ? true: false;
}

int eval(string exp)
{
    stack<int> st;
    for(int i=0;i<exp.length();i++)
    {
        if(!isOperator(exp[i]))
            st.push(exp[i]-48);
        else if(isOperator(exp[i]))
        {
            int x = (int)st.top();
            st.pop();
            int y = (int)st.top();
            st.pop();
            switch(exp[i])
            {
            case'+':
                st.push((x+y));
                break;
            case '-':
                st.push((y-x));
                break;
            case '*':
                st.push((x*y));
                break;
            case '/':
                st.push((y/x));
                break;
            case '%':
                st.push((x%y));
                break;
            case '^':
                st.push((int)pow(y,x));
                break;
            }
        }
    }
    return st.top();
}
