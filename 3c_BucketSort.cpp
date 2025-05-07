//Bucket Sort
#include<iostream>
#include<ctime>
using namespace std;
int n,count = 0;
float a[100],s[100];
struct node
{
    float val;
    struct node * next;
};
struct node * b[100];
void print()
{
    struct node * t;
    int j = 0;
    for(int i=0;i<n;i++)
    {
        if(b[i]!= NULL)
        {
            cout<<"Bucket ["<<i<<"] : ";
            for(t=b[i];t!=NULL;t=t->next)
            {
                a[j++] = t->val;
                cout<<t->val<<"-->";
            }
            if(t==NULL)
                cout<<"NULL"<<endl;
        }
    }
}

void insertion(float a[],int n1)
{
    float key;
    int j;
    for(int i=2;i<=n1;i++)
    {
        key = a[i];
        j = i-1;
        while(j>0 && a[j]>key)
        {
            count++;
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
void bucket_sort()
{
    struct node *temp,*curr;
    for(int i=0;i<n;i++)
    {
        b[i] = NULL;
    }

    for(int i=1;i<=n;i++)
    {
        count++;
        temp = new node;
        temp->val = a[i];
        temp->next = NULL;
        int p = (n * a[i]);
        if(b[p]==NULL)
            b[p] = temp;
        else
        {
            for(curr=b[p];curr->next !=NULL;curr=curr->next);
            curr->next = temp;
        }
    }

    cout<<"***** Before Sorting *****"<<endl;
    print();

    struct node *t;
    int j = 0;
    for(int i=0;i<n;i++)
    {
        count++;
        for(temp=b[i],j=1;temp!=NULL;temp=temp->next,j++)
            s[j] = temp->val;
        int total = j-1;
        insertion(s,total);
        for(temp=b[i],j=1;temp!=NULL;temp=temp->next,j++)
            temp->val = s[j];
    }

    cout<<"***** After Sorting *****"<<endl;
    print();
}
int main()
{
    srand(time(0));
    cout<<"Enter the array size : ";
    cin>>n;
    
    cout<<"Inputs : ";

    for(int i=1;i<=n;i++)
    {
        a[i] = (float) rand() / (float) RAND_MAX;
    }
    
    bucket_sort();
    cout<<"Count : "<<count<<endl;
}
