
https://leetcode.com/problems/text-justification/description/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n = words.size();

        vector<string>ans;

        int bef = 0;
        vector<int>temp;
        for(int i=0;i<n;i++){

            int len = words[i].size();

            if(bef == 0){
                bef += len;
            }
            else{

                int gap = temp.size();

                if(bef + gap + len <= maxWidth){
                    bef += len;
                }
                else{
                    
                    int gap = maxWidth - bef;
                    int field = (int)temp.size() - 1;

                    if(field == 0){
                        string s ="";
                        s += words[temp[0]];
                        while(gap--){
                            s+=" ";
                        }
                        ans.push_back(s);
                    }
                    else{

                        int normal_add = gap / field;
                        int extra_add = gap % field;
                        
                        string s = "";
                        for(int j=0;j<= field ; j++){

                            if(j == 0) { 
                                s+= words[temp[j]];
                            }
                            else{
                                int tot = normal_add;
                                if(extra_add > 0) tot++ , extra_add--;
                                while(tot--){
                                    s+=" ";
                                }
                                s += words[temp[j]];
                            }

                        }
                        ans.push_back(s);

                    }
                    bef = len;
                    temp.clear();   
                }
            }
            temp.push_back(i);
        }

        if(temp.size() > 0){

            int gap = maxWidth - bef;
            int field = (int)temp.size() - 1;

            if(field == 0){
                string s ="";
                s += words[temp[0]];
                while(gap--){
                    s+=" ";
                }
                ans.push_back(s);
            }
            else{
                string s = "";
                int l = 0;
                for(int j=0;j<= field ; j++){

                    if(j == 0) { 
                        s+= words[temp[j]];
                        l += words[temp[j]].size();
                    }
                    else{
                        s += " "+ words[temp[j]];
                        l += 1 + words[temp[j]].size();
                    }

                }

                if(maxWidth - l > 0){

                    int x = maxWidth - l;
                    while(x--){
                        s +=" ";
                    }

                }
                ans.push_back(s);
            }
        }

        return ans;

    }
};
