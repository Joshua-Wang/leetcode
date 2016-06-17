#include <vector>
#include <string>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	struct Data;
	Data* data;
	public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


// 其实就是缓存的利用，以及面向对象的思想，如何使用父类的方法；
class PeekingIterator : public Iterator {
	private:
		int _cache;
		bool _has_next;
	public:
		PeekingIterator(const vector<int>& nums) : Iterator(nums) {
			// Initialize any member here.
			// **DO NOT** save a copy of nums and manipulate it directly.
			// You should only use the Iterator interface methods.
			if (Iterator::hasNext() == false) {
				_has_next = false;
			} else {
				_cache = Iterator::next();
				_has_next = true;
			}
		}

		// Returns the next element in the iteration without advancing the iterator.
		int peek() {
			return _cache;
		}

		// hasNext() and next() should behave the same as in the Iterator interface.
		// Override them if needed.
		int next() {
			if (Iterator::hasNext() == false) {
				_has_next = false;
				return _cache;
			}
			int data = _cache;
			_cache = Iterator::next();
			return data;
		}

		bool hasNext() const {
			return _has_next;	
		}
};
