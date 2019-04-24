#include <iostream>
#include "wirelessAdapter.h"

enum class USBType{
    USB_TYPE_2,
    USB_TYPE_3
};

int main( int argc, char* args[] )
{
    WirelessAdapter adapter("da4c32fb21", "USB_TYPE_2", 100);
    adapter.info();
}