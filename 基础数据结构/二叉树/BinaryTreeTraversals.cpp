#include <iostream>
#include <vector>

using namespace std;
struct node{
	int value;
    node* l;
    node* r;
};
node* solve(vector<int>&, vector<int>&, int, int, int, int);
void postTraverse(node *);
int main(int argc, char **argv){

    int n;
    cin >> n;
    vector<int> preorder;
    vector<int> inorder;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        preorder.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        inorder.push_back(x);
    }
    
    node *root = solve(preorder, inorder, 0, n, 0, n);
    postTraverse(root);
    return 0;
}

node* solve(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end){
    if(pre_start >= pre_end || in_start >= pre_end){
        return nullptr;
    }
    node *root = new node();
    root->value = preorder[pre_start];
    int pos; //当前子树在中序遍历中的位置
    for(int i = in_start; i < in_end; i++){
        if(root->value == inorder[i]){
            pos = i;
        }
    }
    root->l = solve(preorder, inorder, pre_start + 1, pre_start + pos - in_start + 1, in_start, pos);
    root->r = solve(preorder, inorder, pre_start + pos - in_start + 1, pre_end, pos + 1, in_end);
    return root;
}

void postTraverse(node *root){
    if(root == nullptr){
        return;
    }
    postTraverse(root->l);
    postTraverse(root->r);
    cout << root->value << " ";
}
