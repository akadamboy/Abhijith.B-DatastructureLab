#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
}node;

node *create();
void insert(node *,node *);
void preorder(node *);
void inorder(node *);
node *root=NULL,*temp,*t1;


int main()
{
	char ch;
	//node *root=NULL,*temp,*t1;

	do
	{
		temp=create();
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);

		printf("\nDo you want to enter more(y/n)?");
		getchar();
		scanf("%c",&ch);
	}while(ch=='y'|ch=='Y');

	printf("\n Preorder Traversal: ");
	preorder(root);
	printf("\n inorder Traversal: ");
	inorder(root);
	printf("\n postorder Traversal: ");
	postorder(root);

	delete();

	printf("\n inorder Traversal: ");
	inorder(root);
	printf("\n postorder Traversal: ");
	postorder(root);
	printf("\n Preorder Traversal: ");
	preorder(root);
	return 0;
}

node *create()
{
	node *temp;
	printf("\nEnter data:");
	temp=(node*)malloc(sizeof(node));
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	return temp;
}

void insert(node *root,node *temp)
{
	if(temp->data<root->data)
	{
		if(root->left!=NULL)
			insert(root->left,temp);
		else
			root->left=temp;
	}

	if(temp->data>root->data)
	{
		if(root->right!=NULL)
			insert(root->right,temp);
		else
			root->right=temp;
	}
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


void inorder(node *root)
{
	if(root!=NULL)
	{
        inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}


void postorder(node *root)
{
	if(root!=NULL)
	{
        postorder(root->left);

		postorder(root->right);
		printf("%d ",root->data);
	}
}


void delete()
{
    int data;

    if (root == NULL)
    {
        printf("No elements in a tree to delete");
        return;
    }
    printf("\nEnter the data to be deleted : ");
    scanf("%d", &data);
    search1(root, data);
}

/* Search for the node to be deleted */
void search1(node *t, int data)
{
    if ((data>t->data))
    {
        t1 = t;
        search1(t->right, data);
    }
    else if ((data < t->data))
    {
        t1 = t;
        search1(t->left, data);
    }
    else if ((data==t->data))
    {
        delete1(t);
    }
}


/* To delete a node */
void delete1(node *t)
{
    int k;

    /* To delete leaf node */
    if ((t->left == NULL) && (t->right == NULL))
    {
        if (t1->left == t)
        {
            t1->left = NULL;
        }
        else
        {
            t1->right = NULL;
        }
        t = NULL;
        free(t);
        return;
    }

    /* To delete node having one left hand child */
    else if ((t->right == NULL))
    {
        if (t1 == t)
        {
            root = t->left;
            t1 = root;
        }
        else if (t1->left == t)
        {
            t1->left = t->left;

        }
        else
        {
            t1->right = t->left;
        }
        t = NULL;
        free(t);
        return;
    }

    /* To delete node having right hand child */
    else if (t->left == NULL)
    {
        if (t1 == t)
        {
            root = t->right;
            t1 = root;
        }
        else if (t1->right == t)
            t1->right = t->right;
        else
            t1->left = t->right;
        t == NULL;
        free(t);
        return;
    }

    /* To delete node having two child */
    else if ((t->left != NULL) && (t->right != NULL))
    {
         k = smallest(t->right);
        search1(root, k);
        t->data = k;
    }
}


int smallest(node *t)
{

    if (t->left != NULL)
    {

        return(smallest(t->left));
    }
    else
        return (t->data);
}
