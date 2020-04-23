#include<iostream>
#include<queue>
using namespace std;

template <class T>
class Bst
{
    struct Bstnode
    {
        T item;
        Bstnode* left;
        Bstnode* right;

    };
    Bstnode* root=NULL;
public:
    Bst():root(NULL) {}

    Bstnode* insert(T data,Bstnode* node)
    {
        if (node==NULL)
        {
            node=new Bstnode;
            node->item=data;
            node->left=node->right=NULL;

        }
        else if(data<=node->item)
        {
            node->left=insert(data,node->left);
        }
        else if(data>node->item)
        {
            node->right=insert(data,node->right);


        }
        return node;
    }

    void preorder(Bstnode *node)
    {
        if(node!=NULL)
        {
            cout<<node->item<<" ";
            preorder(node->left);
            preorder(node->right);

        }



    }

    void inorder(Bstnode *node)
    {
        if(node!=NULL)
        {
            inorder(node->left);
            cout<<node->item<<" ";
            inorder(node->right);

        }

    }
    void levelorder(Bstnode* node)
    {
        if(node!=NULL)
        {
            queue <Bstnode*>q;
            q.push(node);
            while(!q.empty())
            {
                Bstnode* curr=q.front();
                cout<<curr->item<<" ";
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                q.pop();


            }



        }
    }

    void display(char c)
    {
        switch(c)
        {
        case 'p':
            cout<<"Pre Order : ";
            preorder(root);
            break;
        case 'i':
            cout<<"In Order : ";
            inorder(root);
            break;
        case 'l':
            cout<<"Level Order : ";
            levelorder(root);
            break;
        default :
            cout<<"expect p,i or l";


        }

    }
    void insert(T data)
    {
        root=insert(data,root);
    }
    bool search(T data)
    {
        return(search(data,root));

    }





    bool search(T data,Bstnode* node)
    {
        if(node==NULL)
            return false;
        else if(data==node->item)
            return true;
        else if(data<node->item)
        {
            return(search(data,node->left));

        }
        else if(data>node->item)
        {
            return(search(data,node->right));

        }


    }


    Bstnode* findmin(Bstnode* node)
    {
        if(node->left==NULL)
            return node;
        else
            findmin(node->left);




    }

    Bstnode* findmax(Bstnode* node)
    {
        if(node->right==NULL)
            return node;
        else findmax(node->right);


    }

    T findmin()
    {
        return findmin(root)->item;


    }

    T findmax()
    {
        return findmax(root)->item;

    }

    Bstnode* remove(T data,Bstnode* node)
    {
        if(node==NULL)
            return NULL;
        else if(data<node->item)
        {

            node->left=remove(data,node->left);
        }
        else if(data>node->item)
        {
            node->right=remove(data,node->right);
        }
        else
        {   if(node->left==NULL&&node->right==NULL){

        delete node;
        node=NULL;


        }
           else if(node->left==NULL)
            {
                Bstnode* temp=node;
                node=node->right;
                delete temp;
            }
            else if(node->right==NULL)
            {
               Bstnode* temp=node;
               node=node->left;
               delete temp;

            }
            else
            {
                Bstnode* temp=findmin(node->right);
                node->item=temp->item;
               node->right=remove(node->item,node->right);

            }



        }
return node;

    }


    void remove(T data)
    {
       root=remove(data,root);
    }

    void clear(){
    clear(root);
   //delete root;
   root=NULL;

    }
Bstnode* clear(Bstnode* node){

if(node==NULL)
    return NULL;
clear(node->left);
clear(node->right);
delete node;


}

int height(Bstnode* node){
if(node==NULL)
    return 0;
int left=height(node->left);
int right=height(node->right);
int maxheight=max(left,right)+1;
return maxheight;

}

int height(){
return height(root);
}
};

int main()
{
    Bst <int>tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);
    tree.insert(2);
    tree.display('l');
    cout<<endl;
    tree.display('i');
    cout<<endl;
    tree.display('p');
    cout<<endl;
    tree.remove(3);
    cout<<"After Remove 3\n";
    tree.display('l');
cout<<"\nMax Height : "<<tree.height();
cout<<endl<<"Max : "<<tree.findmax();
cout<<endl<<"Min : "<<tree.findmin();

}




