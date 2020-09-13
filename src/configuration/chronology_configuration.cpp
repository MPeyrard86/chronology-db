//
// Created by Matthew Peyrard on 9/8/2020.
//

#include "chronology_configuration.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace chronology
{
    ChronologyConfiguration ChronologyConfiguration::ReadConfiguration(std::ifstream &config_file)
    {
        // Read and parse the JSON file into a property tree.
        boost::property_tree::ptree pt;
        boost::property_tree::read_json(config_file, pt);

        // Read out all of the configuration settings.
        auto data_directory = pt.get<std::string>(DATA_DIRECTORY_PROPERTY);
        auto logging_ptree = pt.get_child_optional(LOGGING_CONFIGURATION_PROPERTY);
        LoggingConfiguration logging_config = LoggingConfiguration::ReadConfiguration(logging_ptree.get());

        return ChronologyConfiguration(data_directory, logging_config);
    }
}
