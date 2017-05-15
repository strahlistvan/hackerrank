#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct binary_string 
{
	char * vec;
	int buffer_size;
	int length;
	
} binary_string;

void clear_bit (binary_string * bs, int element)
{
    char byte_index = element/8;
    char bit_index = element % 8;
    char bit_mask = ( 1 << bit_index);

    bs->vec[byte_index] &= ~bit_mask;
}

void clear_all(binary_string * bs)
{
	int i = 0;
	while (i!=bs->buffer_size)
	{
	    clear_bit(bs, i);
		++i;
	}
}

char init(binary_string * bs, int buffer_size)
{
	bs->vec = (char *) malloc(buffer_size / 8 + 1);
	bs->buffer_size = buffer_size;
	clear_all(bs);
}


char get_bit(binary_string * bs, int element)
{
    char byte_index = element / 8;
    char bit_index = element % 8;
    char bit_mask = (1 << bit_index);

    return ((bs->vec[byte_index] & bit_mask) != 0);
}

char set_bit (binary_string * bs, int element)
{
    char byte_index = element/8;
    char bit_index = element % 8;
    char bit_mask = ( 1 << bit_index);

    bs->vec[byte_index] |= bit_mask;
}


void print_string(binary_string * bs)
{
	int i = 0;
	while (i!=buffer_size)
	{
		printf("%d", get_bit(bs, i));
		++i;
	}
	printf("\n");
}


int main(int argc, char ** argv) 
{
	printf("Hello world\n");
	binary_string bs;
	
	init(&bs, 1000);
	
	set_bit(&bs, 0);
	set_bit(&bs, 4);
	
	
	printf("%kutya: %d\n", get_bit(&bs, 1));
	print_string(&bs);
	
	
	
//	free(binary_string.vec);
	
}