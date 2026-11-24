#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int k) {
    if (!root) return new Node(k);
    if (k < root->key) root->left = insert(root->left, k);
    else if (k > root->key) root->right = insert(root->right, k);
    return root;
}

void preOrder(Node* root, bool &first) {
    if (!root) return;
    if (!first) cout << " ";
    cout << root->key;
    first = false;
    preOrder(root->left, first);
    preOrder(root->right, first);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Node* root = nullptr;
    string cmd;
    while (cin >> cmd && cmd != "#") {
        if (cmd == "insert") {
            int k;
            cin >> k;
            root = insert(root, k);
        }
    }
    bool first = true;
    preOrder(root, first);
    cout << endl;
    return 0;
}
