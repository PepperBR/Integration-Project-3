#include "core/Catalog.h"
#include "catch.hpp"

namespace jmcp
{


TEST_CASE("Testing Methods:")
{
    SECTION("getLines()")
    {
        Catalog catalog;
        std::string expected_lines[] = {"Apolo", "Ares", "Cronos", "Zeus"};
    
        int index = 0;
        auto lines = catalog.getLines();
    
        REQUIRE(lines.size() == 4);
    
        for (const auto &line : lines)
        {
            REQUIRE(line == expected_lines[index++]);
        }
    }

    SECTION("getLineModels()")
    {
        Catalog catalog;
        std::string expected_models_Apolo[] = {"Apolo 6031"};
        std::string expected_models_Zeus[] = {"Zeus 8021","Zeus 8023","Zeus 8031"};
        std::string expected_models_Cronos[] = {"Cronos 7023","Cronos 7023 L","Cronos 7023 2.5","Cronos 6021 L","Cronos 6021 A","Cronos 6003","Cronos 6001 A"};
        std::string expected_models_Ares[] = {"Ares 7021","Ares 8023","Ares 7023","Ares 7031","Ares 8023 15","Ares 8023 200"};

        int index = 0;
        auto models_apolo = catalog.getLineModels("Apolo");
        auto models_zeus = catalog.getLineModels("Zeus");
        auto models_cronos = catalog.getLineModels("Cronos");
        auto models_ares = catalog.getLineModels("Ares");

        for (const auto &model : models_apolo)
        {
            REQUIRE(model.second == expected_models_Apolo[index++]);
        }

        index = 0;
        for (const auto &model : models_zeus)
        {
            REQUIRE(model.second == expected_models_Zeus[index++]);
        }

        index = 0;
        for (const auto &model : models_cronos)
        {
            REQUIRE(model.second == expected_models_Cronos[index++]);
        }

        index = 0;
        for (const auto &model : models_ares)
        {
            REQUIRE(model.second == expected_models_Ares[index++]);
        }
    }



}
}
