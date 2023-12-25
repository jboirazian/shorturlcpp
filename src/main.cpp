#include "crow.h"
#include "requests.h"
#include "utils.h"
#include <jsoncpp/json/json.h>
#include <string>

int main() {
  static auto tinyUrlToken = getEnvVar("TINYURL_TOKEN");
  crow::SimpleApp shorturlcpp;
  // Parse the JSON string

  CROW_ROUTE(shorturlcpp, "/")
  ([]() {
    auto page = crow::mustache::load_text("index.html");
    return page;
  });

  CROW_ROUTE(shorturlcpp, "/tinyurl/<string>")
  ([](std::string shortlinkname) {
    Json::Value root;
    Json::CharReaderBuilder reader;

    auto tinyurlresponse =
        makeHttpRequest("https://api.tinyurl.com/alias/tinyurl.com/" +
                        shortlinkname + "?api_token=" + tinyUrlToken);

    std::istringstream jsonStream(tinyurlresponse);
    Json::parseFromStream(reader, jsonStream, &root, nullptr);

    return crow::response(root["data"]["hits"].asString());
  });

  CROW_ROUTE(shorturlcpp, "/links/tinyurl")
  ([]() {
    Json::Value root;
    Json::CharReaderBuilder reader;
    auto tinyurlresponse =
        makeHttpRequest("https://api.tinyurl.com/urls/available?api_token=" +
                        std::string(tinyUrlToken));

    std::istringstream jsonStream(tinyurlresponse);
    Json::parseFromStream(reader, jsonStream, &root, nullptr);
    std::string allAlias = "";

    // Extract alias values and append to the new array
    if (root.isMember("data") && root["data"].isArray()) {
      const Json::Value &dataArray = root["data"];
      for (const Json::Value &item : dataArray) {
        if (item.isMember("alias") && item["alias"].isString()) {
          std::string alias = item["alias"].asString();
          allAlias = allAlias + std::string(";") + alias;
        }
      }
    }

    return crow::response(allAlias);
  });

  shorturlcpp.port(9090).multithreaded().run();
}