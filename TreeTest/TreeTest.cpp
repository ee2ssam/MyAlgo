// TreeTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

//이진 트리 구현
// char 데이터를 가지고 있는 노드
struct Node
{
    char data;
    Node* left;
    Node* right;

    //생성자
    Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

//전위순회 : 현재노드(node) -> 왼쪽 트리 -> 오른쪽 트리
void preorder(Node* node)
{
    if (node)
    {
        //현재노드:data 출력
        cout << node->data << ", ";
        preorder(node->left);
        preorder(node->right);
    }
}

//중위순회: 왼쪽 트리 -> 현재노드(node) -> 오른쪽트리
void inorder(Node* node)
{
    if (node)
    {
        inorder(node->left);
        //현재노드: data 출력
        cout << node->data << ", ";
        inorder(node->right);
    }
}

//후위순회: 왼쪽트리 -> 오른쪽 트리 -> 현재노드(node)
void postorder(Node* node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        //현재노드: data 출력
        cout << node->data << ", ";
    }
}

//레벨순서 순회: 낮은 레벨에 있는 노드부터 방문
void levelorder(Node* node)
{
    queue<Node*> q;
    q.push(node);       //먼저 root 노드를 큐에 넣고 시작

    while (!q.empty())
    {
        auto curr = q.front();      //꺼내서 없애기전에 저장
        q.pop();

        //저장한 데이터 처리
        cout << curr->data << ", ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

//트리삭제 : 왼쪽트리삭제->오른쪽트리삭제->현재노드 삭제
void delete_tree(Node* node)
{
    if (node)
    {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}



int main()
{
    /*
           A
         B   C
        D E   F
    */

    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    preorder(root);    cout << endl;
    inorder(root);  cout << endl;
    postorder(root); cout << endl;

    levelorder(root); cout << endl;

    delete_tree(root);
}
