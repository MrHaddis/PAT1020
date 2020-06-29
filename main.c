#include <stdio.h>

//MrHaddis
//https://github.com/MrHaddis/PAT1020

//用结构体
//这里多了个单价的字段是因为，要算最高销售额，那么肯定是单机优先的，这样才能得到最高
struct YueBing {
    //库存
    float kucun;
    //销售额
    float sale;
    //单价
    float single;
};

int main() {
    //种类数量
    //预计销售数量
    int typeNumber, number;
    //结果
    float result = 0;
    scanf("%d %d", &typeNumber, &number);
    //结构体数组
    struct YueBing yueBingArray[typeNumber];
    //记录输入的库存
    for (int i = 0; i < typeNumber; ++i) {
        scanf("%f", &yueBingArray[i].kucun);
    }
    //记录库存对应的销售额，并计算单价
    for (int i = 0; i < typeNumber; ++i) {
        scanf("%f", &yueBingArray[i].sale);
        yueBingArray[i].single = yueBingArray[i].sale / yueBingArray[i].kucun;
    }
    //冒泡排序，按照单价从高到低排序
    for (int i = 0; i < typeNumber; ++i) {
        for (int j = 0; j < typeNumber - 1 - i; ++j) {
            if (yueBingArray[j].single < yueBingArray[j + 1].single) {
                struct YueBing yueBing = yueBingArray[j];
                yueBingArray[j] = yueBingArray[j + 1];
                yueBingArray[j + 1] = yueBing;
            }
        }
    }
    //记录一下算钱的库存数量
    int allKucun = 0;
    for (int i = 0; i < typeNumber; ++i) {
        //默认当前的库存不到预计销售的库存数量
        allKucun += yueBingArray[i].kucun;
        result += yueBingArray[i].sale;
        //加完以后判断一下 如果超过了就减去，然后用差额来算具体金额
        if (allKucun > number) {
            allKucun -= yueBingArray[i].kucun;
            result -= yueBingArray[i].sale;
            //差额库存
            int kucunD = number - allKucun;
            //差额销售额
            float d = (float) (kucunD * yueBingArray[i].single);
            //总金额
            result = result + d;
            break;
        } else if (allKucun == number) {
            //正好相等就直接结束，输出结果
            break;
        }
    }
    printf("%.2f", result);
    return 0;
}