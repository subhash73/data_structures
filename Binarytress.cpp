#include <bits/stdc++.h>
using namespace std;
//class for node
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int val)
	{
		data = val;
		left=right=NULL;
	}
};
Node* InsertNode(Node *root, int data)
{
    if(root==NULL) 
    {
        root=new Node(data);
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) 
    {
        Node *temp=q.front();
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        else {
            temp->left=new Node(data);
            return root;
        }
        if(temp->right!=NULL)
            q.push(temp->right);
        else {
            temp->right=new Node(data);
            return root;
        }
    }
    return root;
}
//Inorder LDR
void Inorder(Node *temp)
{
    if (temp == NULL)
        return;
    Inorder(temp->left);
    cout<<temp->data << ' ';
    Inorder(temp->right);
}
//Preorder DLR
void Preorder(Node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << ' ';
    Preorder(temp->left);
    Preorder(temp->right);
}
//Postorder LRD
void Postorder(Node *temp)
{
    if (temp == NULL)
        return;
    Postorder(temp->left);
    Postorder(temp->right);
    cout << temp->data << ' ';
}
//Level order 
void Levelorder(Node *temp)
{
    if(temp==NULL)
       return;
    queue<Node*> q;
    q.push(temp);
    while(!q.empty()) 
    {
        Node *temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}
int main()
{
	Node *root=NULL;
	int ch,data;
	cout<<"---------------------Binary Trees Implementation----------------------------"<<endl;
	while(true)
	{
	    cout<<"********************************"<<endl;
	    cout<<"1.Insertion"<<endl;
	    cout<<"2.Inorder"<<endl;
	    cout<<"3.Preorder"<<endl;
	    cout<<"4.Postorder"<<endl;
	    cout<<"5.Levelorder"<<endl;
	    cout<<"---------------------------------"<<endl;
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:cout<<"Enter data for insertion"<<endl;
	               cin>>data;
	               root=InsertNode(root,data);
	               break;
	        case 2:cout<<"Inorder Traversal"<<endl;
	               Inorder(root);
	               cout<<endl;
	               break;
	        case 3:cout<<"Preorder Traversal"<<endl;
	               Preorder(root);
	               cout<<endl;
	               break;
	        case 4:cout<<"Postorder Traversal"<<endl;
	               Postorder(root);
	               cout<<endl;
	               break;
	        case 5:cout<<"Levelorder Traversal"<<endl;
	               Levelorder(root);
	               cout<<endl;
	               break;
	        default:exit(0);
	    }
	}
}
