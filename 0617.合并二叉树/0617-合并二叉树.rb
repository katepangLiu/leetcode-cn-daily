# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} t1
# @param {TreeNode} t2
# @return {TreeNode}
def merge_trees(t1, t2)
    return nil if t1.nil? && t2.nil?

    root = TreeNode.new(t1&.val.to_i + t2&.val.to_i)

    root.left = merge_trees(t1&.left, t2&.left)
    root.right = merge_trees(t1&.right, t2&.right)

    root
end