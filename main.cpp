#include <iostream>
#include <curl/curl.h>

int main(int argc, char* argv[])
{
    CURL* curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://catfact.ninja/fact");

        CURLcode res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    
    std::cout << std::endl;
    return EXIT_SUCCESS;
}