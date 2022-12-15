#include "rush.h"

int ft_char_check(char *str)
{
    int i;
    
    i = 0;
    while(i <= 30)
    {
        if(str[i] >= 49 && str[i] <= 52)
            i += 2;
        else
            return(1);
    }
    i = 1;
    while(i <= 29)
    {
        if(str[i] == ' ')
            i += 2;
        else
            return(1);
    }
    return(0);
}

int ft_rep(char *str, char c)
{
    int i;
    int k;
    int l;
    
    k = 0;
    i = 0;
    l = 0;
    while(str[i])
    {
        if (str[i] == c)
            k++;
        i += 2;
        l++;
        if (l == 4 && k == 4)
            return(1);
        else if(l == 4)
        {
            k = 0;
            l = 0;
        }
    }
    return(0);
}

int ft_incomp(char *str)
{
    int i;
    
    i = 0;
    while(i <= 30)
    {
        if((i <= 6) || (i >= 16 && i <= 22))
        {
            if((str[i] - 48 + str[i + 8] - 48) >= 6)
                return(1);
            else if((str[i] - 48 + str[i + 8] - 48) <= 2)
                return(1);
        }
        i += 2;
    }
    return(0);
}

int ft_one(char *str)
{
    int i;
    int l;
    int k;
    
    k = 0;
    i = 0;
    l = 0;
    while(i <= 30)
    {
        if (str[i] == '1')
            k++;
        i += 2;
        l++;
        if (l == 4 && k == 0)
            return(1);
        else if(l == 4)
        {
            k = 0;
            l = 0;
        }
    }
    return(0);
}

int ft_check (int ac, char **av)
{
    if(ac != 2)
      return(1);
    else if(ft_strlen(av[1]) != 31)
        return(1);
    else if(ft_char_check(av[1]))
        return(1);
    else if(ft_rep(av[1], '1') || ft_rep(av[1], '2') || ft_rep(av[1], '3') || ft_rep(av[1], '4'))
        return(1);
    else if(ft_incomp(av[1]))
        return(1);
    else if(ft_one(av[1]))
        return(1);
    return(0);
}
