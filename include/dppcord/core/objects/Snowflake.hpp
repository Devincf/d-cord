/**
 * @file Snowflake.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief Implementation of the Snowflake format discord uses
 * @version 1.0
 * @date 2019-02-01 02:24
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef SNOWFLAKE_HPP
#define SNOWFLAKE_HPP

#include <cstdint>
#include <string>

#include "rapidjson/document.h"

namespace dppcord
{
/**
 * @brief Implementation of the Snowflake format
 */
class Snowflake
{
public:
  /**
   * @brief Construct a new Snowflake object using a given uint64_t
   * @param snowflake the snowflake
   */
  Snowflake(const uint64_t snow) : m_snowflake(snow) {}
  /**
     * @brief Construct a new Snowflake object using a json payload
     * @param payload json that contains the snowflake
     */
  Snowflake(const Document &payload) { m_snowflake = (payload == nullptr) ? 0 : std::stoul(payload.get<std::string>()); }
  /**
     * @brief Construct a new Snowflake object using a string
     * @param snowflake string that contains the snowflake
     */
  Snowflake(const std::string &snowflake) { m_snowflake = (snowflake == "") ? 0 : std::stoul(snowflake); }
  /**
     * @brief Construct a new Snowflake object
     */
  Snowflake():Snowflake(0){}
  /**
     * @brief Destroy the Snowflake object
     */
  ~Snowflake(){}

  /**
     * @brief Returns the Snowflake
     * @return uint64_t the snowflake
     */
  operator uint64_t() const { return m_snowflake; }

  /**
     * @brief returns the timestamp contained within the snowflake
     * @return const uint64_t the timestamp
     */
  const uint64_t __always_inline getTimestamp() const { return (m_snowflake >> 22) + 1420070400000; }
  /**
     * @brief returns the internal worker id contained within the snowflake
     * @return const uint8_t the internal worker id
     */
  const uint8_t __always_inline getInternalWorkerID() const { return (m_snowflake & 0x3E0000) >> 17; }
  /**
     * @brief returns the internal process id contained within the snowflake
     * @return const uint8_t internal process id
     */
  const uint8_t __always_inline getInternalProcessID() const { return (m_snowflake & 0x1F000) >> 12; }
  /**
     * @brief returns the increment contained within the snowflake
     * @return const uint16_t increment
     */
  const uint16_t __always_inline getIncrement() const { return m_snowflake & 0xFFF; }

private:
  /**
     * @brief The snowflake in uint64_t format
     */
  uint64_t m_snowflake;
};
} // namespace discordpp

#endif