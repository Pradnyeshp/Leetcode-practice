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

// We are given a special linked list where each node has two pointers: next –
// which connects to the next node in the list. random – which can point to any
// node in the list or be null. The task is to create a deep copy of this list.
// That means, for each node in the original list, I need to create a completely
// new node with the same value and make sure that the next and random pointers
// in the new list correctly point to the corresponding new nodes (not to the
// old ones).

// First Pass: Traverse the original list and for each node, create a new node
// with the same value. Use a HashMap to map original nodes → copied nodes.
// Second Pass – Set the correct next and random pointers for each copied node
// using the map.
// Return – Return the head of the copied list from the map.

// Tc:- O(N) You're visiting each node exactly once.For each node, you're
// creating a copy and storing it in the map.while loop takes O(n) time. and
// another while takes O(n) time.
// Sc :- O(N) Hash map stores one entry per node for tracking originals → copies

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Base case: if the original list is empty, return null
        if (!head)
            return nullptr;

        // Create a map to store the mapping between original and copied nodes
        std::unordered_map<Node*, Node*> nodeMap;

        // First pass: Copy all nodes and store them in the map
        Node* current = head;
        while (current) {
            // Create a copy of the current node with same value
            nodeMap[current] = new Node(current->val);
            current = current->next; // Move to next node in the original list
        }

        // Second pass: Set the next and random pointers for each copied node
        current = head;
        while (current) {
            // Set the next pointer of the copied node
            nodeMap[current]->next = nodeMap[current->next];

            // Set the random pointer of the copied node
            nodeMap[current]->random = nodeMap[current->random];

            current = current->next; // Move to next node
        }

        // Return the head of the copied list
        return nodeMap[head];
    }
};