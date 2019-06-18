/**
 * @file Timestamp.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 05:55
 * 
 * copied from old project
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>

namespace dppcord::util
{

const boost::posix_time::ptime UNIX_TIME = boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1));

class Timestamp
{
public:
    /**
     * @brief Construct a new Timestamp object
     */
    Timestamp() : _timestamp(time(0)) {}
    /**
     * @brief Construct a new Timestamp object
     * @param date that should be used for initialization as a time_t object
     */
    Timestamp(time_t date) : _timestamp(date) {}
    /**
     * @brief Construct a new Timestamp object
     * @param string timestamp string to construct the timestamp from
     */
    Timestamp(const std::string &string)
    {
        if (std::all_of(string.begin(), string.end(), ::isdigit))
        {
            *this = Timestamp::fromUnixTimestamp(string);
        }
        else
        {
            *this = Timestamp::fromISO8601Timestamp(string);
        }
    }
    /**
     * @brief Destroy the Timestamp object
     */
    ~Timestamp() {}
    /**
     * @brief Get the Timestamp object
     * @return const time_t returns the time saved in the timestamp
     */
    const time_t& getTimestamp() const { return _timestamp; }
    /**
     * @brief Returns the timestamp in an iso timestamp string
     * @return const std::string containing the timestamp
     */
    const std::string getISOTime() const
    {
        char buff[20];
        strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&_timestamp));
        return std::string(buff);
    }
    /**
     * @brief Returns the timestamp in an unix timestamp string
     * @return const std::string containing the timestamp
     */
    const std::string getUnixTime() const { return std::to_string(_timestamp); }
    /**
     * @brief Creates a Timestamp object from a unix timestamp stirng
     * @param time unix timestamp string
     * @return Timestamp 
     */
    static Timestamp fromUnixTimestamp(const std::string &time)
    {
        return Timestamp(static_cast<time_t>(strtol(time.c_str(), NULL, 10)));
    }
    /**
     * @brief Creates a Timestamp object from a iso8601 timestamp string
     * @param time iso timestamp string
     * @return Timestamp 
     */
    static Timestamp fromISO8601Timestamp(std::string time)
    {
        try
        {
            boost::posix_time::ptime pt = boost::posix_time::from_iso_extended_string(time);
            return Timestamp(time_t((pt - UNIX_TIME).total_seconds()));
        }
        catch (const std::exception &e)
        {
            try
            {
                time.insert(time.find("+"), ".000000");
                boost::posix_time::ptime pt = boost::posix_time::from_iso_extended_string(time);
                return Timestamp(time_t((pt - UNIX_TIME).total_seconds()));
            }
            catch (const std::exception &e2)
            {
                std::cerr << e2.what() << '\n';
            }
            std::cerr << e.what() << '\n';
            return Timestamp();
        }
    }

private:
    /**
     * @brief time_t object that holds the Timestamp
     */
    time_t _timestamp;
};
} // namespace discordpp::util

#endif