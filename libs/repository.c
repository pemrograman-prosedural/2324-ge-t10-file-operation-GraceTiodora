#include "repository.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */


void parse_file_std ( FILE *std, struct student_t *mhs, unsigned short int *size_mhs, unsigned short int *prt_mhs, int num_gender){
    struct data_file data_std;
    char buff_std[60];
    buff_std[0] = '\0';

    while(fgets(buff_std, sizeof(buff_std), std)){
                strcpy(data_std.file_id ,strtok(buff_std, "|"));
                strcpy(data_std.file_name ,strtok(NULL, "|"));
                strcpy(data_std.file_year , strtok(NULL, "|"));
                strcpy(data_std.file_gender, strtok(NULL, "|"));

                num_gender = gender_to_value(data_std.file_gender);
                
            
                mhs[*prt_mhs] = create_student(data_std.file_id, data_std.file_name, data_std.file_year,num_gender);
            
            (*size_mhs)++;
            (*prt_mhs)++;
        }

    fflush(std);
    fclose(std);
} 


void parse_file_drm ( FILE *fdrm, struct dorm_t *dorms, unsigned short int *size_drm, unsigned short int *prt_drm, int num_gender){
    struct data_file data_drm;
    char buff_drm[60];
    buff_drm[0] = '\0';

    while(fgets(buff_drm, sizeof(buff_drm), fdrm)){
                strcpy(data_drm.file_id ,strtok(buff_drm, "|"));
            
                unsigned short int capacity;
                strcpy(data_drm.file_year , strtok(NULL, "|"));
                capacity = atoi(data_drm.file_year);

                strcpy(data_drm.file_gender, strtok(NULL, "|"));

                num_gender = gender_to_value (data_drm.file_gender);

            
                dorms[*prt_drm] = create_dorm(data_drm.file_id, capacity, num_gender);
            (*size_drm)++;
            (*prt_drm)++;
            }
        fflush(fdrm);
        fclose(fdrm);
}

