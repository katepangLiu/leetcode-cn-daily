"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):

    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        self.dfs(root, None)
        return root

    def dfs( self, root, next ):
        if root == None :
            return 

        root.next = next
        self.dfs( root.left, root.right )
        self.dfs( root.right, None if root.next==None else root.next.left )