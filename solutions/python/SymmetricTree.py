'''
  A k-ary tree is a tree with k-children, and a tree is symmetrical if the data of the left side of the tree is the same as the right side of the tree.
  
  Here's an example of a symmetrical k-ary tree.
  
          4
       /     \
      3        3
    / | \    / | \
  9   4  1  1  4  9
  
  Given a k-ary tree, figure out if the tree is symmetrical.
  
  Here is a starting point:
'''
class Node():
  def __init__(self, value, children=[]):
    self.value = value
    self.children = children


def is_symmetric(root):
  # Fill this in.
  # My solution 
    def is_mirror(left, right):
        if not left and not right:
            return True
        if not left or not right or left.value != right.value:
            return False
        
        left_children = left.children
        right_children = right.children[::-1]  # Reverse the list for symmetric comparison

        if len(left_children) != len(right_children):
            return False

        for l, r in zip(left_children, right_children):
            if not is_mirror(l, r):
                return False
        return True

    if not root:
        return True
    return is_mirror(root, root)
  

tree = Node(4)
tree.children = [Node(3), Node(3)]
tree.children[0].children = [Node(9), Node(4), Node(1)]
tree.children[1].children = [Node(1), Node(4), Node(9)]
print is_symmetric(tree)
# True
