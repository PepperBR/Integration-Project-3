#pragma once
#include "Model.h"
#include <string>

class ModelAres : public Model
{
    public:
        std::string getName() override;
        int getID() override;
        ModelAres();
        
    private:
        ModelAres & getModelAres() const;
        std::string name;
        const int id;
};