
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

struct min_heap
{
    int *arr;
    int size,capacity;
    min_heap(int c)
    {
        arr = new int[c];
        capacity = c;
        size=0;
    }
    int left_child(int i){return 2*i+1;}
    int right_child(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}

    void heapify(int i)
    {
        int left = left_child(i);
        int right = right_child(i);
        int smaller = i;
        if(left<size && arr[left]<arr[smaller])
        {
            smaller = left;
        }
        if(right<size && arr[right]<arr[smaller])
        {
            smaller = right;
        }
        if(smaller!=i)
        {
            swap(arr[i],arr[smaller]);
            heapify(smaller);
        }
    }
    void build_heap()
    {
        for(int i=(size-2)/2;i>=0;i--)
        {
            heapify(i);
        }
    }

    int get_min(){ return arr[0];}
    void extract_min()
    {
        swap(arr[0],arr[size-1]);
        size--;
        heapify(0);
    }
    void insert_(int x)
    {
        arr[size]=x;
        size++;
        int i=size-1;
        while(i>0 && arr[i]<arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }

    }
    void delete_(int i)
    {
        decrease_key(i,INT_MIN);
        extract_min();

    }
    void decrease_key(int i,int x)
    {
        arr[i]=x;
        while(i>0 && arr[i]<arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i = parent(i);
        }
    }
    void display()
    {
        for(auto i=0;i<size;i++)
            cout<<arr[i]<<" ";
    }
    void heap_sort()
    {
        build_heap();
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        int temp = size;
        for (int i=temp-1; i>=0; i--)
        {
            // Move current root to end
            swap(arr[0], arr[i]);
            size--;

            // call max heapify on the reduced heap
            heapify(0);
        }
        size=temp;
    }

};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    min_heap mh(53);
    mh.insert_(11);
    mh.insert_(221);
    mh.insert_(13);
    mh.insert_(420);
    mh.insert_(5);
    mh.display();
    cout<<endl;
    mh.heap_sort();
    mh.display();
//    mh.delete_(2);
//    cout<<mh.get_min()<<endl;
//    mh.extract_min();
//    cout<<mh.get_min()<<endl;
//    mh.decrease_key(0,1);
//    for(int i=0;i<mh.size;i++)
//        cout<<mh.arr[i]<<" ";


    return 0;
}
