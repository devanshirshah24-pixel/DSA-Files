#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

string infixToPostfix(string expression) {
    stack<char> s;
    string postfix = "";

    for (char ch : expression) {

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            s.push(ch);
        }

        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty()) {
                s.pop();
            }
        }

        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {

            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch)) {

                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string expression;

    cout << "Enter infix expression: ";
    cin >> expression;

    string result = infixToPostfix(expression);

    cout << "Postfix expression: " << result << endl;

    return 0;
}
