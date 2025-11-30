#include<bits/stdc++.h>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100005> isIn = 0;
        for(int x: nums) isIn[x] = 1;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        for(ListNode* curr = head; curr; curr = curr->next){
            if(isIn[curr->val]){
                prev->next = curr->next;
            } else {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};