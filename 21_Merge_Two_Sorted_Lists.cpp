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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;

        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;

        ListNode* merge = nullptr;

        if(list1->val <= list2->val){
            merge = list1;
            list1 = list1->next;
        }else{
            merge = list2;
            list2 = list2->next;
        }
        
        ListNode* cu = merge;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                cu->next = list1;
                list1 = list1->next;
            }else{
                cu->next = list2;
                list2 = list2->next;
            }

            cu = cu->next;
        }

        if(list1 == nullptr)
            cu->next = list2;
        else
            cu->next = list1;

        return merge;
    }
};
