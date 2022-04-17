#include <array>
#include <vector>
#include <string>

#ifndef TRIE_H
#define TRIE_H

#define CHAR_SIZE 256
class Trie{
public:
	bool isLeaf;
	std::array<Trie*, CHAR_SIZE> character;
	Trie();
	void insert(std::string);
	bool deletion(Trie*&, std::string);
	bool search(std::string);
	bool haveChildren(Trie const*);
	std::vector<std::string> suggest(std::string);
};

#endif
