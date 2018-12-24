char* ui2hex(unsigned n, char *s)
{
        int i=0,tmp,N;
        while(n>0)
        {
                tmp = n%16;
                if(tmp<10)
                        s[i]=tmp+'0';/*巧妙的将整型转为数字字符*/
                else
                        s[i]=tmp-10+'A';/*巧妙的将整型转为字母字符*/
                n/=16;
                i++;/*增加数组元素个数*/
        }
        s[i]=0;
        N=i;/*数组元素个数*/
        /*颠倒数组*/
        for(i=0;i<N/2;i++)
        {
                tmp = s[i];
                s[i] = s[N-i-1];
                s[N-i-1] = tmp;
        }
        return s;
}
