#include <iostream>
#include <json.h>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
	CURL *curl;
	CURLcode res;
	std::string readBuffer;
	
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://challenges.hackajob.co/swapi/api/films/?format=json");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		
		std::string strJson = readBuffer; // need escape the quotes
	    Json::Reader reader;
	    Json::Value obj;
	    reader.parse(strJson.c_str(), obj);
	
	    cout << "count: " << obj["count"].asString() << endl;
	}
}