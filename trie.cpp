#include <iostream>
#include <array>
using namespace std;
 
#define CHAR_SIZE 256
 
class Trie {
public:
    bool isLeaf;
    array<Trie*, CHAR_SIZE> character;
 
    Trie() {
        this->isLeaf = false;
				for(auto ch:this->character)
            ch = NULL;
    }
 
    void insert(string);
    bool deletion(Trie*&, string);
    bool search(string);
    bool haveChildren(Trie const*);
};
 
void Trie::insert(string key) {
    Trie* curr = this;
    for (unsigned char c:key) {
        if (curr->character[c] == nullptr)
            curr->character[c] = new Trie();
        curr = curr->character[c];
    }
    curr->isLeaf = true;
}
 
bool Trie::search(string key) {
    Trie* curr = this;

    if (curr == nullptr) {
        return false;
    }
 
    for (unsigned char c:key) {
        curr = curr->character[c];
 
        if (curr == nullptr)
            return false;
    }
 
    return curr->isLeaf;
}
 
bool Trie::haveChildren(Trie const* curr) {
    for (int i = 0; i < CHAR_SIZE; i++)
        if (curr->character[i])
            return true;
 
    return false;
}
 
bool Trie::deletion(Trie*& curr, string key) {
    if (curr == nullptr)
        return false;
 
    if (key.length()) {
 
        if (curr != nullptr &&
            curr->character[(unsigned char)(key[0])] != nullptr &&
            deletion(curr->character[(unsigned char)(key[0])], key.substr(1)) &&
            curr->isLeaf == false)
        {
            if (!haveChildren(curr)) {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    if (key.length() == 0 && curr->isLeaf) {
        if (!haveChildren(curr)) {
            delete curr;
            curr = nullptr;
 
            return true;
        }
 
        else {
            curr->isLeaf = false;
 
            return false;
        }
    }
 
    return false;
}
 
int main() {
    Trie* head = new Trie();
    head->insert("hello");
    cout << head->search("hello") << " ";      // print 1
    head->insert("helloworld");
    cout << head->search("helloworld") << " "; // print 1
    cout << head->search("helll") << " ";      // print 0 (Not found)
    head->insert("hell");
    cout << head->search("hell") << " ";       // print 1
    head->insert("h");
    cout << head->search("h");                 // print 1
    cout << endl;
    cout << head->search("hello") << " ";      // print 0
    cout << head->search("helloworld") << " "; // print 1
    cout << head->search("hell");              // print 1
    cout << endl;
    cout << head->search("h") << " ";          // print 0
    cout << head->search("hell") << " ";       // print 1
    cout << head->search("helloworld");        // print 1
    cout << endl;
    cout << head->search("helloworld") << " "; // print 0
    cout << head->search("hell") << " ";       // print 1
    cout << head->search("hell");              // print 0
    cout << endl;
		
    if (head == nullptr) {
        cout << "Trie empty!!\n";              // Trie is empty now
    }
    cout << head->search("hell");              // print 0
		cout<<'\n';
		
    return 0;
}
