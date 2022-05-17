# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        def dfs(root: TreeNode) :
            nonlocal accumulator
            if root == None :
                return
            
            dfs(root.right)
            accumulator += root.val
            root.val = accumulator
            dfs(root.left)
        
        accumulator = 0
        dfs(root)
        return root

        
        