#include <stdio.h>
#include <stdlib.h>

const char * filename = "ao1.in";
int proc_fuel(int n)
{
        int r = n/3 - 2;
        if(r > 0)
        {
                return r;
        }
        return -1;
}
int main(){
/*
for each line of mass - while the result is not < 0
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
    int module_mass=0;
    size_t n = 0;
    int ret;
    int total = 0;
    int module_total = 0;
    while((n = getline(&mass,&len,fp))!= -1)
    {
        // get a module of fuel from the input file
        ret = sscanf(mass, "%d", &module_mass);
        if(ret != 1)
        {
                perror("Failure reading module\n");
                return EXIT_FAILURE;
        }
        printf("Got module size: %d\n", module_mass);
        module_total = 0;
        while(module_mass != -1)
        {
                module_mass = proc_fuel(module_mass);
                if(module_mass == -1)
                {
                        break;
                }
                printf("This requires %d fuel\n", module_mass);
                module_total += module_mass;
                printf("Total fuel for module: %d\n", module_total);
        }
        //now add mod tot to act tot
        total += module_total;
        printf("Running total: %d\n", total);
    }
    printf("TOTAL: %d\n", total);
    return 0;
}
