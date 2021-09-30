#include <stdio.h>
#include <math.h>

//一个十进制浮点数转化的程序
//修改m的赋值运行即可，精度有限尤其对于过小的数据

int main (){

    float m = -45.8125;
    int bp = m;
    float ap = m - bp;
    int inp[16];
    int dep[50];
    int ib = 0;
    int ia = 0;
    int fra[50];
    int ifr = 0;
    int exponent = 0;
    int exp[8] = {0,0,0,0,0,0,0,0};
    int iex = 0;
    int sign = 0;
    int z = 0;

    /*printf("m = %f\n",m);
    printf("bp = %d\n",bp);
    printf("ap = %f\n",ap);*/
    /*if ( ap > 0){
        printf("float > int");
    }*/
    
    //判断符号
    if ( m < 0){
        sign = 1;
        m = -m;
        bp = -bp;
        ap = -ap;
    }

    //将整数部分转化为二进制数
    while ( bp > 0){
        inp[ib] = bp%2;
        bp /= 2;
        //printf("inp[%d] = %d\n",ib,inp[ib]);
        ib++;
    }

    ib = ib -1;
    //printf("ib = %d\n",ib);
    z = ib;

    //将小数部分转化为二进制数，强制转化50位小数，避免0.2等无限循环小数
    while ( ia <= 50 ){

        ap *= 2;
        if ( ap >= 1){
            dep[ia] = 1;
            ap -= 1;
        }
        else dep[ia] = 0;
        //printf("dep[%d] = %d\n",ia,dep[ia]);
        ia++;
        
    }


    //拼接小数和整数部分，产生23位以上的fraction部分
    while ( ib >= 0 ){
        
        fra[ifr] = inp[ib];
        //printf("fra[%d] = %d\n",ifr,fra[ifr]);
        ib--;
        ifr++;

    }

    ia = 0;
    //初始化ia
    //printf("ifr = %d\n",ifr);
    //////////小数部分规定了50位但非0部分后续会被舍去，故表示范围仍然有限//////////
    while ( ia <= 50 ){
        
        fra[ifr] = dep[ia];
        //printf("fra[%d] = %d\n",ifr,fra[ifr]);
        ifr++;
        ia++;

    }
    //遍历获取到的fraction部分数组找到第一个1，取后续部分
    ifr = 0; 
    while ( ifr <= 50 ){

        if ( fra[ifr] != 1){
            //printf("ifr = %d\n",ifr);
            ifr++;
        }
        else break;
        
    }

    //先判断exponent，若有整数部分此时的ib即为指数
    //若无整数部分此时的-ifr-1即为指数
    ib = z;
    ifr = ifr+1;
    //printf("ifr = %d\n",ifr);
    if ( ib >= 0 ){
        exponent = ib+127;
    }
    else exponent = -ifr+127;
    //printf("exponent = %d\n",exponent);

    printf("%d",sign);
    printf("   ");

    //exponent二进制转化并打印
    while ( exponent > 0 ){

            exp[iex] = exponent%2;
            //printf("exp[%d] = %d\n",iex,exp[iex]);
            exponent /= 2;
            iex++;

        }
    iex -= 1;
    //printf("iex = %d\n",iex);
    while (iex >= 0 ){

        printf("%d",exp[iex]);
        iex--;

    }
    
    printf("   ");

    //打印出fraction部分
    for(int i=1;i<=23;i++){

        printf("%d",fra[ifr]);
        ifr++;

    }
    //int exponent = ib-1+127;*/
    return 0;
}