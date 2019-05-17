#ifndef GATEWAYOPCODES_HPP
#define GATEWAYOPCODES_HPP

#define DISPATCH 0                  //  dispatches an event
#define HEARTBEAT 1                 //  used for ping checking
#define IDENTIFY 2                  //  used for client handshake
#define STATUS_UPDATE 3             //  used to update the client status
#define VOICE_STATE_UPDATE 4        //  used to join/move/leave voice channels
#define RESUME 6                    //  used to resume a closed connection
#define RECONNECT 7                 //  used to tell clients to reconnect to the gateway
#define REQUEST_GUILD_MEMBERS 8     //  used to request guild members
#define INVALID_SESSION 9           //  used to notify client they have an invalid session id
#define HELLO 10                    //  sent immediately after connecting, contains heartbeat and server debug information
#define HEARTBEAT_ACK 11            //  sent immediately following a client heartbeat that was received

#endif