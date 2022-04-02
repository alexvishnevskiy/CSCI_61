// Given an expression in postfix format, we want to evaluate it.
// Example: 5 6 * 2 + -> 5*6+2, if we see an operatop -> convert it to expression
// Example: 5 6 2 3 * * + 2 + -> 5 + 6 * 2 * 3 + 2, firstly 2*3, then 6*6, then 36 + 5, then 41 + 2
#include <string>
#include <stack>
#include <sstream>
#include <iostream>

//from 5 5 * + 12 4 -> 5*5+12-4
void evalPostFix(std::string expPostFix){
    std::stack<double> numbers;
    std::istringstream iss(expPostFix);

    while (!iss.eof(1)){
        std::string str;
        iss >> str;
        if (isdigit(str[0]) || str[0] == '.'){ //only works on char
            numbers.push(std::strtod(str)); //convert string to double
        }else{
            double a = numbers.top(); numbers.pop();
            double b = numbers.top(); numbers.pop();
            switch(str[0]){
                case '+':
                    numbers.push(a + b);
                    break;
                case '-':
                    numbers.push(b - a); //b-a because we push firstly a and then b, ex: 5 6 -, firstly 5 then 6
                    break;
                case '*':
                    numbers.push(a * b);
                    break;
                case '/':
                    numbers.push(b/a); //b/a because we push firstly a and then b, ex: 5 6 /, firstly 5 then 6
                    break;
                default:
                    std::cout << "error" << std::endl; //we don't know character
                    break;
            }
        }
    }
    std::cout << expPostFix << '=' << numbers.top() << std:: endl;
}

//from 5*5+12-4 -> 5 5 * + 12 4 -
void infixtoPostfix(std::string expInFix){
    std::stack<char> ops;
    std::istringstream iss(expInFix);
    while(!iss.eof(1)){
        std::string str;
        iss >> str;
        if (isdigit(str[0]) || str[0] == '.'){
            std::cout << strtod(str) << " ";
        }else{
            switch(str[0]){
                case '*':
                    while (ops.top() == '*' || ops.top() == '/'){
                        std::cout << ops.top() << ' ';
                        ops.pop();
                    }
                    ops.push(str[0]);
                    break;
                case '/':
                    while (ops.top() == '*' || ops.top() == '/'){
                        std::cout << ops.top() << ' ';
                        ops.pop();
                    }
                    ops.push(str[0]);
                    break;
                case '-':
                    while (ops.top() == '*' || ops.top() == '/' || ops.top() == '+' || ops.top() == '-'){
                        std::cout << ops.top() << ' ';
                        ops.pop()
                    }
                    ops.push(str[0]);
                    break;
                case '+':
                    while (ops.top() == '*' || ops.top() == '/' || ops.top() == '+' || ops.top() == '-'){
                        std::cout << ops.top() << ' ';
                        ops.pop()
                    }
                    ops.push(str[0]);
                    break;
            }
        }
    }

    while (!ops.empty()){ //if something left pop
        std::cout << ops.top();
        ops.pop();
    }
}