#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE (256)

//#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
	bool isWordEnd;
};

struct TrieNode* getNode(void) {
	struct TrieNode* pNode = new TrieNode;
	pNode->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(struct TrieNode* root, const string key) {
	struct TrieNode* pCrawl = root;
	for (int level = 0; level < key.length(); level++) {
		int index = key[level];
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->isWordEnd = true;
}

bool isLastNode(struct TrieNode* root) {
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}

void suggestionsRec(struct TrieNode* root, string currPrefix, vector<string> &v) {
	if (root->isWordEnd){
		v.push_back(currPrefix);
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i]) {
			char child = i;
			suggestionsRec(root->children[i],
						currPrefix + child, v);
		}
}

int suggest(TrieNode* root, const string query, vector<string> &v)
{
	struct TrieNode* pCrawl = root;
	for (char c : query) {
		int ind = c;

		if (!pCrawl->children[ind])
			return 0;

		pCrawl = pCrawl->children[ind];
	}
	if (isLastNode(pCrawl)) {
		return -1;
	}
	suggestionsRec(pCrawl, query, v);
	return 1;
}

// Driver Code
int main() {
	struct TrieNode* root = getNode();

	string comm;

	ifstream fin("history.txt");

	while(getline (fin, comm))
		insert(root, comm);

//insert(root, "hello");
//insert(root, "dog");
//insert(root, "hell");
//insert(root, "cat");
//insert(root, "a");
//insert(root, "hel");
//insert(root, "help");
//insert(root, "helps");
//insert(root, "helping");

	vector<string> suggs;

	int comp = suggest(root, "mkdir", suggs);

  for(int i=0; i<suggs.size(); i++)
  	cout<<i+1<<' '<<suggs[i]<<'\n';

  cout<<suggs.size()<<'\n';

  if (comp == -1)
  	cout << "No other strings found with this prefix\n";
  else if (comp == 0)
  	cout << "No string found with this prefix\n";
	else
		cout<<"";

	return 0;
}

