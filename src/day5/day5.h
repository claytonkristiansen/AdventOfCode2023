#include "mytools.h"
#define int_t long long

namespace Day5
{
    enum MAPS
    {
        SEED_TO_SOIL_MAP = 0,
        SOIL_TO_FERTILIZER_MAP,
        FERTILIZER_TO_WATER_MAP,
        WATER_TO_LIGHT_MAP,
        LIGHT_TO_TEMPERATURE_MAP,
        TEMPERATURE_TO_HUMIDITY_MAP,
        HUMIDITY_TO_LOCATION_MAP
    };

    class SubMap
    {
    public:
        int_t inStart;
        int_t outStart;
        int_t length;

        SubMap(int_t inStart, int_t outStart, int_t length)
            :inStart(inStart), outStart(outStart), length(length) {}
        
        SubMap(std::string strInput);
    };

    class Map
    {
        std::vector<SubMap> subMapsVector;
        
        public:

        int_t operator[](int_t key) {
            for (SubMap subMap : subMapsVector) {
                if (key >= subMap.inStart && key <= subMap.inStart + subMap.length) {
                    return subMap.outStart + key - subMap.inStart;
                }
            }
            return key;
        }

        std::vector<std::vector<int_t>> SearchRange(std::vector<std::vector<int_t>> rangeInput);

        void Add(SubMap subMap) {
            subMapsVector.push_back(subMap);
        }
    };

    int Execute();
} // namespace Day5