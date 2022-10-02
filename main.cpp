//
// Created by Nathan Perkins on 10/2/22.
//

#include "CyRocDataTransfer.h"

int main(){
    dt::data_entry de = {.ts = 1, .vel = 100.234562, .acc = 10.2343};
    dt::data_to_file(de);
    dt::data_to_flash();

    return 0;
}
