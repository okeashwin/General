class Solution {
    bool *visited, *visiting;
    unordered_map<int, vector<int>> graph;
    bool topo_visit(int courseNo) {
        if(!visiting[courseNo]) {
            visiting[courseNo]=true;
        }
        unordered_map<int, vector<int>>::iterator iter;
        iter=graph.find(courseNo);
        if(iter!=graph.end()) {
            for(int i=0;i<(iter->second).size();i++) {
                int curr=(iter->second)[i];
                if(visiting[curr] && !visited[curr]) {
                    return false;
                }
                if(!topo_visit(curr)) {
                    return false;
                }
            }
        }
        visited[courseNo]=true;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& p) {
        int n=p.size();
        vector<int> token;
        unordered_map<int, vector<int>>::iterator iter;
        for(int i=0;i<n;i++) {
            iter=graph.find(p[i].second);
            if(iter==graph.end()) {
                token.push_back(p[i].first);
                graph.insert(pair<int,vector<int>> (p[i].second,token));
                token.clear();
            }
            else {
                (iter->second).push_back(p[i].first);
            }
        }
        
        // iter=graph.begin();
        // for(;iter!=graph.end();iter++) {
        //     cout<<iter->first<<"--> ";
        //     for(int j=0;j<(iter->second).size();j++) {
        //         cout<<(iter->second)[j]<<'\t';
        //     }
        //     cout<<endl;
        // } 
        
        visited=new bool[numCourses];
        visiting=new bool[numCourses];
        for(int i=0;i<numCourses;i++) {
            visited[i]=false;
            visiting[i]=false;
        }
        
        for(int i=0;i<numCourses;i++) {
            if(!visited[i]) {
                if(!topo_visit(i)) {
                    return false;
                }
            }
        }
        return true;
    }
};