public class BinaryTreeNode {
    int value;
    BinaryTreeNode left;
    BinaryTreeNode right;

    // Constructor to initialize the node with a value
    public BinaryTreeNode(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    // Method to count branches
    public int countBranches() {
        return countBranches(this, true);
    }

    private int countBranches(BinaryTreeNode node, boolean isRoot) {
        if (node == null) {
            return 0;
        }

        int count = 0;
        if (!isRoot) {
            BinaryTreeNode onlyChild = getOnlyChild(node);
            if (onlyChild != null) {
                BinaryTreeNode grandchild = getOnlyChild(onlyChild);
                if (grandchild != null && grandchild.isLeaf()) {
                    count = 1;
                }
            }
        }

        return count + countBranches(node.left, false) + countBranches(node.right, false);
    }

    // Helper method to get the only child of a node
    private BinaryTreeNode getOnlyChild(BinaryTreeNode node) {
        if (node == null) {
            return null;
        }
        if (node.left != null && node.right == null) {
            return node.left;
        }
        if (node.right != null && node.left == null) {
            return node.right;
        }
        return null;
    }

    // Method to check if a node is a leaf
    public boolean isLeaf() {
        return left == null && right == null;
    }
}