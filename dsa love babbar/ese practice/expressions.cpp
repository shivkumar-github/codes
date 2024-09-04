// linear search

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isDigit(char c)
{
        return (c <= '9' && c >= '0');
}

bool isOptr(char ch)
{
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
}

double performOperation(double a, double b, char op)
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
                cout << "Invalid operator!" << endl;
                return -1;
        }
}

int precedence(char op)
{
        // ^, /*+
        if (ch == '^')
                return 3;
        if (ch == '/' || ch == '*')
                return 2;
        if (ch == '+' || ch == '-')
                return 1;
        return 0;
}

// function for postfix evaluation
double postfixEval(string exp)
{
        int len = exp.length();
        if (len == 0 && len == 2)
        {
                cout << "invalid exp" << endl;
                return -1;
        }
        if (len == 1 && isDigit(exp[0]))
        {
                return (exp[0] - '0');
        }
        stack<double> operands;
        for (int i = 0; i < len; i++)
        {
                char curr = exp[i];
                if (isDigit(curr))
                {
                        operands.push(exp[i] - '0');
                }
                else if (isOptr(curr))
                {
                        double operand2 = operands.top();
                        operands.pop();
                        double operand1 = operands.top();
                        operands.pop();
                        operands.push(performOperation(operand1, operand2, exp[i]));
                }
                else
                {
                        cout << "Invalid exp" << endl;
                        return -1;
                }
        }
        return operands.top();
}

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
        for (int i = len - 1; i >= 0; i++)
        {
                char curr = exp[i];
                if (isDigit(curr))
                {
                        operands.push(exp[i] - '0');
                }
                else if (isOptr(curr))
                {
                        double operand1 = operands.top();
                        operands.pop();
                        double operand2 = operands.top();
                        operands.pop();
                        operands.push(performOperation(operand1, operand2, exp[i]));
                }
                else
                {
                        cout << "Invalid exp" << endl;
                        return -1;
                }
        }
        return operands.top();
}

// for infix evaluation
double infixEval(string exp)
{
        stack<double> oprnds;
        stack<double> oprtrs;
        for (int i = 0; i < exp.size(); i++)
        {
                char crch = exp[i];
                if (isDigit(crch))
                {
                        oprnds.push(crch - '0');
                }
                else if (crch == '(')
                {
                        oprtrs.push();
                }
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
                                oprnds.push(performOperation(oprnd1, oprnd2, op));
                        }
                        oprtrs.pop();
                }
                else if (isOptr(crch))
                {
                        while (!oprtrs.empty() && precedence(crch) > precedence(oprtrs.top()))
                        {
                                char op = oprtrs.top();
                                oprtrs.pop();
                                double oprnd2 = oprnds.top();
                                oprnds.pop();
                                double oprnd1 = oprnds.top();
                                oprnds.pop();
                                oprnb
                        oprtrs.push(crch);
                }

                else
                {
                        cout << "invalid" << endl;
                }

        }
        while (oprtrs.empty())
        {
                
        }
        
}

int main()
{

        return 0;
}