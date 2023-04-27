#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
node* FindMin(node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}


node* GetNewNode(int key) {
	node *newNode = new node();
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	return newNode;
}
// Inorder traversal
void traverseInOrder(struct node *root) {
   if(root == NULL) return;

	traverseInOrder(root->left);       //Visit left subtree
	printf("%i ",root->key);  //Print key
	traverseInOrder(root->right);      // Visit right subtree

}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if(root == NULL) { // empty tree
		root = GetNewNode(key);
	}
	// if key to be inserted is lesser, insert in left subtree. 
	else if(key <= root->key) {
		root->left = insertNode(root->left,key);
	}
	// else, insert in right subtree. 
	else {
		root->right = insertNode(root->right,key);
	}
	return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
 if(root == NULL) return root; 
	else if(key < root->key) root->left = deleteNode(root->left,key);
	else if (key > root->key) root->right = deleteNode(root->right,key);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct node *temp = FindMin(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,temp->key);
		}
	}
	return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}