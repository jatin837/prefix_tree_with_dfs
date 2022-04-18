#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <stack>
#include "trie.h"

 
Trie::Trie() {
	this->isLeaf = false;
	for(auto& ch:this->character)
        ch = nullptr;
}

void Trie::insert(std::string key) {
    Trie* curr = this;
    for (unsigned char c:key) {
        if (curr->character[c] == nullptr)
            curr->character[c] = new Trie();
        curr -> isLeaf = false;
        curr = curr->character[c];
    }
    curr->isLeaf = true;
}
 
bool Trie::search(std::string key) {
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
 
bool Trie::deletion(Trie*& curr, std::string key) {
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

std::vector<std::string> Trie::suggest(std::string key){
    std::vector<std::string>suggs(3, "abc");
    Trie* curr = this;

    for(unsigned char ch:key){
        if(curr->character[ch] == nullptr)
            return suggs;
        curr = curr->character[ch];
    }
    
    if(curr->isLeaf){
        return suggs;
    }



    std::stack<Trie*> st;
    st.push(curr);


    while(!st.empty()){
        curr = st.top();
        st.pop();
        for(int i=0; i<CHAR_SIZE; i++){
            if(curr->character[i] != nullptr){
                std::cout<<char(i)<<' ';
                st.push(curr->character[i]);
            }
        }
        std::cout<<'\n';
    }
	return suggs;
}
