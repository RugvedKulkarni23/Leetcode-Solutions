class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int total_cost =0;
        int starting_index=0;
        int current_gas=0;
        for(int i=0;i<gas.size();i++){
            total_gas+=gas[i];
        }
        for(int i=0;i<cost.size();i++){
            total_cost+=cost[i];
        }
        if(total_gas<total_cost){
            return -1;
        }
        for(int i=0;i<gas.size();i++){
             current_gas+= (gas[i]-cost[i]);
             if(current_gas<0){
                 starting_index=i+1;
                 current_gas=0;
             }
        }
        return starting_index;
    }
};