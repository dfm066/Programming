#include "btree.h"
#include <iostream>
#include <stack>

btree::btree()
{
  root=nullptr;
}
btree::~btree()
{
  delete(root);
}

void btree::destroy_tree(node *leaf)
{
  if(leaf!=nullptr)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=nullptr)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=nullptr;    //Sets the left child of the child node to nullptr
      leaf->left->right=nullptr;   //Sets the right child of the child node to nullptr
    }
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=nullptr)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=nullptr;  //Sets the left child of the child node to nullptr
      leaf->right->right=nullptr; //Sets the right child of the child node to nullptr
    }
  }
}

node *btree::search(int key, node *leaf)
{
  if(leaf!=nullptr)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return nullptr;
}

void btree::insert(int key)
{
  if(root!=nullptr)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=nullptr;
    root->right=nullptr;
  }
}

node *btree::search(int key)
{
  return search(key, root);
}
void btree::preorder(node *root){
    if(root!=nullptr){
        std::cout<<root->key_value<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}
void btree::preorder(){
    preorder(root);
}

void btree::inorder(node *root){
    if(root!=nullptr){
        inorder(root->left);
        std::cout<<root->key_value<<" ";
        inorder(root->right);
    }
    return;
}
void btree::inorder(){
    inorder(root);
}
void btree::postorder(node *root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
         std::cout<<root->key_value<<" ";
    }
    return;
}
/*  Recursive
void btree::postorder(){
    postorder(root);
}
*/
/*Iterative */

void btree::postorder(){
   /* Using 2 Stacks
    std::stack<node*> st1,st2;
    st1.push(root);
    node *tmp;
    while(!st1.empty()){
        tmp  = st1.top();
        st1.pop();
        if(tmp->left!=nullptr)
            st1.push(tmp->left);
        if(tmp->right!=nullptr)
            st1.push(tmp->right);
        st2.push(tmp);
    }
    while(!st2.empty()){
        tmp = st2.top();
        std::cout<<tmp->key_value<<" ";
        st2.pop();
    }
    */

    /* using 1 Stack*/
    if(root==nullptr)
        return;
    std::stack<node*> st;
    node *rt = root;
    do{
        while(rt){
            if(rt->right!=nullptr)
                st.push(rt->right);
            st.push(rt);
            rt = rt->left;
        }
        rt = st.top();
        st.pop();
        if(rt->right!=nullptr && rt->right == st.top()){
            st.pop();
            st.push(rt);
            rt = rt->right;
        }
        else{
            std::cout<<rt->key_value<<" ";
            rt = nullptr;
        }
    }while(!st.empty());

}

void btree::destroy_tree()
{
  destroy_tree(root);
}
