#include <unordered_map>

// 1. Define the Node struct FIRST so the compiler knows it exists
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// 2. Then define your LRUCache class
class LRUCache {
private:
    int capacity;
    std::unordered_map<int, Node*> my_cache_map;
    Node* head;
    Node* tail;

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (my_cache_map.find(key) == my_cache_map.end()) {
            return -1;
        }
        Node* node = my_cache_map[key];
        removeNode(node);
        addToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (my_cache_map.find(key) != my_cache_map.end()) {
            Node* node = my_cache_map[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
            return;
        }

        if (my_cache_map.size() >= capacity) {
            Node* lruNode = tail->prev;
            removeNode(lruNode);
            my_cache_map.erase(lruNode->key);
            delete lruNode;
        }

        Node* newNode = new Node(key, value);
        my_cache_map[key] = newNode;
        addToFront(newNode);
    }
};