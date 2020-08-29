//use vector to implement hashtable
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int>HT;
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(int i=0;i<HT.size();i++){
            if(HT[i]==key)
                return ;
        }
        HT.push_back(key);
    }
    
    void remove(int key) {
        for(int i=0;i<HT.size();i++){
            if(HT[i]==key){
                for(int j=i+1;j<HT.size();j++){
                    HT[j-1]=HT[j];
                }
                HT.pop_back();
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int i=0;i<HT.size();i++){
            if(HT[i]==key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */