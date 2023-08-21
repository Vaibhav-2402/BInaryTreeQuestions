#include<iostream>
#include<queue>

using namespace std;

class node {
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void buildFromLevelOrder(node* &root) {
    queue<node*> q;
    int nodeData;
    cout << " Enter the node data ";
    cin >> nodeData;

    root = new node(nodeData);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        int leftNode;
        cout << "Enter the data for left node " << temp -> data<< endl;
        cin >> leftNode;

        if(leftNode != -1) {
            temp -> left = new node(leftNode);
            q.push(temp -> left);
        }

        int rightNode;
        cout << "Enter the data for Right node "<< temp -> data << endl;
        cin >> rightNode;

        if(rightNode != -1){
            temp -> right = new node(rightNode);
            q.push(temp -> right);
        }
    }
}

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //temp null hai matlab pehle wala row 
            //traverse ho chuka hai

            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << "  ";

            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
            
        }

    }

}

int main() {
    node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    return 0;
}