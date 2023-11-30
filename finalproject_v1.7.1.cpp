#include <stdio.h>

//Version 1.7

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <typeinfo>
#include <iomanip>

double ans; //variables housing the value of operations performed
double left;
double right;
double n;

bool opLast = false; //allows the program to differentiate negative numbers and subtraction if needed
bool isNegative = false; //is switched to "true" then the next number read will be negative
bool runOp = false; //for precedence, if the next number is 

double modDivision(double left, double right) {
    return left - right * floor(left / right);
}

double mdas(double left, char op, double right) { //function that will take left and right numbers and perform operations based on operation character
    switch(op){
        case '+': return  left + right; 
        case '-': return  left - right;
        case '*': return  left * right;
        case '/': return  left / right;
        case '%': return  modDivision(left, right);
    }
}

int main() {
    std::string userInput; //user input variable
    std::cout << "Enter expression: "; //user input prompt
    std::getline(std::cin, userInput); //setting prompt entry to input variable
    
    std::stack<double> nums; //initiating stack for numbers
    std::stack<double> digitConcat; //concatonates digits into a single number from string reader
    std::stack<char> ops; //initiating stack for operations
    
    for (size_t i = 0; i < userInput.length(); ++i) { //loop to iterate through user input
        if (userInput[i] == ' ') { //if statement to skip spaces
            continue;
        }else if (isdigit(userInput[i])) { //else if block to add integers to nums stack
            double digits = 0;
            double len = 0;
            /*the following blocks of code will add each digit to a stack until a character is reached that is not a digit.
            Next the section will take each index of the stack and add it to the final result, with each iteration a 0 will be added to the
            next index of the stack.*/
            while (i < userInput.length() & isdigit(userInput[i])) {
                n = userInput[i] - '0'; //converts the char data type of userInput[i] into an integer
                digitConcat.push(n); //adds to the top of the stack of digits
                len = len + 1; //determines length of adding loop
                i++; //jump to next character
            }
            ans = 0; 
            for (int j = 0; j < len; j++){ //loop for adding the digits into a single number
                n = digitConcat.top(); 
                n = n * pow(10.0, digits);
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
            if (userInput[i] == '(') { //is open parenthesis is next, missing operator error will terminate program
                std::cout << "Invalid expression: Missing operator." << std::endl;
                return 0;
            }
            i--;
            if (runOp == true){ //if last operation was *, /, % then the operation with precedence will run
                right = nums.top(); //creating left right values for function 
                nums.pop(); //removes top number from stack
                left = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                ans = mdas(left, op, right);
                nums.push(ans); //answer is added to the top of the stack
                runOp = false;
            }
        }else if (userInput[i] == '(' |userInput[i] == '+' |userInput[i] == '*' |userInput[i] == '/' |userInput[i] == '%'){
            if (userInput[i] == '+') {
                i++;
                while (userInput[i] == ' '){
                    i++;
                }if (userInput[i] == '-' |isdigit(userInput[i])| userInput[i] == '+'| userInput[i] == '('){
                    i--;
                }else {
                    std::cout << "Invalid expression: Operator without operands." << std::endl;
                    return 0;
                }
            }else if (userInput[i] == '*' | userInput[i] == '/' | userInput[i] == '%' | userInput[i] == '('){
                i++;
                while (userInput[i] == ' '){
                    i++;
                }if (userInput[i] == '-' | isdigit(userInput[i]) | userInput[i] == '+' | userInput[i] == '('){
                    i--;
                }else{
                    std::cout << "Invalid expression: Operator without operands." << std::endl;
                    return 0;
                }
            }if (userInput[i] == '*' | userInput[i] == '/' | userInput[i] == '%' ){
                if (ops.empty() & nums.empty()){
                    std::cout << "Invalid expression: Operator without operands." << std::endl;
                    return 0;
                }
            }
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
            }if (userInput[i] == '*'| userInput[i] == '/' |userInput[i] == '%'){ //if the operation read is *, /, or % then the operation will run once the next number is taken in
                runOp = true;
            }
        }/*exponent operator will take top number on stack as the base, then will jump to the number after the operator as the exponent.
        if next symbol is '-' it will set the exponent as negative*/
        else if (userInput[i] == '^'){ 
            i++; 
            while(userInput[i] == ' '){
                i++;
            }
            if (userInput[i] == '('){ //2 ^ ((1 + (-3)))
                ops.push('^');
                
            }else{
                left = nums.top();
                nums.pop();
                
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
                }i--;
        }else if (userInput[i] == '-') { //if '-' appears, true false statements scattered above will allow distinguishability between subtraction and negative number
            std::cout<<opLast<<std::endl;
            if (opLast == true){
                isNegative = true;
            }else if (nums.empty()){ //if '-' is first character negative number is implied
                isNegative = true;
            }else {
                ops.push(userInput[i]);
            }
        }else if (userInput[i] == ')'){
            if (ops.empty()){
                    std::cout << "Invalid expression: Missing parenthesis." << std::endl;
                    return 0;
            }
            std::cout << nums.top() << std::endl;
            /*if closed parenthesis is found while loop will be excecuted until an open parenthesis operation is found.
            the loop works its way from right to left combining values based on the operations between them. End result is one number*/
            while (ops.top() != '('){
                std::cout << 'a' << std::endl;
                right = nums.top(); //creating left right values for function 
                nums.pop(); //removes top number from stack
                left = nums.top();
                nums.pop();
                char op = ops.top();
                ops.pop();
                ans = mdas(left, op, right);
                nums.push(ans); //answer is added to the top of the stack
                std::cout << nums.top() << std::endl;
            }
            
            ops.pop(); //removes open parenthesis from the stack
            if (!ops.empty()){
                if (ops.top() == '*'| ops.top() == '/'| ops.top() == '%') {
                    right = nums.top(); //creating left right values for function 
                    nums.pop(); //removes top number from stack
                    left = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    ans = mdas(left, op, right);
                    nums.push(ans); //answer is added to the top of the stack
                }
            std::cout << ops.top() << std::endl;
            }if (ops.top() == '^'){
                left = nums.top();
                nums.pop();
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
            }
        }else { //else triggered if an invalid character is entered, will terminate the program is triggered
            std::cout << "Invalid character entered" << std::endl;
            return 0;
        }
    }
    while(!ops.empty()){ //this loop will excecute the functions remaining after the parenthesis are removed
        if (ops.top() == '(') {
            std::cout << "Invalid expression: Missing parenthesis." << std::endl;
            return 0;
        }
        right = nums.top();
        nums.pop(); 
        left = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        ans = mdas(left, op, right);
        nums.push(ans);
    }
    if (modDivision(ans, 1.0) == 0){
        std::cout <<"The result is: " << std::fixed << std::setprecision(0) << nums.top() << std::endl; //returns final result if number is an integer
    }else {
        std::cout << "The result is: " << nums.top() << std::endl; //returning the final result
    }
    return 0;
}
