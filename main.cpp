// #include namespace;


// // // functions we need 

// // // sendComment();
// // // checkLabel();
// // // readproposal();
// // // readFolder();
// // // propose()


// int main() {


// }


#include "json.hpp"
#include <string>
#include <curl/curl.h>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <chrono>
#include <thread>

using json = nlohmann::json;
// Replace these variables with your own GitHub API access token, repo owner, and repo name
const std::string GITHUB_TOKEN = "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";
const std::string REPO_OWNER = "osama256";
const std::string REPO_NAME = "howilive";
const std::string substring = "\"name\": \"help wanted\"";





size_t getAnswerFunction(void* ptr, size_t size, size_t nmemb, std::string* data) {
data->append((char*)ptr, size * nmemb);
return size * nmemb;
}




// Function to send a comment on a GitHub issue using the GitHub API
void sendCommentOnIssue(std::string issueNumber, std::string comment) {
  CURL *curl;
  CURLcode res;
  std::string url = "https://api.github.com/repos/" + REPO_OWNER + "/" + REPO_NAME + "/issues/" + issueNumber + "/comments";

  // Create JSON payload for comment
  std::string jsonPayload = "{\"body\":\"" + comment + "\"}";

  // Set cURL options
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl) {
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, ("Authorization: token " + GITHUB_TOKEN).c_str());
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonPayload.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.64.1");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);

    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
}

void dealwithjson(std::string body) {

            json j = json::parse(body);

        //      std::array labels = j["labels"];

        // for(int i=1; i <= labels.size(); i++) {
        //     std::cout << labels[i-1].name;
        // }
        // std::string name = j["url"];
        // std::cout << "body : " + labels;
        // std::cout << "body : " + body;
}

// Function to get a GitHub issue using the GitHub API
bool getIssue(std::string issueNumber) {
  CURL *curl;
  CURLcode res;
  std::string url = "https://api.github.com/repos/" + REPO_OWNER + "/" + REPO_NAME + "/issues/" + issueNumber;
  std::string response_string;

  // Set cURL options
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl) {
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, ("Authorization: token " + GITHUB_TOKEN).c_str());
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.64.1");

    // res = curl_easy_perform(curl);
    // if(res != CURLE_OK)
    //   std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        // std::cout << res.labels;
        // std::string jsonStrr = "Osama Mostafa";
        // const std::string jsonStr = R"({
        //     "name": "John",
        //     "age": 30,
        //     "city": "New York",
        //     "hobbies": ["reading", "traveling"]
        // })";



    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getAnswerFunction);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 10000);

    res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
    // check if text response_string "name": "help wanted",
        if (response_string.find(substring) != std::string::npos) {
                std::cout << "Help wanted found!!!!";
                return true;

            }
        return false;
            // else{
            //     std::cout << "Help wanted not found!!!!";
            //     return false
            // }
    }

    // dealwithjson(response_string);

        // std::string name = j["url"];
    // std::cout << "The answer from server is: " << response_string;
    // std::cout << "url : " << name;
    else
    {

    std::cout << "curl_easy_perform() failed to get answer: " << curl_easy_strerror(res) << std::endl;
    return false;
    }
        // json j = json::parse(curl_easy_strerror(res));
            // json j = json::parse(jsonStr);

            //  std::string name = j["name"];

        // std::string name = j["url"];

        // std::cout << "name : " + name;
    // resbody = curl_easy_strerror(res);
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
  }

    // dealwithjson(resbody);
// dealwithjson(res);

  curl_global_cleanup();
  return false;
}




int main() {
//   // Replace these variables with the issue number and comment you want to send
//   std::string issueNumber = "1";
//   std::string comment = "Hello, this is a test comment.";

//   sendCommentOnIssue(issueNumber, comment);
bool sent = false;
while(!sent) {
if(getIssue("1")){
    sendCommentOnIssue("1", "Hello How are you 1, Microsoft");
    std::cout<< "should send now";

    sent=true;
}
std::this_thread::sleep_for(std::chrono::milliseconds(150));

}
// dealwithjson("fdsfsdfsd");


  return 0;
}


