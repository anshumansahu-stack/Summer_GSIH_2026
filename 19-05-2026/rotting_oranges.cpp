#include <bits/stdc++.h>
using namespace std;
void rottingOranges(vector<vector<int>> &grid, queue<pair<int, int>> &rotStack, int &time)
{
    if(rotStack.empty()){
        return;
    }
    int rottenOrangesThisMinute = rotStack.size();
    vector<int> dvecRow = {-1, 1, 0, 0}, dvecCol = {0, 0, -1, 1};
    bool newPushed=false;
    for (int i = 1; i <= rottenOrangesThisMinute; i++)
    {
        pair<int, int> currCoord = rotStack.front();
        for (int i = 0; i <= 3; i++)
        {
            if (currCoord.first + dvecRow[i] < 0 || currCoord.first + dvecRow[i] >= grid.size() || currCoord.second + dvecCol[i] < 0 || currCoord.second + dvecCol[i] >= grid[0].size() || grid[currCoord.first + dvecRow[i]][currCoord.second + dvecCol[i]] == 0)
            {
                continue;
            }
            else{
                if(grid[currCoord.first + dvecRow[i]][currCoord.second + dvecCol[i]] == 1){
                    grid[currCoord.first + dvecRow[i]][currCoord.second + dvecCol[i]] = 2;
                }
                int newRow = currCoord.first + dvecRow[i];
                int newCol = currCoord.second + dvecCol[i];
                pair<int,int> newCoord(newRow,newCol);
                rotStack.push(newCoord);
                newPushed=true;
            }
        }
        grid[currCoord.first][currCoord.second]=0;
        rotStack.pop();
    }
    cout<<endl;
    for (int i = 0; i < grid.size(); i++) {
        cout << "[";
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j];
            if (j < grid[i].size() - 1) cout << " ";
        }
        cout << "]" << endl;
    }
    if(newPushed){
        time++;
    }
    //This is Iterative, I just made it recursive
    rottingOranges(grid,rotStack,time);
}
void findRottenOranges(vector<vector<int>> &grid, pair<int, int> &currCoord, queue<pair<int, int>> &rotStack, int& totalOranges)
{
    // cout<<"New Recursion!"<<endl;
    if (currCoord.first < 0 || currCoord.first >= grid.size() || currCoord.second < 0 || currCoord.second >= grid[0].size() || grid[currCoord.first][currCoord.second] == 0 || grid[currCoord.first][currCoord.second] == -1)
    {
        // cout<<"Invalid Index!"<<endl;
        return;
    }
    if (grid[currCoord.first][currCoord.second] == 2)
    {
        // cout<<"Rotten Coordinate found! ("<<currCoord.first<<","<<currCoord.second<<")"<<endl;
        rotStack.push(currCoord);
    }
    vector<int> dvecRow = {-1, 1, 0, 0}, dvecCol = {0, 0, -1, 1};
    // cout<<"currCoord = ("<<currCoord.first<<","<<currCoord.second<<")"<<endl;
    grid[currCoord.first][currCoord.second]=-1;
    totalOranges++;
    for(int i=0;i<=3;i++){
        currCoord.first+=dvecRow[i];
        currCoord.second+=dvecCol[i];
        // cout<<"nextCoord = ("<<currCoord.first<<","<<currCoord.second<<")"<<endl;
        findRottenOranges(grid, currCoord, rotStack,totalOranges);
        currCoord.first-=dvecRow[i];
        currCoord.second-=dvecCol[i];
        // cout<<"currCoord neutralized to = ("<<currCoord.first<<","<<currCoord.second<<")"<<endl;
    }
}
int rottingOranges(vector<vector<int>> &grid)
{
    int max_time=INT_MIN;
    vector<vector<int>> tempgrid=grid;
    for (int i = 0; i < tempgrid.size(); i++)
    {
        for (int j = 0; j < tempgrid[i].size(); j++)
        {
            if (tempgrid[i][j] != 0 || tempgrid[i][j]!=-1)
            {
                queue<pair<int, int>> rotStack;
                pair<int, int> startCoord(i, j);
                int totalOranges=0;
                findRottenOranges(tempgrid, startCoord, rotStack ,totalOranges);
                cout<<"The size of rotstack is "<<rotStack.size()<<endl;
                if(rotStack.empty()){

                    return -1;
                }
                int time = 0;
                bool skipRot=false;
                if(totalOranges==rotStack.size()){
                    skipRot=true;
                }
                rottingOranges(grid, rotStack, time);//This will make all rotten oranges to 0
                if(skipRot){
                    time=0;
                }
                max_time=max(max_time,time);
            }
        }
    }
    return max_time;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin>>val;
            grid[i][j]=val;
        }
    }
    // for (int i = 0; i < grid.size(); i++) {
    //     cout << "[";
    //     for (int j = 0; j < grid[i].size(); j++) {
    //         cout << grid[i][j];
    //         if (j < grid[i].size() - 1) cout << " ";
    //     }
    //     cout << "]" << endl;
    // }
    int soln = rottingOranges(grid);
    cout<<"The maximal time taken is "<<soln<<" minutes."<<endl;
    return 0;
}