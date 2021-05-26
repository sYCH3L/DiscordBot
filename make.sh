#!/usr/bin/sh

g++ -std=c++14 main.cpp -Isleepy_discord/ -I/usr/include/boost/ -I/usr/include/opus -Lwebsocketpp -Lopus -Lboost -Lsleepy_discord -o moistbot
