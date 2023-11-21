class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans = 0, n = garbage.size();
        bool M = false, P = false, G = false;   // the loop will stop after all 3 is true
                                                // means that all garbage has been collected
        for (int i = n - 1; i >= 0; i--) {
            if (!G && garbage[i].find('G') != std::string::npos){// if G is false and there is a garbage found then accumulate travel from house 0 to house i
                G = true;
                ans += std::accumulate(travel.begin(), travel.begin() + i, 0);  // adds from first element to the element of i position
            }

            if (!P && garbage[i].find('P') != std::string::npos){
                P = true;
                ans += std::accumulate(travel.begin(), travel.begin() + i, 0);
            }

            if (!M && garbage[i].find('M') != std::string::npos){
                M = true;
                ans += std::accumulate(travel.begin(), travel.begin() + i, 0);
            }
            if (M && G && P) break;
        }
        return ans + std::accumulate(garbage.begin(), garbage.end(), 0, [](int sum, const std::string &str) {return sum + str.size();});
    }   // return the accumulated minutes in travelling + accumulate every garbage with the lambda function that adds all the string size of each garbage i.
};
