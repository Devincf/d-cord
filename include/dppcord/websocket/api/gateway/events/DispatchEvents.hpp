/**
 * @file DispatchEvents.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-19 07:14
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef DISPATCHEVENTS_HPP
#define DISPATCHEVENTS_HPP

#include "ReadyEvent.hpp"
#include "guild/GuildCreateEvent.hpp"
#include "guild/GuildBanAddEvent.hpp"
#include "guild/GuildBanRemoveEvent.hpp"
#include "guild/GuildDeleteEvent.hpp"
#include "guild/GuildEmojisUpdateEvent.hpp"
#include "guild/GuildIntegrationsUpdateEvent.hpp"
#include "guild/GuildMemberAddEvent.hpp"
#include "guild/GuildMemberRemoveEvent.hpp"
#include "guild/GuildMembersChunkEvent.hpp"
#include "guild/GuildMemberUpdateEvent.hpp"
#include "guild/GuildRoleCreateEvent.hpp"
#include "guild/GuildRoleDeleteEvent.hpp"
#include "guild/GuildRoleUpdateEvent.hpp"
#include "guild/GuildUpdateEvent.hpp"
#include "message/MessageCreateEvent.hpp"
#include "message/MessageUpdateEvent.hpp"
#include "message/MessageDeleteEvent.hpp"
#include "message/MessageDeleteBulkEvent.hpp"
#include "message/MessageReactionAddEvent.hpp"
#include "message/MessageReactionRemoveEvent.hpp"
#include "message/MessageReactionRemoveAllEvent.hpp"
#include "channel/ChannelCreateEvent.hpp"
#include "channel/ChannelDeleteEvent.hpp"
#include "channel/ChannelUpdateEvent.hpp"
#include "channel/ChannelPinsUpdateEvent.hpp"
#include "TypingStartEvent.hpp"
#include "PresenceUpdateEvent.hpp"
#include "ResumeEvent.hpp"
#include "user/UserUpdateEvent.hpp"
#include "voice/VoiceStateUpdateEvent.hpp"
#include "voice/VoiceServerUpdateEvent.hpp"
#include "WebhooksUpdateEvent.hpp"

#endif