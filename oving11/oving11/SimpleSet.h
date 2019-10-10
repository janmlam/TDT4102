template<class T>
#include <iostream>
class SimpleSet{
    public:
        /** Construct empty set **/
        SimpleSet();
        /** Destructor */
        ~SimpleSet();
        /** Insert i into set, return true if the element was inserted, else false **/
        bool insert(int i);
        /** Returns true if i is in the set **/
        bool exists(int i);
        /** Removes i from the set, return true if an element was removed **/
        bool remove(int i);
    private:
        /** Dynamic array containing set elements **/
        T *data;
        /** Current number of elements **/
        int currentSize;
        /** Max capasity of data **/
        int maxSize;       
        
        /** Returns the index where i may be found, else an invalid index. **/
        int find(int i);
        /** Resizes data, superflous elements are dropped. **/
        void resize(int n); 

		template <class Y>
		friend std::ostream& operator<<(std::ostream& os, const SimpleSet<Y>& simpleset);
};

template<class T>
inline SimpleSet<T>::SimpleSet() {
	data = new T[10];
	currentSize = 0;
	maxSize = 10;
}

template <class T>
inline SimpleSet<T>::~SimpleSet() {
	delete[] data;
}

template<class T>
inline bool SimpleSet<T>::insert(int i){
	if (find(i) > 0) { 
		return false; 
	}
	if (currentSize == maxSize) resize(maxSize * 2);
		data[currentSize++] = i;
	return true;
}

template<class T>
inline bool SimpleSet<T>::exists(int i) {
	return (find(i) > 0);
}

template<class T>
inline bool SimpleSet<T>::remove(int i) {
	int toRemoveIndex = find(i);
	if (toRemoveIndex > 0) {
		for (int i = toRemoveIndex; i < currentSize; ++i) {
			data[i] = data[i + 1];
		}
		--currentSize;
		return true;
	} 
	return false;
}

template<class T>
inline int SimpleSet<T>::find(int i) {
	for (int j = 0; j < currentSize; ++j) {
		if (data[j] == i)
			return j;
	} return -1;
}

template<class T>
inline void SimpleSet<T>::resize(int n) {
	T *newData = new T[n];
	int amount = 0;
	for (int i = 0; i < n; ++i) {
		if (i == maxSize) break;
		newData[i] = data[i];
		++amount;
	}
	delete[] data;
	data = newData;
	currentSize = amount;
	maxSize = n;
}

template<class T>
inline std::ostream & operator<<(std::ostream & os, const SimpleSet<T>& simpleset) {
	for (int i = 0; i < simpleset.currentSize; ++i) {
		std::cout << simpleset.data[i] << " ";
	} 
	return std::cout;
}
