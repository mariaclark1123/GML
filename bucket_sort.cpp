//Bucket sort
//Each array's first data store the bucket length
#include<stdio.h>

void radix_sort(int *array, int num)
{
	int i, j, count = 1;
	int array2[10];

	array2[0] = num;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < num; j++)
		{  //sort in unit, index from 1->num, 
			if ((array[j + 1] % 10) == i)
				array2[count++] = array[j + 1];
		}
	}
	for (i = 0; i < num; i++)
		array[i + 1] = array2[i + 1];
}

void Print(int array[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		printf("bucket [%d]:", i);
		for (int j = 0; j < array[i][0]; j++)
			printf("%d ", array[i][j + 1]);
		printf("\n");
	}
}

void Bucket_sort()
{
	int num, bucket_no;
	int array[10];
	int bucket[10][10] = { 0,0 };   //first index store the number quantity
	printf("please input 10 numbers:\n");


	for (int i = 0; i < 10; i++)
	{
		scanf_s("%d", &num);
		bucket_no = num / 10;

		bucket[bucket_no][0]++;
		bucket[bucket_no][bucket[bucket_no][0]] = num;
	}

	printf("\nPut into the Bucket\n--------------\n");
	Print(bucket);

	for (int i = 0; i < 10; i++)
			radix_sort(bucket[i], bucket[i][0]);

	printf("\nAfter sorting, the Bucket is\n--------------\n");
	Print(bucket);

	printf("\nSorted array is:\n--------------\n");
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < bucket[i][0]; j++)
		{
			printf("%d ", bucket[i][j + 1]);
		}
}

int main()
{
	Bucket_sort();
	return 0;
}