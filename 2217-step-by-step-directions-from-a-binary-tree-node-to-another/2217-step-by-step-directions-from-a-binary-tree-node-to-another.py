# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def parentTrack(self, root, mp):
        if not root:
            return
        if root.left:
            mp[root.left] = root
        if root.right:
            mp[root.right] = root
        self.parentTrack(root.left, mp)
        self.parentTrack(root.right, mp)
    
    def getNode(self, root, startValue):
        if not root:
            return None
        lt = self.getNode(root.left, startValue)
        rt = self.getNode(root.right, startValue)
        if root.val == startValue:
            return root
        if lt:
            return lt
        return rt

    def solve(self, root, destValue, mp, path, vis):
        if not root:
            return False
        vis[root.val] = True
        if root.val == destValue:
            return True
        if root.left and root.left.val not in vis:
            path.append('L')
            if self.solve(root.left, destValue, mp, path, vis):
                return True
        if root.right and root.right.val not in vis:
            path.append('R')
            if self.solve(root.right, destValue, mp, path, vis):
                return True
        if root in mp and mp[root].val not in vis:
            path.append('U')
            if self.solve(mp[root], destValue, mp, path, vis):
                return True
        path.pop()
        return False

    def getDirections(self, root, startValue, destValue):
        mp = {}
        vis = {}
        self.parentTrack(root, mp)
        node = self.getNode(root, startValue)
        path = []
        if self.solve(node, destValue, mp, path, vis):
            return ''.join(path)
        return ""
        