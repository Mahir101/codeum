// LC 547: Number of Provinces | LC 721: Accounts Merge
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank_;
    UnionFind(int n) : parent(n), rank_(n, 0) { for (int i = 0; i < n; i++) parent[i] = i; }
    int find(int x) { if (parent[x] != x) parent[x] = find(parent[x]); return parent[x]; }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
    }
};

// LC 547: Number of Provinces
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionFind uf(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isConnected[i][j]) uf.unite(i, j);
    int count = 0;
    for (int i = 0; i < n; i++) if (uf.find(i) == i) count++;
    return count;
}

// LC 721: Accounts Merge
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    UnionFind uf(n);
    unordered_map<string, int> emailToId;
    
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < (int)accounts[i].size(); j++) {
            string& email = accounts[i][j];
            if (emailToId.count(email)) uf.unite(i, emailToId[email]);
            else emailToId[email] = i;
        }
    }
    
    unordered_map<int, set<string>> mergedEmails;
    for (auto& [email, id] : emailToId) mergedEmails[uf.find(id)].insert(email);
    
    vector<vector<string>> result;
    for (auto& [id, emails] : mergedEmails) {
        vector<string> account = {accounts[id][0]};
        account.insert(account.end(), emails.begin(), emails.end());
        result.push_back(account);
    }
    return result;
}

int main() {
    vector<vector<int>> conn = {{1,1,0},{1,1,0},{0,0,1}};
    cout << "Provinces: " << findCircleNum(conn) << endl;
    return 0;
}
