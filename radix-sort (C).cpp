//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <string.h>
//#include <stdlib.h>
//using namespace std;
//int main()
//{
//	ifstream infile;
//	ofstream outfile;
//	infile.open("input.txt", ios::in);
//	outfile.open("out.txt", ios::out);
//	vector<string>  data;
//	while (!infile.eof())
//	{
//		string linestring;
//		getline(infile, linestring);
//		if (linestring.size() != 0) {
//			int pos = linestring.find(" ");
//			string firstItem = linestring.substr(0, pos);
//			if (atoi(firstItem.c_str()) - atof(firstItem.c_str()) != 0) {
//				data.push_back(linestring);
//			}
//		}
//	}
//	int count = data.size();
//	for (int i = 0; i<count; i++) {
//		/*outfile << data[i] << endl;*/
//		cout << data[i] << endl;
//	}
//	outfile.close();
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void radix_sort(int *array1, int *array2)
{
	int i, j, count1 = 0, count2 = 0;

	for (i = 0; i<10; i++)
		for (j = 0; j < 50; j++)
		{  //sort in unit
			if ((array1[j] % 10) == i)
				array2[count1++] = array1[j];
		}

	for (i = 0; i<10; i++)
		for (j = 0; j < 50; j++)
		{  //sort in tens
			if ((array2[j] / 10) == i)
		    	array1[count2++] = array2[j];
		}
}

int main()
{
	int array[50];
	int temp_array[50];
	int i;

	srand((unsigned)time(NULL));    //set array with random number between 0-99
	for (i = 0; i<50; i++)
		array[i] = rand() % 100; 

	printf("Before radix sort:\n");
	for (i = 0; i < 50; i++)
		printf("%d ", array[i]);

	radix_sort(array, temp_array);  //radix sort

	printf("\nAfter radix sort:\n");
	for (i = 0; i < 50; i++)
		printf("%d ", array[i]);
	getchar();
}