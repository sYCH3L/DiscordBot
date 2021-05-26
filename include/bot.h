#ifndef DISCBOT_H
#define DISCBOT_H

#include "sleepy_discord/sleepy_discord.h"
#include "../include/MsgHandler.h"
#include <list>

class Bot : public SleepyDiscord::DiscordClient {
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) override;
public:
    std::list<MessageHandler> msg_handlers;
    void botSend(SleepyDiscord::Snowflake<SleepyDiscord::Channel> channelID, std::string message);
};

#endif