/**
 * @file BiTree.cc
 * @brief binary tree and operations 
 * @author Qing Xu, xuqinguestc@163.com
 * @version 0.1.00
 * @date 2014-06-16
 */

#include <bits/stdc++.h>
using namespace std;

//定义树的节点
struct TreeNode
{
  int val;
  TreeNode *left, *right, *parent;
  TreeNode(int x):val(x),left(NULL),right(NULL), parent(NULL){}
};
//定义链表的节点
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x):val(x), next(NULL){}
};


//level insert node to a tree
//-1 meand the current node is NULL
TreeNode *Build(const vector<int> data)
{
  if(data.empty()) return NULL;
  const int n = data.size();
  queue<TreeNode *> prev, next;
  if(data[0] == -1)
  {
    throw runtime_error("Input Illegal!!!");
  }

  TreeNode *root =  new TreeNode(data[0]);
  prev.push(root);
  int index = 1 ; // record the index in data
  while(!prev.empty() && index < n)
  {
    while(!prev.empty() && index < n)
    {
      TreeNode *parent =  prev.front(); prev.pop();
      if (index < n)
      {
        if(data[index] != -1) 
        {
          TreeNode *node = new TreeNode(data[index]); 
          parent->left= node;
          node->parent = parent;
          next.push(node);
        }
        ++index;
      }
      if (index < n)
      {
        if(data[index] != -1) 
        {
          TreeNode *node = new TreeNode(data[index]); 
          parent->right = node;
          node->parent = parent;
          next.push(node);
        }
        ++index;
      }
    }
    if(!next.empty())
    {
      prev.swap(next);
    }
  }
  return root;
}
//pre traverse
void preTraverse(TreeNode *root)
{
  cout << "Pre order : ";
  if(root == NULL ) return;
  stack<TreeNode *> s;
  while(!s.empty() || root)
  {
    while(root)
    {
      s.push(root);
      cout << root->val << " ";
      root = root->left;
      if(root == NULL) cout << -1 << " ";
    }
    root = s.top(); s.pop();
    root = root->right;
    if(root == NULL)
    {
      cout << -1 << " ";
    }
  }
  cout << endl;
}
//inorder 
/*void inTraverse(TreeNode *root)
{
  cout << "In order : ";
  if(root == NULL ) return ;
  stack<TreeNode *> s;
  while(!s.empty() || root)
  {
    while(root)
    {
      s.push(root);
      root = root->left;
    }
    root = s.top();s.pop();
    if(root->left == NULL)  cout << -1 << " ";
    cout << root->val << " ";
    root = root->right;
    if(root == NULL) cout << -1 << " ";
  }
  cout << endl;
}
*/
void inTraverse(TreeNode *root)
{
  cout << "In order..." << endl;
  while(root != nullptr)
  {
    if(root->left == nullptr)
    {
      cout << root->val << " ";
      root = root->right;
    }
    else
    {
      TreeNode *tmp = root->left;
      while(tmp->right != nullptr && tmp->right != root)
        tmp = tmp->right;
      if(tmp->right == nullptr)
      {
          tmp->right = root;
          root = root->left;
      }
      else if(tmp->right == root)
      {
          cout << root->val << "\t";
          tmp->right = nullptr;
          root = root->right;
      }
    }
  }
}
//posorder 
void posTraverse(TreeNode *root)
{
  cout << "pos order : ";
  if(root == NULL ) return ;
  stack<TreeNode *> s;
  TreeNode *prev = NULL;
  while(!s.empty() || root)
  {
    while(root)
    {
      s.push(root);
      root = root->left;
    }
    root = s.top();//read the stack top but no pop !!!

    //right child is NULL or right child has visited
    if(root->right == NULL || prev == root->right)
    {
      cout << root->val << " ";
      prev = root;
      s.pop(); //here pop the node because its children has been visited
      root = NULL; //avoid visted repeatly
    }
    else
    {
      root = root->right;
    }
  }
  cout << endl;
}
void traverse(TreeNode *root)
{
  if(root == NULL) return;
  queue<TreeNode *> q;
  q.push(root);
  while(!q.empty())
  {
    TreeNode *node = q.front(); q.pop();
    cout << node->val << " ";
    if(node->left)q.push(node->left);
    if(node->right)q.push(node->right);
  }
}

//deatory tree incursivelly
void destory(TreeNode * &root)
{
  if(root == NULL) return;
  destory(root->left);
  destory(root->right);
  delete root;
  root = NULL;
}

int depth(TreeNode * root)
{
  if(root == NULL) return 0;
  else return max(depth(root->left), depth(root->right))+1;
}
//此版本存在着重复计算
bool isBalance(TreeNode *root)
{
  if(root == NULL) return true;
  //each sub tree is balanced!!!
  int height = depth(root->left) - depth(root->right);
  if(abs(height) > 1)
    return false;
  else 
    return isBalance(root->left) && isBalance(root->right);
}
//此版本不存在重复计算
bool helper_balance(TreeNode *root, int &depth)
{
  if(root == NULL)
  {
    depth = 0;
    return true;
  }
  int left = 0, right = 0;
  bool l = helper_balance(root->left,left);
  bool r = helper_balance(root->right,right);
  if (l && r && (abs(left-right) < 2))
  {
    depth = max(left, right)+1;
    return true;
  }
  else
  {
    return false;
  }
}
bool isBalance2(TreeNode *root)
{
  int depth = 0;
  return helper_balance(root, depth);
}

TreeNode *createMinDepthTree(vector<int> data, int beg, int end)
{
  if(end < beg)
  {
    return NULL;
  }
  int mid = beg + (end-beg)/2;
  TreeNode *root =  new TreeNode(data[mid]);
  root->left = createMinDepthTree(data,beg,mid-1);
  root->right = createMinDepthTree(data, mid+1, end);
  return root;
}

vector<ListNode *> printKLevelNode(TreeNode *root)
{
  vector<ListNode *> heads;
  if(root == NULL) return heads;
  queue<TreeNode *> prev, next;
  prev.push(root);
  ListNode *cur_head = NULL, *cur_temp = NULL;
  TreeNode *cur = NULL;
  while(!prev.empty())
  {
    cur_head = NULL;
    while(!prev.empty())
    {
      cur = prev.front(); prev.pop();
      ListNode *node = new ListNode(cur->val);
      if(cur_head == NULL)
      {
        cur_head = node;
        heads.push_back(cur_head);
        cur_temp = node;
      }
      else
      {
        cur_temp->next = node;
        cur_temp = node;
      }
      if(cur->left) next.push(cur->left);
      if(cur->right) next.push(cur->right);
    }
    next.swap(prev);
  }

}
void printList(ListNode *head)
{
  while(head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
//destory list !!! the parameter must be reference!!
//否则改变的只是传入指针的值改为了NULL，而实际参数的值是没有变成NULL的！！！
void destoryList(ListNode * &head)
{
  while(head)
  {
    ListNode *t = head->next;
    delete head;
    head = NULL;
    head = t;
  }
  return;
}
//check a tree is a BST or not
//仅仅判断左子树的至 < 根节点 < 右子树是不够的，必须还的保证左子树的所有节点的值都要小于根节点，右子树的所有节点的值都要大于右节点

bool helper(TreeNode *root, int lower, int upper)
{
  if(root == NULL) return true;
  if(root->val >= lower && root->val <= upper)
  {
    return helper(root->left, lower, root->val) && helper(root->right, root->val , upper);
  }
  return false;
}
bool isBST(TreeNode *root)
{
  return helper(root, INT_MIN,INT_MAX);
}

TreeNode *minNode(TreeNode *root)
{
  while(root->left)
  {
    root = root->left;
  }
  return root;
}
TreeNode *next_node(TreeNode *root, TreeNode *cur)
{
  if(cur == NULL) return NULL;

  //have right child
  if(cur->right) return minNode(cur->right);
  else
  {
    TreeNode *parent = cur->parent;
    while(parent && parent->right ==  cur)
    {
      cur = parent;
      parent =  cur->parent;
    }
    return parent;
  }
  /*
  //no parent
  if(cur->parent == NULL)
  {
    if(cur->right) return minNode(cur->right);
    else return NULL;
  }
  //is left child of parent
  if(cur->parent->left == cur)
  {
    return cur->parent;
  }
  else
  {
    while(cur->parent != NULL && cur->parent->right == cur)
    {
      cur = cur->parent;
    }
    if(cur->parent == NULL) return NULL;
    else 
    {
      return cur->parent;
    }
  }
  */
}
//have the parent pointer 
//need a hash table to store the visited node
TreeNode *commonAncester(TreeNode *node1, TreeNode *node2)
{
  assert(node1 && node2);
  unordered_set<TreeNode *> visited;

  while(node1)
  {
    visited.insert(node1);
    node1 = node1->parent;
  }
  while(node2)
  {
    if(visited.find(node2) != visited.end())
    {
      return node2;
    }
    node2 = node2->parent;
  }
  return NULL;

}

//node 是不是root的孩子节点
bool isChild(TreeNode *root, TreeNode *node)
{
  if(root == NULL) return false;
  if(root == node) return true;
  return isChild(root->left, node) || isChild(root->right, node);
}

TreeNode *commonAncester2Helper(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
  if(root == NULL) return NULL;
  if(root == node1 || root == node2) return root;

  bool is_left_child_node1 = isChild(root->left,node1);
  bool is_left_child_node2 = isChild(root->left,node2);
  if(!(is_left_child_node1 && is_left_child_node2))
  {
    return root;
  }
  return commonAncester2Helper(is_left_child_node2?root->left : root->right , node1,node2);

}
//common ancester
//time comlexity: O(n)
TreeNode *commonAncester2(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
  //node1, node2 exists in root 
  if(!isChild(root,node1) || !isChild(root, node2))
  {
    return NULL;
  }
  assert(isChild(root, node1)  && isChild(root, node2));
  return commonAncester2Helper(root, node1, node2);
}

void printPath(TreeNode *root, TreeNode *node , vector<TreeNode *> &path, bool &found)
{
  //if found or visit the leaf node
  if(found || root == NULL) return;

  path.push_back(root);
  if(root == node) 
  {
    found = true;
    return;
  }
  //visit left tree and right tree, if not found, we pop back current root node
  printPath(root->left,node,path, found);
  printPath(root->right,node,path, found);

  if (!found)
  path.pop_back();
}

TreeNode *lastCommonNode(const vector<TreeNode *> &path1, const vector<TreeNode *> &path2)
{
  //vector<TreeNode *>::const_iterator it1 = path1.begin(), it2 = path2.begin();
  auto it1 = path1.begin(), it2 = path2.begin();
  TreeNode *ret = *it1;
  while(it1 != path1.end() && it2 != path2.end())
  {
    if (*it1 == *it2)
    {
      ret = *it1;
    }
    ++it1;
    ++it2;
  }
  return ret;
}

TreeNode *commonAncester3(TreeNode *root, TreeNode *node1, TreeNode *node2)
{
  vector<TreeNode * > path1, path2;
  bool found = false;
  printPath(root, node1, path1, found);

  cout << "path to node " << node1->val << ": "; 
  for(auto a: path1) 
    cout << a->val << " " ;
  cout << endl;

  found = false;
  printPath(root, node2, path2, found);
  cout << "path to node " << node2->val << ": "; 
  for(auto a: path2) 
    cout << a->val << " " ;
  cout << endl;
  return lastCommonNode(path1, path2);
}
/*
bool subTree(TreeNode *root1, TreeNode *root2)
{
  if(root1 == NULL && root2 == NULL) return true;
  if(root1 == NULL || root2 == NULL) return false;
  vector<int> preOrder1, inOrder1, preOrder2,inOrder2;
  preOrder1 = preTraverse(root1);
  preOrder2 = preTraverse(root2);
  inOrder1 = inTraverse(root1);
  inOrder2 = inTraverse(root2);
  
}
*/
bool match(TreeNode *root1, TreeNode *root2)
{
  //递归结束条件
  if(root1 == NULL && root2 == NULL) return true;
  if(root1 == NULL || root2 == NULL) return false;
  if(root1->val != root2->val)
    return false;
  return match(root1->left, root2->left) && match(root1->right, root2->right);
}
bool subTreeHelper(TreeNode *root1, TreeNode *root2)
{
  if(root1 == NULL) return false;
  if(root1->val == root2->val)
  {
    if(match(root1, root2)) return true;
  }
  return subTreeHelper(root1->left, root2 ) || subTreeHelper(root1->right, root2);
}
bool subTree(TreeNode *root1, TreeNode *root2)
{
  if(root2 == NULL) return true;
  return subTreeHelper(root1,root2) ;
}
/*
void helper(TreeNode *root, const int target, vector<vector<int> > &ret, vector<int> &cur)
{
  if (root == NULL)
  {
    int sum = 0;
    for(auto a : cur)
      sum += a->val;
    if(sum == target)
    {
      ret.push_back(cur);
    }
    return;
  }
  vector<int> left_cur;
  vector<int> right_cur;
  helper(root->left,target,ret,left_cur);
  helper(root->right,target,ret,right_cur);
  int sum = root->val;
  for(auto a:left_cur)
    sum += a;
  for(auto a: right_cur)
    sum += a;
  if(sum == target)
  {
    vector<int> temp(left_cur.begin(), left_cur.end());
    temp.insert(temp.end(), root->val);
    temp.insert(temp.end(), right_cur.begin(), right_cur.end());
    ret.push_back(temp);
  }
}
int pathSum(TreeNode *root, const int target)
{
  if(root == NULL) return;
  vector<vector<int> > ret;
  vector<int> cur;
  helper(root,target,cur, ret);
  return ret;
}
*/
int main()
{
  vector<int> data = {1,2,4,-1,3,-1,5};
  TreeNode *root = Build(data);
  cout << "Test : " << root->left->parent->val << endl;
  cout << "Test : " << root->right->parent->val << endl;

  traverse(root);
  cout << endl;
  preTraverse(root);
  inTraverse(root);
  posTraverse(root);
  cout << "Depth : " << depth(root) << endl;
  cout << "Balance :" << isBalance(root) << endl;
  cout << "Balance2 :" << isBalance2(root) << endl;

  destory(root);
  assert(root == NULL);
//  vector<int> data2 = {1,2,3,4,5,6,7};
/*
  vector<int> data2 = {1,1};
  root = createMinDepthTree(data2, 0, data2.size()-1);
  assert(isBST(root));
  preTraverse(root);
  inTraverse(root);
  vector<ListNode *> heads = printKLevelNode(root);
  cout << heads.size() << " " << depth(root) << endl;
  assert(heads.size() == depth(root));
  destory(root);
  assert(root == NULL);
  for(int i = 0 ; i < heads.size() ; ++i)
  {
    printList(heads[i]);
  }
  for(int i = 0 ; i < heads.size() ; ++i)
  {
    destoryList(heads[i]);
    assert(heads[i] == NULL);
  }
  root = new TreeNode(1);
  root->left = new TreeNode(1);
  assert(isBST(root));
  destory(root);



  //find the next node
//  vector<int> data3 = {4, 3, 7, 1,-1,5,-1,-1,2,-1,-1,-1,6};
  root = new TreeNode(4);
  root->left = new TreeNode(3);
  root->left->parent = root;
  root->right = new TreeNode (7);
  root->right->parent = root;
  TreeNode * t = root->left;
  t->left =  new TreeNode (1);
  t->left->parent = t;
  t = root->right;
  t->left =  new TreeNode (5);
  t->left->parent = t;
  t = root->left->left;
  t->right = new TreeNode(2);
  t->right->parent = t;
  t = root->right->left;
  t->right = new TreeNode (6);
  t->right->parent = t;
  traverse(root);
  cout << endl;
  inTraverse(root);
  posTraverse(root);
  t = root->right;//->left->right;
  cout << "prev : " << t->val << endl;
  t = next_node(root, t);
  cout << "next : " << (t?(t->val):(-1)) << endl;
  TreeNode *node1  = root->left->left, *node2 = root->left->left->right;
  cout << node1->val << " " << node2->val <<  "common ancester : " << commonAncester(node1, node2)->val << endl;
  cout << commonAncester2(root, node1, node2)->val << endl;

  cout <<   commonAncester3(root, node1, node2)->val << endl;
  TreeNode *root2 = new TreeNode(7);
  root2->left = new TreeNode(5);
  root2->left->right =  new TreeNode(6);
  if(subTree(root,root2)) 
    cout << "is sub..." << endl;
  else cout << "not sub ..." << endl;
  destory(root);
  destory(root2);
*/  
  return 0;
}
