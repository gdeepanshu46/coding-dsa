#include <bits/stdc++.h>
using namespace std;

class lru_cache
{
	map<char, list<pair<char, int>>::iterator> mp;
	list<pair<char, int>> lru;
	int cache_size;
public:
	lru_cache(int size){
		cache_size = size;
		mp.clear();
		lru.clear();
	}

	int get(char key){

		//if key is not present
		if(mp.count(key) == 0) return -1;

		//store required val
		int val = mp[key]->second;

		//remove pair from list
		lru.erase(mp[key]);

		//remove key, val binding from map
		mp.erase(key);

		//insert pair at beg
		lru.insert(lru.begin(), {key, val});

		//store key, val pair in map
		mp[key] = lru.begin();

		return val;

	}

	void set(char key, int val){

		//if key is already present, delete current key, val from both list and map
		if(mp.count(key)){
			lru.erase(mp[key]);
			mp.erase(key);
		}

		//if size of cache is full, remove Least used one
		if(mp.size() == cache_size){
			
			auto last = lru.back();	
			mp.erase(last.first);
			lru.pop_back();
		}

		//finally insert key, val to front of the list also update map value
		lru.insert(lru.begin(), {key, val});
		mp[key] = lru.begin();
	}

	void display(){
		for(auto x : lru){
			cout << x.first << " " << x.second << endl;
		}
		cout << endl;
	}
	
};

int main(){

	lru_cache lru(3);

	lru.set('a', 1);
	lru.set('b', 2);
	lru.set('c', 3);

	lru.display();

	cout << endl << lru.get('a') << endl;

	lru.display();

	cout << endl << lru.get('b') << endl;

	lru.display();

	cout << endl << lru.get('c') << endl;

	lru.display();

	lru.set('d', 4);

	lru.display();

	return 0;
}