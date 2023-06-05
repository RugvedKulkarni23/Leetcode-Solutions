class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        vector<int>& point1 = coordinates[0];
        vector<int>& point2 = coordinates[1];
        
        
        int deltaX = point2[0] - point1[0];
        int deltaY = point2[1] - point1[1];
        
    
        for (int i = 2; i < coordinates.size(); i++) {
            vector<int>& currentPoint = coordinates[i];
            
        
            int currentDeltaX = currentPoint[0] - point1[0];
            int currentDeltaY = currentPoint[1] - point1[1];
            
        
            if (deltaX * currentDeltaY != deltaY * currentDeltaX) {
                return false;
            }
        }
    
        return true;
    }
};