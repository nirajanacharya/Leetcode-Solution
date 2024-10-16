class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = 0;
        int col = 0;
        int minRow = 0;
        int minCol = 0;
        int maxRow = matrix.size()-1;
        int maxCol = matrix.at(0).size()-1;
        int count = 0;
        int total = (maxRow+1) * (maxCol+1);
        vector<int> result;
        int mode = 0;
        
        // top row --> right col --> bottom row --> left col --> top row --> ....
        //    0            1              2            3
        
        
        while (count < total){
            // cout << "( " << row << " , " << col << " )\n";
            result.push_back(matrix.at(row).at(col));
            ++count;
    
            // cout << "ROW bound: " << minRow << " " << maxRow << "\n";
            // cout << "COL bound: " << minCol << " " << maxCol << "\n"; 
            
            
            
            // top row -> move right
            if (mode == 0){
                // cout << "min ROW\n";
                if (col < maxCol){
                    ++col;
                } else { // go down
                    ++row;
                    ++minRow;
                    mode = (mode+1) % 4;
                }
            }
             // right col -> move down
            else if (mode == 1){
                // cout << "max COl\n";
                if (row < maxRow){
                    ++row;
                } else { // go left
                    --col;
                    --maxCol;
                    mode = (mode+1) % 4;
                }
            }
            // bottom row --> move left
            else if (mode == 2){
                // cout << "max ROW\n";
                if (col > minCol){
                    --col;
                } else { // go up
                    --row;
                    --maxRow;
                    mode = (mode+1) % 4;
                }
            } 
           // left col -> move up
            else if (mode == 3){
                // cout << "min COL\n";
                if (row > minRow){
                    --row; 
                } else { // go right
                    ++col;
                    ++minCol;
                    mode = (mode+1) % 4;
                }
            }
        }
        return result;
    }
};