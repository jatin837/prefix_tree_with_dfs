#include <iostream>
#include "trie.h"

using namespace std;

int main(void){
    Trie* head = new Trie();
    head->insert("br");
    head->insert("bro");
    head->insert("branson");

    cout << head->search("br") << " ";      // print 0 (Not found)
		cout << endl;

    vector<string>suggs = head->suggest("br");
    return 0;
}
