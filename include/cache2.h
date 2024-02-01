#include <vector>
#include <algorithm>
#include <mutex>
#include <iostream>
#include <type_traits>
#include <vector>
#include <stdexcept>

template <typename Key, typename Value,
          typename = std::enable_if_t<std::is_default_constructible_v<Key> && std::is_default_constructible_v<Value>>>
class LRUCache
{
private:

    struct Node
    {
        Key key;
        Value value;
        Node* next;
        Node* prev;
    };

    Node* head;
    size_t capacity;
    std::mutex mutex_;

public:

    explicit LRUCache(size_t capacity) : head(nullptr), capacity(capacity) {}

    ~LRUCache()
    {

        Node* current = head;
        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    Value get(const Key &key) {

        std::lock_guard<std::mutex> lock(mutex_);

        Node *current = head;
        
        while (current)
        {
            if (current->key == key)
            {
               
                if (current->prev)
                {
                    current->prev->next = current->next;
                    if (current->next)
                    {
                        current->next->prev = current->prev;
                    }
                    current->next = head;
                    current->prev = nullptr;
                    head->prev = current;
                    head = current;
                }
                return current->value;
            }
            current = current->next;
        }

        throw std::out_of_range("Key not found in the cache");
    }

    void put(const Key &key, const Value &value)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        Node* current = head;
        while (current)
        {
            if (current->key == key)
            {
                current->value = value;
                if (current->prev)
                {
                    current->prev->next = current->next;
                    if (current->next)
                    {
                        current->next->prev = current->prev;
                    }
                    current->next = head;
                    current->prev = nullptr;
                    head->prev = current;
                    head = current;
                }
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node{key, value, head, nullptr};
        if (head)
        {
            head->prev = newNode;
        }
        head = newNode;

    
        if (countNodes() > capacity)
        {
            Node* last = head;
            while (last->next)
            {
                last = last->next;
            }
            if (last->prev)
            {
                last->prev->next = nullptr;
            }
            delete last;
        }
    }

    void print()
    {
        std::lock_guard<std::mutex> lock(mutex_);

        Node* current = head;
        while (current)
        {
            std::cout << "Key: " << current->key << ", Value: " << current->value << std::endl;
            current = current->next;
        }
    }

private:
    size_t countNodes() const
    {
        size_t count = 0;
        Node* current = head;
        while (current)
        {
            ++count;
            current = current->next;
        }
        return count;
    }
};

