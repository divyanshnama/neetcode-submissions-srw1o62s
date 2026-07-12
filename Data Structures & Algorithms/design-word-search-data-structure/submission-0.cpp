struct TrieNode {
    TrieNode* children[26];
    bool flag;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        flag = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string& word, int index, TrieNode* node) {
        if (node == nullptr)
            return false;

        if (index == word.length())
            return node->flag;

        char c = word[index];

        if (c != '.') {
            return dfs(word, index + 1, node->children[c - 'a']);
        }

        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();

            curr = curr->children[index];
        }

        curr->flag = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};