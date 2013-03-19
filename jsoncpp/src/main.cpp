#include <string>
#include <json/json.h>

void readJson();
void writeJson();
void writeJson2();

int main(int argc, char** argv) {
	readJson();
	writeJson();
	writeJson2();
	return 0;
}

void readJson() {
	using namespace std;
/*
{
   "array" : [
      {
         "cpp" : "jsoncpp",
         "java" : "jsoninjava",
         "php" : "support"
      }
   ],
   "name" : "json"
}
*/
	std::string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";

	Json::Reader reader;
	Json::Value value;

	if (reader.parse(strValue, value))
	{
		std::string out = value["name"].asString();
		std::cout << out << std::endl;
		const Json::Value arrayObj = value["array"];
		for (unsigned int i = 0; i < arrayObj.size(); i++)
		{
			if (!arrayObj[i].isMember("cpp")) 
				continue;
			out = arrayObj[i]["cpp"].asString();
			std::cout << out;
			if (i != (arrayObj.size() - 1))
				std::cout << std::endl;
		}
	}
}

void writeJson() {
	using namespace std;

	Json::Value root;
	Json::Value arrayObj;
	Json::Value item;

	item["cpp"] = "jsoncpp";
	item["java"] = "jsoninjava";
	item["php"] = "support";
	arrayObj.append(item);

	root["name"] = "json";
	root["test"] = 1;
	root["array"] = arrayObj;

	root.toStyledString();
	std::string out = root.toStyledString();
	std::cout << out << std::endl;
}
/*
  {  
     "id":123
     "jsonrpc":"2.0",
     "method":"add_matches_for_post_process",
     "params":
     {
          "source_type": "taisan_sync",
          "match":
              {
                  "website_name": "netload",
                  "key_id": "datei00sRMPOHIL",
                  "host_url":"http:\/\/netload.in/datei00sRMPOHIL\/The.School.of.Rock.2003.720p.HDTV.DD5.1.264-CRiSC.part03.rar.htm",
                  "task_priority":"normal",
                  "matched_storage_domain": "192.168.1.246",
                  "matched_storage_date": "2013-01-30",
                  "company_ids": [1, 3]
              }
     }
  } 
*/
void writeJson2() {
	using namespace std;

	Json::Value root;
    Json::Value array_company_ids;
	Json::Value match_item;
	Json::Value params_item;

    array_company_ids.append(1);
    array_company_ids.append(2);

	match_item["website_name"] = "netload";
	match_item["key_id"] = "datei00sRMPOHIL";
	match_item["host_url"] = "http://netload.in/datei00sRMPOHIL/The.School.of.Rock.2003.720p.HDTV.DD5.1.264-CRiSC.part03.rar.htm";
	match_item["task_priority"] = 9876543;
	match_item["matched_storage_domain"] = "192.168.1.246";
	match_item["matched_storage_date"] = "2013-01-30";
	match_item["company_ids"] = array_company_ids;
   
    params_item["source_type"] = "taisan_sync";
    params_item["match"] = match_item;

	root["id"] = 123;
	root["jsonrpc"] = "2.0";
	root["method"] = "add_matches_for_post_process";
    root["params"] = params_item;

	root.toStyledString();
	std::string out = root.toStyledString();
	std::cout << out << std::endl;
}
