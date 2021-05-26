#ifndef MSGHANDLER_H
#define MSGHANDLER_H

#include "sleepy_discord/sleepy_discord.h"
#include <functional>
#include <string>

class Bot;

typedef enum CommandRights_t
{
   NORMAL = 0,
   ADMIN = 1
} CommandRights;

class MessageHandler {
public:
  MessageHandler(std::string message,
                 std::function<void(Bot*, MessageHandler*, SleepyDiscord::Message)> fn);
  MessageHandler(std::string message,
                 std::string response);

  bool startsWith(const std::string& test);

  bool isCommand(const std::string& test);

  std::function<void(Bot*, MessageHandler*, SleepyDiscord::Message)> fn;
  std::string message;
  std::string _fn_none_msg;
};

#endif