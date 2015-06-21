class Solution {
public:
	//可行并不代表着可解
	bool judge(int x,int y,vector<vector<char> >& board)
    	{
    		for(int i=0;i<board.size();i++)
    			{
    				if(board[x][y]==board[i][y] && i!=x) return false;
    				if(board[x][y]==board[x][i] && i!=y) return false;
				}

			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
				{
					if(board[x][y]==board[x/3*3+i][y/3*3+j] && x!=(x/3*3+i) && y!=(y/3*3+j))
						return false;
				}

				return true;
    	}

    bool isValidSudoku(vector<vector<char>>& board) {
    	
    	for(int i=0;i<board.size();i++)
    		for(int j=0;j<board.size();j++)
    		{
    			if(board[i][j]=='.') continue;
    			if(!judge(i,j,board)) return false;
    		}
    		return true;
    	}
};