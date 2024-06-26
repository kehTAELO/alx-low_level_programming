#include "hash_tables.h"

/**
 * create_and_add_node - insert node into hash table
 * @ht: hash table
 * @key: can't be empty string
 * @value: value
 * @idx: index to insert
 * Return: 1
 */
int create_and_add_node(hash_table_t *ht, const char *key, const char *value,
			unsigned long int idx)
{
	hash_node_t *node = NULL;
	char *k;
	char *v;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);

	k = strdup(key);
	if (!k)
	{
		free(node);
		return (0);
	}

	v = strdup(value);
	if (!v)
	{
		free(k);
		free(node);
		return (0);
	}

	node->key = k;
	node->value = v;

	if ((ht->array)[idx] == NULL)
		node->next = NULL;
	else
		node->next = (ht->array)[idx];
	(ht->array)[idx] = node;

	return (1);
}

/**
 * hash_table_set - add elements to hash table
 * @ht: hash table
 * @key: can't be empty string
 * @value: value
 * Return: 1 
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{

	unsigned long int idx;
	hash_node_t *node = NULL;
	char *v;

	if (!ht || !(ht->array) || !key || strlen(key) == 0 || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	node = (ht->array)[idx];
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;
	if (node != NULL)
	{
		v = strdup(value);
		if (!v)
			return (0);
		if (node->value)
			free(node->value);
		node->value = v;
		return (1);
	}

	return (create_and_add_node(ht, key, value, idx));
}

