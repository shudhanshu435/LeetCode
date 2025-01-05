class Trie {
public:
    struct trieNode{
        bool isendofWord;
        trieNode* child[26];

        trieNode() {
            isendofWord = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };
    trieNode* root;
    Trie() {
        root=new trieNode();
    }
    
    void insert(string word) {
        trieNode* crawl=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawl->child[idx]==nullptr){
                crawl->child[idx]=new trieNode();
            }
            crawl=crawl->child[idx];
        }
        crawl->isendofWord=true;
    }
    
    bool search(string word) {
        trieNode* crawl=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';
            if(crawl->child[idx]==nullptr){
                return false;
            }
            crawl=crawl->child[idx];
        }
        return crawl->isendofWord;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl=root;
        int i;
        for(i=0;i<prefix.length();i++){
            char ch=prefix[i];
            int idx=ch-'a';
            if(crawl->child[idx]==nullptr){
                return 0;
            }
            crawl=crawl->child[idx];
        }
        return 1;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */