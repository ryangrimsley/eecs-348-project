//Version 1.2

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

std::string userInput; //user input variable
std::stack<int> nums; //initiating stack for numbers
std::stack<char> ops; //initiating stack for operations
int ans; //variable housing the value of operations performed

int mdas(int8_t left, char op, int8_t right) { //function that will take left and right numbers and perform operations based on operation character
    std::cout << left << std::endl;
    switch(op){
        case '+': return  left + right; //the issue is present at this stage of the code
        case '-': return  left - right; //the value returned is an address after going through any function, not a number
        case '*': return  left * right;
        case '/': return  left / right;
        case '^': return  pow(left, right);
    }
}

int main() {
    std::cout << "Enter expression: "; //user input prompt
    std::getline(std::cin, userInput); //setting prompt entry to input variable
    for (size_t i = 0; i < userInput.length(); ++i) { //loop to iterate through user input
        if (userInput[i] == ' ') { //if statement to skip spaces
            continue;
        }else if (isdigit(userInput[i])) { //else if block to add integers to nums stack
            nums.push(userInput[i]);        
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
    }
    std::cout << ans << std::endl; //returning the final result
/*    while (!ops.empty()) { //checking for expected stack format
        char op = ops.top();
        ops.pop();
        std::cout << op << std::endl;
    }while (!nums.empty()) {
        int8_t num = nums.top();
        nums.pop();
        std::cout << num << std::endl;
    }*///use this section to check values contained in stack if needed
    return 0;
}
