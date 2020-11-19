/*
0116. Populating Next Right Pointers in Each Node

给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

思路1：层序遍历，对每一层的结点，相互设指针。但是不符合常数空间的要求。

*/

#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;

        queue<Node *> q1, q2;
        q1.emplace(root);
        while (!q1.empty() || !q2.empty()) {
            while (!q1.empty()) {
                Node *currentNode = q1.front();
                q1.pop();
                // 是当前层最后一个结点
                if (!q1.empty())
                    currentNode->next = q1.front();
                else
                    currentNode->next = nullptr;
                // 将其孩子放入另一个队列
                if (currentNode->left != nullptr)
                    q2.emplace(currentNode->left);
                if (currentNode->right != nullptr)
                    q2.emplace(currentNode->right);
            }
            while (!q2.empty()) {
                Node *currentNode = q2.front();
                q2.pop();
                // 是当前层最后一个结点
                if (!q2.empty())
                    currentNode->next = q2.front();
                else
                    currentNode->next = nullptr;
                // 将其孩子放入另一个队列
                if (currentNode->left != nullptr)
                    q1.emplace(currentNode->left);
                if (currentNode->right != nullptr)
                    q1.emplace(currentNode->right);
            }
        }

        return root;
    }
};


