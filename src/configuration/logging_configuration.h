//
// Created by Matthew Peyrard on 9/12/2020.
//

#ifndef CHRONOLOGY_DB_LOGGING_CONFIGURATION_H
#define CHRONOLOGY_DB_LOGGING_CONFIGURATION_H

#include <iostream>
#include <boost/core/null_deleter.hpp>
#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/log/expressions/formatters/stream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/property_tree/ptree.hpp>

namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace pt = boost::property_tree;

namespace chronology
{
    enum Severity
    {
        Debug,
        Trace,
        Information,
        Warning,
        Error,
        Fatal
    };

    using Logger = src::severity_logger<Severity>;

    class LoggingConfiguration
    {
    private:
        static const std::string DIRECTORY_PROPERTY;
        static const std::string ROTATION_SIZE_PROPERTY;

    private:
        std::string directory_;
        int rotation_size_;

    public:
        LoggingConfiguration(const std::string &directory, int rotation_size)
                : directory_(directory), rotation_size_(rotation_size)
        {
        }

        LoggingConfiguration(const LoggingConfiguration &to_copy)
                : directory_(to_copy.directory_), rotation_size_(to_copy.rotation_size_)
        {
        }

        LoggingConfiguration(LoggingConfiguration &&to_move)
        {
            directory_ = std::move(to_move.directory_);
            rotation_size_ = to_move.rotation_size_;
        }

        LoggingConfiguration() = delete;

        ~LoggingConfiguration() = default;

    public:
        const std::string& GetLoggingDirectory() const
        {
            return directory_;
        }

        int GetRotationSize() const
        {
            return rotation_size_;
        }

    public:
        static LoggingConfiguration ReadConfiguration(const pt::ptree &property_tree);
    };

    /**
     * Initializes the logging framework.
     */
    void init_logging(const LoggingConfiguration&);
}

struct severity_tag;
logging::formatting_ostream& operator<<(
        logging::formatting_ostream&,
        const logging::to_log_manip<chronology::Severity, severity_tag>& manip);

#endif //CHRONOLOGY_DB_LOGGING_CONFIGURATION_H
