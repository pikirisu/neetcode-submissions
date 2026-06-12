class PrefixTree {
public:
    class Trie{
        public:
        char val;
        unordered_map<char,Trie*> children;
        bool isTerminal;

        Trie(char val){
            this->val = val;
            isTerminal = false;
        }
    };
    void insertTrie(Trie* root, const string& word, int i){
        // Base case
        if(i==word.length()){
            root->isTerminal = true;
            return;
        }

        char ch = word[i];
        Trie* child;

        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            child = new Trie(ch);
            root->children[ch] = child;
        }

        insertTrie(child, word, i+1);
    }

    bool searchTrie(Trie * root, const string& word, int i){
        // Base Case
        if(i==word.length()){
            if(root->isTerminal==true)
            return true;
            else return false;
        }

        char ch = word[i];
        Trie * child;

        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        bool recAns = searchTrie(child, word, i+1);
        return recAns;
    }

    bool prefixTrie(Trie * root, const string& word, int i){
        // Base Case
        if(i==word.length()){
            return true;
        }

        char ch = word[i];
        Trie * child;

        if(root->children.find(ch)!=root->children.end()){
            child = root->children[ch];
        }
        else{
            return false;
        }
        bool recAns = prefixTrie(child, word, i+1);
        return recAns;
    }
    Trie * root;
    PrefixTree() {
        root = new Trie('-');
    }
    
    void insert(string word) {
        insertTrie(root,word,0);
    }
    
    bool search(string word) {
        return searchTrie(root,word,0); 
    }
    
    bool startsWith(string prefix) {
        return prefixTrie(root,prefix,0);
    }
};
