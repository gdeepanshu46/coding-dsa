#include <bits/stdc++.h>
using namespace std;

void build_tree(int* arr, int* tree, int start, int end, int tree_node){
	if(start == end){
		if(arr[start]%5 == 0)
			tree[tree_node] = 1;
		else 
			tree[tree_node] = 0;
		return;
	}

	int mid = (start + end)/2;

	build_tree(arr, tree, start, mid, tree_node*2 + 1);
	build_tree(arr, tree, mid + 1, end, tree_node*2 + 2);

	tree[tree_node] = tree[tree_node*2 + 1] + tree[tree_node*2 + 2];
}

void update(int* arr, int* tree, int start, int end, int tree_node, int index, int value){
	if(start == end){
		arr[index] = value;
		if(arr[index]%5 == 0)
			tree[tree_node] = 1;
		else
			tree[tree_node] = 0;
		return;
	}

	int mid = (start + end)/2;

	if(index <= mid){
		update(arr, tree, start, mid, tree_node*2 + 1, index, value);
	}
	else
		update(arr, tree, mid + 1, end, tree_node*2 + 2, index, value);

	tree[tree_node] = tree[tree_node*2 + 1] + tree[tree_node*2 + 2];
}

int query(int* tree, int start, int end, int q_start, int q_end, int tree_node){
	
	//completedly inside
	if(start >= q_start && end <= q_end)
		return tree[tree_node];

	//completedly outside
	if(start > q_end || end < q_start)
		return 0;

	//partially inside and outside

	int mid = (start + end)/2;
	int left = query(tree, start, mid, q_start, q_end, tree_node*2 + 1);
	int right = query(tree, mid + 1, end, q_start, q_end, tree_node*2 + 2);

	return left + right;
}


int main(){

	int arr[6] = {1, 5, 7, 10, 12, 15};
	int tree[24];

	build_tree(arr, tree, 0, 5, 0);

	cout << "prev array : ";
	// for(int i=0; i<5; i++)
	// 	cout << arr[i] << " ";
	cout << endl;

	// for(int i=0; i<11; i++)
	// 	cout << tree[i] << endl;
	update(arr, tree, 0, 5, 0, 2, 4);

	cout << "updated array : ";
	// for(int i=0; i<11; i++)
	// 	cout << arr[i] << " ";
	cout << endl;
	cout << "After updation" << endl;


	// for(int i=0; i<11; i++)
	// 	cout << tree[i] << endl;

	cout << "Sum btw 0 and 4 : " << query(tree, 0, 5, 0, 4, 0) << endl;
	cout << "Sum btw 1 and 3 : " << query(tree, 0, 5, 1, 3, 0) << endl;
	cout << "Sum btw 3 and 4 : " << query(tree, 0, 5, 3, 4, 0) << endl;
	return 0;
}