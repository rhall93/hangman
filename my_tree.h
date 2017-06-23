#include "my_string.h"
#include "my_vect.h"
typedef struct tree_node
{
	MY_STRING key;
	STR_VECT words;
	struct tree_node* left_child;
	struct tree_node* right_child;
}Tree_node;


typedef struct tree
{
	Tree_node* root; 
}Tree;



Tree* my_tree_init_default();


Tree_node* my_tree_get_root(Tree hTree);

MY_STRING my_tree_node_get_key(Tree_node pTree_node);

/*STR_VECT my_tree_node_get_vector(TREE_NODE hTree_node);*/

Tree_node* my_tree_find_key(Tree_node *pRoot, MY_STRING hKey);

Tree_node* my_tree_insert_key(Tree *pTree, MY_STRING hKey);

void my_tree_largest_key(Tree_node *pRoot, Tree_node **pMax, int* max);
void my_tree_print(Tree_node *pRoot);
void my_tree_destroy_nodes(Tree_node *pRoot);

