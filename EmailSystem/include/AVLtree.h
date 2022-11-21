/***
* Team leader : Farez Samah Ikram
***/
#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include <algorithm>
#include <iostream>
#include<chrono>
using namespace std;

template <typename Comparable>
class AVL
{
public:

    struct AvlNode
    {
        Comparable element;
        AvlNode   *left;
        AvlNode   *right;
        int       height;

        AvlNode( const Comparable & ele, AvlNode *lt, AvlNode *rt, int h = 0 )
            : element{ ele }, left{ lt }, right{ rt }, height{ h } { }

        AvlNode( Comparable && ele, AvlNode *lt, AvlNode *rt, int h = 0 )
            : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
    };
    AvlNode* get_root()
    {
        return root;
    }

    AVL():root{nullptr}
    {}
    AVL( const AvlNode & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    AVL( AVL &&rhs ): root( rhs.root )
    {
        rhs.root = nullptr;
    }
    ~AVL()
    {
        makeEmpty(root);
    }

    AVL & operator=( const AVL & rhs )
    {
        AVL copy = rhs;
        std::swap( *this, copy );
        return *this;
    }

    AVL & operator=( AVL && rhs )
    {
        std::swap( root, rhs.root );

        return *this;
    }

    bool isEmpty( )
    {
        return root==nullptr;
    }

    bool contains( const Comparable & x ) const
    {
        return contains( x, root );
    }

    void printTree( ) const
    {
        printTree( root );
    }

    void makeEmpty( )
    {
        makeEmpty( root );
    }

    void insert( const Comparable & x )
    {
        insert( x, root );
    }

    void insert( Comparable && x )
    {
        insert( std::move( x ), root );
    }

    void remove( const Comparable & x )
    {
        remove( x, root );
    }

    int hight()
    {
        return height(root);
    }

private:

    AvlNode *root;
    static const int ALLOWED_IMBALANCE = 1;

    AvlNode * clone( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new AvlNode{ t->element, clone( t->left ), clone( t->right ), t->height };
    }

    void makeEmpty( AvlNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    bool contains( const Comparable & x, AvlNode *t ) const
    {
        if( t == nullptr )
            return false;
        else if( x < t->element )
            return contains( x, t->left );
        else if( t->element < x )
            return contains( x, t->right );
        else
            return true;
    }

    void printTree( AvlNode *t ) const
    {
        if( t != nullptr )
        {
            printTree( t->left );
            cout << t->element << endl;
            printTree( t->right );
        }
    }

    void insert( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
            t = new AvlNode{ x, nullptr, nullptr };
        else if( x < t->element )
            insert( x, t->left );
        else if( t->element < x )
            insert( x, t->right );

        balance( t );
    }

    void insert( Comparable && x, AvlNode * & t )
    {
        if( t == nullptr )
            t = new AvlNode{ std::move( x ), nullptr, nullptr };
        else if( x < t->element )
            insert( std::move( x ), t->left );
        else if( t->element < x )
            insert( std::move( x ), t->right );

        balance( t );
    }

    void remove( const Comparable & x, AvlNode * & t )
    {
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
            AvlNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }

        balance( t );
    }

    void balance( AvlNode * & t )
    {
        if( t == nullptr )
            return;

        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )
            if( height( t->left->left ) >= height( t->left->right ) )
                rotateWithLeftChild( t );
            else
                doubleWithLeftChild( t );
        else if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )
            if( height( t->right->right ) >= height( t->right->left ) )
                rotateWithRightChild( t );
            else
                doubleWithRightChild( t );

        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

    int height( AvlNode *t ) const
    {
        return t == nullptr ? -1 : t->height;
    }

    int max( int lhs, int rhs ) const
    {
        return lhs > rhs ? lhs : rhs;
    }
    void rotateWithLeftChild( AvlNode * & k2 )
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }
    void rotateWithRightChild( AvlNode * & k1 )
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->right ), k1->height ) + 1;
        k1 = k2;
    }
    void doubleWithLeftChild( AvlNode * & k3 )
    {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }
    void doubleWithRightChild( AvlNode * & k1 )
    {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }

};
#endif // AVL_H_INCLUDED
