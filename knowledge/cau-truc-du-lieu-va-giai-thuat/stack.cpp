#include <iostream>

#define BLANK_LINE std::cout << std::endl

const int MAX_SIZE = 100000;

struct Stack {
    int numberOfNode;
    int* node;

    Stack() {
        this->numberOfNode = 0;
        this->node = nullptr;
    }

    bool push(int value) {
        if (this->numberOfNode >= MAX_SIZE) {
            return false;
        }

        this->node[this->numberOfNode] = value;
        ++this->numberOfNode;
        return true;
    }

    bool pop() {
        if (this->numberOfNode == 0) {
            return false;
        }

        this->node[this->numberOfNode] = 0;
        --this->numberOfNode;
        return true;
    }
};

void Init(Stack* stack, int numberOfNode = 0) {
    stack->numberOfNode = numberOfNode;
    stack->node = new int [MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        stack->node[i] = 0;
    }
}

void Print(Stack* stack) {
    for (int i = 0; i < stack->numberOfNode; ++i) {
        std::cout << stack->node[i] << " ";
    }
    BLANK_LINE;
}

int main() {
    Stack stack;
    Init(&stack);
    for (int i = 1; i <= 10; ++i) {
        stack.push(i);
    }

    Print(&stack);



    return 0;
}

/*
* 


*/

