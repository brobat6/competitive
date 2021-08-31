#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int elem;
    TreeNode* left;
    TreeNode* right;
};

int occurence(TreeNode* root, int num) {
    if(root!=NULL) {
        if(root->elem==num) return 1 + occurence(root->left, num) + occurence(root->right, num);
        else return occurence(root->left, num) + occurence(root->right, num);
    }
    return 0;
}

// vector<TreeNode*> rightMostPath(TreeNode* root) {
//     vector <TreeNode*> v;
//     if(root!=NULL) {
//         v.push_back(root);
//         vector <TreeNode*> temp = rightMostPath(root->right);
//         for(auto it: temp) v.push_back(it);
//     }
//     return v;
// }

vector<TreeNode*> rightMostPath(TreeNode* root) {
    vector <TreeNode*> v;
    while(root!=NULL) {
        v.push_back(root);
        root = root->right;
    }
    return v;
}

bool maxHeap(TreeNode* root) {
    if(root==NULL||root->right==NULL) return true;
    return (root->elem>=root->right->elem&&root->elem>=root->left->elem&&maxHeap(root->left)&&maxHeap(root->right));
}

int main() {
    TreeNode tr4 = {0,0,0};
    TreeNode tr5 = {0,0,0};
    TreeNode tr6 = {0,0,0};
    TreeNode tr7 = {0,0,0};
    TreeNode tr2 = {21, &tr4, &tr5};
    TreeNode tr3 = {15, &tr6, &tr7};
    TreeNode tr1 = {1600, &tr2, &tr3};
    // if(maxHeap(&tr1)) cout << "YES";
    // else cout << "NO";
    // cout << occurence(&tr1, 20) << endl;
    vector<TreeNode*> x;
    x = rightMostPath(&tr1);
    for(auto it: x) {
        cout << it->elem << " ";
    }
    cout << endl;
}