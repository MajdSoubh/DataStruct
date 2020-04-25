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
        {
            if(node->left==NULL&&node->right==NULL)
            {

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

    void clear()
    {
        clear(root);
        //delete root;
        root=NULL;

    }
    Bstnode* clear(Bstnode* node)
    {

        if(node==NULL)
            return NULL;
        clear(node->left);
        clear(node->right);
        delete node;


    }

    int height(Bstnode* node)
    {
        if(node==NULL)
            return 0;
        int left=height(node->left);
        int right=height(node->right);
        int maxheight=max(left,right)+1;
        return maxheight;

    }

    int height()
    {
        return height(root);
    }
    int balancefac(Bstnode* node)
    {
        return (height(node->left)-height(node->right));


    }

    Bstnode* LLrot(Bstnode* node)
    {
        Bstnode* temp=node->left;
        node->left=NULL;
        if(temp->right!=NULL)
        {
            node->left=temp->right;
        }
        temp->right=node;
        return temp;


    }

    Bstnode* LRrot(Bstnode* node)
    {
        Bstnode* node2=node->left;
        Bstnode* node3=node2->right;
        node->left=NULL;
        node2->right=NULL;
        if(node3->left!=NULL)
            node2->right=node3->left;


        if(node3->right!=NULL)
        {

            node->left=node3->right;

        }
        node3->left=node2;
        node3->right=node;
        return node3;

    }
    Bstnode* RRrot(Bstnode* node){
    Bstnode* node2=node->right;
    node->right=NULL;
    if(node2->left!=NULL)
        node->right=node2->left;
    node2->left=node;
    return node2;
    }

    Bstnode* RLrot(Bstnode* node){
    Bstnode* node2=node->right;
    Bstnode* node3=node2->left;
    node->right=NULL;
    node2->left=NULL;
    if(node3->left!=NULL)
        node->right=node3->left;
    if(node3->right!=NULL)
        node2->left=node3->right;
    node3->left=node;
    node3->right=node2;
    return node3;
    }
    Bstnode* rebalance(Bstnode* node)
    {
        if(node==NULL)
            return NULL;
        node->left=rebalance(node->left);
        node->right=rebalance(node->right);
        if(balancefac(node)>1)
        {
            if(balancefac(node->left)>=0)
            {
                return (LLrot(node));


            }
            else
            {
                return (LRrot(node));
            }

        }
        if(balancefac(node)<-1)
        {
            if(balancefac(node->right)<=0)
            {
                return (RRrot(node));
            }
            else
                return (RLrot(node));
        }
        return node;






    }
    void rebalance()
    {
        root=rebalance(root);
    }



};

int main()
{
    Bst <int>tree;
    tree.insert(40);
    tree.insert(39);
    tree.insert(60);
    tree.insert(50);
    tree.insert(61);
    tree.insert(49);
    tree.insert(51);
    cout<<"Befor Balance : "<<endl;
    tree.display('l');
    cout<<endl<<"After Balance : "<<endl;
    tree.rebalance();
    tree.display('l');

}




