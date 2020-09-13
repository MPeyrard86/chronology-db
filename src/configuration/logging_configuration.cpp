//
// Created by Matthew Peyrard on 9/12/2020.
//

#include "logging_configuration.h"

#include <boost/filesystem.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/expressions/formatters/date_time.hpp>
#include <boost/log/support/date_time.hpp>

namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

logging::formatting_ostream& operator<<(
        logging::formatting_ostream& stream,
        const logging::to_log_manip<chronology::Severity, severity_tag>& manip)
{
    static const char* severity_literals[] =
    {
        "DEBUG", "TRACE", "INFO", "WARN", "ERROR", "FATAL"
    };

    stream << severity_literals[manip.get()];
    return stream;
}

namespace chronology
{
    const std::string LoggingConfiguration::DIRECTORY_PROPERTY = "directory";
    const std::string LoggingConfiguration::ROTATION_SIZE_PROPERTY = "rotation-size";

    void init_logging(const LoggingConfiguration& logging_config)
    {
        boost::filesystem::path directory(logging_config.GetLoggingDirectory());
        boost::filesystem::path file_name("chronology-db-%5N.log"); // Formatted for log rolling.
        boost::filesystem::path full_logging_path = directory / file_name;

        logging::add_common_attributes();
        logging::add_file_log(
                keywords::file_name = full_logging_path,
                keywords::format =
                (
                    expr::stream
                        << "["
                        << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S")
                        << "]["
                        << expr::attr<chronology::Severity, severity_tag>("Severity")
                        << "] "
                        << expr::smessage
                )
        );

    }

    LoggingConfiguration LoggingConfiguration::ReadConfiguration(const pt::ptree &property_tree)
    {
        auto logging_directory = property_tree.get<std::string>(DIRECTORY_PROPERTY);
        auto rotation_size = property_tree.get<int>(ROTATION_SIZE_PROPERTY);
        return LoggingConfiguration(logging_directory, rotation_size);
    }
}
