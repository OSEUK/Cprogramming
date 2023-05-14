/* 이진 탐색 트리를 사용하는 연락처 프로그램*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char name[80];
    char phone[200];
    struct TreeNode *left, *right;
}TreeNode;

// 중위 순회
void inorder( TreeNode *root ){
	if ( root ){
		 inorder( root->left );	// 왼쪽서브트리 순회
		 printf("%10s : %s \n", root->name, root->phone ); 	// 출력
		 inorder( root->right );	// 오른쪽서브트리 순회
	}
}

TreeNode  *search(TreeNode  *node,  char name[])
{
	// strcmp 사용. 두 문자열이 같으면 0, 왼쪽이 작으면 -1, 오른쪽이 작으면 1.
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
	// strcpy를 사용해 입력받은 문자열 name을 temp->name으로 카피한다.
	strcpy(temp->name, name);
    strcpy(temp->phone, phone);
	temp->left = temp->right = NULL;

	return temp;
}
TreeNode * insert_node(TreeNode * node, char name[], char phone[])
{
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) 
        return new_node(name, phone);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (strcmp(name , node->name)<0)
		node->left = insert_node(node->left, name, phone);
	else if (strcmp(name , node->name) > 0)
		node->right = insert_node(node->right, name, phone);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 
// 새로운 루트 노드를 반환한다. 
TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
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
	// 삭제할 노드를 찾았다면. 
    else {
		if (root->left == NULL & root->right == NULL) {
			free(root);
			return NULL;
		}
		// 왼쪽이 null이면 오른쪽 노드와 부모노드를 연결
		else if (root->left == NULL) {
			TreeNode * temp = root->right;
			free(root);
			return temp;
		}
		// 오른쪽이 null이면 왼쪽과 연결
		else if (root->right == NULL) {
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		// 삭제할 노드가 왼쪽 오른쪽 자식노드를 가지고 있다면
		// root의 오른쪽부분의 가장 작은 수 = temp
		TreeNode * temp = min_value_node(root->right);

		// 삭제할 노드의 이름을 temp로 바꾼다
		strcpy(root->name , temp->name);
		
		// root의 right서브트리중에 같은 숫자의 노드가 여전히 남아있으므로 delete_node를 다시 사용하여 삭제
		root->right = delete_node(root->right, temp->name);
	}
	return root;
}
int main(void)
{
	char	command, name[80], phone[200];
	TreeNode* root = NULL, * p;
	// 계속 반복
	while(1) {
		printf("삽입(i), 탐색(s), 삭제(d), 출력(p), 종료(q): ");
		scanf("%c", &command);
		
		switch (command) {
			case 'i':
				printf("친구의 이름: ");
				scanf("%s", name);
				printf("친구의 전화번호: "); 
				scanf("%s", phone);
				root = insert_node(root, name, phone);
				break;
			case 'd':
				printf("  > 삭제할 친구 이름: "); 
				scanf("%s", name);
				root = delete_node(root, name);
				break;
			case 'p':
				inorder(root);
				printf("\n");
				break;
			case 's':
				printf("친구의 이름: ");
				scanf("%s", name);
				p = search(root, name);
				if (p != NULL) {
					printf("%s의 전화번호: %s\n", name, p->phone);
				}
				else {
					printf("%s를 찾을수 없음\n",name);
				}
				break;
			// q입력시 반복 종료.
			case 'q':
				return 0;
		}
		rewind(stdin);
	} 
	
	return 0;
}