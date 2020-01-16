#include <stdio.h>
#include <stdlib.h>

int arr[113] = {1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,19,6,23,2,23,13,27,1,27,5,31,2,31,10,35,1,9,35,39,1,39,9,43,2,9,43,47,1,5,47,51,2,13,51,55,1,55,9,59,2,6,59,63,1,63,5,67,1,10,67,71,1,71,10,75,2,75,13,79,2,79,13,83,1,5,83,87,1,87,6,91,2,91,13,95,1,5,95,99,1,99,2,103,1,103,6,0,99,2,14,0,0};

int arrtest[12] = {1,9,10,3,2,3,11,0,99,30,40,50};
int at[6]={2,4,4,5,99,0};
// opcodes are 1, 2 or 99
// 1 = adds
// 2 = multiplies
// 99 = halt
// after ever opcode instruction move 4 from current opcode
//
int * current = at;
int get_opcode(int *ptr)
{
        if(*ptr == 1)
        {
                return 1;
        }
        else if(*ptr == 2)
        {
                return 2;
        }
        else if(*ptr == 99)
        {
                return 99;
        }
        else{
                perror("unknown opcode!\n");
                exit(-1);
        }
}
int opcode_add(int read_pos_one, int read_pos_two, int write_pos)
{
        int a = arr[read_pos_one];
        int b = arr[read_pos_two];
        arr[write_pos] = a + b;
        return a+b;
}
int opcode_multiply(int read_pos_one, int read_pos_two, int write_pos)
{
        int a = arr[read_pos_one];
        int b = arr[read_pos_two];
        arr[write_pos] = a * b;
        return a * b;
}
int* move_to_next_opcode(int *ptr)
{
        return ptr+4;
}

int main()
{
        printf("current = %d\n", *current);
        printf("plus 4 = %d\n", *(current+4));
        int r = 0;
        int last_op = 0;
        while(1)
        {

                r = get_opcode(current);

                switch(r)
                {
                        case 1:
                                last_op = opcode_add(*(current+1), *(current+2), *(current+3));
                                break;
                        case 2:
                                last_op = opcode_multiply(*(current+1), *(current+2), *(current+3));
                                break;
                        case 99:
                                break;
                }
                if(*current == 99)
                {
                        printf("Last value = %d\n", last_op);
                        break;
                }
                current = move_to_next_opcode(current);

        }
}
