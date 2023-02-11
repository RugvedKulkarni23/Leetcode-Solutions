class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        multiset<int>temp;
        vector<multiset<int>>redchilds(n,temp),bluechilds(n,temp);
        for(auto j:redEdges)
        {
            redchilds[j[0]].insert(j[1]);
        }
        for(auto j:blueEdges)
        {
            bluechilds[j[0]].insert(j[1]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            //BFS for all
            vector<multiset<int>>reds=redchilds,blues=bluechilds;
            queue<pair<char,int>>visit;
            visit.push({'n',0});//neutral='n'
            int steps=0;
            while(!visit.empty())
            {
                bool justbreak=false;
                int n=visit.size();
                for(int j=0;j<n;j++)
                {
                    pair<char,int>x=visit.front();
                    visit.pop();
                    if(x.second==i)
                    {
                        ans.push_back(steps);
                        justbreak=true;
                        break;
                    }
                    if(x.first=='n')
                    {
                        for(auto j:reds[x.second])
                        {
                            visit.push({'r',j});
                            auto itr1=reds[x.second].find(j);
                            reds[x.second].erase(itr1);
                        }
                        for(auto j:blues[x.second])
                        {
                            visit.push({'b',j});//blue='b'
                            auto itr1=blues[x.second].find(j);
                            blues[x.second].erase(itr1);
                        }
                    }
                    else if(x.first=='b')
                    {
                        for(auto j:reds[x.second])
                        {
                            visit.push({'r',j});//red='r'
                            auto itr1=reds[x.second].find(j);
                            reds[x.second].erase(itr1);
                        }
                    }
                    else if(x.first=='r')
                    {
                        for(auto j:blues[x.second])
                        {
                            visit.push({'b',j});
                            auto itr1=blues[x.second].find(j);
                            blues[x.second].erase(itr1);
                        }
                    }
                }
                if(justbreak)
                {
                    break;
                }
                steps++;
            }
            if(i==ans.size())
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};