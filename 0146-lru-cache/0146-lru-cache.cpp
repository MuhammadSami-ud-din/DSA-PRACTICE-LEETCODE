struct Node{
    int value;
    int key;
    Node* next;
    Node* prev;

    Node (int key , int value) : key(key) , value(value) , prev(nullptr) , next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int size = 0;
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

        tail->prev = head;
        head->next = tail;
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
        if (my_cache_map.find(key) != my_cache_map.end()){
            Node* node = my_cache_map[key];
            node->value = value;
            removeNode(node);
            addToFront(node);
            return;
        }

        if(size >= capacity){
            Node* node = tail->prev;
            removeNode(node);
            my_cache_map.erase(node->key);
            delete node;
            size--;
            
        }

        Node* node = new Node(key , value);
        my_cache_map[key] = node;
        addToFront(node);
        size++;


    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */