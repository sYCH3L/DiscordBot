#include "handlers.h"

#include <cpr/util.h>
#include <iostream>
#include <string>
#include <vector>

static std::vector<std::string> split(std::string s, std::string delimiter) {
  std::vector<std::string> res;
  {
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      res.push_back(token);
      s.erase(0, pos + delimiter.length());
    }
        res.push_back(s);
  }
  return res;
}

void gusti(Bot *parent, MessageHandler *hndlr, SleepyDiscord::Message msg) {
  parent->sendMessage(msg.channelID,
                      "<@" + msg.author.ID + "> kus mu aramis on?");
}

void wuffy(Bot *parent, MessageHandler *hndlr, SleepyDiscord::Message msg) {
  parent->sendMessage(msg.channelID,
                      "<@" + msg.author.ID +
                          "> Naturaalsed lokid ja kümne tolline TÜRA");
}

void addcmd(Bot *parent, MessageHandler *hndlr, SleepyDiscord::Message msg) {
  std::string temp = msg.content;
  std::vector<std::string> tmp = split(temp, " ");

  if (tmp.size() > 2) {


    std::string cmd = '.' + tmp[1];
    for(auto &c : parent->msg_handlers)
    {
       if((cmd.compare(0, c.message.length(), c.message) == 0))
       {
          parent->sendMessage(msg.channelID, "Command exists no way hosey");
          return;
       }
    }
    std::string response = temp.substr(temp.find(tmp[1])+tmp[1].length()+1, temp.length() - tmp[0].length() - tmp[1].length());

    parent->msg_handlers.push_back(MessageHandler(cmd, response));
    parent->sendMessage(msg.channelID,
                      "<@" + msg.author.ID +
                          "> " + cmd + " added with text: " + response);
  }
}

void delcmd(Bot *parent, MessageHandler *hndlr, SleepyDiscord::Message msg) {
  std::string temp = msg.content;
  std::vector<std::string> tmp = split(temp, " ");

  if (tmp.size() > 1) {
    std::string cmd = tmp[1];
    for(auto it = parent->msg_handlers.begin(); it != parent->msg_handlers.end(); it++)
    {
       if((cmd.compare(0, (*it).message.length(), (*it).message) == 0))
       {
              parent->msg_handlers.erase(it);
              parent->sendMessage(msg.channelID,
                      "<@" + msg.author.ID +
                          "> " + cmd + " removed ");
              return;
       }
    }
    parent->sendMessage(msg.channelID, "Not found");
  }
}