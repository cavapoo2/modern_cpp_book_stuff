#include <curl/curl.h>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
// callback function writes data to a std::ostream
static size_t data_write(void* buf, size_t size, size_t nmemb, void* userp)
{
	if(userp)
	{
		std::ostream& os = *static_cast<std::ostream*>(userp);
		std::streamsize len = size * nmemb;
		if(os.write(static_cast<char*>(buf), len))
			return len;
	}

	return 0;
}

/**
 * timeout is in seconds
 **/
CURLcode curl_read(const std::string& url, std::ostream& os, long timeout = 30)
{
	CURLcode code(CURLE_FAILED_INIT);
	CURL* curl = curl_easy_init();

	if(curl)
	{
		if(CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &data_write))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FILE, &os))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout))
		&& CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_URL, url.c_str())))
		{
			code = curl_easy_perform(curl);
		}
		curl_easy_cleanup(curl);
	}
	return code;
}

int main()
{
	curl_global_init(CURL_GLOBAL_ALL);

	std::ofstream ofs("output.html");
	if(CURLE_OK == curl_read("http://google.com", ofs))
	{
		// Web page successfully written to file
	}

	std::ostringstream oss;
	if(CURLE_OK == curl_read("http://google.com", oss))
	{
		// Web page successfully written to string
		std::string html = oss.str();
	}

	if(CURLE_OK == curl_read("http://google.com", std::cout))
	{
		// Web page successfully written to standard output (console?)
	}

	curl_global_cleanup();
}
