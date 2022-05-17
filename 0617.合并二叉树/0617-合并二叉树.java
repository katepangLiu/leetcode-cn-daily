/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if( t1 == null && t2 == null ) {
            return null;
        }
        
        int val = 0;
        if( t1 != null ) {
            val += t1.val;
        }
        if( t2 != null ) {
            val += t2.val;
        }

        TreeNode root = new TreeNode(val);
        root.left = mergeTrees( t1!=null ? t1.left:null,  t2!=null ? t2.left:null  );
        root.right = mergeTrees( t1!=null ? t1.right:null,  t2!=null ? t2.right:null  );
        return root;
    }
}