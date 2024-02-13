
pair<int, int> dfs(int node, const vector<int>& tree_from, const vector<int>& tree_to, vector<bool>& visited) {
    visited[node] = true;
    pair<int, int> farthest(node, 0); 

    for (int i = 0; i < tree_from.size(); ++i) {
        if (tree_from[i] == node && !visited[tree_to[i]]) {
            pair<int, int> temp = dfs(tree_to[i], tree_from, tree_to, visited);
            temp.second++; 
            if (temp.second > farthest.second) {
                farthest = temp;
            }
        }
    }
    visited[node] = false; 
    return farthest;
}

vector<int> isSpecial(int tree_nodes, vector<int> tree_from, vector<int> tree_to) {
    vector<int> ans(tree_nodes, 0);
    vector<bool> visited(tree_nodes, false);
    
    pair<int, int> farthest_from_first = dfs(0, tree_from, tree_to, visited);
    
    fill(visited.begin(), visited.end(), false); 
    pair<int, int> diameter = dfs(farthest_from_first.first, tree_from, tree_to, visited);
    
    ans[farthest_from_first.first] = 1;
    ans[diameter.first] = 1;
    

    return ans;
}

