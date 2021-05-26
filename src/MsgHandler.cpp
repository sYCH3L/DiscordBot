#include "../include/MsgHandler.h"

#include <vector>
#include <string>
#include <iostream>


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


MessageHandler::MessageHandler(std::string message,
                 std::function<void(Bot*, MessageHandler*, SleepyDiscord::Message)> fn)
{
    this->message = message;
    this->fn = fn;
}
MessageHandler::MessageHandler(std::string message,
                 std::string response)
{
    this->message = message;
    this->_fn_none_msg = response;
}

bool MessageHandler::startsWith(const std::string& test) {
		return this->message.compare(0, test.length(), test) == 0;
}

bool MessageHandler::isCommand(const std::string& test)
{
    std::string temp = test;
    std::vector<std::string> tmp = split(temp, " ");
    if(tmp.size() > 0)
    {
        return this->message.compare(0, tmp[0].length(), tmp[0]) == 0;
    }
    return false;
}