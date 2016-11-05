#include <iostream>
#include <map>

using namespace std;

struct Node {
	Node* pre;
	Node* post;
	int key;
	int value;
};

class LRUCache{
	private:
		map<int, Node*> _mymap;
		Node* _head;
		int _capacity;
		int _cur;
	public:
		LRUCache(int capacity) {
			_capacity = capacity;
			_cur = 0;
			_head = NULL;
		}

		void put_first(Node* &head, Node* &cur) {
            if (head == cur) {
                return ;
            }
			if (cur->pre != NULL) {
				cur->pre->post = cur->post;
			}	
			if (cur->post != NULL) {
				cur->post->pre = cur->pre;
			}
			cur->post = head;
			cur->pre = NULL;
            if (head != NULL) {
                head->pre = cur;
            }
			head = cur;
		}

		int get(int key) {
			if (_mymap.count(key) == 1) {
				put_first(_head, _mymap[key]);
				return _mymap[key]->value;
			} else {
				return -1;
			}
		}

		void set(int key, int value) {
			if (_mymap.count(key) == 1) {
			    _mymap[key]->value = value;
				put_first(_head, _mymap[key]);
			} else {
			    if (_cur == _capacity) {
					// delete node in list, clear record in map
					Node* pos = _head;
					while (pos != NULL && pos->post != NULL) {
						pos = pos->post;
					}
					if (pos->pre != NULL) {
						pos->pre->post = NULL;
					}
                    map<int, Node*>::iterator iter = _mymap.find(pos->key);
					if (iter != _mymap.end()) {
						_mymap.erase(iter);
						_cur--;
					}
					delete pos;
				} 
				Node *node = new Node();
				node->value = value ;
				node->key = key;
				node->pre = NULL;
				node->post = _head;
                if (_head != NULL) {
                    _head->pre = node;
                }
				_head = node;
				_mymap.insert(make_pair(key, node));
				_cur++;
			}
		}
};

int main () {
	LRUCache cache(2);
	cache.set(1,1);            // 5 3 
	cache.set(3,3);
	cache.get(1);
	cache.set(4,4);
	cout << cache.get(3) << endl; //3
	cout << cache.get(1) << endl; //3
	cache.set(5,5); //3
	cout << cache.get(5) << endl; //3
	cout << cache.get(1) << endl; //3

	return 0;
}




