#include "calculator.h"

using namespace std;

int main(void){
    string input1, input2;
    int num1, num2, result;
    char op;
    string resultOp;

    cout << "Please enter the two operands followed by the operation you wish to use." << endl;
    cin >> input1 >> input2 >> op;

    if(validateInput(input1, input2, op) == 0){
        cout << "Invalid input." << endl;
        return 0;
    }
    
    num1 = convertNum(input1);
    num2 = convertNum(input2);
    result = calcResult(num1, num2, op);
    resultOp = convertOp(op);

    cout << "The "<< resultOp <<" of " << num1 << " and " << num2 << " is " <<result <<"." << endl;

    return 0;
}

int calcResult(int num1, int num2, char op){
    if(op == '+'){
        return num1+num2;
    }
    else if(op == '-'){
        return num1-num2;
    }
    else if(op == '*'){
        return num1*num2;
    }
    else if(op == '/'){
        return num1/num2;
    }
    return 0;

}

int validateInput(string input1, string input2, char op){
    int validInput1, validInput2;
    char validOp;
    vector<string> validInputs = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<char> validOps = {'+', '-', '*', '/'};

    for(string x : validInputs){
        if(input1 == x){
            validInput1 = 1;
        }
        if(input2 == x){
            validInput2 = 1;
        }
    }
    for(char x : validOps){
        if(op == x){
            validOp = 1;
        }
    }

    if(validInput1 == 1 && validInput2 == 1 && validOp == 1){
        return 1; //Return 1 if all inputs are valid
    }
    else{
        return 0; //Return 0 if an input is invalid
    }

}

int convertNum(string input){
    if(input == "one" || input == "1"){
        return 1;
    }
    else if(input == "two" || input == "2"){
        return 2;
    }
    else if(input == "three" || input == "3"){
        return 3;
    }
    else if(input == "four" || input == "4"){
        return 4;
    }
    else if(input == "five" || input == "5"){
        return 5;
    }
    else if(input == "six" || input == "6"){
        return 6;
    }
    else if(input == "seven" || input == "7"){
        return 7;
    }
    else if(input == "eight" || input == "8"){
        return 8;
    }
    else if(input == "nine" || input == "9"){
        return 9;
    }
    return 0;
}

string convertOp(char op){
    switch(op){
        case '+':
            return "sum";
        case '-':
            return "difference";
        case '*':
            return "product";
        case '/':
            return "quotient";
        default:
            return "undefined";
    }
}