#pragma once

#include <string>
#include <iostream>
#include <vector>

//Abstract Class
class Meter
{
protected:
    int const ID;
    std::string name; // TODO: Transformar em 2 parametros line e model, e tu pode manter um metodo getFullName
    //bool is_template;
public:
    /* Meter(int id, std::string name, bool is_template = false) 
            : ID(id), name(std::move(name)), is_template(is_template) {}; */
    Meter(int id,  std::string name)
        : ID(id), name(std::move(name)) {};
    virtual std::vector<double> & getPhaseValues() = 0;
    virtual std::string & getName() = 0;
    virtual int getID() = 0;
    virtual ~Meter()
    {
        std::cout << "Virtual Meter Destructor is begin called" << std::endl;
    };
};
