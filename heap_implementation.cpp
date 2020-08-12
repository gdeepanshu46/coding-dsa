#include <bits/stdc++.h>
using namespace std;

class Heap{
	vector<int> v;

public:
	int getMin(){
		return v[0];
	}

	int left_child(int i){return 2*i+1;}

    int right_child(int i){return 2*i+2;}
    
    int parent(int i){return (i-1)/2;}

	void heapify(int i)
    {
        int left = left_child(i);
        int right = right_child(i);
        int smaller = i;
        if(left < v.size() && v[left] < v[smaller])
        {
            smaller = left;
        }
        if(right < v.size() && v[right] < v[smaller])
        {
            smaller = right;
        }
        if(smaller!=i)
        {
            swap(v[i], v[smaller]);
            heapify(smaller);
        }
    }

    void build_heap(){
    	for (int i = (v.size()-2)/2; i>=0; i--){
    		heapify(i);
    	}
    }

	void extractMin(){
		swap(v[0], v[v.size()-1]);
		v.pop_back();
		heapify(0);
	}

	void insert(int key){
		v.push_back(key);

		int i = v.size()-1;
		int parent = (i-1)/2;

		while(i != 0){
			if(v[i] < v[parent]){
				swap(v[i], v[parent]);
			}
			i = parent;
			parent = (i-1)/2;
		}
	}

	void decreaseKey(int ind, int key){
		v[ind] = key;
		int i = ind;
		int parent = (i-1)/2;

		while(i != 0){
			if(v[i] < v[parent]){
				swap(v[i], v[parent]);
			}
			i = parent;
			parent = (i-1)/2;
		}
	}

	void delete_(int ind){
		decreaseKey(ind, INT_MIN);
		extractMin();
	}

	void heapSort(){
		while(!v.empty()){
			cout << getMin() << " ";
			extractMin();
		}
	}

	void display(){
		for(auto x: v)
			cout << x << " ";
		cout <<endl; 
	}
};






int main(){

	vector<int> v{4, 1, 2, 5, 6, 7};

	Heap h;
	h.insert(4);
	h.insert(1);
	h.insert(2);
	h.insert(8);
	h.insert(14);
	h.insert(11);
	h.insert(5);
	h.insert(9);
	h.display();
	cout << h.getMin() << endl;
	h.extractMin();
	h.display();
	cout << h.getMin() <<endl;

	h.heapSort();

	return 0;
}




int heap[5]; 

void heapify(int* v, int n, int i)
{
    int left = 2*i + 1;
    int right = 2*i + 2;
    int smaller = i;
    if(left < n && v[left] < v[smaller])
    {
        smaller = left;
    }
    if(right < n && v[right] < v[smaller])
    {
        smaller = right;
    }
    if(smaller!=i)
    {
        swap(v[i], v[smaller]);
        heapify(v, n, smaller);
    }
}

void build_heap(int* arr, int n){
	for(int i = (n-2)/2; i>=0; i--){
		heapify(arr, n, i);
	}
}

void traversal_(int )


int arr[5] = {1, 5, 2, 4, 3};

build_heap(arr, n);

traversal()



















