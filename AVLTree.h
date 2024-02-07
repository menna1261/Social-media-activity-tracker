#ifndef AVLTREE_H
#define AVLTREE_H
#include<iostream>
#include<user.h>
#include<vector>
#include<queue>
#include<cassert>
template<class T>
class AVLTree
{
    private:
	T data { };
	int height { };
	AVLTree* left { };
	AVLTree* right { };
	vector<int>sizes;
	vector<user>users;

	int ch_height(AVLTree* node) {	// child height
		if (!node)
			return -1;			// -1 for null
		return node->height;	// 0 for leaf
	}
	int update_height() {	// call in end of insert function
		return height = 1 + max(ch_height(left), ch_height(right));
	}
	int balance_factor() {
		return ch_height(left) - ch_height(right);
	}
	AVLTree* right_rotation(AVLTree* Q) {
		cout << "right_rotation " << Q->data << "\n";
		AVLTree* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	AVLTree* left_rotation(AVLTree* P) {
		cout << "left_rotation " << P->data << "\n";
		AVLTree* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update_height();
		Q->update_height();
		return Q;
	}

	AVLTree* min_node() {
		AVLTree* cur = this;
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}
	void special_delete(AVLTree* child) {
		data = child->data;
		left = child->left;
		right = child->right;
		delete child;
	}
	AVLTree* delete_node(string target, AVLTree* node) {

		if (!node)
			return nullptr;

		if (t_hash_function(target) < node->data.hash_function())
			node->left = delete_node(target, node->left);
		else if (t_hash_function(target) > node->data.hash_function())
			node->right = delete_node(target, node->right);
		else {
			if (!node->left && !node->right) {
				delete node;
				node = nullptr;
			}
			else if (!node->right) 	// case 2: has left only
				node->special_delete(node->left);		// connect with child
			else if (!node->left)	// case 2: has right only
				node->special_delete(node->right);
			else {
				AVLTree* mn = node->right->min_node();
				node->data = mn->data;
				node->right = delete_node(node->data.return_name(), node->right);
			}
		}
		 // delete the size of the deleted node from the sizes vector
		 sizes.erase(sizes.begin()+return_index(node->data.return_q_size()));
		 users.erase(users.begin()+return_index(node->data.return_q_size()));

		if (node) {
			node->update_height();
			node = balance(node);
		}
		cout<<"user has been deleted successfully "<<endl;

		return node;
	}

	AVLTree* balance(AVLTree* node) {
		if (node->balance_factor() == 2) { 			// Left
			if (node->left->balance_factor() == -1)	// Left Right?
				node->left = left_rotation(node->left);	// To Left Left

			node = right_rotation(node);	// Balance Left Left
		} else if (node->balance_factor() == -2) {
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);

			node = left_rotation(node);
		}
		return node;
	}

	void reroot(AVLTree* node) {
		if (node == this)
			return;

		swap(this->data, node->data);
		swap(this->height, node->height);

		if (this == node->left) {
			// Give node my 2 children
			// I take his right child and
			// point to him as my left
			swap(node->right, this->right);
			node->left = this->left;
			this->left = node;
		} else if (this == node->right) {
			swap(node->left, this->left);
			node->right = this->right;
			this->right = node;
		}
	}
	public:
	AVLTree(T data):
			data(data) {
			    sizes.push_back(data.return_q_size());
	}
	AVLTree(){}

	void level_order_traversal() {
		queue<AVLTree*> nodes_queue;
		nodes_queue.push(this);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout << "Level " << level << ": ";
			while (sz--) {
				AVLTree*cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->data << " ";
				//cur->data.display_activities();
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			level++;
			cout << "\n";
		}
		cout << "******************\n";
	}

	void insert(T target) {
		if (target.hash_function() < data.hash_function()) {
			if (!left)
				left = new AVLTree(target);
			else
				left->insert(target);
		} else if (target.hash_function() > data.hash_function()) {
			if (!right)
				right = new AVLTree(target);
			else
				right->insert(target);
		}
		update_height();
		//this = balance(this);
		reroot(balance(this));
		sizes.push_back(target.return_q_size());
		users.push_back(target);
		cout<<"User has been inserted successfully "<<endl;

		//target.add_activites();

	}
	 unsigned int t_hash_function (string username)
    {

        unsigned int sum=0;
        for (size_t i = 0; i < username.length(); ++i) {
                 sum += static_cast<int>(username[i]);

    }
        // hash_value=sum;
       return sum%100;

    }

	void delete_value(string target) {
		if (t_hash_function(target) == data.hash_function() && !left && !right)
			return;	// can't remove root in this structure
		reroot(delete_node(target, this));
	}

	bool is_bst() {
		bool left_bst = !left || data > left->data && left->is_bst();

		if (!left_bst)
			return false;

		bool right_bst = !right || data < right->data && right->is_bst();
		return right_bst;
	}
    void verify() {
		assert(abs(balance_factor()) <= 1);
		assert(is_bst());
	}
	AVLTree<T>* searchNode(AVLTree<T>* node, string target) {
        if (!node || node->data.hash_function() ==t_hash_function(target)) {
            cout<<node->data<<" "<<endl;
            cout<<"(1) Add activites\n(2)Remove activities(3)Return "<<endl;
                 int c;cin>>c;
            switch(c){
          case 1:
                 node->data.add_activites();
                 break;
          case 2:

              node->data.remove_activities();

            break;
          case 3:
            return node;
            break;
        }
         return node;
        }
        if (t_hash_function(target) < node->data.hash_function()) {
            return searchNode(node->left, target);
        }

        return searchNode(node->right, target);

	}
    bool search_value(string target)
    {
        if (t_hash_function(target) == data.hash_function()){
            searchNode(this,target);
        //  cout<<"aaaa"<<endl;

        return true;}
        if(searchNode(this,target)!=nullptr)
        {
            return true;
        }
        return false;
    }
	void most_active_user(){

	  int k =*max_element(sizes.begin(),sizes.end());
	  for(int i =0;i<sizes.size();i++){
        if(sizes[i]==k){
            cout<<users[i];
        }
	  }

	}
int return_index(int k){
	 auto it = find(sizes.begin(), sizes.end(), k);

    // If element was found
    if (it != sizes.end())
    {

        // calculating the index
        // of K
        int index = it - sizes.begin();
       return index;
    }}
};

#endif // AVLTREE_H
