#include <iostream>
#include <boost/log/sources/severity_feature.hpp>

#include "configuration/chronology_configuration.h"
//#include "logging/logging.h"


int main(int, char**)
{
    try
    {
        // Read the configuration file.
        std::ifstream fp("chronology-config.json");
        auto config = chronology::ChronologyConfiguration::ReadConfiguration(fp);
        // Initialize logging framework.
        chronology::init_logging(config.GetLoggingConfiguration());

        chronology::Logger logger;
        BOOST_LOG_SEV(logger, chronology::Severity::Information)
            << "Starting Chronology DB.";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
