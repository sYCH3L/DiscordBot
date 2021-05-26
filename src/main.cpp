#include "../include/bot.h"
#include "../include/handlers.h"
#include "token.h"

int main() {
	Bot moistbot(TOKEN, SleepyDiscord::USER_CONTROLED_THREADS);
  moistbot.msg_handlers.push_back(MessageHandler(".gusti",&gusti));
  moistbot.msg_handlers.push_back(MessageHandler(".wuffy",&wuffy));
  moistbot.msg_handlers.push_back(MessageHandler(".addcmd", &addcmd));
  moistbot.msg_handlers.push_back(MessageHandler(".delcmd", &delcmd));
  moistbot.msg_handlers.push_back(MessageHandler(".moist", "Moistbot is made to moist the moist moist moist."));
	moistbot.run();
}
