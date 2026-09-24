"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        # Each node will have a neightbors list that can be reached.

        # clone the node that we recieved

        # can we map it? like
        # we are going to be using the dfs. lets look at the logic.

        cloned = {}

        def dfs(node):
            if (node == None): return None
            if (node.val in cloned.keys()): return cloned[node.val]

            # Create the node
            copy = Node(node.val)

            # put it in cloned
            cloned[copy.val] = copy

            for neighbor in node.neighbors:
                copy.neighbors.append(dfs(neighbor))

            return copy
        
        return dfs(node)
        