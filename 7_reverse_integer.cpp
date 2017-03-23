class Solution {
public:
    int reverse(int x) {
        long long output;
        std::string inString;
        std::stringstream inStream, outStream;
        inStream << x;
        inStream >> inString;
        
        if(inString[0] == '-'){
            std::reverse(inString.begin() + 1, inString.end());
        }
        else
            std::reverse(inString.begin(), inString.end());
        outStream << inString;
        outStream >> output;
        if(output > 2147483647 || output < -2147483648)
            return 0;
        return output;
    }
};