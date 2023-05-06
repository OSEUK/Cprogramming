/* 201910903 오세욱 20230504 과제 1 */
/* 단말 노드 개수 구하기 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode n1={1, NULL, NULL};
TreeNode n2={4, &n1, NULL};
TreeNode n3={16, NULL, NULL};
TreeNode n4={25, NULL, NULL};
TreeNode n5={20, &n3, &n4};
TreeNode n6={15, &n2, &n5};
TreeNode *node= &n6;

int get_leaf_node_count(TreeNode *node)
{
    int count = 0;
    if(node == NULL)
        return 0;
    else if(node->left == NULL && node->left == NULL)
        return 1;
    else
        return get_leaf_node_count(node->left) + get_leaf_node_count(node->right);
}
int main(void)
{
    printf("단말노드의 개수는 %d입니다.",get_leaf_node_count(node));
    return 0;
}

