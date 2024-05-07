#ifndef GENDER_H
#define GENDER_H

enum gender_t
{
    GENDER_MALE,
    GENDER_FEMALE
};

char *gender_to_text(enum gender_t mhs_gender); 
unsigned short int gender_to_value(char *data_gender);  

#endif
