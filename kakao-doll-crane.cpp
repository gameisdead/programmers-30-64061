#include <string>
#include <vector>

using namespace std;

const int INVALID_BOARD_VAL = 0;
const int INVALID_MOVE_VAL = 0;

enum eMove{
    eMove_min = 1,
    eMove_max = 1000,
};

enum eBoard{
    eBoard_min = 0,
    eBoard_max = 100,
};

int solution(vector<vector<int>> board, vector<int> moves);
int pick(vector<vector<int>> &board, int move);
bool tryMatch(vector<int> &basket, int block);

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    
    for (auto i = moves.begin(); i != moves.end(); ++i) {
        int move = (*i); 
        if ((move < eMove_min) || (move > eMove_max))
            return INVALID_MOVE_VAL;
        
        int picked = pick(board, move);
        
        if (picked == 0)
            continue;
        
        if (tryMatch(basket, picked))
            answer += 2;
    }
    return answer;
}

int pick(vector<vector<int>> &board, int move) {
    int picked = 0;
    int x = move - 1;
    
    for (auto i = board.begin(); i!= board.end(); ++i) {
        vector<int> &rowset = (*i);
        
        if ((rowset.at(x) < eBoard_min) || (rowset.at(x) > eBoard_max))
            return INVALID_BOARD_VAL;
        
        if (rowset.size() < move)
            return INVALID_MOVE_VAL;
        
        if (rowset.at(x) == 0)
            continue;
        
        picked = rowset.at(x);
        rowset.at(x) = 0;
        break;
    }

    return picked;
}


bool tryMatch(vector<int> &basket, int block) {
    bool canMatch = false;
    
    if (basket.size() < 1) {
        basket.push_back(block);
    }
    else {
        if (basket.back() == block)
        {
            basket.pop_back();
            canMatch = true;
        }
        else
        {
            basket.push_back(block);
        }
    }
    
    return canMatch;
}
