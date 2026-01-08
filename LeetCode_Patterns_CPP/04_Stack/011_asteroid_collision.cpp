// LC 735: Asteroid Collision
// Pattern: Stack Simulation
// Time: O(n) | Space: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stk;
    
    for (int a : asteroids) {
        bool destroyed = false;
        while (!stk.empty() && a < 0 && stk.back() > 0) {
            if (stk.back() < -a) {
                stk.pop_back();
                continue;
            } else if (stk.back() == -a) {
                stk.pop_back();
            }
            destroyed = true;
            break;
        }
        if (!destroyed) stk.push_back(a);
    }
    
    return stk;
}

int main() {
    vector<int> asteroids = {5, 10, -5};
    auto result = asteroidCollision(asteroids);
    cout << "After collision: ";
    for (int a : result) cout << a << " ";
    cout << endl;
    return 0;
}
