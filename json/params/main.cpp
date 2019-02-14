#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include<vector>
#include<cstring>
#include<string_view>

#include <curl/curl.h>
#include "dist/json/json.h"

using namespace std;
//"./params https://challenges.hackajob.co/swapi/api/people/?search=Luke%20Skywalker"
namespace
{
	std::size_t callback(
			const char *in,
			std::size_t size,
			std::size_t num,
			std::string *out)
	{
		const std::size_t totalBytes(size * num);
		out->append(in, totalBytes);
		return totalBytes;
	}
}

bool getJsonData(const std::string &url, Json::Value &result)
{
	CURL *curl = curl_easy_init();

	// Set remote URL.
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

	// Don't bother trying IPv6, which would increase DNS resolution time.
	curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

	// Don't wait forever, time out after 10 seconds.
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

	// Follow HTTP redirects if necessary.
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	// Response information.
	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	// Hook up data handling function.
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

	// Hook up data container (will be passed as the last parameter to the
	// callback handling function).  Can be any pointer type, since it will
	// internally be passed as a void pointer.
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

	// Run our HTTP GET command, capture the HTTP response code, and clean up.
	curl_easy_perform(curl);
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
	curl_easy_cleanup(curl);

	if (httpCode == 200)
	{
		std::cout << "\nGot successful response from " << url << std::endl;

		// Response looks good - done using Curl now.  Try to parse the results
		// and print them out.
		Json::Value jsonData;
		Json::Reader jsonReader;

		if (jsonReader.parse(*httpData.get(), jsonData))
		{
			result = jsonData;
			return 0;
			/*
				 std::cout << "Successfully parsed JSON data" << std::endl;
				 std::cout << "\nJSON data received:" << std::endl;
				 std::cout << jsonData.toStyledString() << std::endl;

				 const std::string dateString(jsonData["date"].asString());
				 const std::size_t unixTimeMs(
				 jsonData["milliseconds_since_epoch"].asUInt64());
				 const std::string timeString(jsonData["time"].asString());

				 std::cout << "Natively parsed:" << std::endl;
				 std::cout << "\tDate string: " << dateString << std::endl;
				 std::cout << "\tUnix timeMs: " << unixTimeMs << std::endl;
				 std::cout << "\tTime string: " << timeString << std::endl;
				 std::cout << std::endl;
				 */
		}
		else
		{
			std::cout << "Could not parse HTTP data as JSON" << std::endl;
			std::cout << "HTTP data was:\n"
				<< *httpData.get() << std::endl;
			return 1;
		}
	}
	else
	{
		std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
		return 1;
	}
}

void printValueType(const Json::Value &val)
{
	switch (val.type())
	{
		case Json::nullValue:
			cout << "null\n";
			break;
		case Json::intValue:
			cout << "int " << val.asLargestInt() << "\n";
			break;
		case Json::uintValue:
			cout << "uint " << val.asLargestUInt() << "\n";
			break;
		case Json::realValue:
			cout << "real " << val.asDouble() << "\n";
			break;
		case Json::stringValue:
			cout << "string " << val.asString() << "\n";
			break;
		case Json::booleanValue:
			cout << "boolean " << val.asBool() << "\n";
			break;
		case Json::arrayValue:
			cout << "array of length " << val.size() << "\n";
			break;
		case Json::objectValue:
			cout << "object of length " << val.size() << "\n";
			break;
		default:
			cout << "wrong type\n";
			break;
	}
}
void Indent(ostream& ofs, int indent) {
	for (int i=0; i < indent; i++)
	{
		ofs << " ";
	}
	return;
}

void scan(std::ostream& ofs, const Json::Value &val, int indent=0)
{

	switch (val.type())
	{
		case Json::nullValue:
			{
				ofs  << "null";
				break;
			}
		case Json::booleanValue: 
			{
				ofs << (val.asBool() ? "true" : "false"); 
				break;
			}
		case Json::intValue:
			{
				ofs <<  val.asLargestInt();
				break;
			}
		case Json::uintValue:
			{
				ofs << val.asLargestUInt();
				break;
			}
		case Json::realValue:
			{
				ofs << val.asDouble();
				break;
			}
		case Json::stringValue:
			{
				ofs <<  val.asString();
				break;
			}
		case Json::arrayValue: 
			{
				if(val.empty()) {
					ofs << "[]";
				}else {
					//ofs <<  val.size()  << ","  << "\n";
					ofs << "[\n";
					int newIndent = indent + 4;
					for(Json::Value::const_iterator itr = val.begin() ; itr != val.end() ; itr++ ) {
						Indent(ofs,newIndent);
						scan(ofs, *itr, newIndent);
						ofs << (itr == val.end() ? "\n" : ",\n");
					}
					Indent(ofs,indent);
					ofs << "]";
				}
				break;
			}
		case Json::objectValue:
			{
				if(val.empty())
				{
					ofs << "{}";
				}
				else
				{
					ofs << "{\n";
					int newIndent = indent + 4;
					if(val.size() > 0) {
						vector<string> keys = val.getMemberNames();
						for(int i=0; i < keys.size(); i++){
							Indent(ofs,newIndent);
							const string &key = keys[i];
							ofs <<  key << ":";
							scan(ofs, val[key],newIndent);
							ofs << (i +1 == keys.size() ? "\n" : ",\n");
						}
					}
					Indent(ofs,indent);
					ofs << "}";
				}
				break;
			}
		default:
			ofs << "wrong type\n";
			break;
	}
}

const Json::Value* findObjectKey(const Json::Value & val, string_view sv) {

	return val.find(sv.data(),sv.data() + sv.size());

}

const Json::Value attributeHelper(const Json::Value& val,string_view attribute) {
	switch (val.type())
	{
		case Json::arrayValue: 
			{
				if(!val.empty()) 
				{
					for(Json::Value::const_iterator itr = val.begin() ; itr != val.end() ; itr++ ) {
						//cout << "itr= " << *itr << endl; 
						 const Json::Value res = attributeHelper(*itr ,attribute);
						 if(res != Json::Value::null)
						 {
							 return res;
						 }
					}
				}
				break;
			}
		case Json::objectValue:
			{
				if(!val.empty())
				{
					if(val.size() > 0) {
						vector<string> keys = val.getMemberNames();
						for(int i=0; i < keys.size(); i++){
							const string &key = keys[i];
							if(attribute.compare(key.c_str()) == 0 ){
								cout << "equal " << attribute << endl;
								return val[key];
							}

							cout << attribute << "," << key << endl;
							const Json::Value res = attributeHelper(val[key],attribute);
							if(res != Json::Value::null) return res;


						}
					}
				}
				break;
			}
		default:
			break;
	}
	return Json::Value::null;

}

const Json::Value findAttribute(const Json::Value& val, string_view objectname, string_view attribute_name) 
{
	const Json::Value* f = findObjectKey(val,objectname);	
	cout << "find objectKey" << endl;
	printValueType(*f);

	if(!f) {
		std::cout << "could not find object" << endl;
		return f;
	}
	return attributeHelper(*f,attribute_name);

}


int main(int argc, char *argv[])
{
	std::string ref = "https://challenges.hackajob.co/swapi/api/films/?format=json";
	if (argc == 2)
	{
		ref = std::string(argv[1]);
	}
	const std::string url(ref);
	Json::Value result;
	if (!getJsonData(url, result))
	{
		std::cout << result.toStyledString() << std::endl;
	}
	printValueType(result);
	printValueType(result["results"][0]["films"]);
	//cout << "trying scan" << endl;
	//	scan(std::cout, result);

	//	const char* fnd = "results";
	//	const Json::Value* f = result.find(fnd,fnd + strlen(fnd));
	cout << "find object " << endl;
	const Json::Value* f = findObjectKey(result, "results") ;
	if(!f){
		cout << "could not find" << endl;
	}else {
		cout << "found it " << endl;
		cout << f->toStyledString() << endl;
	}
	cout << "attributes" << endl;
	const Json::Value ret = findAttribute(result,"results","films");
	cout << "ret=";
	printValueType(ret);

	cout << "test more" << endl;
//	const Json::Value = attributeHelper(result,"films");





	return 0;
}
