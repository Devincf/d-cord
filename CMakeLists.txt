cmake_minimum_required(VERSION 3.9)

project(dppcord VERSION 0.3.0 DESCRIPTION "Discord Library written in C++")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")


set(CMAKE_BUILD_TYPE Debug)

find_package(Boost 1.55.0 REQUIRED COMPONENTS thread system filesystem)
include_directories(... ${Boost_INCLUDE_DIRS})
link_directories(... ${Boost_LIBRARY_DIRS})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


add_library(dppcord SHARED
src/dppcord/core/client/DiscordClient.cpp  

src/dppcord/core/handler/GuildsHandler.cpp
src/dppcord/core/handler/UsersHandler.cpp
 
src/dppcord/core/task/BaseTask.cpp

src/dppcord/core/objects/guild/Guild.cpp  
src/dppcord/core/objects/channel/BaseChannel.cpp src/dppcord/core/objects/channel/GuildChannel.cpp src/dppcord/core/objects/channel/DmChannel.cpp src/dppcord/core/objects/channel/GuildVoiceChannel.cpp src/dppcord/core/objects/channel/GuildTextChannel.cpp 
src/dppcord/core/objects/user/User.cpp  src/dppcord/core/objects/user/GuildUser.cpp src/dppcord/core/objects/user/BotUser.cpp 
src/dppcord/core/objects/Role.cpp 
src/dppcord/core/objects/emoji/Emoji.cpp 
src/dppcord/core/objects/message/BaseMessage.cpp

src/dppcord/command/argument/ArgumentList.cpp
src/dppcord/command/builder/CommandBuilder.cpp src/dppcord/command/builder/CommandMap.cpp
src/dppcord/command/parser/CommandParser.cpp
src/dppcord/command/Command.cpp src/dppcord/command/CommandName.cpp 

src/dppcord/core/config/ConfigData.cpp src/dppcord/core/config/ConfigReader.cpp

src/dppcord/database/Database.cpp src/dppcord/database/SQLiteDatabase.cpp

src/dppcord/plugin/IPlugin.cpp

src/dppcord/rest/Request.cpp src/dppcord/rest/RequestContent.cpp src/dppcord/rest/RequestHeaderList.cpp src/dppcord/rest/RequestResponse.cpp src/dppcord/rest/DiscordEndpoint.cpp

src/dppcord/websocket/WebsocketConnection.cpp       src/dppcord/websocket/WebsocketHandler.cpp
src/dppcord/websocket/api/gateway/events/DispatchDistributor.cpp  src/dppcord/websocket/api/gateway/events/BaseEvent.cpp    
src/dppcord/websocket/api/gateway/events/ReadyEvent.cpp    src/dppcord/websocket/api/gateway/events/GuildCreateEvent.cpp    
src/dppcord/websocket/api/gateway/events/MessageCreateEvent.cpp src/dppcord/websocket/api/gateway/events/MessageDeleteEvent.cpp
src/dppcord/websocket/api/gateway/events/ChannelCreateEvent.cpp src/dppcord/websocket/api/gateway/events/TypingStartEvent.cpp src/dppcord/websocket/api/gateway/events/PresenceUpdateEvent.cpp 
src/dppcord/websocket/api/gateway/events/MessageReactionAdd.cpp src/dppcord/websocket/api/gateway/events/ResumeEvent.cpp
src/dppcord/websocket/api/gateway/Heartbeater.cpp    

)


set_target_properties(dppcord PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(dppcord PROPERTIES SOVERSION 1)

export(PACKAGE dppcord)

target_include_directories(dppcord PRIVATE include/ submodules/nlohmannjson/single_include submodules/curlpp/include submodules/websocketpp/websocketpp
                            )

target_link_libraries(dppcord stdc++fs Threads::Threads crypto ssl  curl curlpp sqlite3 Boost::thread pthread)

include(GNUInstallDirs)

install(TARGETS dppcord 
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

