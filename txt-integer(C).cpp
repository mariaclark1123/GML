#include<stdio.h>
#include<string.h>

void main()
{
	float temp;
	float array[20000];
	int count = 0;
	FILE *fp;
	FILE *fout;

	fopen_s(&fp, "export.txt", "r");
	if (fp == NULL)
		printf("can not open this file\n");

	while (!feof(fp))
	{
		fscanf_s(fp, "%f", &temp);
		array[count] = temp;
		count = count + 1;
	}
	fclose(fp);

	fopen_s(&fout,"output.txt", "w");
	for (int i = 0; i < count - 2; i = i + 3)
	{
		if ((array[i] - (int)array[i]) != 0)
			fprintf(fout,"%f %f %f\n", array[i], array[i + 1], array[i + 2]);
	}
	fclose(fout);
}