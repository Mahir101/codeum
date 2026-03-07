// LC 588: Design In-Memory File System
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class FileSystem {
    struct Node {
        bool isFile = false;
        string content;
        map<string, Node*> children;
    };
    Node* root = new Node();
    
    pair<Node*, string> traverse(string& path) {
        Node* node = root;
        string name;
        stringstream ss(path);
        while (getline(ss, name, '/')) {
            if (name.empty()) continue;
            if (!node->children.count(name)) node->children[name] = new Node();
            node = node->children[name];
        }
        return {node, name};
    }
    
public:
    vector<string> ls(string path) {
        auto [node, name] = traverse(path);
        if (node->isFile) return {name};
        vector<string> result;
        for (auto& [childName, _] : node->children) result.push_back(childName);
        return result;
    }
    
    void mkdir(string path) { traverse(path); }
    
    void addContentToFile(string filePath, string content) {
        auto [node, _] = traverse(filePath);
        node->isFile = true;
        node->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto [node, _] = traverse(filePath);
        return node->content;
    }
};

int main() {
    FileSystem fs;
    fs.mkdir("/a/b/c");
    fs.addContentToFile("/a/b/c/d", "hello");
    cout << "Read: " << fs.readContentFromFile("/a/b/c/d") << endl;
    return 0;
}
