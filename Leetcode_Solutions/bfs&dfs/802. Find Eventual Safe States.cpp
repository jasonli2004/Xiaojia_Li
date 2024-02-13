class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n,0);
        vector<vector<int>> incoming(n);
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < graph.size(); i++){
            for (int edge : graph[i]){
                incoming[edge].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if (graph[i].size() == 0){
                q.push(i);
            }
        }
        while (!q.empty()){
            int target = q.front();
            for (int node : incoming[target]){
                outdegree[node]--;
                if (outdegree[node] == 0){
                    q.push(node);
                }
            }
            ans.push_back(target);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};