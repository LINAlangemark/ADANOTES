import java.lang.Math;
/**
 * Implements an unbalanced binary search tree.
 * inspired by Mark Allen Weiss
 */
public class BinarySearchTree
{
    public BinarySearchTree( )
    {
        root = null;
    }

    // Insert into the tree; duplicates are ignored.
    public void insert( int x )
    {
        root = insert( x, root );
    }
    
    public void remove( int x )
    {
        root = remove( x, root );
    }
    
    public BinaryNode findMin()
    {
        if( isEmpty( ) )
            ;
        return findMin( root );
    }
    
    public BinaryNode findMax()
    {
        if( isEmpty( ) )
            ;
        return findMax( root);
    }

    public boolean contains( int x )
    {
        return contains( x, root );
    }
    
    public void makeEmpty( )
    {
        root = null;
    }
    
    public boolean isEmpty( )
    {
        return root == null;
    }

    public void printTree( )
    {
        if( isEmpty( ) )
            System.out.println( "Empty tree" );
        else
            printTree( root );
    }
    
    private BinaryNode insert( int x, BinaryNode t )
    {
        if( t == null )
            return new BinaryNode( x, null, null );
        
        if( x < t.element )
            t.left = insert( x, t.left );
        else
        if( x > t.element )
            t.right = insert( x, t.right );
        else
            ;  // Duplicate; do nothing
        return t;
    }
    
    private BinaryNode remove( int x, BinaryNode t )
    {
        if( t == null )
            return t;   // Item not found; do nothing
            
        if( x < t.element )
            t.left = remove( x, t.left );
        else
        if( x > t.element )
            t.right = remove( x, t.right );
        else
        if( t.left != null && t.right != null ) // Two children
        {
            t.element = findMin( t.right ).element;
            t.right = remove( t.element, t.right );
        }
        else
            t = ( t.left != null ) ? t.left : t.right;
        return t;
    }
    
    private BinaryNode findMin( BinaryNode t)
    {
        if( t == null )
            return null;
        else if( t.left == null )
            return t;
        return findMin( t.left );
    }
    
    private BinaryNode findMax( BinaryNode t )
    {
        if( t != null )
            while( t.right != null )
                t = t.right;

        return t;
    }
    
    private boolean contains( int x, BinaryNode t )
    {
        if( t == null )
            return false;
        if (x < t.element )
            return contains( x, t.left );
        else
        if( x > t.element )
            return contains( x, t.right );
        else
            return true;    // Match
    }
    
    private void printTree( BinaryNode t)
    {
        if( t != null )
        {
            printTree( t.left );
            System.out.println( t.element );
            printTree( t.right );
        }
    }

    private int height( BinaryNode t )
    {
        if( t == null )
            return -1;
        else
            return 1 + Math.max( height( t.left ), height( t.right ) );    
    }

    // Basic node stored in unbalanced binary search trees
    private static class BinaryNode
    {
            // Constructors
        BinaryNode( int theElement )
        {
            this( theElement, null, null );
        }

        BinaryNode( int theElement, BinaryNode lt, BinaryNode rt )
        {
            element  = theElement;
            left     = lt;
            right    = rt;
        }

        int element;            // The data in the node
        BinaryNode left;   // Left child
        BinaryNode right;  // Right child
    }


      /** The tree root. */
    private BinaryNode root;


        // Test program
    public static void main( String [ ] args ) {
        BinarySearchTree t = new BinarySearchTree();


        t.insert(7);
        t.insert(4);
        t.insert(28);
        t.insert(3);
        t.insert(55);
        t.insert(2);
        t.insert(51);
        t.insert(60);
        t.insert(1);
        t.insert(48);
        t.insert(58);
        t.insert(69);
        t.insert(40);
        t.insert(57);
        t.insert(35);
        t.remove(55);
        t.remove(3);
        System.out.println(t.contains(80));
        t.printTree();
    }
}
