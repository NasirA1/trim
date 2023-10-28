#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* buffer) 
{
    size_t realsize = size * nmemb;
    buffer->append(reinterpret_cast<char*>(contents), realsize);
    return realsize;
}

int main(int argc, char* argv[])
{
    CURL* curl = curl_easy_init();
    std::string buffer;

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://catfact.ninja/fact");

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);        

        CURLcode res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } 
        else {
            auto data = json::parse(buffer);
            std::cout << "A random cat fact: " << data["fact"];
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    
    std::cout << std::endl;
    return EXIT_SUCCESS;
}