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
Node* fxn(Node* node, map<Node*,Node*>&mp){
    if(!node) return nullptr;
    Node* newnode=new Node(node->val);
    mp[node] = newnode; 
    for(auto it:node->neighbors){
        if(mp.find(it)==mp.end()){
            newnode->neighbors.push_back(fxn(it,mp));
        }
        else{
 newnode->neighbors.push_back(mp[it]);
        }
    }
    return newnode;
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
      if(!node) return nullptr;
      map<Node*,Node*>mp;
      return fxn(node,mp);
    }
};
