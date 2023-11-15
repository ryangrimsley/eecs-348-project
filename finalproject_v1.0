#include <iostream>
#include <stack>
#include <string>
#include <cctype>

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
            continue;        
        }else if (userInput[i] == '(' || ')' || '+' || '-' || '*' || '/' || '^'){ //else if block to add operations to ops stack
            ops.push(userInput[i]);
        }
    }
    while (!ops.empty()) { //checking for expected stack format
        char op = ops.top();
        ops.pop();
        std::cout << op << std::endl;
    }

    return 0;
}
