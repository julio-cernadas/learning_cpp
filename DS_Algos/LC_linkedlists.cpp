#include<iostream>
#include<sstream>
#include<vector>

using std::cout, std::cin, std::endl, std::string, std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*                          141. Linked List Cycle                          */
// Here we use Robert Floyd's Tortoise and the Hare algorithm, fast and slow!
class Solution_141 {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) 
                return false;
            slow = slow->next;          // one step - tortoise
            fast = fast->next->next;    // two step - hare
        }
        return true;
    }
};
/* ________________________________________________________________________ */

//////////////////////////////////////////////////////////////////////////////

/* ________________________________________________________________________ */
/*                      237. Delete Node in a Linked List                   */
class Solution_237 {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;   
    }
};
/* ________________________________________________________________________ */

//////////////////////////////////////////////////////////////////////////////

/* ________________________________________________________________________ */
/*                      203. Remove Linked List Elements                    */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr){
            return head;
        }
        ListNode* p = head;
        while(p->next != nullptr){
            if (p->next->val == val){
                p->next = p->next->next;
            }
            else{
                p=p->next;
            }
        }
        if (head->val==val)
            head=head->next;
        return head;
    }
};
/* ________________________________________________________________________ */

//////////////////////////////////////////////////////////////////////////////

/* ________________________________________________________________________ */


