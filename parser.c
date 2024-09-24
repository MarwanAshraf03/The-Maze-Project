#include "project.h"

/**
 * parse_map - gets map from a file
 * @lineNumber: the line containing the map
 * @worldMap: 2d representation of the game
 */
void parse_map(int lineNumber, int worldMap[mapWidth][mapHeight])
{
	FILE *maps = fopen("maps.txt", "r");
	int count = 1;
	char *map = malloc(486);

	if (maps == NULL)
		return;
	while (fgets(map, 486, maps) != NULL)
	{
		if (count == lineNumber)
			for (int i = 0; i < mapWidth; i++)
				for (int j = 0; j < mapHeight; j++)
					worldMap[i][j] = map[i * mapHeight + j] - '0';
		count++;
	}
	free(map);
	fclose(maps);
}
