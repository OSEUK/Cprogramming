/* ���� Ž�� Ʈ���� ����ϴ� ����ó ���α׷�*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char name[80];
    char phone[200];
    struct TreeNode *left, *right;
}TreeNode;

// ���� ��ȸ
void inorder( TreeNode *root ){
	if ( root ){
		 inorder( root->left );	// ���ʼ���Ʈ�� ��ȸ
		 printf("%10s : %s \n", root->name, root->phone ); 	// ���
		 inorder( root->right );	// �����ʼ���Ʈ�� ��ȸ
	}
}

TreeNode  *search(TreeNode  *node,  char name[])
{
	// strcmp ���. �� ���ڿ��� ������ 0, ������ ������ -1, �������� ������ 1.
      if ( node == NULL )  
               return NULL;
      if ( strcmp(name , node->name) == 0 ) 
              return node;                                   
      else if ( strcmp(name , node->name)< 0 )
            return  search(node->left, name);        
      else
            return  search(node->right, name);    
}  

TreeNode * new_node(char name[], char phone[])
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	// strcpy�� ����� �Է¹��� ���ڿ� name�� temp->name���� ī���Ѵ�.
	strcpy(temp->name, name);
    strcpy(temp->phone, phone);
	temp->left = temp->right = NULL;

	return temp;
}
TreeNode * insert_node(TreeNode * node, char name[], char phone[])
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) 
        return new_node(name, phone);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (strcmp(name , node->name)<0)
		node->left = insert_node(node->left, name, phone);
	else if (strcmp(name , node->name) > 0)
		node->right = insert_node(node->right, name, phone);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� 
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�. 
TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}

TreeNode * delete_node(TreeNode * root, char name[])
{
	if (root == NULL) 
        return root;
	
	if (strcmp(name , root->name) < 0)
		root->left = delete_node(root->left, name);
	
	else if (strcmp(name , root->name) > 0)
		root->right = delete_node(root->right, name);
	// ������ ��带 ã�Ҵٸ�. 
    else {
		if (root->left == NULL & root->right == NULL) {
			free(root);
			return NULL;
		}
		// ������ null�̸� ������ ���� �θ��带 ����
		else if (root->left == NULL) {
			TreeNode * temp = root->right;
			free(root);
			return temp;
		}
		// �������� null�̸� ���ʰ� ����
		else if (root->right == NULL) {
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		// ������ ��尡 ���� ������ �ڽĳ�带 ������ �ִٸ�
		// root�� �����ʺκ��� ���� ���� �� = temp
		TreeNode * temp = min_value_node(root->right);

		// ������ ����� �̸��� temp�� �ٲ۴�
		strcpy(root->name , temp->name);
		
		// root�� right����Ʈ���߿� ���� ������ ��尡 ������ ���������Ƿ� delete_node�� �ٽ� ����Ͽ� ����
		root->right = delete_node(root->right, temp->name);
	}
	return root;
}
int main(void)
{
	char	command, name[80], phone[200];
	TreeNode* root = NULL, * p;
	// ��� �ݺ�
	while(1) {
		printf("����(i), Ž��(s), ����(d), ���(p), ����(q): ");
		scanf("%c", &command);
		
		switch (command) {
			case 'i':
				printf("ģ���� �̸�: ");
				scanf("%s", name);
				printf("ģ���� ��ȭ��ȣ: "); 
				scanf("%s", phone);
				root = insert_node(root, name, phone);
				break;
			case 'd':
				printf("  > ������ ģ�� �̸�: "); 
				scanf("%s", name);
				root = delete_node(root, name);
				break;
			case 'p':
				inorder(root);
				printf("\n");
				break;
			case 's':
				printf("ģ���� �̸�: ");
				scanf("%s", name);
				p = search(root, name);
				if (p != NULL) {
					printf("%s�� ��ȭ��ȣ: %s\n", name, p->phone);
				}
				else {
					printf("%s�� ã���� ����\n",name);
				}
				break;
			// q�Է½� �ݺ� ����.
			case 'q':
				return 0;
		}
		rewind(stdin);
	} 
	
	return 0;
}