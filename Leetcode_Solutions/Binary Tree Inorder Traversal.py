class Solution:
    def __init__(self):
        self.lst1 = []

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if (root == None):
            return []
        else:
            self.inorderTraversal(root.left)
            self.lst1.append(root.val)
            self.inorderTraversal(root.right)
            return self.lst1