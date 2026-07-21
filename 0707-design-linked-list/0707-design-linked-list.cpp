class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;

    MyLinkedList() {
        head = NULL;
    }

    int get(int index) {
        Node* temp = head;

        for (int i = 0; temp != NULL && i < index; i++) {
            temp = temp->next;
        }

        if (temp == NULL)
            return -1;

        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; temp != NULL && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {

        if (head == NULL)
            return;

        if (index == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        Node* temp = head;

        for (int i = 0; temp->next != NULL && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp->next == NULL)
            return;

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna