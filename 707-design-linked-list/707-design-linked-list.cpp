class MyLinkedList {
public:
    vector <int> LL;
    
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if(index < LL.size()){ 
        return LL[index];}
        else
            return -1;
    }
    
    void addAtHead(int val) {
        auto itPos = LL.begin() ;
       LL.insert(itPos,val);
    }
    
    void addAtTail(int val) {
         LL.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index <= LL.size()){ 
        auto itPos = LL.begin() +index;
       LL.insert(itPos,val);
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index < LL.size()){ 
        auto itPos = LL.begin() +index;
       LL.erase(itPos);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */