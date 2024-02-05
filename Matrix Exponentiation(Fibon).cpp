int multiplyMat(vector<vector<int>> &A, vector<vector<int>> &B){
    vector<vector<int>> ans(3, vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                ans[i][j] += A[i][k]*B[k][j];
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            A[i][j] = ans[i][j];
        }
    }
}

int powerMat(vector<vector<int>> &F, int n){

    if(n==1) return F[0][0] + F[0][1];

    powerMat(F, n/2);
    multiplyMat(F, F);

    vector<vector<int>>buff = {{1,1,0},{1,0,0},{0,1,0}};

    if(n%2!=0) multiplyMat(F, buff);

    return F[0][0] +F[0][1];
}

int fibon(int n){
    vector<vector<int>>F = {{1,1,0},{1,0,0},{0,1,0}};
    if(n==0) return 0;
    if(n==1 or n==2) return 1;
    return powerMat(F, n-2);
}
