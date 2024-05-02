#include "hash_tables.h"

/**
 * hash_table_get - this will be the given key
 * @ht: this is a hash table
 * @key: key
 * Return: value
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *tmp;

	if (!ht || !key)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);

	tmp = (ht->array)[idx];
	while (tmp != NULL && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	else
		return (tmp->value);
}

