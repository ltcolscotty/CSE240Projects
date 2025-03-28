/* 
* Non recursive implementation of BST
* Aidan Y
* 3/27/2025
*/

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

template <typename K, typename V>
class Node
{
public:
	Node() {}
	Node(const K& key, V& value) : key(key), data(value), left(nullptr), right(nullptr) {}

	K key;
	V data;
	Node* left;
	Node* right;
};

template <typename K, typename V>
class BinarySearchTree
{
public:
	BinarySearchTree() : root(nullptr) {}

	void insert(K key, V value);
	bool contains(const K& key);
	V find(const K& key);
private:
	Node<K, V>* root;
};

template <typename K, typename V>
void BinarySearchTree<K, V>::insert(K key, V value)
{
	// new tree case
	if (!root) {
		root = new Node<K, V>(key, value);
		return;
	}
	
	Node<K, V>* current = root;
	Node<K, V>* parent = nullptr;

	while (current) {
		// update step back pointer thing
		parent = current;
		if (key < current->key) {
			// key left - less than
			current = current->left;
		} else if (key > current->key) {
			// key right - greater than
			current = current->right;
		} else {
			// update key
			current->data = value;
			return;
		}
	}

	// new node at null position
	if (key < parent->key) {
		parent->left = new Node<K, V>(key, value);
	} else {
		parent->right = new Node<K, V>(key, value);
	}
}

template <typename K, typename V>
bool BinarySearchTree<K, V>::contains(const K& key)
{
	Node<K, V>* current = root;

	while (current) {
		if (key < current->key) {
			current = current->left;
		} else if (key > current->key) {
			current = current->right;
		} else {
			return true;
		}
	}

	return false;
}

// Implementation assumes contains has been run before
template <typename K, typename V>
V BinarySearchTree<K, V>::find(const K& key)
{
	Node<K, V>* current = root;
    
    while (current) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return current->data;
        }
    }
}

#endif