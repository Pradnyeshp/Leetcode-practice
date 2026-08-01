class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return root;
        
        if(key < root.val){
            root.left = deleteNode(root.left, key);
        } else if(key > root.val){
            root.right = deleteNode(root.right, key);
        } else {
            if(root.left == null) {
                return root.right;
            } else if(root.right == null){
                return root.left;
            }
            root.val = getMin(root.right);
            root.right = deleteNode(root.right, root.val);
        }
        return root;
    }

    private int getMin(TreeNode root){
        int val = root.val;
        while(root.left != null){
            val = root.left.val;
            root = root.left;
        }
        return val;
    }
}