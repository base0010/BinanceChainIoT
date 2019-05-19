
#pragma once

#include "BNBClient.h"
#include <WiFiClientSecure.h>

WiFiClientSecure client;


const char *testnet_ca =
	"-----BEGIN CERTIFICATE-----\n"
	"MIIFYzCCBEugAwIBAgIQBFuRvsfto3+Vw79MxWWD4jANBgkqhkiG9w0BAQsFADBG\n"
	"MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRUwEwYDVQQLEwxTZXJ2ZXIg\n"
	"Q0EgMUIxDzANBgNVBAMTBkFtYXpvbjAeFw0xODEyMjQwMDAwMDBaFw0yMDAxMjQx\n"
	"MjAwMDBaMBgxFjAUBgNVBAMMDSouYmluYW5jZS5vcmcwggEiMA0GCSqGSIb3DQEB\n"
	"AQUAA4IBDwAwggEKAoIBAQCxKuJT2JRRngBdsUC2fYOVmXsID+Jd0hV/GaDppDY6\n"
	"NqP3oEIoOPzyQj996ct3QlzA/z67zfXWm824t9ridMDEKzYxX5mjew3VC7bRPLD7\n"
	"bK2Gwe8DykyncoLpdwQWf4a3WOtI/IPHm/fNxqO7nkUiEkrAMjrgQIW6I1XqiPyT\n"
	"Q3nm+x3CTq/aXcZxDIRqnZqT3drTWRiyr5qIqGO/xORPnC3lNIFMPAMzEzFL9DlN\n"
	"TrS4RzgvlbeGe7fTR24VhZbf6YgSW7Buo8K77/MYAwcaOf1B861onNiTDO37Opoc\n"
	"x9hdqIkey/IemWQ8CznEMe/bMakJqgoJFjbypb9iNwLRAgMBAAGjggJ5MIICdTAf\n"
	"BgNVHSMEGDAWgBRZpGYGUqB7lZI8o5QHJ5Z0W/k90DAdBgNVHQ4EFgQU/st5QvDi\n"
	"tzSgxjv8SFkNo/zS5vcwGAYDVR0RBBEwD4INKi5iaW5hbmNlLm9yZzAOBgNVHQ8B\n"
	"Af8EBAMCBaAwHQYDVR0lBBYwFAYIKwYBBQUHAwEGCCsGAQUFBwMCMDsGA1UdHwQ0\n"
	"MDIwMKAuoCyGKmh0dHA6Ly9jcmwuc2NhMWIuYW1hem9udHJ1c3QuY29tL3NjYTFi\n"
	"LmNybDAgBgNVHSAEGTAXMAsGCWCGSAGG/WwBAjAIBgZngQwBAgEwdQYIKwYBBQUH\n"
	"AQEEaTBnMC0GCCsGAQUFBzABhiFodHRwOi8vb2NzcC5zY2ExYi5hbWF6b250cnVz\n"
	"dC5jb20wNgYIKwYBBQUHMAKGKmh0dHA6Ly9jcnQuc2NhMWIuYW1hem9udHJ1c3Qu\n"
	"Y29tL3NjYTFiLmNydDAMBgNVHRMBAf8EAjAAMIIBBAYKKwYBBAHWeQIEAgSB9QSB\n"
	"8gDwAHYAu9nfvB+KcbWTlCOXqpJ7RzhXlQqrUugakJZkNo4e0YUAAAFn4C+qqwAA\n"
	"BAMARzBFAiEAwTv4xb5O15uD8HueEd0G1qifGqFEFC3PBM9HUdQNVeYCIFR2SvIH\n"
	"SZiDoN7Ekt4I1eTZqTvCEfAWnlNm0yOHhhrZAHYAh3W/51l8+IxDmV+9827/Vo1H\n"
	"Vjb/SrVgwbTq/16ggw8AAAFn4C+rhQAABAMARzBFAiBvseRQHAi4aKfl971EvGhr\n"
	"eO3G/05dzhug1juw3kzN4QIhAJ3ZJHlRzv+sR7a4Xxkj2M8OkEuUm+mFeAFD7lKt\n"
	"AzQCMA0GCSqGSIb3DQEBCwUAA4IBAQBUAoOxg+9cmp++A46JXIoBSrHvDcfkaebh\n"
	"Ryk026Lud5NyWj1150PThhJzN3X0pnyuz22mUItsJEt7VszR3GgpYKq0s7TFKL/w\n"
	"HfO9jgiNaRtogDTpnzCsJQVl8LEYJpxOZObTBxldma+JOLT3ixqvX+bQokwyVxVj\n"
	"rygRsvON4Z5+WvDOURV/xQZgevJMU656meJ2aeDjdHEQbLSxQXUmGiJypf5xWnUj\n"
	"EBXTGW7saash0rg2uF3d7ry4zoXEbTINaEY71X3v7uM78Vrae3MXL139+iEp2Nqx\n"
	"YyOb3JIiuK0JBpAR//mrlkbXQytT2aQzlGAj6TdrCZ6Q0j7BboAm\n"
	"-----END CERTIFICATE-----\n";

BNBClient::BNBClient(){
	client.setCACert(testnet_ca);
}


//std::string BNBClient::GetBalanceJSON(){
//		std::string encoded = testnetURLRoot + "/api/v1/account/" + deviceAddress;
//		//maybe not a pointer below ?
//	    std::string res = BNBClient::GET(&encoded);
//	    return res;
//}
int BNBClient::ParseJSON(std::string json){
	  	DynamicJsonBuffer jb(2048);
	    JsonObject &root = jb.parseObject(json.c_str());

//maybe float or double
	    int bnbBal;
	    if (root.success())
	    {
	        Serial.println("Successful Parse");
	    }

	    JsonArray& balancesArray = root["balances"];

	    for(JsonObject& t : balancesArray){
	    	auto symbol = t.get<const char*>("symbol");
	    	if (strcmp(symbol, "BNB") == 0){
	    		//Got BNB tokens
	    		auto freeBNB = t.get<const char*>("free");
	    		auto lockedBNB = t.get<const char*>("locked");
	    		auto frozenBNB = t.get<const char*>("frozen");

	    		stringstream ss;
	    		ss << freeBNB;


	    		ss >> bnbBal;

	    	}
	    }

		return bnbBal;




}
int BNBClient::GetBNBBalance(){
	std::string res = BNBClient::GET();
	int latestBal = BNBClient::ParseJSON(res);
	Serial.printf("BNB Balance\n %i", latestBal); 
	return latestBal;

}


std::string BNBClient::GET(){
	Serial.println("GETTING "); 
	std::string path = "/api/v1/account/" + deviceAddress + "/";

	std::string result;
	int connected = client.connect(testnetURLRoot.c_str(), 443);
//	 if (!connected) {
//	        LOG("Unable to connect to Host");
//	        LOG(host);
//	        return "";
//	    }

	    // Make a HTTP request:
//	    int l = data->size();
//	    stringstream ss;
//	    ss << l;
//	    string lstr = ss.str();

	    std::string strPost = "GET " + string(path) + " HTTP/1.1";
	    string strHost = "Host: " + string(testnetURLRoot);
//	    string strContentLen = "Content-Length: " + lstr;

	    client.println(strPost.c_str());
	    client.println(strHost.c_str());
//	    client.println("Content-Type: application/json");
//	    client.println(strContentLen.c_str());
	    client.println("Connection: close");
	    client.println();
//	    client.println(data->c_str());

	    while (client.connected()) {
	        String line = client.readStringUntil('\n');
	        if (line == "\r") {
	            break;
	        }
	    }
	    // if there are incoming bytes available
	    // from the server, read them and print them:


	    //maybe uncomment
	    while (client.available()) {
	        char c = client.read();
	        result += c;
	    }
	    client.stop();
		Serial.println(result.c_str()); 
		return result;
	}


//std::string BNBClient::httpGET(const char *endpoint, const char *cookie, bool isJson)
//{
//	stringstream ss;
//    http->begin(endpoint);
//    http->addHeader("Cookie", (String)authCookie.c_str());
//    http->addHeader("Authorization", "Bearer foo");
//
//    int httpCode = http->GET();
//    if(httpCode == HTTP_CODE_OK) {
//
//                   // get lenght of document (is -1 when Server sends no Content-Length header)
//                   int len = http->getSize();
//
//                   // create buffer for read
//                   uint8_t buff[128] = { 0 };
//
//                   // get tcp stream
//                   WiFiClient * stream = http->getStreamPtr();
//
//                   // read all data from server
//                   while(http->connected() && (len > 0 || len == -1)) {
//                       // get available data size
//                       size_t size = stream->available();
//
//                       if(size) {
//                           // read up to 128 byte
//                           int c = stream->readBytes(buff, ((size > sizeof(buff)) ? sizeof(buff) : size));
//
//                           // write it to Serial
////                           USE_SERIAL.write(buff, c);
//                           ss.write((char*)buff, c);
//
//                           if(len > 0) {
//                               len -= c;
//                           }
//                       }
//                       vTaskDelay(500/portTICK_RATE_MS);
//                   }
//
//
//               }
//    http->end();
//return ss.str();
//}
