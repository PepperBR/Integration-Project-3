#pragma once

#include <string>
#include <iostream>
#include <vector>

//Abstract Class
class Meter
{
protected:
    int const ID;
    bool is_template;
    std::string name_line;
    std::string name_model;

public:
    virtual std::vector<double> & getPhaseValues() = 0;

    Meter(int id, std::string line, std::string model, bool is_template = true) 
        : ID(id), name_line(std::move(line)), 
          name_model(std::move(model)),  
          is_template(is_template) 
    {}
    
    std::string getFullName() const
    {
        return name_line + " " + name_model;
    }

    int getID() const 
    {
        return ID;
    }

    std::string getNameLine () const
    {
        return name_line;
    }

    std::string getNameModel () const
    {
        return name_model;
    }

    /*
        Por padrão os modelos de medidores serão inicializados como template, apenas quando eu adicionar um novo medidor,
        por meio de uma cópia do objeto original, que o is_template será alterado para false
    */
    
    // Construtor de Cópia
    Meter(const Meter &other, int new_id) 
        : ID(new_id),           
          is_template(false),    
          name_line(other.name_line),   
          name_model(other.name_model)  
    {
        std::cout << "Meter Copy constructor" << std::endl;
    }

    Meter(const Meter &other) = default;
    Meter(Meter &&meter) = default;
    
    virtual ~Meter()
    {
        std::cout << "Virtual Meter Destructor is begin called" << std::endl;
    };

    virtual std::unique_ptr<Meter> createMeter(int new_id) const = 0;

    virtual std::unique_ptr<Meter> cloneMeter() const = 0;

};
