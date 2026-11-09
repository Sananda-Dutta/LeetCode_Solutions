class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
       
        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishTime, serverId}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> busy;

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Release servers whose requests are completed
            while(!busy.empty() && busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                available.insert(server);
                busy.pop();
            }

            // All servers are busy
            if(available.empty()) {
                continue;
            }

            // Find the first available server >= i % k
            int start = i % k;

            auto it = available.lower_bound(start);

            // Circular wrapping
            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Assign request
            available.erase(it);

            count[server]++;

            // Mark server as busy
            busy.push({arrival[i] + load[i], server});
        }

        // Find maximum number of requests
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans; 
    }
};