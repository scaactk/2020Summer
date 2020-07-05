#include <iostream>
#include <stack>
using namespace std;
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
private:
    int s[10000];
    int t = -1;
    int min = INT32_MAX;

public:
    /** initialize your data structure here. */

    MinStack() {

    }

    void push(int x) {
        if(x<min){min = x;}
        t++;
        s[t] = x;
    }

    void pop() {
        if(s[t]==min){
            min = INT32_MAX;
            for( int i=t-1;i>=0;i--){
                if(s[i]<min){min = s[i];}
            }
        }
        t--;
    }

    int top() {
        return s[t];
    }

    int getMin() {
        return min;
    }
};


int main() {
    MinStack s;
    s.push(0);
    s.push(1);
    s.push(0);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
