#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define fo(i,n) for(int i=0;i<n;i++)
#define fof(i,a,b) for(int i=a;i<=b;i++)
#define Inf INFINITY
#define PI acos(-1)
typedef long long ll;

//Definition of Node for BST
struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

//Function to find minimum in a tree. 
BstNode* FindMin(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

//To create new node in heap
BstNode* GetNewNode(int data)
{
	BstNode* newnode = new BstNode();
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

//Function to visit nodes in Inorder
void Inorder(BstNode *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to Delete a node from BST
struct BstNode* Delete(struct BstNode *root, int data)
{
	if(root==NULL)return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if(data > root->data) root->right = Delete(root->right,data);
	else
	{
		//No child
		if(root->left==NULL and root->right==NULL){
			delete root;
			root = NULL;
		}
		//1 Children 
		else if(root->left == NULL){
			struct BstNode *temp = root;
			root = root->right;
			delete temp;
		} 
		else if(root->right == NULL){
			struct BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		//2 children
		else
		{
			struct BstNode *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
} 

// Insert the data in node
BstNode* insert(BstNode* root, int data)
{
	if(root==NULL){ //empty tree
		root = GetNewNode(data);
	}
	else if(data<=root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

//Search a number in BST
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    BstNode* root = NULL; //Creating empty tree;
    int n; //number of insertion
    cin>>n;
    fo(i,n)
    {
    	int num; //number to be inserted
    	cin>>num;
    	root = insert(root,num);
    }
    int x;
	//cout<<"Enter number be searched\n";
	cin>>x;
	//If number is found, print "FOUND"
	if(Search(root,x) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
	int del;cin>>del;
	root = Delete(root,del);
	cout<<"Inorder: ";
	Inorder(root);
	cout<<endl;
}

///Alhamdulillah
