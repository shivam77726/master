typedef struct Node
{
	int data;
	struct Node *left,*right;
	int height;

}Node;


typedef struct
{
	Node* node;
	int key;
}DSinsert;
