/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL){return head;}
        ListNode* temp = head;
        int len=0;
        int rotate = 0;
        while(temp)
        {
            len++;
            temp = temp->next;
        }

        rotate = k%len;
 
        if(rotate == 0){return head;}
        temp = head;
        int c = 1;
        while(c < (len-rotate))
        {
            temp = temp->next;
            c++;
        }
        
        ListNode* newHead = temp->next;
        temp->next = NULL;
        
        temp = newHead;
        
        while(temp && temp->next){temp = temp->next;}
        temp->next = head;
        
        return newHead;
    }
};