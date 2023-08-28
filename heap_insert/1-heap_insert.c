#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: The value store in the node to be inserted
 * Return: A tree with max heap ordering
 */
heap_t *heap_insert(heap_t **root, int value)
{
  heap_t *new_node, *parent;

  if (!root)
    return NULL;

  new_node = binary_tree_node(NULL, value);
  if (!new_node)
    return NULL;

  if (!*root)
    {
      *root = new_node;
      return new_node;
    }

  parent = *root;
  while (parent)
    {
      if (parent->left && parent->right)
        {
	  if (!parent->left->left || !parent->left->right)
	    new_node->parent = parent->left;
	  else
	    new_node->parent = parent->right;
        }
      else
        {
	  new_node->parent = parent;
        }

      parent = parent->left;
    }

  if (new_node->parent->left)
    new_node->parent->right = new_node;
  else
    new_node->parent->left = new_node;

  return node_swap(new_node);
}

/**
 * node_swap - Swaps current node with larger node
 * @node: Pointer to current node
 * Return: A new node
 */
heap_t *node_swap(heap_t *node)
{
  while (node && node->parent)
    {
      if (node->n > node->parent->n)
        {
	  int temp = node->n;
	  node->n = node->parent->n;
	  node->parent->n = temp;
	  node = node->parent;
        }
      else
        {
	  break;
        }
    }
  return node;
}
