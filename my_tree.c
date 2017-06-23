#include <stdlib.h>
#include "my_tree.h"



Tree* my_tree_init_default()
{
	Tree *pTree = (Tree*) malloc(sizeof(Tree));
	if(pTree == NULL)
	{
		return NULL;
	}
	pTree->root = NULL;
	return pTree;
}

/*TREE_NODE my_tree_get_root(TREE hTree)
{
	Tree *pTree = (Tree*) hTree;
	return (TREE_NODE) pTree->root;
}*/

/*MY_STRING my_tree_node_get_key(TREE_NODE hTree_node)
{
	Tree_node *pTree_node = (Tree_node*) hTree_node;

	return pTree_node->key;
}*/

/*STR_VECT my_tree_node_get_vector(TREE_NODE hTree_node)
{
	Tree_node *pTree_node = (Tree_node*) hTree_node;
	
	return pTree_node->words;
}*/
/* adapted from https://en.wikipedia.org/wiki/Binary_search_tree */
Tree_node* my_tree_find_key(Tree_node *pRoot, MY_STRING hKey)
{
	if( pRoot == NULL   ||
		my_string_compare(pRoot->key, hKey) == 0 )
	{	
		return pRoot;
	}
	else if(my_string_compare(pRoot->key, hKey) < 0)
	{
		return my_tree_find_key(pRoot->left_child, hKey);
	}
	else 
	{
		return my_tree_find_key(pRoot->right_child, hKey);
	}
}

/* adapted from https://www.tutorialspoint.com/data_structures_algorithms/binary_search_tree.htm */
Tree_node* my_tree_insert_key(Tree *pTree, MY_STRING hKey)
{
	Tree_node *pMark;
	Tree_node *pParent;
	Tree_node *pNew_node = (Tree_node*) malloc(sizeof(Tree_node));
	if(pNew_node == NULL)
	{
		return NULL;
	}

	pNew_node->words = my_vect_init_default();
	pNew_node->left_child = NULL;
	pNew_node->right_child = NULL;
	my_string_assignment(&pNew_node->key, hKey);

	/*printf("new node:%s\n", my_string_get_data(pNew_node->key));*/

	if(pTree->root == NULL)
	{
		pTree->root = pNew_node;
		return pNew_node;
	}
	else
	{
		pMark = pTree->root;
		pParent = NULL;

		while(1)
		{
			pParent = pMark;

			if(my_string_compare(pMark->key, hKey) < 0)
			{
				pMark = pMark->left_child;
				if(pMark == NULL)
				{
					pParent->left_child = pNew_node;
					return pNew_node;
				}
			}
			else
			{
				pMark = pMark->right_child;
				if(pMark == NULL)
				{
					pParent->right_child = pNew_node;
					return pNew_node;
				}
			}
		}
	}
}

void my_tree_largest_key(Tree_node* pRoot, Tree_node **pMax, int *max)
{
	if(pRoot == NULL)
	{
		return;
	}
	my_tree_largest_key(pRoot->left_child, pMax, max);
	if(my_vect_get_size(pRoot->words) > *max)
	{
		*max = my_vect_get_size(pRoot->words);
		*pMax = pRoot;
	}
	my_tree_largest_key(pRoot->right_child, pMax, max);
}

void my_tree_destroy_nodes(Tree_node *pRoot)
{
	/*printf("destroy root: %s\n", my_string_get_data(pRoot->key));*/
	if(pRoot != NULL)
	{
		
	
	
	my_tree_destroy_nodes(pRoot->left_child);
	my_tree_destroy_nodes(pRoot->right_child);

	
	my_vect_destroy(&(pRoot->words));
	
	my_string_destroy(&(pRoot->key));

	free(pRoot);
	pRoot = NULL;
	}
}

void my_tree_print(Tree_node *pRoot)
{
	if(pRoot == NULL)
	{
		return;
	}

	my_tree_print(pRoot->left_child);
	printf("%s\n", my_string_get_data(pRoot->key));
	my_tree_print(pRoot->right_child);
}


