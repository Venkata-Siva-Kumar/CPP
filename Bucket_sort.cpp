/* BUCKET SORT */
#include<iostream>
#include<ctime>
float a[100],s[100];
using namespace std;
int n,count =0;

struct node 
{
    float val;
    struct node * next;
};
struct node * b[100];

void print()
{
    struct node * t;
    int j=1;
    for(int i=0;i<n;i++)
    {
        if(b[i]!=NULL)
        {
            cout<<"Bucket "<<i<<" : ";
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

void insertion_sort(float s[],int n1)
{
    float key;
    int j;
    for(int i=2;i<=n1;i++)
    {
        key = s[i];
        j = i-1;
        while(j>=0 and s[j]>key)
        {
            count++;
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = key;
    }
}
void bucket_sort()
{
    struct node * temp,*curr;
    int p;

    for(int i=0;i<n;i++)
        b[i] = NULL;
    for(int i=1;i<=n;i++)
    {
        count++;
        temp = new node;
        temp->val = a[i];
        temp->next = NULL;
        p = (n*a[i]);
        if(b[p]==NULL)
            b[p] = temp;
        else
        {
            for(curr=b[p];curr->next!=NULL;curr=curr->next);
            curr->next = temp;
        }
    }

    cout<<"Before Sorting\n";
    print();

    struct node * t;
    int j,total;
    for(int i=0;i<n;i++)
    {
        count++;
        if(b[i]!=NULL)
        {
            for(t=b[i],j=1;t!=NULL;t=t->next,j++)
                s[j] = t->val;
            total = j-1;
            insertion_sort(s,total);
            for(t=b[i],j=1;t!=NULL;t=t->next,j++)
                t->val = s[j];
        }
    }
}
int main()
{
    cout<<"Enter the size of the bucket : ";
    cin>>n;
    srand(time(0));
    for(int i=1;i<=n;i++)
    {
        a[i] = (float) rand() / (float) RAND_MAX;
    }

    bucket_sort();
    cout<<"After Sorting\n";
    print();
    cout<<"\nCount : "<<count<<endl;
}
