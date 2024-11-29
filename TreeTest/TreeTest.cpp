// TreeTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

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
}
