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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr)
            temp->next = l1;
        else
            temp->next = l2;

        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        int n = lists.size();
        while (n > 1) {
            int idx = 0;

            for (int i = 0; i < n; i += 2) {

                if (i + 1 < n) {
                    lists[idx] = mergeTwoLists(lists[i], lists[i + 1]);
                }
                else {
                    lists[idx] = lists[i];
                }

                idx++;
            }

            n = idx;
        }

        return lists[0];
    }
};