/*
Write a code to evaluate infix posfix and prefix expressions
*/

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

bool isDigit(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    return false;
}

bool isOptr(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

double performOpr(double a, double b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;

    else if (op == '*')
        return a * b;

    else if (op == '/')
    {
        if (b == 0)
            cout << "Can not devide by 0!" << endl;

        else
            return a / b;
    }
    else if (op == '^')
        return pow(a, b);

    else
    {
        cout << "invalid operator!" << endl;
        return 0;
    }
}

// fucntion which evaluates postfix expression
double postfixEvaluation(string exp)
{
    int len = exp.length();
    if (len == 0 || len == 2)
    {
        cout << "Enter a valid postfix expression." << endl;
        return -1;
    }

    if (len == 1 && isDigit(exp[0]))
        return (exp[0] - '0');

    stack<double> operands;

    for (int i = 0; i < len; i++)
    {
        if (isDigit(exp[i]))
            operands.push(exp[i] - '0');

        else if (isOptr(exp[i]))
        {
            double oprnd2 = operands.top();
            operands.pop();
            double oprnd1 = operands.top();
            operands.pop();
            operands.push(performOpr(oprnd1, oprnd2, exp[i]));
        }
        else
        {
            cout << "Invalid input!" << endl;
            return -1;
        }
    }
    return operands.top();
} /* ->> space complexity - O(n)
     ->> time complexity - O(n)
 */

double prefixEvaluation(string exp)
{
    int len = exp.length();
    if (len == 0 || len == 2)
    {
        cout << "Enter a valid postfix expression." << endl;
        return -1;
    }

    if (len == 1 && isDigit(exp[0]))
        return (exp[0] - '0');

    stack<double> operands;

    for (int i = len - 1; i >= 0; i--)
    {
        if (isDigit(exp[i]))
            operands.push(exp[i] - '0');

        else if (isOptr(exp[i]))
        {
            double oprnd1 = operands.top();
            operands.pop();
            double oprnd2 = operands.top();
            operands.pop();
            double ans = performOpr(oprnd1, oprnd2, exp[i]);
            operands.push(ans);
        }
        else
        {
            cout << "Invalid input!" << endl;
            return -1;
        }
    }
    return operands.top();
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '/' || ch == '*')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

double infixEvaluation(string exp)
{
    stack<double> oprnds;
    stack<char> oprtrs;

    for (int i = 0; i < exp.size(); i++)
    {
        char crch = exp[i];
        if (isDigit(crch))
            oprnds.push(crch - '0');
        else if (crch == '(')
            oprtrs.push(crch);
        else if (crch == ')')
        {
            while (!oprtrs.empty() && oprtrs.top() != '(')
            {
                char op = oprtrs.top();
                oprtrs.pop();
                double oprnd2 = oprnds.top();
                oprnds.pop();
                double oprnd1 = oprnds.top();
                oprnds.pop();
                oprnds.push(performOpr(oprnd1, oprnd2, op));
            }
            oprtrs.pop(); // to pop out '('
        }
        else if (isOptr(crch))
        {
            while (!oprtrs.empty()) && (precedence(crch) < precedence(oprtrs.top()))
            {
                char op = oprtrs.top();
                oprtrs.pop();
                double oprnd2 = oprnds.top();
                oprnds.pop();
                double oprnd1 = oprnds.top();
                oprnds.pop();
                oprnds.push(performOpr(oprnd1, oprnd2, op));
            }
            oprtrs.push(crch);
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }
    }

    while (!oprtrs.empty())
    {
        char op = oprtrs.top();
        oprtrs.pop();
        double oprnd2 = oprnds.top();
        oprnds.pop();
        double oprnd1 = oprnds.top();
        oprnds.pop();
        oprnds.push(performOpr(oprnd1, oprnd2, op));
    }
    return oprnds.top();
}

int main()
{
    string prefix = "*+23-74";
    string postfix = "23+74-*";
    string infix = "(2+3)*(7-4)";

    cout << "In prefix " << prefix << ": " << prefixEvaluation(prefix) << endl;
    cout << "In postfix " << postfix << ": " << postfixEvaluation(postfix) << endl;
    cout << "In infix " << infix << ": " << infixEvaluation(infix) << endl;

    return 0;
}