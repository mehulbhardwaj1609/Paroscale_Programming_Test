//In the fiunction remove_data(), we should check whether the head is NULL before trying to access its data.
int remove_data() {
    if (head == NULL) {
        return -1; 
    }
    Node *temp = head;
    int data = temp->data;
    head = head->next;
    free(temp); 
    count--;
    return data;
}


//In main() function we need to destroy empty and full buffer after the work is done to reease memory occupied

sem_destroy(&full);
sem_destroy(&empty);




