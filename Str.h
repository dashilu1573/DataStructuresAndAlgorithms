//
// Created by 芦yafei  on 18/7/18.
// 参考 http://wiki.jikexueyuan.com/project/kmp-algorithm/violent-match.html
//

#ifndef SORT_STR_H
#define SORT_STR_H

void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

// 字符串包含（暴力匹配）
int substr(const char* s, char* p)
{
    if (NULL == s || NULL == p)
    {
        return -1;
    }

    int len_s = strlen(s);
    int len_p = strlen(p);

    int i = 0;
    int j = 0;

    // 开始匹配，直到匹配到字符串s或p结束
    while (i < len_s && j < len_p)
    {
        // 匹配一致，下标都加1
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        // 匹配不到，下标重置
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }

    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1
    if (len_p == j)
    {
        return i - j;
    } else
    {
        return -1;
    }
}


// 字符串反转
char* reverse(char* s)
{
    int len = strlen(s);

    for(int n = 0; n < len / 2; n++)
    {
        swap(&s[n], &s[len - n -1]);
    }
}


#endif //SORT_STR_H
