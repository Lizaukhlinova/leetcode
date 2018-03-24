/*
Given a linked list and a value x, partition it such that all nodes less than x come before 
nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * partition(ListNode * head, int x) {
    	if (head == NULL) 
    		return head;
    	ListNode * prev = (head->val < x) ? head : NULL;
    	ListNode * cur = head;
    	while (cur->next != NULL) {
	        if (cur->next->val < x) {
	        	if (prev == cur) { //nothing to change
	        		prev = prev->next;
	        		cur = cur->next;
	        		continue;
	        	}
	        	ListNode * temp = cur->next; //insert smaller node to correct place
	        	cur->next = cur->next->next;
	        	if (prev == NULL) { //correct place is head
	        		temp->next = head;
	        		head = temp;
	        		prev = head;
	        	} else { //correct place is in the middle
	        		temp->next = prev->next;
	        		prev->next = temp;
	        		prev = temp;
	        	}
	    		
	    	} else { //greater value, move forward
        		cur = cur->next;
        	}
	    }
    	return head;
    }

    void printList(ListNode * head) {
    	ListNode * cur = head;
    	while (cur != NULL) {
			cout << cur->val << ' ';
			cur = cur->next;
		}
		cout << endl;
    }
};

int main() {
	ListNode * head = new ListNode(2);
	ListNode * cur = head;
	for (int i = 3; i >= 0; i--) {
		ListNode * temp = new ListNode(i);
		cur->next = temp;
		cur = cur->next;
	}

	Solution s;	

	s.printList(head);

	head = s.partition(head, 2);
	
	s.printList(head);

	return 0;
}