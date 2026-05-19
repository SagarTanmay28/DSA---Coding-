bool isPerfectSquare(int x){
        int root = sqrt(x);
        if(root*root==x) return true;
        else return false;
    }

    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while(x<=y){
            if(isPerfectSquare(x) && isPerfectSquare(y)) return true;
            else if(!isPerfectSquare(y)){
                y = (int)sqrt(y)*(int)sqrt(y);
                x = c - y;
            }
            else {
                x = ((int)sqrt(x)+1) * ((int)sqrt(x)+1) ; // here brakets are very important
                y = c - x;
            }
        }
           
        return false;
    }
};