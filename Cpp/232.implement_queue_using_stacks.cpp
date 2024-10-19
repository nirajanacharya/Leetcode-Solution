#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push(x);
    }

    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        int val = outputStack.top();
        outputStack.pop();
        return val;
    }

    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    
    MyQueue* queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    cout << "Peek: " << queue->peek() << endl; // returns 1
    cout << "Pop: " << queue->pop() << endl;   // returns 1
    cout << "Empty: " << (queue->empty() ? "true" : "false") << endl; // returns false
    return 0;
}
