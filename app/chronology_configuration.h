#ifndef CHRONOLOGY_DB_CHRONOLOGY_CONFIGURATION_H
#define CHRONOLOGY_DB_CHRONOLOGY_CONFIGURATION_H

#include <string>
#include <fstream>

/**
 * Parses and stores the top-level configuration for the application.
 * The configuration is loaded using the static ``ReadConfiguration`` method.
 */
class ChronologyConfiguration
{
private: // Members
    std::string data_directory_;

private: // Hidden constructors
    ChronologyConfiguration() = default;

public: // Public constructors/destructor
    ChronologyConfiguration(ChronologyConfiguration&& to_move)
    {
        data_directory_ = std::move(to_move.data_directory_);
    }

    ~ChronologyConfiguration() = default;

public: // Public methods
    /**
     * Reads the configuration from a JSON file.
     * @param config_file Stream pointing to the configuration in JSON format.
     * @return Configuration object that can be queried for application settings.
     */
    static ChronologyConfiguration ReadConfiguration(std::ifstream& config_file);

public: // Accessors
    [[nodiscard]] const std::string& GetDataDirectory() const
    {
        return data_directory_;
    }
};


#endif //CHRONOLOGY_DB_CHRONOLOGY_CONFIGURATION_H
