#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:
template<typename Data>
class TreeNode{
    public:
        Data data;
        unique_ptr<TreeNode<Data> > leftChild;
        unique_ptr<TreeNode<Data> > rightChild;
        TreeNode<Data>* parent;
    public:
        TreeNode();
        TreeNode(Data data):data(data){
            parent = nullptr;
        };
        //设置left child
        void setLeftChild(TreeNode<Data>* child){
            this->leftChild.reset(child);
            this->leftChild->parent = this;
        };
        //设置right child
        void setRightChild(TreeNode<Data>* child){
            this->rightChild.reset(child);
            this->rightChild->parent = this;
        };
        //按照文档
        void write(ostream & o) const {
            if(this->leftChild != nullptr){
                this->leftChild->write(o);
            }
            o<<" ";
            o<<data;
            o<<" ";
            if(this->rightChild != nullptr){
                this->rightChild->write(o);
            }
        };


};

// do not edit below this line

#endif