#include <stdio.h>
#include <stdlib.h>
#include "iris_data.h"
#include <string.h>
#include <cassert>

/*load iris data into a matrix X, and vector y. Sample data format:
5.1,3.5,1.4,0.2,Iris-setosa
4.9,3.0,1.4,0.2,Iris-setosa
*/

static char iris_classes[3][20] = {"Iris-setosa", "Iris-versicolor", "Iris-virginica"};

IrisDataset::IrisDataset() {
	int result = load_iris_data_from_file("iris.data");
	assert(result);
}

IrisDataset::~IrisDataset() {
	free(X);
	free(y);
}

int IrisDataset::load_iris_data_from_file(const char *filename)
//Expected:
//filename: string pointing to the flat file with iris data
//X: vector of size: sizeof(float) * numExamples * 4
//Y: vector of size: sizeof(int) * numExamples
{
	X = (float*) malloc (sizeof(float) * (nExamples * nDim));
	y = (int*) malloc (sizeof(int) * (nExamples));

	FILE *file = fopen(filename,"r");

	if (!file) return 0;

	char line[256];
	float tempx[4];
	char flowerclass[100];
	int i = 0;
	int j;

	while (fgets(line, sizeof(line), file))
	{
		//Get line content
		sscanf(line, "%f,%f,%f,%f,%s", &tempx[0], &tempx[1], &tempx[2], &tempx[3], flowerclass);

		//Assign X
		X[i*4 + 0] = tempx[0];
		X[i*4 + 1] = tempx[1];
		X[i*4 + 2] = tempx[2];
		X[i*4 + 3] = tempx[3];

		//Assign y
		for (j = 0; j< 3; j++)
			if (strcmp(iris_classes[j], flowerclass) == 0)
				y[i] = j;
		i++;
	}
	fclose(file);
	return 1;
}
