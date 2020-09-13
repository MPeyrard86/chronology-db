#ifndef CHRONOLOGY_DB_CHRONOLOGY_CONFIGURATION_H
#define CHRONOLOGY_DB_CHRONOLOGY_CONFIGURATION_H

#include <string>
#include <fstream>

#include "logging_configuration.h"

namespace chronology
{
    inline const std::string DATA_DIRECTORY_PROPERTY = "data-directory";
    inline const std::string LOGGING_CONFIGURATION_PROPERTY = "logging-configuration";

/**
 * Parses and stores the top-level configuration for the application.
 * The configuration is loaded using the static ``ReadConfiguration`` method.
 */
    class ChronologyConfiguration
    {
    private: // Members
        std::string data_directory_;
        LoggingConfiguration logging_configuration_;

    public: // Public constructors/destructor
        ChronologyConfiguration() = delete;

        ChronologyConfiguration(std::string data_directory, LoggingConfiguration logging_config)
            : data_directory_(data_directory), logging_configuration_(std::move(logging_config))
        {
        }

        ChronologyConfiguration(ChronologyConfiguration &&to_move)
            : data_directory_(std::move(to_move.data_directory_))
            , logging_configuration_(std::move(to_move.logging_configuration_))
        {
        }

        ~ChronologyConfiguration() = default;

    public: // Public methods
        /**
         * Reads the configuration from a JSON file.
         * @param config_file Stream pointing to the configuration in JSON format.
         * @return Configuration object that can be queried for application settings.
         */
        static ChronologyConfiguration ReadConfiguration(std::ifstream &config_file);

    public: // Accessors
        [[nodiscard]] const std::string &GetDataDirectory() const
        {
            return data_directory_;
        }

        const LoggingConfiguration& GetLoggingConfiguration() const
        {
            return logging_configuration_;
        }
    };
}

#endif //CHRONOLOGY_DB_CHRONOLOGY_CONFIGURATION_H
