#include <iostream>

template <class T>
class LinkedList
{
    struct Node
    {
        T data = nullptr;
        Node* next = nullptr;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    LinkedList(const LinkedList<T>& ll) = delete;
    LinkedList& operator=(LinkedList const&) = delete;
    ~LinkedList();
    void insert(T);
    void display(std::ostream& out = std::cout) const
    {
        Node* node = head;
        while (node != nullptr)
        {
            out << node->data << " ";
            node = node->next;
        }
    }
    void insertionSort();
    void sortedInsert(struct Node** head_ref, struct Node* new_node);

    void deleteNodeNumber(size_t number);

    void deleteNode(T);
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& ll);

private:
    struct Node* search(T n)
    {                            
        Node* node = head;
        while (node != nullptr)
        {
            if (node->data == n)
                return node;
            node = node->next;
        }

        //std::cout << "������� �� ������" << std::end;
        return nullptr;
    }

};

template <class U>
std::ostream& operator<<(std::ostream& os, const LinkedList<U>& ll)
{
    ll.display(os);
    return os;
}

template <class T>
void LinkedList<T>::sortedInsert(struct Node** head_ref, struct Node* new_node)
{
    struct Node* current;
    // ������ ������
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        // ������ ���� ����� ��������
        current = *head_ref;
        while (current->next != NULL &&
            current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// ���������� ���������
template <class T>
void LinkedList<T>::insertionSort() {
    
    Node** head_ref = &head;

    // ������������� 
    struct Node* sorted = NULL;

    // ������� �� ���� ����� � ������� �� � ��������������� ������
    struct Node* current = *head_ref;
    while (current != NULL)
    {
        // ��������� ����
        struct Node* next = current->next;

        // ��������� ������� ����
        sortedInsert(&sorted, current);

        // ��������� ������� ����
        current = next;
    }

    // ��������� ������ ������
    *head_ref = sorted;
}

template <class T>
void LinkedList<T>::insert(T data)
{
    Node* t = new Node(data);
    Node* tmp = head;
    if (tmp == nullptr)
    {
        head = t;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = t;
    }
}

template <class T>
void LinkedList<T>::deleteNode(T data)
{
    Node* node = search(data);
    Node* tmp = head;

    if (tmp == node)
    {
        head = tmp->next;
    }
    else if (node != nullptr)
    {
        while (node != nullptr)
        {
            if (tmp->next == node)
            {
                tmp->next = node->next;
                return;
            }
            tmp = tmp->next;
        }
        delete tmp;
    }
}

template <class T>
void LinkedList<T>::deleteNodeNumber(size_t number)
{    
    if (number == 0) {
        Node* newHead = head->next;
        delete head;
        this->head = newHead;
        return;
    }

    Node* prev = head;
    Node* node = head->next;
    size_t n = 1;

    while (node != nullptr) {
        if (n == number) {
            prev->next = node->next;
            delete node;
            return;
        }        
        prev = prev->next;
        node = node->next;
        n++;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node* tmp = nullptr;
    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    head = nullptr;
}