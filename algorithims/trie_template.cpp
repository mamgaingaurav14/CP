
#include <bits/stdc++.h>
using namespace std;
#define lil long long int 
  //tries
    class Node {
public:
    Node* lists[26];
    bool flag = false;

};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            int ch = c - 'a';
            if (!node->lists[ch]) {
                node->lists[ch] = new Node();
            }
            node = node->lists[ch];
            node->flag = true;
        }
    }

   
    vector<int> search(const string& target, int start) {
        vector<int> valid_lengths;
        Node* node = root;
        for (int i = start; i < target.length(); i++) {
            if (!node->lists[target[i] - 'a']) break;
            node = node->lists[target[i] - 'a'];
            if (node->flag) {
                valid_lengths.push_back(i - start + 1);
            }
        }
        return valid_lengths;
    }
};