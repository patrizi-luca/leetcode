# You are given the root of a binary tree. You need to implement 2 functions:

# 1. serialize(root) which serializes the tree into a string representation
# 2. deserialize(s) which deserializes the string back to the original tree that it represents

# For this problem, often you will be asked to design your own serialization format. However, for simplicity, let's use the pre-order traversal of the tree.
class Node:
    def _init_(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def _str_(self):
        result = str(self.val)
        if self.left:
            result += ' ' + str(self.left)
        if self.right:
            result += ' ' + str(self.right)
        return result

def serialize(root):
    if not root:
        return '#'
    return str(root.val) + ' ' + serialize(root.left) + ' ' + serialize(root.right)

def deserialize(data):
    values = iter(data.split())
    return buildTree(values)

def buildTree(values):
    val = next(values)
    if val == '#':
        return None
    node = Node(int(val))
    node.left = buildTree(values)
    node.right = buildTree(values)
    return node

# Example usage:
tree = Node(1)
tree.left = Node(3)
tree.left.left = Node(2)
tree.left.right = Node(5)
tree.right = Node(4)
tree.right.right = Node(7)

serialized_tree = serialize(tree)
print(serialized_tree)
# Output: 1 3 2 # # 5 # # 4 # 7 # #

deserialized_tree = deserialize(serialized_tree)
print(serialize(deserialized_tree))
# Output: 1 3 2 # # 5 # # 4 # 7 # #
