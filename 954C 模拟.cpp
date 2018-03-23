/*
 * @Samaritan_infi
 */
 ///这种题目数据不大的时候，可以第一遍预处理一个x，y，第二遍在检验一遍，会写的很方便
#include <bits/stdc++.h>
using namespace std ;

const int maxn = 200005 ;


void cal(int val , int y , int & x , int & b) {
    if(val % y == 0) x = val / y ;
    else  x = val / y + 1 ;

    b = val % y ;
    if(!b) b = y ;
}

int save[maxn] ;
int main() {
    int n ;
    while( ~ scanf("%d" , &n) ){
    scanf("%d" , &save[1]) ;
    if(n == 1) {
        puts("YES") ;
        printf("%d %d\n" , 1 , save[1]) ;
        continue ;
    }
    int y = -1 , x = -1 ;
    bool flag = true ;

    int max_c = save[1] ;
    int time = 0 ;
    int hang = 0 ;

    for(int i = 2 ; i <= n ; i ++) {
        scanf("%d" , &save[i]) ;
        int d = save[i] - save[i - 1] ;
        /*if(abs(d) > 1 && y == -1 && x != -1) {
            if(abs(d) < x && x >= ) flag = false ;
            else  y = x = abs(d) ;
        }
        else */
            if(abs(d) > 1 && y == -1) {
            y = abs(d) ;
        } else if(abs(d) > 1 && y == abs(d)) {

            int now_x , now_y ;
            cal(save[i] , y , now_x , now_y) ;
            int pre_x , pre_y ;
            cal(save[i - 1] , y , pre_x , pre_y) ;
            if(fabs(pre_x - now_x) + fabs(pre_y  - now_y) > 1) {
                flag = false ;
            }
        }
          else if (abs(d) > 1){
           // cout << "y: "<<y << endl ;
            flag = false ;
        } else if(d == 0) {
            flag = false ;
        } else if(y > 0 && fabs(d) == 1) {
            int now_x , now_y ;
            cal(save[i] , y , now_x , now_y) ;
            int pre_x , pre_y ;
            cal(save[i - 1] , y , pre_x , pre_y) ;
            if(fabs(pre_x - now_x) + fabs(pre_y  - now_y) > 1) {
                flag = false ;
            }
        } else if(  fabs(d) == 1) {
            if(y == -1) x = max(x , save[i]) ;

            else        x = max(x , save[i] % y) ;
        }

        max_c = max(max_c , save[i]) ;
       //cout << flag << endl ;
    }

    if(y == -1) y = max_c ;

    if(max_c % y == 0 ) hang = max_c / y ;
    else
    hang = max_c / y + 1 ;

    for(int i = 2 ; i <=  n; i ++) {
        int now_x , now_y ;
        cal(save[i] , y , now_x , now_y) ;
        int pre_x , pre_y ;
        cal(save[i - 1] , y , pre_x , pre_y) ;
        if(fabs(pre_x - now_x) + fabs(pre_y  - now_y) > 1) {
            flag = false ;
        }
    }

    if(! flag) {
        puts("NO") ;
        continue ;
    }
    puts("YES") ;
    printf("%d %d\n" , hang , y ) ;
    }
    return 0 ;
}
