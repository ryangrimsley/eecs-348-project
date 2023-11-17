//Version 1.3

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <typeinfo>

int ans; //variable housing the value of operations performed

int mdas(int left, char op, int right) { //function that will take left and right numbers and perform operations based on operation character
    switch(op){
        case '+': return  left + right; 
        case '-': return  left - right;
        case '*': return  left * right;
        case '/': return  left / right;
    //    case '^': return  pow(left, right); //for exponential function. Else if case will need to be implemented for this below
    }
}

int main() {
    std::string userInput; //user input variable
    std::cout << "Enter expression: "; //user input prompt
    std::getline(std::cin, userInput); //setting prompt entry to input variable
    
    std::stack<int> nums; //initiating stack for numbers
    std::stack<char> ops; //initiating stack for operations
    for (size_t i = 0; i < userInput.length(); ++i) { //loop to iterate through user input
        if (userInput[i] == ' ') { //if statement to skip spaces
            continue;
        }else if (isdigit(userInput[i])) { //else if block to add integers to nums stack
            int n = userInput[i] - '0'; //converts the char data type of userInput[i] into an integer
            nums.push(n); //adds number to top of stack
        }else if (userInput[i] == '(' |userInput[i] == '+' |userInput[i] == '-' |userInput[i] == '*' |userInput[i] == '/' |userInput[i] == '^'){
            ops.push(userInput[i]);  //if an operation character arises that matches one above the character will be added to the stack
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
        }else { //else triggered if an invalid character is entered, will terminate the program is triggered
            std::cout << "Invalid character entered" << std::endl;
            return 0;
        }
    }
    while(!ops.empty()){ //this loop will excecute the functions remaining after the parenthesis are removed
        int right = nums.top();
        nums.pop(); 
        int left = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        ans = mdas(left, op, right);
        nums.push(ans);
    }
    std::cout << "The result is: " << nums.top() << std::endl; //returning the final result
    
    return 0;
}
