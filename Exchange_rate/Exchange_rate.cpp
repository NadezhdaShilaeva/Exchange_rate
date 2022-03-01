#define CURL_STATICLIB
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

size_t CurlWriteFunction(char* data, size_t size, size_t nmemb, std::string* buffer)
{
    size_t result = 0;

    if (buffer != NULL)
    {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;
}

int main()
{
    system("chcp 65001 > nul");
    std::vector<std::vector<double>> currencies(34);
    std::string buffer;
    nlohmann::json valutes;
    CURL* curl;
    CURLcode response;

    while (true)
    {
        curl = curl_easy_init();
        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteFunction);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            response = curl_easy_perform(curl);
            if (response != CURLE_OK)
            {
                std::cout << "Error: " << curl_easy_strerror(response) << std::endl;
            }
            curl_easy_cleanup(curl);
        }
        valutes.clear();
        valutes = nlohmann::json::parse(buffer);
        std::cout << "Valute  Nominal  Value" << std::endl;
        int i = 0;
        for (auto& val : valutes["Valute"].items())
        {
            int nominal = val.value()["Nominal"];
            double value = val.value()["Value"];
            currencies[i].push_back(value);
            std::cout << std::setw(8) << std::left << val.key();
            std::cout << std::setw(9) << std::left << nominal << value << std::endl;
            ++i;
        }
        std::cout << std::endl;
        buffer.clear();
        Sleep(10000);
        if (GetAsyncKeyState(VK_RETURN))
        {
            break;
        }
    }

    std::cout << "Valute  Arithmetic mean  Median value" << std::endl;
    int i = 0;
    for (auto& val : valutes["Valute"].items())
    {
        double summ = 0;
        int count = currencies[i].size();
        for (auto it : currencies[i])
        {
            summ += it;
        }
        std::cout << std::setw(8) << std::left << val.key();
        std::cout << std::setw(17) << std::left << std::fixed << std::setprecision(4) << summ / count;
        std::sort(currencies[i].begin(), currencies[i].end());
        if (count % 2 == 1)
        {
            std::cout << currencies[i][count / 2] << std::endl;
        }
        else
        {
            std::cout << (currencies[i][count / 2] + currencies[i][count / 2 - 1]) / 2 << std::endl;
        }
        ++i;
    }
    return 0;
}