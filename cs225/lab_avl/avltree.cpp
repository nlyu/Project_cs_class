/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    if(t == NULL || t->right == NULL) return;
    Node * newRoot = t->right;
    Node * temp = newRoot->left;
    
    newRoot->left = t;
    t->right = temp;
    t = newRoot;
    t->left->height = max(heightOrNeg1(t->left->left), heightOrNeg1(t->left->right)) + 1;
    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
   // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    if(t == NULL || t->left == NULL) return;
    Node * newRoot = t->left;
    Node * temp = newRoot->right;
    
    newRoot->right = t;
    t->left = temp;
    t = newRoot;
    t->right->height = max(heightOrNeg1(t->right->left), heightOrNeg1(t->right->right)) + 1;
    t->height = max(heightOrNeg1(t->right), heightOrNeg1(t->left)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here   
    if(heightOrNeg1(subtree->left) - heightOrNeg1(subtree->right) > 1){
    	if(heightOrNeg1(subtree->left->left) - heightOrNeg1(subtree->left->right) >= 0)	rotateRight(subtree);
    	else	rotateLeftRight(subtree);
    }
    
    if(heightOrNeg1(subtree->left) - heightOrNeg1(subtree->right) < -1){
    	if(heightOrNeg1(subtree->right->left) - heightOrNeg1(subtree->right->right) > 0)	rotateRightLeft(subtree);
    	else	rotateLeft(subtree);
    }
    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
    return;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if(subtree == NULL)	{
    	subtree = new Node(key, value);
    	}
    if(key < subtree->key) {
    	insert(subtree->left, key, value);
    	}
    if(key > subtree->key) {
    	insert(subtree->right, key, value);
    	}
    rebalance(subtree);

    return;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    else if (key < subtree->key) {
        // your code here
        remove(subtree->left, key);
        }
    else if (key > subtree->key) {
        // your code here
        remove(subtree->right, key);
    } 
    else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
        }
        else if (subtree-> left == NULL || subtree->right == NULL){
            Node * next = (subtree->left) ? subtree->left : subtree->right;
            delete subtree;
            subtree = next;
        } 
        else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node * left = subtree->left;
            //Node * right = subtree->right
            while(left->right != NULL){
            	left = left->right;
            }
            	swap(left, subtree);
            	//if(subtree != NULL){
            	remove(subtree->left, key); 
        } 
        else {
            //rebalance(subtree);
            //subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));

        }
    }
        // your code here
    if(subtree != NULL){
    	rebalance(subtree);
    }
    //subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
}
