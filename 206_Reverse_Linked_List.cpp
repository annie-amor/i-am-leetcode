/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;

        ListNode* reverse = nullptr;
        ListNode* cu = head;

        while(cu != nullptr){

            reverse = new ListNode(cu->val, reverse);

            cu = cu->next;
        }

        return reverse;
    }
};
