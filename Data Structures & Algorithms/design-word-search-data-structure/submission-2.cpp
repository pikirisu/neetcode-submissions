class WordDictionary {
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

        if(ch == '.'){
            for(auto &it : root->children){
                if(searchTrie(it.second, word, i+1))
                    return true;
            }
            return false;
        }

        if(root->children.find(ch)==root->children.end())
            return false;

        return searchTrie(root->children[ch], word, i+1);
    }

    Trie * root;
    WordDictionary() {
        root = new Trie('-');
    }
    
    void addWord(string word) {
        insertTrie(root,word,0);
    }
    
    bool search(string word) {
        return searchTrie(root,word,0);
    }
};
