#include "core/GlobalID.h"

int GlobalID::id = 1;

int GlobalID::generateID()
{
    return id++;
}