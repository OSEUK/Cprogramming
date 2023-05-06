/* 201910903 ������ 20230504 ���� 2 */
/* ���� Ʈ�� ���� ���ϱ� */

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

int get_height(TreeNode *node)
{
    int maxheight;
    if( node == NULL ){
        return 0;
    }
    if(get_height(node->left) >= get_height(node->right))
        return 1 + get_height(node->left);
    else
        return 1 + get_height(node->right);

}


int main(void)
{
    printf("Ʈ���� ���̴� %d�Դϴ�.",get_height(node));
    return 0;
}

