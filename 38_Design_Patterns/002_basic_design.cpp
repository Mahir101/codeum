// LC 1603: Design Parking System | LC 705: Design HashSet
// LC 232: Implement Queue using Stacks
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// LC 1603: Parking System
class ParkingSystem {
    int slots[3];
public:
    ParkingSystem(int big, int medium, int small) { slots[0] = big; slots[1] = medium; slots[2] = small; }
    bool addCar(int carType) { return slots[carType - 1]-- > 0; }
};

// LC 232: Queue using Two Stacks
class MyQueue {
    stack<int> in, out;
    void transfer() { while (!in.empty()) { out.push(in.top()); in.pop(); } }
public:
    void push(int x) { in.push(x); }
    int pop() { if (out.empty()) transfer(); int x = out.top(); out.pop(); return x; }
    int peek() { if (out.empty()) transfer(); return out.top(); }
    bool empty() { return in.empty() && out.empty(); }
};

// LC 225: Stack using Two Queues
class MyStack {
    queue<int> q1, q2;
public:
    void push(int x) { q2.push(x); while (!q1.empty()) { q2.push(q1.front()); q1.pop(); } swap(q1, q2); }
    int pop() { int x = q1.front(); q1.pop(); return x; }
    int top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

int main() {
    MyQueue q; q.push(1); q.push(2);
    cout << "Queue peek: " << q.peek() << endl;
    return 0;
}
