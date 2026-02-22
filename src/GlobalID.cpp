#include "GlobalID.h"

int GlobalID::ID = 0;

int GlobalID::generateID()
{
    return ID++;
};