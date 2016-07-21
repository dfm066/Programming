#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

struct node
{
  int key_value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node *search(int key);
        node* get_root();
        void destroy_tree();
        void  preorder();
        void  inorder();
        void  postorder();
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        void  preorder(node *root);
        void  inorder(node *root);
        void  postorder(node *root);
        node *root;
};

#endif // BTREE_H_INCLUDED
