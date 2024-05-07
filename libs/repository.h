#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "gender.h"
#include "dorm.h"
#include "student.h"
#include <stdio.h>

/**
 * @brief define your structure, enums, globally accessible variables, and function prototypes here.
 * The actual function implementation should be defined in the corresponding source file.
 *
 */
struct data_file
{
    char file_id[12];
    char file_name[40];
    char file_year[5];
    char file_gender[8];
};


void parse_file_std (FILE *std, struct student_t *mhs, unsigned short int *size_mhs, unsigned short int *prt_mhs, int num_gender);

void parse_file_drm ( FILE *fdrm, struct dorm_t *dorms, unsigned short int *size_drm, unsigned short int *prt_drm, int num_gender);

#endif

