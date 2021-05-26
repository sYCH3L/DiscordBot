#include "bot.h"
#include <sys/socket.h>

void Bot::onMessage(SleepyDiscord::Message message) {

    /*
  if (message.startsWith(".gusti")) {
    sendMessage(message.channelID,
                "<@" + message.author.ID + "> kus mu aramis on?");
  }
  if (message.startsWith(".wuffy")) {
    sendMessage(message.channelID,
                "<@" + message.author.ID +
                    "> Naturaalsed lokid ja kümne tolline TÜRA");
  }
  */
  for(auto &m : msg_handlers)
  {
      if(m.isCommand(message.content))
      {
          if(m.fn != NULL)
          {
              m.fn(this, &m, message);
          }
          else
          {
              sendMessage(message.channelID, m._fn_none_msg);
          }
      }
  }
}