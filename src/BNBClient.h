#pragma once

#ifndef BNBClient_h
#define BNBClient_h

#include <string>
#include <iostream>
#include <sstream>
#include <WiFiClientSecure.h>



#include "ArduinoJson.h"
using namespace std;


class BNBClient{
public:

BNBClient();
std::string httpGET(const char *endpoint, const char *cookie, bool isJson);

std::string GetBalanceJSON();

std::string GET();
int GetBNBBalance();
int ParseJSON(std::string json);
private:

std::string deviceAddress = "tbnb1rfufqre8sgtz7z4c23zzj4nhzv83uac6as8eh0";
//may need to remove https
std::string testnetURLRoot =  "testnet-dex.binance.org";
};
#endif
