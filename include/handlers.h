#ifndef HANDLERS_H_
#define HANDLERS_H_

#include "sleepy_discord/sleepy_discord.h"

#include "bot.h"

void gusti(Bot* parent, MessageHandler* hndlr, SleepyDiscord::Message msg);
void wuffy(Bot* parent, MessageHandler* hndlr, SleepyDiscord::Message msg);
void addcmd(Bot* parent, MessageHandler* hndlr, SleepyDiscord::Message msg);
void delcmd(Bot *parent, MessageHandler *hndlr, SleepyDiscord::Message msg);

#endif