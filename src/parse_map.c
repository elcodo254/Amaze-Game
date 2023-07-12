#include "header.h"

/**
 * parseMap - parse array from file to create maze
 * @filename: file name of map
 * @map: 2d array
 * Return: pointer to map
 */
int *parseMap(char *filename, int *map)
{
	FILE *fp;
	char row[MAP_WIDTH * 2];
	char *number;
	int i, j;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("Map failed to open");
		return (NULL);
	}

	map = malloc(sizeof(int) * MAP_HEIGHT * MAP_WIDTH);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (fgets(row, sizeof(row), fp) != NULL)
	{
		if (strlen(row) <= 1)
			continue;
		number = strtok(row, "\n ");

		j = 0;
		while (number != NULL)
		{
			map[i * MAP_WIDTH + j] = atoi(number);
			number = strtok(NULL, "\n ");
			j++;
		}
		i++;
	}
	fclose(fp);
	return (map);
}
