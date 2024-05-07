#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main() {
    char input[100];
    char sentence[100];
    char command[50];
    char data_id[10];
    char data_name[25];
    char data_year[5];
    char data_gender[8];
    int gender_value = 0;

    struct student_t *students = malloc(20 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(20 * sizeof(struct dorm_t));

    unsigned short int stop = 0;
    unsigned int student_size = 1, student_count = 0;
    unsigned int dorm_size = 1, dorm_count = 0;
    unsigned int student_index, dorm_index;

    FILE *student_file = fopen("./storage/student-repository.txt", "r");
    FILE *dorm_file = fopen("./storage/dorm-repository.txt", "r");

    parse_file_std(student_file, students, &student_size, &student_count, gender_value);
    parse_file_drm(dorm_file, dorms, &dorm_size, &dorm_count, gender_value);

    fclose(student_file);
    fclose(dorm_file);

    student_file = fopen("./storage/student-repository.txt", "a");
    dorm_file = fopen("./storage/dorm-repository.txt", "a");

    fprintf(student_file, "\n");
    fprintf(dorm_file, "\n");

    while (!stop) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\r\n")] = 0;
        strcpy(sentence, input);
        strcpy(command, strtok(sentence, "#"));

        if (strcmp(command, "tambah siswa") == 0) {
            strcpy(data_id, strtok(NULL, "#"));
            strcpy(data_name, strtok(NULL, "#"));
            strcpy(data_year, strtok(NULL, "#"));
            strcpy(data_gender, strtok(NULL, "#"));
            gender_value = gender_to_value(data_gender);

            students[student_count] = create_student(data_id, data_name, data_year, gender_value);
            struct student_t {
                char id[10];
                char nama[25]; // Add this line
                char tahun[5]; // Add this line
                int gender;
            };

            struct dorm_t {
                char nama[25]; // Add this line
                unsigned short int kapasitas; // Add this line
                int gender;
            };

            // Rest of the code...

            dorm_size++;
            dorm_count++;
        } else if (strcmp(command, "dorm-print-all-detail") == 0) {
            print_all_dorm(dorms, dorm_count);
        } else if (strcmp(command, "dorm-print-all") == 0) {
            print_name_dorm(dorms, dorm_count);
        } else if (strcmp(command, "assign-student") == 0) {
            strcpy(data_id, strtok(NULL, "#"));
            strcpy(data_name, strtok(NULL, "#"));

            student_index = 0;
            dorm_index = 0;
            student_index = get_index_student(students, student_count, data_id);
            dorm_index = get_index_dorm(dorms, dorm_count, data_name);

            assign_student(students, dorms, student_index, dorm_index);
        } else if (strcmp(command, "---") == 0) {
            stop = 1;
        }
    }

    fclose(student_file);
    fclose(dorm_file);

    free(students);
    free(dorms);

    return 0;
}
