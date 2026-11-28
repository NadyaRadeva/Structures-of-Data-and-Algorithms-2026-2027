class LRUCache {
public:
    struct Node {
        int key, value;
        Node *prev, *next;

        Node(int key, int value)
            : key(key), value(value), prev(NULL), next(NULL) {}
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    void insert(Node* node) {
        Node* n = head->next;

        head->next = node;
        node->prev = head;
        node->next = n;
        n->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            remove(node);
            insert(node);
            return;
        }

        if (mp.size() == capacity) {
            Node* node = tail->prev;

            remove(node);
            mp.erase(node->key);
            delete node;
        }

        Node* node = new Node(key, value);

        insert(node);
        mp[key] = node;
    }
};
