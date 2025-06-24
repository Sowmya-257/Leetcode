class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* curr=head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                Node* next=curr->next;
                curr->next=flatten(curr->child);
                
                curr->next->prev=curr;
                curr->child=NULL;

                // find tail
                while(curr->next!=NULL){
                    curr=curr->next;
                }
                // attach tail
               if(next!=NULL){
                 curr->next=next;
                next->prev=curr;

               }
                
            }
            curr=curr->next;           
        }
        return head;
    }
};