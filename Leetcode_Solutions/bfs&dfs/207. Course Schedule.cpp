class Solution
{
public:
    bool dfs(int course, unordered_map<int, unordered_set<int>> &mp, unordered_set<int> &visited)
    {
        if (mp.find(course) == mp.end())
        {
            return true;
        }
        for (auto it : mp[course])
        {
            if (visited.find(it) != visited.end())
            {
                return false;
            }
            visited.insert(it);
            if (dfs(it, mp, visited) == false)
            {
                return false;
            }
            visited.erase(it);
            mp.erase(it);
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int preq = prerequisites[i][1];
            if (mp.find(course) == mp.end())
            {
                unordered_set<int> temp;
                temp.insert(preq);
                mp[course] = temp;
            }
            else
            {
                mp[course].insert(preq);
            }
        }
        for (int i = 0; i < numCourses; i++)
        {
            unordered_set<int> visited;
            if (dfs(i, mp, visited) == false)
            {
                return false;
            }
        }
        return true;
    }
};