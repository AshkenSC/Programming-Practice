# 198
'''
1 3 4 5 2


'''

from typing import List
import heapq

from typing_extensions import ParamSpec

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def find_predecessor(self, root):
        root = root.left
        while root.right:
            root = root.right
        return root.val

    def find_successor(self, root):
        root = root.right
        while root.left:
            root = root.left
        return root.val

    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None
        p = root
        while p and p.val != key:
            if p.val > key:
                p = p.left
            else:
                p = p.right
        if p:
            if not (p.left or p.right):
                p = None
            elif p.left:
                p.val = self.find_predecessor(p)
                self.deleteNode(p.left, p.val)
            else:
                p.val = self.find_successor(p)
                self.deleteNode(p.right, p.val)
        return root

a = TreeNode(5)
b = TreeNode(3)
c = TreeNode(6)
d = TreeNode(2)
e = TreeNode(4)
f = TreeNode(None)
g = TreeNode(7)
a.left = b
a.right = c
b.left =d
b.right = e
c.left = f
c.right = g
sol = Solution()
ans=sol.deleteNode(a,3)
print(ans)

        

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()

#sol = Solution()
obj = MyQueue()
obj.push(1)
obj.push(2)
a = obj.peek()
b = obj.pop()
c = obj.empty()