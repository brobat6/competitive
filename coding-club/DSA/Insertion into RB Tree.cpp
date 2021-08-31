#include <iostream>
#include <cassert>
using namespace std;

#define RED true
#define BLACK false

// NODE - key, left, right, color
// Insert operation - takes KEY as argument. 
// TREE - root(ptr), count

template <class T>
class TreeNode
{
private:
    // root
    // 
    T data;
    TreeNode<T> *right;
    TreeNode<T> *left;
    bool color;

    bool isRed(TreeNode<T> *x)
    {
        if (x == nullptr)
            return false;
        return (x->color == RED);
    }

    TreeNode<T>* RotateLeft(TreeNode<T>* h)
    {
        assert(isRed(h->right));
        TreeNode<T> *x = h->right;
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    TreeNode<T> *RotateRight(TreeNode<T> *h)
    {
        assert(isRed(h->right));
        TreeNode<T> *x = h->left;
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    void FlipColors(TreeNode<T> *h)
    {
        assert(!isRed(h));
        assert(isRed(h->left));
        assert(isRed(h->right));
        h->color = RED;
        h->left->color = BLACK;
        h->right->color = BLACK;
    }

public:
    TreeNode(T val) : data{val}, right{nullptr}, left{nullptr}, color{RED} {}

    TreeNode<T> *Insert(TreeNode<T> *h, T val)
    {
        if (h == nullptr)
            return new TreeNode<T> *(val);
        if (val < h->data)
            h->left = Insert(h->left, val);
        else if (val > h->data)
            h->right = Insert(h->right, val);

        if (isRed(h->right) && !isRed(h->left))
            h = RotateLeft(h);
        if (isRed(h->left) && isRed(h->left->left))
            h = RotateRight(h);
        if (isRed(h->left) && isRed(h->right))
            FlipColors(h);

        return h;
    }

    void PrintTree(TreeNode<T>* h, int level) {
        if(h==nullptr) return;
        cout << "At level - " << level << ", value - " << h->data;
        PrintTree(h->left, level + 1);
        PrintTree(h->right, level + 1);
    }
};

int main() {
    TreeNode<int> t;
}