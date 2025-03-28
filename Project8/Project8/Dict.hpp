#ifndef Dict_hpp
#define Dict_hpp

#include <vector>
#include "BinarySearchTree.hpp"

template <typename K, typename V>
class Dict
{
public:
	Dict() : bt(BinarySearchTree<K, V>()) {}
	void add(K key, V value);
	V& operator[](K key);
private:
	BinarySearchTree<K, V> bt;
};

template <typename K, typename V>
void Dict<K, V>::add(K key, V value)
{
	bt.insert(key, value);
}

template <typename K, typename V>
V& Dict<K, V>::operator[](K key)
{
	if (!bt.contains(key))
		bt.insert(key, V());

	return bt.find(key);
}

#endif // !Dict_hpp
