#include <cctype>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

#define INT_MAX __INT_MAX__
#define INT_MIN (-INT_MAX - 1)
typedef long long ll;
using namespace std;

//Get rid of whitespaces and consecutive --, ++, +- and -+ cases
//(4-7)*-(-4+5*-3/4)=(4-7)*-1*(-4+5*-3/4)
//(4-7)/-(-4+5*3/-4)=(4-7)*-1*(-4+5*3/-4)
//(4-7)/-(4+5*3/-4)=(4-7)*-1*(4+5*3/-4)
string preprocess(string &expression) {
    cout << expression << "\n";
    string exp;

    for (char ch : expression) {
        if (isspace(ch)) continue;
        else
            exp += ch;
    }
    expression = exp;
    exp.clear();

    for (unsigned int i = 0; i < expression.length(); i++) {
        if (expression[0] == '+') i++;
        char first = expression[i];
        bool notLast = i <= expression.length() - 2;

        if (first == '-') {
            if (notLast && expression[i + 1] == '-') {
                exp += '+';
                i++;
            } else if (notLast && expression[i + 1] == '+') {
                exp += '-';
                i++;
            } else
                exp += '-';
        } else if (first == '+') {
            if (notLast && expression[i + 1] == '-') {
                exp += '-';
                i++;
            } else if (notLast && expression[i + 1] == '+') {
                exp += '+';
                i++;
            } else
                exp += '+';
        } else
            exp += expression[i];
    }
    expression = exp;
    exp.clear();
    cout << expression << "\n";

    for (unsigned int i = 0; i < expression.length(); i++) {
        bool notSecondLast = i <= expression.length() - 3;

        if (expression[i] == '*' && notSecondLast && expression[i + 1] == '-' && expression[i + 2] == '(') {
            exp += "*-1*(";
            i += 2;
        } else if (expression[i] == '/' && notSecondLast && expression[i + 1] == '-' && expression[i + 2] == '(') {
            exp += "/-1/(";
            i += 2;
        } else if (expression[i] == '-' && notSecondLast && expression[i + 1] == '(') {
            exp += "-1*(";
            i++;
        } else
            exp += expression[i];
    }
    cout << exp << "\n";
    return exp;
}

int isp(char ch) { //In Stack Priority
    switch (ch) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '(': return 0;
    }
    return -1;
}

int icp(char ch) { //In Coming Priority
    switch (ch) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '(': return 3;
    }
    return -1;
}

double operate(double a, double b, char ch) {
    switch (ch) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return INT_MIN;
}

bool isOperator(char ch) { return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '('; }
bool isOperand(char ch) { return ('0' <= ch && ch <= '9') || ch == '.'; }

double calc(std::string expression) {
    if (expression.empty()) return 0;
    expression = preprocess(expression);

    size_t length = expression.length();
    bool isNegativeNumber = expression[0] == '-' && '0' <= expression[1] && expression[1] <= '9'; //"-4+7"
    stack<double> number;
    stack<char> op;
    string num;
    for (size_t i = 0; i < length;) {
        //"(-4"  "*-4"  "/-4"
        if (i > 0)
            isNegativeNumber = expression[i] == '-' && (expression[i - 1] == '(' || expression[i - 1] == '*' || expression[i - 1] == '/');

        if (isOperator(expression[i])) {
            if (expression[i] == '-' && isNegativeNumber) {
                num = "-";
                i++;
                while (isOperand(expression[i]))
                    num += expression[i++];
                number.push(stod(num));
                num = "";
            } else {
                while (!op.empty() && (icp(expression[i]) <= isp(op.top()))) {
                    double a = number.top();
                    number.pop();
                    double b = number.top();
                    number.pop();
                    number.push(operate(b, a, op.top()));
                    op.pop();
                }
                op.push(expression[i++]);
            }
        } else if (expression[i] == ')') {
            while (op.top() != '(') {
                double a = number.top();
                number.pop();
                double b = number.top();
                number.pop();
                number.push(operate(b, a, op.top()));
                op.pop();
            }
            i++;
            op.pop();
        } else {
            while (isOperand(expression[i]))
                num += expression[i++];
            number.push(stod(num));
            num = "";
        }
        isNegativeNumber = false;
    }

    while (!op.empty() && number.size() > 1) {
        double a = number.top();
        number.pop();
        double b = number.top();
        number.pop();
        number.push(operate(b, a, op.top()));
        op.pop();
    }
    if (!op.empty() && op.top() == '-' && number.size() == 1) {
        double a = number.top();
        number.pop();
        number.push(-1 * a);
        op.pop();
    }
    return number.top();
}

int main() {
    // cout << calc("(-87) - (38 + -59 / -(61)) / (71 + ((((-39 + -29)))) / -34)") << "\n";
    cout << calc("-(-(-1))") << "\n";

    return 0;
}