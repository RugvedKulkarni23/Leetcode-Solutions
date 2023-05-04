class Solution {
public:
    string predictPartyVictory(string senate) {
        queue < int > rq;
        queue < int > dq;
        int len = senate.size();
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                rq.push(i);
            }
            else {
                dq.push(i);
            }
        }
        while (!rq.empty() && !dq.empty()) {
            int r = rq.front();
            rq.pop();
            int d = dq.front();
            dq.pop();
            if (d < r) {
                dq.push(d + len);
            }
            else {
                rq.push(r + len);
            }
        }
        string s = "Radiant";
        if (rq.empty()) {
            s = "Dire";
        }
        return s;
    }
};