#init BST
#a functional approach
init = lambda value, left = None, right = None: {'value': value, 'left': left, 'right': right} if value else None

def insert(root,val):
    if not root:
        return init(val)
    if val < root['value']:
        root['left'] = insert(root['left'],val)
    else:
        root['right'] = insert(root['right'],val)
    return root

def search(root,val):
    if not root:
        return False
    if root['value'] == val:
        return True
    if val < root['value']:
        return search(root['left'],val)
    return search(root['right'],val)

def inorder(root):
    if not root:
        return []
    return inorder(root['left']) + [root['value']] + inorder(root['right'])

def preorder(root):
    if not root:
        return []
    return [root['value']] + preorder(root['left']) + preorder(root['right'])

def postorder(root):
    if not root:
        return []
    return postorder(root['left']) + postorder(root['right']) + [root['value']]

def delete(root,val):
    if not root:
        return None
    if val < root['value']:
        root['left'] = delete(root['left'],val)
    elif val > root['value']:
        root['right'] = delete(root['right'],val)
    else:
        if not root['left']:
            return root['right']
        if not root['right']:
            return root['left']
        temp = root['right']
        while temp['left']:
            temp = temp['left']
        root['value'] = temp['value']
        root['right'] = delete(root['right'],temp['value'])
    return root

def height(root):
    if not root:
        return 0
    return 1 + max(height(root['left']),height(root['right']))

minimum = lambda root: minimum(root['left']) if root['left'] else root['value']
maximum = lambda root: maximum(root['right']) if root['right'] else root['value']

def successor(root,val):
    if not root:
        return None
    if root['value'] == val:
        if root['right']:
            return minimum(root['right'])
    if val < root['value']:
        return successor(root['left'],val)
    temp = successor(root['right'],val)
    return temp if temp else None

