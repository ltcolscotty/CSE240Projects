#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

template <typename K, typename V>
class Node
{
public:
	Node() {}
	Node(const K& key, V& value) : key(key), data(value), left(nullptr), right(nullptr), height(1) {}

	int height;
	K key;
	V data;
	Node* left;
	Node* right;
};

template <typename K, typename V>
int height(Node<K, V>* n)
{
	if (n == nullptr)
		return 0;
	return n->height;
}

template <typename K, typename V>
Node<K, V>* rightRotate(Node<K, V>* n)
{
	if (n == nullptr || n->left == nullptr)
	{
		return n;
	}

	// Temporary references
	Node<K, V>* n1 = n->left;
	Node<K, V>* n2 = n1->right;

	// Rotate
	n1->right = n;
	n->left = n2;

	//Height update
	n->height = 1 + std::max(height(n->left), height(n->right));
	n1->height = 1 + std::max(height(n1->left), height(n1->right));

	return n1;
}

template <typename K, typename V>
Node<K, V>* leftRotate(Node<K, V>* n)
{
	if (n == nullptr || n->right == nullptr)
	{
		return n;
	}

	// Temporary references
	Node<K, V>* n1 = n->right;
	Node<K, V>* n2 = n->left;

	// Rotate
	n1->left = n;
	n->right = n2;

	//Height update
	n->height = 1 + std::max(height(n->left), height(n->right));
	n1->height = 1 + std::max(height(n1->left), height(n1->right));

	return n1;
}

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
	Node* head;
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