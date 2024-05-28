void printVec(vector<vector<int>> v){
    cout<<"{";
    for(auto i:v){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"], ";
    }
    cout<<"}";
}

void CombSum(vector<int>&v, int ind, int tar, vector<int>&arr,
            vector<vector<int>>&ans){
        
        if(ind == v.size()){
            if(tar == 0){
                ans.push_back(arr);
            }
            return;
        }

        if(v[ind] <= tar){
            arr.push_back(v[ind]);
            CombSum(v, ind+1, tar-v[ind], arr, ans);
            arr.pop_back();
        }
        CombSum(v, ind+1, tar, arr, ans);

    }
