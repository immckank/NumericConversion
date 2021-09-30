#include <stdio.h>
#include <math.h>

//一个十进制转化位二进制原码和补码的程序
//用了一个比较奇妙的算法，跳过了产生反码的步骤？？？运算似乎没有更简单

int main(){

  int m = -pow(2,14)-pow(2,12)-1024-32-16-3;      //输入的整数m
  int bin[16];                                    //bin的下标比二进制数的位数上限小2???好像不对???
  int sign = 0;                                   //sign是符号正负
  int k = 0;
  int i = 0;

  printf("m = %d\n",m);

//判断正负，负数先取绝对值
if ( m < 0){
   sign = 1; 
   m = -m;
}

//除二取余的循环，可以把m变成二进制数存到数组bin[]
while (m > 0)
{

  bin[i] = m%2;
  m/=2;
  //printf("bin[%d] = %d\n",i,bin[i]);
  //上面一句可以看到数组里每个数
  i++;

}

//重置变量
i = i-1;
k = i;
//printf("k = %d\n",k);
//debug看看k是多少

printf("%d",sign);
//先输出符号正负

//逆序输出bin数组里的每一个数
while ( i >= 0 ){

    printf("%d",bin[i]);
    --i;

}

printf("\n");

i += 1;
//使i回到了0

//对于负数 从低位找起，找到第一个1在什么地方
while ( i <= k && sign != 0 ){
    if (bin[i] != 1 ){
     ++i;   
    }
    else break;
}

//printf("i = %d\n",i);
//debug用，看看i是多少
i += 1;

//对于负数 对第一个1以后的每一位数取反，得到补码
while ( i <= k && sign != 0 ){

    if ( bin[i] == 1 ){
        bin[i] = 0;
    }

    else if ( bin[i] == 0 ){
        bin[i] = 1;
    }

    ++i;
    
}

i = k;
//重置i，输出补码

printf("%d",sign);
while ( i >= 0 ){

    printf("%d",bin[i]);
    --i;

}

return 0;
}