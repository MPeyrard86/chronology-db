#include <iostream>
#include "app/chronology_configuration.h"

int main()
{
    try
    {
        std::ifstream fp("test-resources/chronology-config.json");
        auto config = ChronologyConfiguration::ReadConfiguration(fp);

        std::cout << config.GetDataDirectory() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
