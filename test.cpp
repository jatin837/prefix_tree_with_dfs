#include <iostream>
#include "trie.h"

using namespace std;

int main(void){
    Trie* head = new Trie();
    head->insert("hello");
    head->insert("alaska");
    head->insert("this");
    head->insert("is");
    head->insert("your");
    head->insert("brad");
    head->insert("pitt");
    head->insert("helloworld");
    head->insert("hell");
    head->insert("h");

    cout << head->search("brad") << " ";      // print 0 (Not found)
    cout << head->search("br") << " ";      // print 0 (Not found)
		cout << endl;

		vector<string>suggs = head->suggest("this");
		for(auto s:suggs)
			cout<<s<<'\n';
    return 0;
}
