#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>


using namespace std;

struct Node {
    int id;
    string username;

    Node (int id, string username) {
        this->id = id;
        this->username = username;
    }
};

class BST {
    private: 
        struct TreeNode {
            Node* data;
            TreeNode* left;
            TreeNode* right;

            TreeNode(Node *data) {
                this->data = data;
                this->left = nullptr;
                this->right = nullptr;
            }
        };
    
        TreeNode* root;

        TreeNode* insertNode(TreeNode* root, Node* data) {
            if( root == nullptr ) return new TreeNode(data);

            if( data->username < root->data->username ){
                root->left = insertNode(root->left, data);
            } else {
                root->right = insertNode(root->right, data);
            }

            return root;
        }

        TreeNode* searchNode(TreeNode* root, string username) {
            if( root == nullptr ) return nullptr;

            if( root->data->username == username ) return root;

            if( username < root->data->username ) {
                return searchNode(root->left, username);
            } else {
                return searchNode(root->right, username);
            }
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(Node* data) {
            this->root = insertNode(this->root, data);
        }

        Node* search(string username) {
            TreeNode* node = searchNode(this->root, username);

            if( node == nullptr ) return nullptr;
            
            return node->data;
        }
};


int main() {

    return 0;
};