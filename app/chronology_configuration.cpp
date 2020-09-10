//
// Created by Matthew Peyrard on 9/8/2020.
//

#include "chronology_configuration.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

const std::string DATA_DIRECTORY_PROPERTY = "data-directory";

ChronologyConfiguration ChronologyConfiguration::ReadConfiguration(std::ifstream& config_file)
{
    // Read and parse the JSON file into a property tree.
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(config_file, pt);

    // Read out all of the configuration settings.
    ChronologyConfiguration config;
    config.data_directory_ = pt.get<std::string>(DATA_DIRECTORY_PROPERTY);

    return config;
}
