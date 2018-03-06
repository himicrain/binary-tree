#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;
    
    // TODO your code for KeyValuePair goes here

public:
    //初始化
    KeyValuePair<Key,Value>(Key k, Value v):k(k){
        this->v = v;
    };
    KeyValuePair<Key,Value>( Key k):k(k){
    };
    //重载<运算符
    bool operator<(const KeyValuePair<Key, Value> other){
        return (this->k < other.k);
    };
    
    
    
};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:
    
    KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    void write(ostream & o) const {
        tree.write(o);
    }
    
    // TODO your code for TreeMap goes here:

    //递归调用node节点的find函数
    KeyValuePair<Key,Value>* find(Key k){
        return &(this->tree.find(KeyValuePair<Key,Value>(k))->data);
    }
    
    
    
};


// do not edit below this line

#endif