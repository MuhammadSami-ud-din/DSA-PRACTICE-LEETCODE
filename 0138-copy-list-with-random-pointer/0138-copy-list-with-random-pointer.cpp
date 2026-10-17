/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
     unordered_map<Node* , Node*> oldToNew;
    Node* current = head;
     while(current != nullptr){
        oldToNew[current] = new Node(current->val);
        current = current->next;
     }

    current = head;
     while(current != nullptr){
        oldToNew[current]->next = oldToNew[current->next];
        oldToNew[current]->random = oldToNew[current->random];
        current = current->next;

     }





       return oldToNew[head];
    }
};