#include <stdio.h>
#include <stdlib.h>

const char * filename = "ao1.in";
int main(){
/*
for each line of mass
mass / 3 and then round down
subtract 2
add this to the total fuel
*/
    FILE *fp = fopen(filename,"r");
    if(!fp)
    {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    size_t len;
    char *mass = NULL;
    int x=0;
    size_t n = 0;
    int ret;
    int total = 0;
    while((n = getline(&mass,&len,fp))!= -1)
    {
        ret = sscanf(mass, "%d", &x);
        x = x/3 - 2;
        total = total + x;
    }
    printf("total: %d\n", total);
    return 0;
}