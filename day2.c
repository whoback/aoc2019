#include <stdio.h>
#include <stdlib.h>

int at[113] = {1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,19,6,23,2,23,13,27,1,27,5,31,2,31,10,35,1,9,35,39,1,39,9,43,2,9,43,47,1,5,47,51,2,13,51,55,1,55,9,59,2,6,59,63,1,63,5,67,1,10,67,71,1,71,10,75,2,75,13,79,2,79,13,83,1,5,83,87,1,87,6,91,2,91,13,95,1,5,95,99,1,99,2,103,1,103,6,0,99,2,14,0,0};

// opcodes are 1, 2 or 99
// 1 = adds
// 2 = multiplies
// 99 = halt
// after ever opcode instruction move 4 from current opcode
//
int * current = at;
//                  op type  val1   val2   write_to
int opcode_operation(int* a, int* b, int*c, int*d)
{
        //check value of op type
        if(*a == 1)
        {
                //b and c are positions not values so we need to get 
                //the underlying values from them
            int res = at[*b] + at[*c]; 
            at[*d] = res;
            return res;
        }
        if(*a == 2)
        {
            int res = at[*b] * at[*c];
            at[*d] = res;
                return res;
        }
        if(*a == 99)
        {
                return 99;
        }
}

int main()
{       int last = 0;
        int r = 0;
        while(r != 99)
        {
            r = opcode_operation(current,current+1,current+2,current+3);
            if(r != 99)
            {
                    last = r;
            }
            current = current + 4;
        }        
        printf("%d\n",last);
        printf("%d\n",at[0]);
}
