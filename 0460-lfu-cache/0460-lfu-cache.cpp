class Node {
public:
    int key;
    int val;
    int freq;
    
    Node* prev = NULL;
    Node* next = NULL;
    
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        freq = 1;
    }    
};

// List is a Doubly Linked List
class List {
public:
    int size;
    Node *head;
    Node *tail;
    
    List() {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addFront(Node *newNode) {
        Node *tmp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = tmp;
        tmp->prev = newNode;
        ++size;
    }
    
    void removeNode(Node *tar) {
        Node *tarNext = tar->next;
        Node *tarPrev = tar->prev;
        tarNext->prev = tarPrev;
        tarPrev->next = tarNext;
        --size;
    }    
    
};

class LFUCache {
private:
    int maxCap;     
    int minFreq;    
    int currCap;    
    
    map<int, Node*> keyNodeMap;
    map<int, List*> freqListMap;
    
    void updateFreqListMap(Node *node) {
        keyNodeMap.erase(node->key);
        freqListMap[node->freq]->removeNode(node);
        
        if(node->freq == minFreq && freqListMap[node->freq]->size == 0) {
            ++minFreq;
        }
        
        List *nextHigherFreqList = new List();
        
        if(freqListMap.find(node->freq + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->freq + 1];
        }
        
        node->freq += 1;
        
        nextHigherFreqList->addFront(node);
        
        freqListMap[node->freq] = nextHigherFreqList;
        keyNodeMap[node->key] = node;        
    }
    
public:
    LFUCache(int capacity) {
        maxCap = capacity;
        minFreq = 0;
        currCap = 0;
    }
    
    int get(int key) {
        int res = -1;
        if(keyNodeMap.find(key) != keyNodeMap.end()) {
            Node *node = keyNodeMap[key];
            res = node->val;
            updateFreqListMap(node);
        }
        return res;
    }
    
    void put(int key, int value) {
        if(maxCap == 0) return;
        
        if(keyNodeMap.find(key) != keyNodeMap.end()) {
            Node *node = keyNodeMap[key];
            node->val = value;
            updateFreqListMap(node);
            return;
        }
        else {
            if(currCap == maxCap) {
                List *tmp = freqListMap[minFreq];
                keyNodeMap.erase(tmp->tail->prev->key);
                freqListMap[minFreq]->removeNode(tmp->tail->prev);
                --currCap;
            }
            
          
            
            minFreq = 1;
            
            List *minFreqList = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                minFreqList = freqListMap[minFreq];
            }
                
            Node *node = new Node(key, value);
            
            minFreqList->addFront(node);
            keyNodeMap[key] = node;
            freqListMap[minFreq] = minFreqList;
            
            ++currCap;
        }
    }
};