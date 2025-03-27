#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

template <typename K, typename V>
class Node
{
public:
	Node() {}
	Node(const K& key, V& value) : key(key), data(value), left(NULL), right(NULL), height(1) {}

	int height;
	K key;
	V data;
	Node* left;
	Node* right;
};

template <typename K, typename V>
class BinarySearchTree
{
public:
	BinarySearchTree() {}

	void insert(K key, V value);
	void remove(K key);
	bool contains(K key);
	V find(K key);
private:

};

template <typename K, typename V>
void BinarySearchTree<K, V>::insert(K key, V value)
{

}

template <typename K, typename V>
void BinarySearchTree<K, V>::remove(K key)
{

}

template <typename K, typename V>
bool BinarySearchTree<K, V>::contains(K key)
{

}

template <typename K, typename V>
V BinarySearchTree<K, V>::find(K key)
{

}

#endif