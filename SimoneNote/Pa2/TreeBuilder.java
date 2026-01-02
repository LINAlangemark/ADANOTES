public class TreeBuilder {
    public static void main(String[] args) {
        // Create nodes
        BinaryTreeNode root = new BinaryTreeNode(7);

        // Build Left Subtree
        root.left = new BinaryTreeNode(4);
        root.left.left = new BinaryTreeNode(3);
        root.left.left.left = new BinaryTreeNode(2);
        root.left.left.left.left = new BinaryTreeNode(1);
       
        // Build Right Subtree
        root.right = new BinaryTreeNode(28);
        root.right.right = new BinaryTreeNode(55);
        root.right.right.left = new BinaryTreeNode(51);
        root.right.right.left.left = new BinaryTreeNode(48);
        root.right.right.left.left.left = new BinaryTreeNode(40);
        root.right.right.left.left.left.left = new BinaryTreeNode(36);
        root.right.right.right = new BinaryTreeNode(60);
        root.right.right.right.left = new BinaryTreeNode(58);
        root.right.right.right.left.left = new BinaryTreeNode(57);
        root.right.right.right.right = new BinaryTreeNode(69);

        // Test the countBranches method
        int branchCount = root.countBranches();
        System.out.println("Number of branches: " + branchCount); // Expected output: 2
    }
}