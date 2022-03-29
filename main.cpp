/*
Michael Huang
Professor Ross
CISP 430
March - 4 -2022
*/
#include<iostream>
using namespace std;

/* Assuming that all values in given array or nodes are all unique */
/* Given struct */
struct node{
	int data;
	node* left;
	node* right;
};

/*Function Prototype */
void insert(int);


// Just some global variables
node* head = 0;
node* current = 0;

void print_preorder(node* root){
	// Node Left Right
	cout<<root->data<<" ";
	if(root->left){
		print_preorder(root->left);
	}

	if(root->right){
		print_preorder(root->right);
	}
}

void print_postorder(node* root){
	// Left Right Node
	if (root->left) { print_postorder(root->left); }

	if (root->right) {
	    print_postorder(root->right);
	}

	cout << root->data <<" ";
}

void print_inorder(node* root){
	// Left Node Right
    if (root->left) {
        print_inorder(root->left);
    }

    cout << root->data <<" ";

    if (root->right) {
        print_inorder(root->right);
    }
}

int search(int data, node* root){
	int stuff = 0;

	// Off the bat
	if(root == NULL){
		return 0;
	}

	if(root->data == data){
		return root->data;
	}

	if(root->data != data && root->data > data){
		stuff = search(data, root->left);
	}
	
	if(root->data != data && root->data < data){
		stuff = search(data, root->right);
	}
	
	return stuff;
}

void clearTree(node* root){
	// Deleting the left side first then the right
	if(root->left){
		clearTree(root->left);
	}

	if(root->right){
		clearTree(root->right);
	}

	// std::cout<<"End of the line"<<root->data<<std::endl;
	
	if(root == head){
		head = nullptr;
		return;
	}

	delete root;
}

int main(){
	
	int trail[8] = {1, 5, 4, 6, 7, 2, 3};	// Put a zero there to stop it
	int final[300] = {
					150,125,175,166,163,123,108,116,117,184,165,137,141,111,138,122,109,194,143,183,178,173,
					139,126,170,190,140,188,120,195,113,104,193,181,185,198,103,182,136,115,191,144,145,155,
					153,151,112,129,199,135,146,157,176,159,196,121,105,131,154,107,110,158,187,134,132,179,
					133,102,172,106,177,171,156,168,161,149,124,189,167,174,147,148,197,160,130,164,152,142,
					162,118,186,169,127,114,192,180,101,119,128,100
					};

	// index of the element
	for(int i = 0; trail[i] != 0; i++){
		insert(trail[i]);
	}

	std::cout<<"Small Array";
	std::cout<<std::endl;
	cout<<"Preorder:  ";
	print_preorder(head);
	std::cout<<std::endl<<std::endl;
	cout<<"Postorder: ";
	print_postorder(head);
	std::cout<<std::endl<<std::endl;
	cout<<"Inorder:   ";
	print_inorder(head);
	std::cout<<std::endl<<std::endl;;

	std::cout<<search(1, head)<<std::endl;
	std::cout<<search(4, head)<<std::endl;
	std::cout<<search(2, head)<<std::endl;
	std::cout<<std::endl;

	// Clear Tree
	clearTree(head);

	for(int i = 0; final[i] != 0; i++){
		insert(final[i]);
	}

	std::cout<<"Big Array";
	std::cout<<std::endl;
	cout<<"Preorder:  ";
	print_preorder(head);
	std::cout<<std::endl<<std::endl;
	cout<<"Postorder: ";
	print_postorder(head);
	std::cout<<std::endl<<std::endl;
	cout<<"Inorder:   ";
	print_inorder(head);
	std::cout<<std::endl<<std::endl;

	std::cout<<search(42, head)<<std::endl;
	std::cout<<search(142, head)<<std::endl;
	std::cout<<search(102, head)<<std::endl;
	std::cout<<search(190, head)<<std::endl;
	std::cout<<std::endl;

	std::cout<<"Stop"<<std::endl;

	return 0;
}


void insert(int data){
	// Create a new node
	node* temp = new node;
	temp->data = data;
	temp->left = 0;
	temp->right = 0;

	// Turning of the wheel
	if(head == 0){
		head = current = temp;
		temp = 0;

		return;
	}

	current = head; // Reseting the pointer
	while(true){
		// Comparing values
		// temp small root big
		if(current->data > temp->data && current->left == 0){
			current->left = temp;	// The Many-Faced God 
			temp = 0;	// No Russian
			break;
		}
		// tamp big root small
		else if(current->data < temp->data && current->right == 0){
			current->right = temp;
			temp = 0;
			break;
		}

		if(current->data > temp->data && current->left != 0){
			current = current->left;
		}
		else if(current->data < temp->data && current->right != 0){
			current = current->right;
		}
	}
}

