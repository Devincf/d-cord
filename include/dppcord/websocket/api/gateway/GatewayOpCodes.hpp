#ifndef GATEWAYOPCODES_HPP
#define GATEWAYOPCODES_HPP

#define GATEWAYOP_DISPATCH 0                  //  dispatches an event
#define GATEWAYOP_HEARTBEAT 1                 //  used for ping checking
#define GATEWAYOP_IDENTIFY 2                  //  used for client handshake
#define GATEWAYOP_STATUS_UPDATE 3             //  used to update the client status
#define GATEWAYOP_VOICE_STATE_UPDATE 4        //  used to join/move/leave voice channels
#define GATEWAYOP_RESUME 6                    //  used to resume a closed connection
#define GATEWAYOP_RECONNECT 7                 //  used to tell clients to reconnect to the gateway
#define GATEWAYOP_REQUEST_GUILD_MEMBERS 8     //  used to request guild members
#define GATEWAYOP_INVALID_SESSION 9           //  used to notify client they have an invalid session id
#define GATEWAYOP_HELLO 10                    //  sent immediately after connecting, contains heartbeat and server debug information
#define GATEWAYOP_HEARTBEAT_ACK 11            //  sent immediately following a client heartbeat that was received

#endif