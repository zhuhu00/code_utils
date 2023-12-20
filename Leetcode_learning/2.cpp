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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 设置进位和返回的链表
        ListNode root(0);
        ListNode * cursor = &root;

        int carry=0;//进位
        while(l1||l2||carry){
            int l1Val = l1==nullptr?0:l1->val;
            int l2Val = l2==nullptr?0:l2->val;

            int sumVal = l1Val+l2Val +carry;

            carry = sumVal/10;
            sumVal %=10;

            //存储结果的数值
            ListNode *sumNode = new ListNode(sumVal);
            sumNode->val = sumVal;
            cursor->next = sumNode;
            cursor = cursor->next;

            if(l1) l1=l1->next;
            if(l2) l2 = l2->next;
        }
        return root.next;
    }
};
