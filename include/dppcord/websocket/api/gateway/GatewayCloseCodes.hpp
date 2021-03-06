/**
 * @file GatewayCloseCodes.hpp
 * @author Devin-Can Firat (devinc.firat@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-05-17 05:55
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef GATEWAYCLOSECODES_HPP
#define GATEWAYCLOSECODES_HPP

#define GATEWAYCLOSE_UNKNOWN_ERROR 4000	        //	We're not sure what went wrong. Try reconnecting?
#define GATEWAYCLOSE_UNKNOWN_OPCCODE 4001	    //	You sent an invalid Gateway opcode or an invalid payload for an opcode. Don't do that!
#define GATEWAYCLOSE_DECODE_ERROR4002	        //  sent an invalid payload to us. Don't do that!
#define GATEWAYCLOSE_NOT_AUTHENTICATED 4003	    //	You sent us a payload prior to identifying.
#define GATEWAYCLOSE_AUTHENTICATION_FAILED 4004	//  The account token sent with your identify payload is incorrect.
#define GATEWAYCLOSE_ALREADY_AUTHENTICATED 4005	//  You sent more than one identify payload. Don't do that!
#define GATEWAYCLOSE_INVALID_SEQ 4007        	//  sequence sent when resuming the session was invalid. Reconnect and start a new session.
#define GATEWAYCLOSE_RATE_LIMITED 4008   	    //  You're sending payloads to us too quickly. Slow it down!
#define GATEWAYCLOSE_SESSION_TIMEOUT 4009	    //  Your session timed out. Reconnect and start a new one.
#define GATEWAYCLOSE_INVALID_SHARD 4010      	//  sent us an invalid shard when identifying.
#define GATEWAYCLOSE_SHARDING_REQUIRED 4011	    //  The session would have handled too many guilds - you are required to shard your connection in order to connect.
#endif