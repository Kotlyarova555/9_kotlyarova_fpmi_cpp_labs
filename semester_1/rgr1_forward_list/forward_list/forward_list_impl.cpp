#include "forward_list_impl.h"

// your code goes here
#include <stdexcept>

ForwardList::ForwardList() : head_(nullptr), size_(0) {
}

ForwardList::ForwardList(const ForwardList& rhs) : head_(nullptr), size_(0) {
    Node* current = rhs.head_;
    ForwardList temp; 

    while (current != nullptr) {
        Node* new_node = new Node(current->value_);
        new_node->next_ = temp.head_;
        temp.head_ = new_node;
        temp.size_++;
        current = current->next_;
    }

    current = temp.head_;
    while (current != nullptr) {
        Node* new_node = new Node(current->value_);
        new_node->next_ = head_;
        head_ = new_node;
        size_++;
        current = current->next_;
    }

}

ForwardList::ForwardList(size_t count, int32_t value) : head_(nullptr), size_(0) {
    for (size_t i = 0; i < count; ++i) {
        PushFront(value);
    }
}

ForwardList::ForwardList(std::initializer_list<int32_t> init) : head_(nullptr), size_(0) {
    for (auto it = init.end(); it != init.begin();) {
        --it;
        PushFront(*it);
    }
}

ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs) {
        return *this;  
    }

    Clear();

    Node* current = rhs.head_;
    ForwardList temp;  

    while (current != nullptr) {
        Node* new_node = new Node(current->value_);
        new_node->next_ = temp.head_;
        temp.head_ = new_node;
        temp.size_++;
        current = current->next_;
    }

    current = temp.head_;
    while (current != nullptr) {
        Node* new_node = new Node(current->value_);
        new_node->next_ = head_;
        head_ = new_node;
        size_++;
        current = current->next_;
    }

    return *this;
}

ForwardList::~ForwardList() {
    Clear();
}

void ForwardList::PushFront(int32_t value) {
    Node* new_node = new Node(value);
    new_node->next_ = head_;
    head_ = new_node;
    size_++;
}

void ForwardList::PopFront() {
    if (head_ == nullptr) {
        return;
    }

    Node* to_delete = head_;
    head_ = head_->next_;
    delete to_delete;
    size_--;
}

void ForwardList::Remove(int32_t value) {
    Node* current = head_;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->value_ == value) {
            Node* to_delete = current;

            if (prev == nullptr) {
                head_ = current->next_;
                current = head_;
            } else {
                prev->next_ = current->next_;
                current = current->next_;
            }

            delete to_delete;
            size_--;
        } else {
            prev = current;
            current = current->next_;
        }
    }
}

void ForwardList::Clear() {
    Node* current = head_;
    while (current != nullptr) {
        Node* next = current->next_;
        delete current;
        current = next;
    }
    head_ = nullptr;
    size_ = 0;
}

bool ForwardList::FindByValue(int32_t value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = current->next_;
    }
    return false;
}

void ForwardList::Print(std::ostream& out) {
    Node* current = head_;
    while (current != nullptr) {
        out << current->value_;
        if (current->next_ != nullptr) {
            out << " ";
        }
        current = current->next_;
    }
}

int32_t ForwardList::Front() const {
    if (head_ == nullptr) {
        throw std::runtime_error("List is empty");
    }
    return head_->value_;
}

size_t ForwardList::Size() const {
    return size_;
}
