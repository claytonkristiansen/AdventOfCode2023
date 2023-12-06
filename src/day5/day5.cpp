#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <limits>

#include "day5.h"

using namespace std;

namespace Day5
{

    SubMap::SubMap(std::string strInput) {
        std::istringstream ss(strInput);
        string readBuff;
        getline(ss, readBuff, ' ');
        outStart = stoll(readBuff);

        readBuff.clear();
        getline(ss, readBuff, ' ');
        inStart = stoll(readBuff);

        readBuff.clear();
        getline(ss, readBuff);
        length = stoll(readBuff);
    }

    vector<vector<int_t>> Map::SearchRange(vector<vector<int_t>> rangeInput) {
        vector<vector<int_t>> rangeList;

        for (vector<int_t> range : rangeInput) {
            vector<vector<int_t>> coveredList;
            int_t rStart = range[0];
            int_t rEnd = range[1];
            for (SubMap subMap : subMapsVector) {
                vector<int_t> newRange;
                int_t mapStart = subMap.inStart;
                int_t mapEnd = subMap.inStart + subMap.length;
                int_t searchStart = -1;
                int_t searchEnd = -1;
                
                if (rEnd < mapStart) {
                    continue;
                }
                else if (rStart > mapEnd) {
                    continue;
                }
                else if (mapStart <= rStart && mapEnd <= rEnd) {
                    searchStart = rStart;
                    searchEnd = mapEnd;
                }
                else if (mapStart <= rStart && rEnd <= mapEnd) {
                    searchStart = rStart;
                    searchEnd = rEnd;
                }
                else if (rStart <= mapStart && mapEnd <= rEnd) {
                    searchStart = mapStart;
                    searchEnd = mapEnd;
                }
                else if (rStart <= mapStart && rEnd <= mapEnd) {
                    searchStart = mapStart;
                    searchEnd = rEnd;
                }

                if (searchStart >= 0 && searchEnd >= 0) {
                    int_t num1 = subMap.outStart + searchStart - subMap.inStart;
                    int_t num2 = subMap.outStart + searchEnd - subMap.inStart;
                    newRange.push_back(num1);
                    newRange.push_back(num2);

                    // Keeping track of covered items for later
                    coveredList.push_back(vector<int_t>({searchStart, searchEnd}));

                    rangeList.push_back(newRange);
                }
                
            }

            // Sort the covered list to ease the filtering
            for (int i = 0; i < coveredList.size(); ++i) {
                for (int k = i + 1; k < coveredList.size(); ++k) {
                    if (coveredList[k][0] < coveredList[i][0]) {
                        vector<int_t> temp = coveredList[i];
                        coveredList[i] = coveredList[k];
                        coveredList[k] = temp;
                    }
                }
            }

            // If nothing was covered just push the whole range
            if(coveredList.empty()) {
                rangeList.push_back(range);
            }

            // Filter out the ranges that weren't covered by a map and pass them on with no change
            int_t look = rStart;
            for (vector<int_t> range2 : coveredList) {
                if (range2[0] > look) {
                    rangeList.push_back(vector<int_t>({look, range2[0] - 1}));
                }
                look = range2[1] + 1;
            }
        }
        return rangeList;
    }

    int Execute() {
        vector<string> input;
        MyTools::ParseInput(input, "input.txt");

        Map seedToSoilMap;
        Map soilToFertilizerMap;
        Map fertilizerToWaterMap;
        Map waterToLightMap;
        Map lightToTemperatureMap;
        Map temperatureToHumidityMap;
        Map humidityToLocationMap;

        string seedsLine = input.front();
        input.erase(input.begin());

        // Parse the seeds line
        vector<int_t> seeds;
        vector<vector<int_t>> seeds2;
        istringstream ss(seedsLine);
        ss.ignore(7);
        string seedString;
        int count = 0;
        vector<int_t> pair;
        while (getline(ss, seedString, ' ')) {
            int_t seedNum = stoll(seedString);
            if (++count > 1) {
                count = 0;
                pair.push_back(pair.back() + seedNum);
                seeds2.push_back(pair);
                pair.clear();
            }
            else {
                pair.push_back(seedNum);
            }
            seeds.push_back(seedNum);
            
        }

        Map *currMap = &seedToSoilMap;

        // Initialize all the maps
        for (string s : input) {
            if (!MyTools::IsNumber(s[0])) {
                if (s == "seed-to-soil map:") {
                    currMap = &seedToSoilMap;
                }
                else if (s == "soil-to-fertilizer map:") {
                    currMap = &soilToFertilizerMap;
                }
                else if (s == "fertilizer-to-water map:") {
                    currMap = &fertilizerToWaterMap;
                }
                else if (s == "water-to-light map:") {
                    currMap = &waterToLightMap;
                }
                else if (s == "light-to-temperature map:") {
                    currMap = &lightToTemperatureMap;
                }
                else if (s == "temperature-to-humidity map:") {
                    currMap = &temperatureToHumidityMap;
                }
                else if (s == "humidity-to-location map:") {
                    currMap = &humidityToLocationMap;
                }
            }
            else {
                currMap->Add(SubMap(s));
            }
        }

        int_t lowestLocation = numeric_limits<long long>::max();
        int_t lowestLocation2 = numeric_limits<long long>::max();

        for (int_t seed : seeds) {
            int_t soil;
            int_t fertilizer;
            int_t water;
            int_t light;
            int_t temperature;
            int_t humidity;
            int_t location;
            soil = seedToSoilMap[seed];
            fertilizer = soilToFertilizerMap[soil];
            water = fertilizerToWaterMap[fertilizer];
            light = waterToLightMap[water];
            temperature = lightToTemperatureMap[light];
            humidity = temperatureToHumidityMap[temperature];
            location = humidityToLocationMap[humidity];
            
            if (location < lowestLocation) {
                lowestLocation = location;
            }
        }

        vector<vector<int_t>> soilRanges;
        vector<vector<int_t>> fertilizerRanges;
        vector<vector<int_t>> waterRanges;
        vector<vector<int_t>> lightRanges;
        vector<vector<int_t>> temperatureRanges;
        vector<vector<int_t>> humidityRanges;
        vector<vector<int_t>> locationRanges;

        soilRanges = seedToSoilMap.SearchRange(seeds2);
        fertilizerRanges = soilToFertilizerMap.SearchRange(soilRanges);
        waterRanges = fertilizerToWaterMap.SearchRange(fertilizerRanges);
        lightRanges = waterToLightMap.SearchRange(waterRanges);
        temperatureRanges = lightToTemperatureMap.SearchRange(lightRanges);
        humidityRanges = temperatureToHumidityMap.SearchRange(temperatureRanges);
        locationRanges = humidityToLocationMap.SearchRange(humidityRanges);

         for(vector<int_t> locationRange : locationRanges) {
            if (locationRange[0] < lowestLocation2) {
                lowestLocation2 = locationRange[0];
            }
        }

        cout << "The lowest location is: " << lowestLocation << "\n\n";

        cout << "The lowest location for part 2 is: " << lowestLocation2 << "\n\n";
        
        return 0;
    }       
}