#ifndef TREE_H
#define TREE_H

#include "treenode.h"
using namespace std;

// TODO your code goes here:
template<typename Data>
class BinarySearchTree{
private:
    unique_ptr<TreeNode<Data> > root;

public:
    BinarySearchTree(){
        this->root.reset(nullptr);
    }
    void write(ostream &o) const {
        this->root->write(o);
    };
    //递归查找data的节点
    TreeNode<Data>* findByData(TreeNode<Data>*& p,Data data){
        if(p!=nullptr){
            //如果所查找的打他小于该节点的data，那么继续在该节点下的leftchild下寻找
            if(data < p->data){
                if(p->leftChild != nullptr){
                    TreeNode<Data>* ps = p->leftChild.get();
                    return this->findByData(ps,data);
                }else{
                    return nullptr;
                }
            //如果大于该节点的data，那么在该节点的right child处继续寻找
            }else if (p->data < data){
                //如果右孩子不是空的，那么寻找
                if(p->rightChild != nullptr){
                    TreeNode<Data>* ps = p->rightChild.get();
                    return this->findByData(ps,data);
                //如果是空的，那么返回nullptr
                }else{
                    return nullptr;
                }
            }else {
                return p;
            }
        }
    };
    TreeNode<Data>* find(Data data){
        //如果root是空的，那么返回nullptr
        if(this->root.get() == nullptr){
            return nullptr;
        }else{
            TreeNode<Data>* ps = this->root.get();
            //寻找
            return this->findByData(ps,data);
        }
    };

    TreeNode<Data>* insertByData(TreeNode<Data>*& p,Data data){
        if(p!=nullptr){
            //如果所查找的打他小于该节点的data，那么继续在该节点下的leftchild下寻找插入
            if(data < p->data){
                if(p->leftChild != nullptr){
                    TreeNode<Data>* ps = p->leftChild.get();
                    this->insertByData(ps,data);
                }else{
                    TreeNode<Data>* temp = new TreeNode<Data>(data);
                    p->setLeftChild(temp);
                }
            //同理在right下选找插入
            }else if (p->data < data){
                if(p->rightChild != nullptr){
                    TreeNode<Data>* ps = p->rightChild.get();
                    this->insertByData(ps,data);
                }else{
                    TreeNode<Data>* temp = new TreeNode<Data>(data);
                    p->setRightChild(temp);
                }
                //相等，那么返回该节点
            }else {
                return p;
            }
        }
    };

    TreeNode<Data>* insert(Data data){
        if(this->root.get() == nullptr){
            this->root.reset(new TreeNode<Data>(data));
        }else{
            TreeNode<Data>* ps = this->root.get();
            this->insertByData(ps,data);
        }
    };

};


// do not edit below this line

#endif