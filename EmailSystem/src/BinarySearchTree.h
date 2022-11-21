#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include<iostream>
#include<chrono>
using namespace std;

template <typename Comparable>
class BinarySearchTree
 {
   public:
 	BinarySearchTree( ):root{nullptr} {}
 	BinarySearchTree( const BinarySearchTree & rhs ){
 	    root=clone( rhs.root);
 	}

 	BinarySearchTree( BinarySearchTree && rhs );

 	~BinarySearchTree( ){
 	  makeEmpty( root );
 	}


 	bool contains( const Comparable & x ) const{
 	  return contains(x,root );
 	}
 	bool isEmpty( ) const{
 	    if (root=nullptr)
 	        return true;
 	    else
            return false;
 	}
 	void printTree_inorder( ostream & out = cout ) const{
 	   printTree_in( root,out );
 	}
    void printTree_preorder( ostream & out = cout ) const{
        printTree_pre( root,out );
    }
    void printTree_postorder( ostream & out = cout ) const{
      printTree_pos( root,out );
    }
 	void makeEmpty( ){
 	    makeEmpty(root);
 	}
 	void insert( const Comparable & x ){
 	    insert(  x, root );
 	}
 	void insert( Comparable && x ){
 	    insert( x, root );
 	}
 	void remove( const Comparable & x ){
 	   remove( x, root );
 	}

 	BinarySearchTree & operator=( const BinarySearchTree & rhs );
 	BinarySearchTree & operator=( BinarySearchTree && rhs );

 	int number_of_nodes(){
 	     return nof_nodes(root);
 	}


 	int depth(){
 	    return Depth(root);
 	}


  private:

 	struct BinaryNode{
 		Comparable element;
 		BinaryNode *left;
 		BinaryNode *right;

 		BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
 		   : element{ theElement }, left{ lt }, right{ rt } { }

 		BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
 		   : element{ std::move( theElement ) }, left{ lt }, right{ rt } { }
 	};

	BinaryNode *root;

    void insert( const Comparable & x, BinaryNode * & t ){
 	if( t == nullptr )
 	    t = new BinaryNode{ x, nullptr, nullptr };
 	else if( x < t->element )
 	         insert( x, t->left );
 	     else if( t->element < x )
 		      insert( x, t->right );
 		  else
 			;
 }
 	void insert( Comparable && x, BinaryNode * & t ){
 	if( t == nullptr )
 	    t = new BinaryNode{ std::move( x ), nullptr, nullptr };
 	else if( x < t->element )
 		 insert( std::move( x ), t->left );
 	     else if( t->element < x )
 		      insert( std::move( x ), t->right );
 		  else
 			;
 }
 	void remove( const Comparable & x, BinaryNode * & t ){
 	if( t == nullptr )
	    return;
 	if( x < t->element )
 	    remove( x, t->left );
 	else if( t->element < x )
 		 remove( x, t->right );
 	     else if( t->left != nullptr && t->right != nullptr )
 		  {
 		      t->element = findMin( t->right )->element;
	 	      remove( t->element, t->right );
 		  }
		  else
 		  {
 		      BinaryNode *oldNode = t;
 		      t = ( t->left != nullptr ) ? t->left : t->right;
 		      delete oldNode;
 		   }
 }
    void makeEmpty( BinaryNode * & t ){
 	if( t != nullptr )
 	{
 	    makeEmpty( t->left );
	    makeEmpty( t->right );
 	    delete t;
	}
 	t = nullptr;
    }


 	bool contains( const Comparable & x, BinaryNode *t ) const{
 	if( t == nullptr )
 		return false;
 	else if( x < t->element )
 		return contains( x, t->left );
 	     else if( t->element < x )
 			return contains( x, t->right );
 		  else
 			return true; // Match

 			 }
 	BinaryNode * clone( BinaryNode *t ) const{
 	if( t == nullptr )
	    return nullptr;
 	else
 	    return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
 }
 	void printTree_in( BinaryNode *t, ostream & out ) const{
 	if( t != nullptr )
 	{
 		printTree_in( t->left, out );
 		out << t->element << endl;
 		printTree_in( t->right, out );
 	}
    }
    void printTree_pre( BinaryNode *t, ostream & out ) const{
 	if( t != nullptr )
 	{
 	    out << t->element << endl;
 		printTree_pre( t->left, out );
 		printTree_pre( t->right, out );
 	}
    }
    void printTree_pos( BinaryNode *t, ostream & out ) const{
 	if( t != nullptr )
 	{
 		printTree_pos( t->left, out );
 		printTree_pos( t->right, out );
 		out << t->element << endl;
 	}
    }
    int nof_nodes(const BinaryNode *t){
 	    if (t==nullptr)
 	       return 0;
 	    else if (t->left==nullptr && t->right==nullptr)
 	       return 1;
 	    else
            return 1+nof_nodes(t->left)+nof_nodes(t->right);

 	}

    int Depth(const BinaryNode *t){
 	    if(t=nullptr)
 	      return 0;
        else
            return 1+ max(Depth(t->left),Depth(t->right));

 	}

 };

#endif
