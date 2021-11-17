
#include <map>
#include <string>
#include <vector>
using namespace std;


/*
Complexity:
    insert O(|s|)
    erase O(|s|)
    search O(|s|)
Memory:
    O(sum(|s|))
*/

constexpr int ALPH_SIZE = 26;
constexpr int MAXN = int(1e5);

struct Node {
    map<char,int> go;
    bool end = false;
};

int n;
Node trie[MAXN];
int trie_size = 1;

bool can_go(int v, char c) {
    return trie[v].go.count(c);
}
int go(int v, char c) {
    return trie[v].go[c];
}
bool is_end(int v) {
    return trie[v].end;
}
void create_vertice(int v, char c) {
    trie[v].go[c] = trie_size++;
}

void insert(string& s) {
    int v = 0;
    for (auto& c : s) {
        if (!can_go(v, c)) {
            create_vertice(v, c);
        }
        v = go(v, c);
    }
    trie[v].end = true;
}

void erase(string& s) {
    int v = 0;
    for (auto& c : s) {
        if (!can_go(v, c)) {
            return;
        }
        v = go(v, c);
    }
    trie[v].end = false;
}

bool search(string& s) {
    int v = 0;
    for (auto& c : s) {
        if (!can_go(v, c)) {
            return false;
        }
        v = go(v, c);
    }
    return is_end(v);
}

