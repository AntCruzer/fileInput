// INCLUDES
#include <stdio.h>



// DISABLE WARNINGS
#pragma warning(disable: 4996) 



int main(void)
{
    // TEXT FILE

    // initialize variables
    FILE *tfp = NULL;

    // open/create file
    tfp = fopen("myTextFile.txt", "w");

    // error checking
	if (tfp == NULL)
	{
		printf("Can't open text file for writing.\n");
		return -1;
	}

    // write lines of text to the previously opened file
	for(int i = 0; i < 2; i++)
	{
		// write to the file, making sure that it succeeded
		if (fprintf(tfp, "This is line #%d.\n", i) < 0)
		{
			// if fprintf() returns less than 0, something went wrong
			printf("Can't write line to text file.\n");
			return -2;
		}
	}
    
    // close the file
	if (fclose(tfp) != 0)
	{
		// the closing of the file failed
		printf("Can't close text file opened for writing.\n");
		return -3;
	}

    // BINARY FILE

    // initialize variables
    FILE *bfp = NULL;

    // open/create file
    bfp = fopen("myBinaryFile.data", "wb");

    // error checking
	if (bfp == NULL)
	{
		printf("Can't open binary file for writing.\n");
		return -1;
	}

    // data to be written to binary file
    const unsigned short kBinaryData[] = { 26946, 24942, 31090,
    25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    // TESTING 
    const unsigned short arraySize = sizeof(kBinaryData) / sizeof(kBinaryData[0]);

    // write lines of text to the previously opened file
	for(int i = 0; i < arraySize; i++)
	{
		// write to the file, making sure that it succeeded
		if (fprintf(bfp, "%hu\n", kBinaryData[i]) < 0)
		{
			// if fprintf() returns less than 0, something went wrong
			printf("Can't write line to binary file.\n");
			return -2;
		}
	}

	if (fclose(bfp) != 0)
	{
		// the closing of the file failed
		printf("Can't close binary file opened for writing.\n");
		return -3;
	}

    return 0;
}