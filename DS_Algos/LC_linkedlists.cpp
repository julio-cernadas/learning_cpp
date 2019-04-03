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

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
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

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                      203. Remove Linked List Elements                    */

class Solution_203 {
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

/* –––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––– */
//////////////////////////////////////////////////////////////////////////////
/* ________________________________________________________________________ */
/*                          206. Reverse Linked List                        */

// Iterative Method
class Solution_206_Itr {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev, * curr, * next;
        prev = nullptr;
        curr = head;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
};

// Recursive Method
class Solution_206_Rec {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode* revHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return revHead;
    }
};


int main()
{
    return 0;
}

