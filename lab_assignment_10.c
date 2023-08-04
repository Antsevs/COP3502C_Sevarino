#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 100

// Trie node structure
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	int isEndOfWord;
	int count;
};

// Initializes a trie node
struct TrieNode *createTrieNode()
{
	struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

	if (pNode)
	{
		int i;

		pNode->isEndOfWord = 0;
		pNode->count = 0;

		for (i = 0; i < ALPHABET_SIZE; i++)
			pNode->children[i] = NULL;
	}

	return pNode;
}

// Inserts the word to the trie structure
void insert(struct TrieNode *root, char *word)
{
	int level;
	int length = strlen(word);
	int index;

	struct TrieNode *pNode = root;

	for (level = 0; level < length; level++)
	{
		index = word[level] - 'a';
		if (!pNode->children[index])
			pNode->children[index] = createTrieNode();

		pNode = pNode->children[index];
	}

	pNode->isEndOfWord = 1;
	pNode->count++;
}

// Computes the number of occurrences of the word
int numberOfOccurances(struct TrieNode *root, char *word)
{
	int level;
	int length = strlen(word);
	int index;
	struct TrieNode *pNode = root;

	for (level = 0; level < length; level++)
	{
		index = word[level] - 'a';

		if (!pNode->children[index])
			return 0;

		pNode = pNode->children[index];
	}

	if (pNode != NULL && pNode->isEndOfWord)
		return pNode->count;

	return 0;
}

// Deallocate the trie structure
void deallocateTrie(struct TrieNode *root)
{
	if (!root) return;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		deallocateTrie(root->children[i]);

	free(root);
}

// Reads the dictionary file and stores words in the provided array
int readDictionary(char *filename, char ***pInWords)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Could not open file %s\n", filename);
		return 0;
	}

	char word[MAX_WORD_LENGTH];
	int count = 0;

	while (fgets(word, MAX_WORD_LENGTH, file) != NULL)
		count++;

	*pInWords = (char **)malloc(sizeof(char *) * count);

	rewind(file);

	int i = 0;
	while (fgets(word, MAX_WORD_LENGTH, file) != NULL)
	{
		word[strcspn(word, "\n")] = '\0';

		(*pInWords)[i] = (char *)malloc(sizeof(char) * (strlen(word) + 1));
		strcpy((*pInWords)[i], word);

		i++;
	}

	fclose(file);
	return count;
}

int main(void)
{
	char **inWords;

	// Read the number of words in the dictionary
	int numWords = readDictionary("dictionary.txt", &inWords);

	struct TrieNode *root = createTrieNode();
	for (int i = 0; i < numWords; i++)
	{
		insert(root, inWords[i]);
	}

	// Parse line by line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i = 0; i < 5; i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(root, pWords[i]));
	}
	deallocateTrie(root);

	for (int i = 0; i < numWords; i++)
	{
		free(inWords[i]);
	}
	free(inWords);

	if (root != NULL)
		printf("There is an error in this program\n");
	return 0;
}
