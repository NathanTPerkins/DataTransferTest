//
// Created by Nathan Perkins on 10/2/22.
//

#include "CyRocDataTransfer.h"

int delete_oldest_line(){
    const char* intra_file_path = "./intra_data_file.txt";
    const char* temp_file_path = "temp.txt";
    FILE* temp = fopen(temp_file_path, "w");
    FILE* intra_file = fopen(intra_file_path, "w");
    int line_number = 0;
    char c;
    while((c = fgetc(intra_file)) != EOF){
        if(line_number == 0){
            if(c == '\n'){
                ++line_number;
            }
        }else{
            fputc(c, temp);
        }
    }
    fclose(temp);
    fclose(intra_file);
    remove(intra_file_path);
    rename(temp_file_path, intra_file_path);
}

int dt::data_to_file(dt::data_entry data) {
    FILE* intra_file = fopen("./intra_data_file.txt", "a");
    fprintf(intra_file,"%d,%lf,%lf\n", data.ts, data.acc, data.vel);
    fclose(intra_file);
}

int dt::data_to_flash() {
    FILE* intra_file = fopen("./intra_data_file.txt", "r");
    char data_line[256];
    char c;
    while((c = fgetc(intra_file))!= '\n'){
        strncat(data_line, &c, 1);
    }
    fclose(intra_file);

    delete_oldest_line();

    FILE* flash_file = fopen("./fake_flash.txt", "a");
    fprintf(flash_file, "%s\n", data_line);
    fclose(flash_file);

}
