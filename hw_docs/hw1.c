#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int binary_math();
int grid_challenge();
int complete_the_code();
int byte_splitting(uint16_t);
int combined_byte_splitting(uint16_t, uint16_t);
char* to_binary_string(uint16_t);
void binaryCommands();
void typeSizes();

/* generate multiple lines of output */
int binary_math()
{
	int rows;

	/* get and verify input */
	printf("How many rows (18 max)? ");
	scanf("%d",&rows);
	/* avoid out-of-range values */
	if(rows < 0 || rows > 18) {
		printf("invalid rows value: %d (18 max)\n Row value will be set to 18\n", rows);
		rows = 18;
	}
	/* process the rows */
	printf("I will process %d rows\n",rows);
	// EW: shifting the rows value left will double it and shifting the value left will half it
	printf("Double rows: %d, Half rows: %d\n", rows << 1, rows >> 1);
	return 0;
}

/* generate multiple lines of output */
int grid_challenge()
{
	int rows;

	/* get and verify input */
	printf("How many rows (18 max)? ");
	scanf("%d",&rows);
	/* avoid out-of-range values */
	if(rows < 0 || rows > 18) {
		printf("invalid rows value: %d (18 max)\n Row value will be set to 18\n", rows);
		rows = 18;
	}
	/* process the rows */
	printf("I will process %d rows\n",rows);
	// EW: iterate through the number of rows
	for(int i = 0; i < rows; i++) {
		// EW: if the row is divisible by 2, print out 40 equal signs, i think this is technically opposite of how it was supposed to be in the demo but this is how the solution does it. It appears they assume the first row as 1
		if(i % 2) {
			printf("========================================\n");
		} else { // EW: If the row is odd then print the grid with the row number and a letter between A-J 
			for(int j = 0; j < 10; j++) {
				printf(" %d%c ", i >> 1, 'A'+j);
			}
			printf("\n");
		}
	}

	return 0;
}

// EW: declarations for the new functions
void newline();
void seperator_row(int count, char c);

/* generate multiple lines of output */
int complete_the_code()
{
	int row,c,rows,x;
	char column;

	/* get and verify input */
	printf("How many rows (18 max)? ");
	scanf("%d",&rows);
	/* avoid out-of-range values */
	if( rows>18 )
		rows = 18;

	/* use variable c to count the number rows */
	c = 0;
	/* process the rows */
	for( row=0; row<rows; row++ )
	{
		/* switch output every other row */
		/* separator row */
		if( row%2 )
		{
			// EW: added the newline and seperator row functions
			seperator_row(40, '=');
			newline();
		}
		else
		/* values row */
		{
			for( column='A'; column<='J'; column++ )
				printf(" %d%c ",c,column);
			putchar('\n');
			c++;
		}
	}

	return 0;
}

void newline() {
	printf("\n"); // EW: print a new line, here putchar can be used as well
}

void seperator_row(int count, char c) {
	// EW: iterate count number of times, each time print the char c once; here putchar can be used as well
	for(int i = 0; i < count; i++) {
		printf("%c", c);
	}
}

int byte_splitting(uint16_t value1) {
	// EW: to find the lower byte, AND the value with a bitmask with 0x00FF to clear the upper 8 
    uint8_t lower_byte = value1;
    uint8_t upper_byte = (value1 & 0xFF00) >> 8;
	char* value_binary_str = to_binary_string(value1);
	char* lower_binary_str = to_binary_string(lower_byte);
	char* upper_binary_str = to_binary_string(upper_byte);
	printf("Initial Value: 0b%s (binary), %d (decimal), 0x%x (hex)\n", value_binary_str, value1, value1);
    printf("Lower Byte: 0b%s (binary), %d (decimal), 0x%x (hex)\n", lower_binary_str+8, lower_byte, lower_byte);
    printf("Upper Byte: 0b%s (binary), %d (decimal), 0x%x (hex)\n", upper_binary_str+8, upper_byte, upper_byte);
    free(lower_binary_str);
	free(upper_binary_str);
	free(value_binary_str);
	return 0;
}

int combined_byte_splitting(uint16_t upper, uint16_t lower) {
    uint16_t combined_byte = (upper << 8) | lower;
    printf("Combined Byte: 0b%s (binary), %d (decimal), %x (hex)\n", to_binary_string(combined_byte), combined_byte, combined_byte);
    byte_splitting(combined_byte);
    return 0;
}

char* to_binary_string(uint16_t value) {
	char* str = malloc(17 * sizeof(char));
	int mask_cnt = 0;
	for(int i = 15; i >= 0; i--) {
		uint16_t mask = 1 << mask_cnt;
		if(value & mask) {
			str[i] = '1';
		} else {
			str[i] = '0';
		}
		mask_cnt++;
	}
	str[16] = '\0';
	return str;
}

void binaryCommands() {
    printf("1. The reason each character takes 10/9600 to send over a UART connection with a baude rate of 9600 bits per second is because the UART communication protocol sends a starting bit, the 8 data bits of the character, and a final stop bit to conclude the communication. This is because the protocol is asynchronous and such requires a start and stop signal.\n");
    printf("2. %x\n", 532 & 205);
    printf("3. %x\n", 0x4f & 0x1ad);
    printf("4. %x\n", 0x02ad | 0x1a1);
    printf("5. %x\n", 0x3ba >> 4);
    printf("6. %ld\n", 104 << 3);
    printf("7. %x\n", 495 & (0x5 << 4));
}

void typeSizes() {
	printf("int: 16\n long int: 32\n unsigned int: 16\n, short int: 16\n, char: 16\n, double: 32 or 64?\n float: 32\n");
	printf("Using sizeof - int: %d\n long int: %d\n unsigned int: %d\n, short int: %d\n, char: %d\n, double: %d?\n float: %d\n",
			sizeof(int)*16,
			sizeof(long int)*16,
			sizeof(short int)*16,
			sizeof(char)*16,
			sizeof(double)*16,
			sizeof(float)*16);
}

void print_test_header(char* name) {
	seperator_row(40, '=');
	newline();
	printf("%s\n", name);
	seperator_row(40, '=');
	newline();
	newline();
}

int main() {
	print_test_header("Binary Math");
	binary_math();
	newline(); newline();
	print_test_header("Grid Challenge");
	grid_challenge();
	newline(); newline();
	print_test_header("Complete The Code");
	complete_the_code();
	newline(); newline();
	print_test_header("Byte Splitting");
	byte_splitting(0x6492);
	byte_splitting(0xB8AA);
	combined_byte_splitting(0xA5, 0x5D);
	newline(); newline();
	print_test_header("Exercise 11: Binary Operations");
	binaryCommands();
	newline(); newline();
	print_test_header("Exercise 12: Type bit sizes");
	typeSizes();
	newline(); newline();
	return 0;
}




