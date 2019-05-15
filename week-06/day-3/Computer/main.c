#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer;
    computer.cpu_speed_GHz = 8.5;
    computer.ram_size_GB =512;
    computer.bits = 256;

    Notebook notebook;
    notebook.cpu_speed_GHz = 5;
    notebook.ram_size_GB = 128;
    notebook.bits = 128;

    printf("The device has a(n) %.2f GHz, %d bit CPU and %d GBs of RAM!\n", computer.cpu_speed_GHz, computer.bits, computer.ram_size_GB);
    printf("The device has a(n) %.2f GHz, %d bit CPU and %d GBs of RAM!\n", notebook.cpu_speed_GHz, notebook.bits, notebook.ram_size_GB);

    return 0;
}
