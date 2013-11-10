#ifndef BINTREE_H
#define BINTREE_H
#include "nodedata.h"

class Node{
    friend class BinTree;

public:
	Node();  			   			   	  // Node constructor
	Node(const Node &);  				  // copy constructor
	~Node();  			  				  // Node destructor
	bool operator==(const Node &) const;  // Node equality operator
 
private:
	NodeData* data; 			          // pointer to data object 
	Node* left; 				          // left subtree pointer 
	Node* right; 				          // right subtree pointer 
};

class BinTree {  
	friend ostream & operator<<(ostream &, const BinTree &);

public:
	BinTree(); 						// BinTree constructor 
	BinTree(const BinTree &); 		// BinTree copy constructor	
	~BinTree(); 					// BinTree destructor, calls makeEmpty 
	bool isEmpty() const; // true if tree is empty, otherwise false 
	void makeEmpty(); // empties the tree, calls makeEmpty() helper 
	BinTree& operator=(const BinTree &);    // BinTree Assignment operator
	bool operator==(const BinTree &) const; // BinTree Equality operator
	bool operator!=(const BinTree &) const; // BinTree Inequality operator
	bool insert(NodeData*);					// Insert node method
	void bstreeToArray(NodeData* []); //converts bstree to an arary
	void arrayToBSTree(NodeData* []); //converts array to bstree
	int getDepth(const NodeData &) const; // gets the depth of the tree
	bool retrieve(const NodeData &, NodeData*&) const; // retrieves a node
	void displaySideways() const; // provided, displays the tree sideways
 
private:
	Node* root;						// root node of the binary tree 
	void copyNode(Node&, Node &);  // copy constructor helper method
	int getDepth(const Node &, const NodeData &, int) const; //getDepth helper 
	int maximum(const int, const int); //determines the higher of two integers
	bool isEqual(const Node&,const Node&)const;      // helper for operator==
	bool isNotEqual(const Node&,const Node&)const;   // helper for operator==
	void makeEmpty(Node*); 				 // helper for makeEmpty() 
	bool insert(NodeData*,Node*,Node*,bool); // helper for displaySideways() 
	void convertArrayToTree(NodeData*[], int); // arrayToBSTree helper
    void initializeArrayHelper(NodeData* []); // Sets array elements to NULL
	void inorderHelper(Node*,NodeData* [],int&) const;//does inorder traversal
	void cleanTree(Node *); // empties tree like empty tree but deletes data
	void sideways(Node*, int) const; // helper for displaySideways() 
	bool retrieve(Node*, const NodeData&, NodeData*&) const; //retrieve helper
};

#endif
