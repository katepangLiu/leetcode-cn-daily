# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {TreeNode}
def convert_bst(root)
    @accumulator = 0
    dfs(root)
end

def dfs(root)
    return nil if root.nil?
    dfs(root.right)
    @accumulator += root.val
    root.val = @accumulator
    dfs(root.left)
    root
end