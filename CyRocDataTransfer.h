//
// Created by Nathan Perkins on 10/2/22.
//

#ifndef CYROCDATATRANSFER_LIB_CYROCDATATRANSFER_H
#define CYROCDATATRANSFER_LIB_CYROCDATATRANSFER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

namespace dt{

    typedef struct data_entry{
        int ts;
        double vel;
        double acc;
    } data_entry;

    int data_to_file(dt::data_entry);

    int data_to_flash();

}

#endif //CYROCDATATRANSFER_LIB_CYROCDATATRANSFER_H
