/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> oldToNew;
         if(node==nullptr) return nullptr;
         if(node->neighbors.size()==0)
         {
            Node* clone = new Node(node->val);
            return clone;
         }
        return dfs(node,oldToNew);
    }

    Node* dfs(Node* curr,unordered_map<Node*,Node*>& oldToNew)
    {
       vector<Node*> neighbour;

       Node* clone =new Node(curr->val);
        oldToNew[curr] = clone;

        for(auto it: curr->neighbors)
        {
            if(oldToNew.find(it)!=oldToNew.end())
                neighbour.push_back(oldToNew[it]);
            else
                neighbour.push_back(dfs(it,oldToNew));
        }
        clone->neighbors=neighbour;
        return clone;
    }
};
