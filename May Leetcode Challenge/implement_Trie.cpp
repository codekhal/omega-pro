/*
Implement a trie with insert, search, and startsWith methods.

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note: Input is lowercase letters 'a-z' only.
*/

struct TrieNode
{
    char val;
    int count;
    int endsHere;
    TrieNode *child[26];
};

// Global Root
TrieNode* root;

// Creating newNode
TrieNode *getNode(int index)
{
    TrieNode *newNode = new TrieNode;
    
    newNode->val = 'a' + index;
    newNode->count = newNode->endsHere = 0;
    for(int i=0;i<26;i++)
    {                      // creating a node with 26 child null values
        newNode->child[i] = NULL; // creating a n-ary tree basically.
    }
    
    return newNode;
}

public:
/** Initialize your data structure here. */
Trie() {
    root = getNode('/' - 'a'); // Hack which let us get ASCII of '/'
}

/** Inserts a word into the trie. */
void insert(string word) {
    TrieNode *curr_node = root;
    int index;
    
    for(int i =0; word[i] != '\0';i++)
    {
        index = word[i] - 'a'; // fetching the value for alphabet
        if(curr_node->child[index] == NULL)
        {
            curr_node->child[index] = getNode(index);
        }
        
        curr_node->child[index]->count += 1;
        curr_node = curr_node->child[index];
    }
        curr_node->endsHere += 1;
}

/** Returns if the word is in the trie. */
bool search(string word) {
    
    TrieNode *node = root;

    if(node == NULL)
        return false;
    
    int index;
    for(int i=0;word[i] != '\0';i++)
    {
        index = word[i] - 'a';
        
        if(node->child[index] == NULL)
            return false;
        
        node = node->child[index];
    }
    return (node->endsHere > 0);
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool startsWith(string prefix) {
    TrieNode *node = root;

    int index;
    for(int i=0;prefix[i] != '\0';i++)
    {
        index = prefix[i] - 'a';
        
        if(node->child[index] == NULL)
            return false;
        
        node = node->child[index];
    }
    return (node->count > 0);
    
}