#include <exception>
#include <cstdio>

template <class T> class Node{
	public:
		T data;
		Node<T> *left;
		Node<T> *right;
		Node<T> *parent;
		Node(T d):data(d){

	    };
	    bool operator == (const Node &n){
	    	return n.data == data;
	    }
	    ~Node(){

	    }
};

Node<int>* process(int* inorder,int* postorder, int instart, int inend, int poststart, int postend){
	int tmp = postorder[postend];
	Node<int> *node = new Node<int> (tmp);

	if(postend == poststart){
		if(instart == inend && inorder[instart] == tmp){
			return node;
		} else {
			throw std::exception();
		}
	}

	int rootindex = instart;
	while(rootindex < inend){
		if(tmp == inorder[rootindex])
			break;
		rootindex++;
	}
	if (rootindex == inend&& inorder[rootindex] != tmp)
		throw std::exception();

	int leftlen = rootindex - instart;
	if(leftlen >= 1)
		node->left = process(inorder, postorder, instart, rootindex-1, poststart, poststart+leftlen -1);
	if(postend -1 >= poststart + leftlen)
		node->right = process(inorder, postorder, rootindex+1, inend, poststart+leftlen, postend -1);
	return node;
}

void print_preorder(Node<int> *tree){
	printf("%d ",tree->data);
	if(tree->left !=NULL)
		print_preorder(tree->left);
	if(tree->right != NULL)
		print_preorder(tree->right);
}

int main(){
	int n;
	scanf("%d",&n);
	int *inorder = new int[n];
	int *postorder = new int [n];

	for(int i = 0; i< n; i++){
		scanf("%d",&inorder[i]);
	}

	for(int i=0; i < n; i++){
		scanf("%d", &postorder[i]);
	}

	Node<int> *tree = NULL;
	try{
		tree = process(inorder, postorder, 0, n-1, 0, n-1);
		print_preorder(tree);
	} catch(std::exception){
		printf("-1\n");
	}
	delete[] inorder;
	delete[] postorder;

	if(tree != NULL)
		delete tree;
	return 0;
}


























