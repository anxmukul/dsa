#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
};
node *create_node(int v)
{
    node *cur = new node();
    if (cur != NULL)
    {
        cur->left = cur->right = NULL;
        cur->data = v;
    }
    return cur;
}
vector<int> topView(node *root){
    vector <int> result;
    if(root == NULL){
        return result;
    }
    map <int, int> m;
    queue <pair<node *, int>> q;            //pair for storing node* and the horizontal height of that node;
    q.push({root,0});
    while(!q.empty()){
        node *temp = q.front().first;
        int horizontal_height_of_temp = q.front().second;
        q.pop(); //pop out from queue;
        if(!m[horizontal_height_of_temp]){              // IF 0 that means first occurance and this will be the required node
            m[horizontal_height_of_temp] = temp->data;
        }
        if(temp -> left){
            q.push({temp->left, horizontal_height_of_temp-1});
        }
        if(temp -> right){
            q.push({temp->right, horizontal_height_of_temp+1});
        }
    }
    // Itterate over map
    for(auto x:m){
        result.push_back(x.second);
    }
    return result;
}

int main()
{
    node *root = NULL;
    root = create_node(4);
    root->left = create_node(9);
    root->left->right = create_node(2);
    root->left->left = create_node(3);
    root->left->left->right = create_node(1);
    root->right = create_node(8);
    root->right->left = create_node(7);
    root->right->right = create_node(6);
	root->right->right->left = create_node(45);
    vector <int> res = topView(root);
    for(auto i=res.begin(); i<res.end(); i++){
        cout<<*i<<" ";
    }
	cout<<"\n";
	return 0;
}

//More approach are on geekforgeek

