#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void printInorder (struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder (node->left);
 
    /* then print the data of node */
    printf("%d ", node->data);
 
    /* now recur on right child */
    printInorder (node->right);
}
Node *  binaryTreeToBST (Node *root);
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     Node *res = binaryTreeToBST (root);
     printInorder(res);
     cout<<endl;
    // cout << endl;
  }
  return 0;
}



/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*Your code here*/

void inOrder(Node* root,vector<int> &v){
    if(root==NULL)
        return;
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}

void inOrder1(Node* root,vector<int> &v,int ind){
    if(root==NULL){
        return;
    }
    inOrder1(root->left,v,ind);
    vector<int>::iterator it=v.begin();
    root->data=*it;
    v.erase(it);
    inOrder1(root->right,v,ind);
}

Node *binaryTreeToBST (Node *root){
    vector<int> v;
    inOrder(root,v);
    sort(v.begin(),v.end());
    /*for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;*/
    inOrder1(root,v,0);
    return root;
}
 
