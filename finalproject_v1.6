#include <stdio.h>

//Version 1.6

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <typeinfo>

int ans; //variables housing the value of operations performed
int left;
int right;
int n;

bool opLast = false;
bool isNegative = false;
bool runOp = false;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int mdas(int left, char op, int right) { //function that will take left and right numbers and perform operations based on operation character
    switch(op){
        case '+': return  left + right; 
        case '-': return  left - right;
        case '*': return  left * right;
        case '/': return  left / right;
        case '%': return  left % right;
    }
}

int main() {
    std::string userInput; //user input variable
    std::cout << "Enter expression: "; //user input prompt
    std::getline(std::cin, userInput); //setting prompt entry to input variable
    
    std::stack<int> nums; //initiating stack for numbers
    std::stack<int> digitConcat; //concatonates digits into a single number from string reader
    std::stack<char> ops; //initiating stack for operations
    
    for (size_t i = 0; i < userInput.length(); ++i) { //loop to iterate through user input
        if (userInput[i] == ' ') { //if statement to skip spaces
            continue;
        }else if (isdigit(userInput[i])) { //else if block to add integers to nums stack
            int digits = 0;
            int len = 0;
            /*the following blocks of code will add each digit to a stack until a character is reached that is not a digit.
            Next the section will take each index of the stack and add it to the final result, with each iteration a 0 will be added to the
            next index of the stack.*/
            while (i < userInput.length() & isdigit(userInput[i])) {
                int n = userInput[i] - '0'; //converts the char data type of userInput[i] into an integer
                digitConcat.push(n); //adds to the top of the stack of digits
                len = len + 1; //determines length of adding loop
                i++; //jump to next character
            }
            ans = 0; 
            for (int j = 0; j < len; j++){ //loop for adding the digits into a single number
                n = digitConcat.top(); 
                n = n * pow(10, digits);
                digits = digits + 1; //adds a 0 to the next loop
                ans = ans + n; //adds digit to total
                digitConcat.pop();
            }
            i--;
            if (isNegative == true){ //if '-' symbol preluded number, number will be made negative.
                isNegative = false; //resets negative number
                ans = ans * -1;
            }
            nums.push(ans); //adds number to top of stack
            opLast = false;
            i++;
            if (userInput[i] == '(') { //is open parenthesis is next, multiplication is implied
                ops.push('*');
            }
            i--;
            if (runOp == true){
                int right = nums.top(); //creating left right values for function 
                nums.pop(); //removes top number from stack
                int left = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                ans = mdas(left, op, right);
                nums.push(ans); //answer is added to the top of the stack
                runOp = false;
            }
        }else if (userInput[i] == '(' |userInput[i] == '+' |userInput[i] == '*' |userInput[i] == '/' |userInput[i] == '%'){
            runOp = false;
            ops.push(userInput[i]);  //if an operation character arises that matches one above the character will be added to the stack
            if (userInput[i] == '+' |userInput[i] == '*' |userInput[i] == '/'|userInput[i] == '%'){ //giving program ability to distinguish the - operator and a negative number
                opLast = true;
            }if (userInput[i] == '/'){ //if statement for possible division by zero
                i++;
                if (userInput[i] == '0'){ //if zero is present checks if digit is an excessive zero
                    while (userInput[i] == '0'){ //deals with excessive zeros before number
                        i++;
                    }if (!isdigit(userInput[i])) { //if value entered after divison is actually zero, program will terminate
                        std::cout << "Invalid expression: Division by zero." << std::endl;
                        return 0;
                    }i--; //sends program to deal with number after divison symbol
                }i--;
            }if (userInput[i] == '*'| userInput[i] == '/' |userInput[i] == '%'){
                runOp = true;
            }
        }/*exponent operator will take top number on stack as the base, then will jump to the number after the operator as the exponent.
        if next symbol is '-' it will set the exponent as negative*/
        else if (userInput[i] == '^'){ 
            left = nums.top();
            nums.pop();
            i++;
            if (userInput[i] == '-'){
                i++;
                isNegative = true;
            }
            right = userInput[i] - '0';
            if (isNegative == true){
                isNegative = false;
                right = right * -1;
            }
            ans = pow(left, right);
            nums.push(ans);
        }else if (userInput[i] == '-') { //if '-' appears, true false statements scattered above will allow distinguishability between subtraction and negative number
            if (opLast == true){
                isNegative = true;
            }else if (nums.empty()){ //if '-' is first character negative number is implied
                isNegative = true;
            }else {
                ops.push(userInput[i]);
            }
        }else if (userInput[i] == ')'){
            /*if closed parenthesis is found while loop will be excecuted until an open parenthesis operation is found.
            the loop works its way from right to left combining values based on the operations between them. End result is one number*/ 
            while (ops.top() != '('){
                int right = nums.top(); //creating left right values for function 
                nums.pop(); //removes top number from stack
                int left = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                ans = mdas(left, op, right);
                nums.push(ans); //answer is added to the top of the stack
            }
            ops.pop(); //removes open parenthesis from the stack
            if (!ops.empty()){
                if (ops.top() == '*'| ops.top() == '/'| ops.top() == '%') {
                    int right = nums.top(); //creating left right values for function 
                    nums.pop(); //removes top number from stack
                    int left = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    ans = mdas(left, op, right);
                    nums.push(ans); //answer is added to the top of the stack
                }
            }
        }else { //else triggered if an invalid character is entered, will terminate the program is triggered
            std::cout << "Invalid character entered" << std::endl;
            return 0;
        }
    }
    while(!ops.empty()){ //this loop will excecute the functions remaining after the parenthesis are removed
        right = nums.top();
        nums.pop(); 
        left = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        ans = mdas(left, op, right);
        nums.push(ans);
    }
    std::cout << "The result is: " << nums.top() << std::endl; //returning the final result
    
    return 0;
}
