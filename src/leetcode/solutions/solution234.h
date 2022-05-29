#include <string>
#include <iostream>
#include <stack>


class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    void reverse(ListNode** ref_to_head) {

        ListNode* prev = nullptr;
        ListNode* current = *ref_to_head;
        ListNode* next;
         
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *ref_to_head = prev;
    }
    
    bool compareLists(ListNode* head1, ListNode* head2) {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
     
        while (temp1 && temp2)
        {
            if (temp1->val == temp2->val)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
                return 0;
        }
     
        // Both are empty return 1
        if (temp1 == nullptr && temp2 == nullptr)
            return true;
     
        // Will reach here when one is nullptr
        // and other is not
        return false;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *slow_ptr = head, *fast_ptr = head;
        ListNode *second_half, *prev_of_slow_ptr = head;
         
        // To handle odd size list
        ListNode* midnode = nullptr;
         
        // initialize result
        bool res = true;
     
        if (head != nullptr && head->next != nullptr)
        {
             
            // Get the middle of the list. Move slow_ptr by 1
            // and fast_ptr by 2, slow_ptr will have the middle
            // node
            while (fast_ptr != nullptr && fast_ptr->next != nullptr)
            {
                fast_ptr = fast_ptr->next->next;
     
                // We need previous of the slow_ptr for
                // linked lists with odd elements
                prev_of_slow_ptr = slow_ptr;
                slow_ptr = slow_ptr->next;
            }
     
            // fast_ptr would become nullptr when there
            // are even elements in list. And not nullptr
            // for odd elements. We need to skip the
            // middle node for odd case and store it
            // somewhere so that we can restore the
            // original list
            if (fast_ptr != nullptr)
            {
                midnode = slow_ptr;
                slow_ptr = slow_ptr->next;
            }
     
            // Now reverse the second half and
            // compare it with first half
            second_half = slow_ptr;
             
            // nullptr terminate first half
            prev_of_slow_ptr->next = nullptr;
             
            // Reverse the second half
            reverse(&second_half);
             
            // compare
            res = compareLists(head, second_half);
     
            // Construct the original list back
            reverse(&second_half); // Reverse the second half again
     
            // If there was a mid node (odd size case)
            // which was not part of either first half
            // or second half.
            if (midnode != nullptr)
            {
                prev_of_slow_ptr->next = midnode;
                midnode->next = second_half;
            }
            else
                prev_of_slow_ptr->next = second_half;
        }
        return res;
            
    }

    //second solution
    bool isPalindrome2(ListNode* head) {
             
            // Temp pointer
            ListNode* slow= head;
     
            // Declare a stack
            std::stack <int> s;
      
     
            // Push all elements of the list
            // to the stack
            while(slow != NULL){
                    s.push(slow->val);
     
                    // Move ahead
                    slow = slow->next;
            }
     
            // Iterate in the list again and
            // check by popping from the stack
            while(head != NULL ){
                 
                // Get the top most element
                 int i=s.top();
     
                 // Pop the element
                 s.pop();
     
                 // Check if data is not
                 // same as popped element
                if(head -> val != i){
                    return false;
                }
     
                // Move ahead
               head=head->next;
            }
     
    return true;
    }

    void test() {
        return;
    }
};