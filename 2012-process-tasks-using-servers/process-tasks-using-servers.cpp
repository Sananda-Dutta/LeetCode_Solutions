/*
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<long long> freeTime(n, 0);
        vector<int> ans(m);
        for(int j = 0; j < m; j++) {
            long long time = j;
            int best = -1;
            for(int i = 0; i < n; i++) {
                if(freeTime[i] <= time) {
                    if(best == -1 ||
                       servers[i] < servers[best] ||
                       (servers[i] == servers[best] && i < best)) {

                        best = i;
                    }
                }
            }
            if(best == -1) {

                time = LLONG_MAX;

                for(int i = 0; i < n; i++) {
                    time = min(time, freeTime[i]);
                }
                for(int i = 0; i < n; i++) {

                    if(freeTime[i] <= time) {

                        if(best == -1 ||
                           servers[i] < servers[best] ||
                           (servers[i] == servers[best] && i < best)) {

                            best = i;
                        }
                    }
                }
            }
            ans[j] = best;
            freeTime[best] = time + tasks[j];
        }

        return ans;
    }
};
*/


class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        // Available: {weight, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        // Busy: {freeTime, weight, index}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > busy;

        for(int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for(int j = 0; j < m; j++) {

            // Time should never move backwards
            time = max(time, (long long)j);

            // Release all servers that are free
            while(!busy.empty() && get<0>(busy.top()) <= time) {

                auto [freeTime, weight, index] = busy.top();
                busy.pop();

                available.push({weight, index});
            }

            // If all servers are busy, wait
            if(available.empty()) {

                time = get<0>(busy.top());

                // Release all servers becoming free
                // at this time
                while(!busy.empty() && get<0>(busy.top()) <= time) {

                    auto [freeTime, weight, index] = busy.top();
                    busy.pop();

                    available.push({weight, index});
                }
            }

            // Select the best available server
            auto [weight, index] = available.top();
            available.pop();

            ans[j] = index;

            // Update server's completion time
            busy.push({time + tasks[j], weight, index});
        }

        return ans;
    }
};
