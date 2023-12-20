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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first=-1, pre = -1;
        int min_d = INT_MAX, max_d = -1;
        int idx = 0;
        while(head!=nullptr&&head->next !=nullptr&& head->next->next !=nullptr){
            // 保证了极值至少存在
            idx++;
            if(head->next->val > head->val && head->next->val > head->next->next->val
            || head->next->val< head->val&& head->next->val< head->next->next->val){
                if(first == -1){
                    first = idx;
                }
                else{
                    max_d = idx-first;
                    min_d = min(min_d,idx-pre);
                }
                pre = idx;
            }
            head = head->next;
        }
        if(max_d ==-1){
            return {-1,-1};
        }
        return {min_d,max_d};
    }
};
